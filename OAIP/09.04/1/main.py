def to_set(arg):
    ret = {}
    if isinstance(arg, list):
        ret = set(arg)
        print("Мощность: " + str(len(ret)))
        return ret
    elif isinstance(arg, str):
        ret = set(int(x) for x in arg.split(" "))
        print("Мощность: " + str(len(ret)))
        return ret


def main():
    lst = [1, 2, 3, 4, 5]
    lst1 = "1 2 3 4"
    print(to_set(lst))
    print(to_set(lst1))


if __name__ == '__main__':
    main()