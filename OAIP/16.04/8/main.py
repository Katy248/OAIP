#!/usr/bin/env python
import inspect

def reflect(func):
    if (not callable(func)):
        print("Is not a fuction")
        return

    args = inspect.getfullargspec(func)
    print("Name:", func.__name__, "->", args.annotations["return"])
    for arg in args.args:
        print(f"\t{arg}", args.annotations.get(arg))    

    # print(args)

def test_fn(arg1, arg2: int, arg3 = 12) -> int:
    return 0

def main():
    reflect(test_fn)
    

if __name__ == "__main__":
    main()
