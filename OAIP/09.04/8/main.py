def three_args(*args):
    st = "Переданы аргументы: "
    for i in range(0, 3):
        if not isinstance(i, type(None)):
            st += "var {i} = {args[i]}"
    return st

def main():
    print(three_args(1, 5, None))
    print(three_args(None, 5))
    


if __name__ == '__main__':
    main()