#!/usr/bin/env python
class MyClass:
    def generate(self, start: int, end: int):
        for i in range(start, end + 1):
            if i % 7 == 0:
                yield i
        

def main():
    numbers = MyClass().generate(
        int(input("Start:")),
        int(input("End:")))
    for i in numbers:
        print(i)

if __name__ == "__main__":
    main()
