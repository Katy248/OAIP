def list_to_set(arg): 
    ret = set()
    if isinstance(arg, list):
        for x in arg:
            try:
                hash(x)
                ret.add(x)
            except TypeError:
                continue
        return ret
    else:
        return -1


def main():
    lst = [1, "s", 3.2, [1, 3, 4], "da", ('1', '2', '3')]
    print(list_to_set(lst))
    


if __name__ == '__main__':
    main()