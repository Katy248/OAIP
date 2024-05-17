def all_eq(lst: list):
    if not isinstance(lst, list):
        return -1
    new_lst = []
    result = max(len(x) for x in lst)
    for i in lst:
        while len(i) < result:
            i += "_"
        new_lst.append(i)
    return new_lst

def main():
    a = ["Vova", "Alexander", "Vadim", "Ilya"]
    print(a)
    print(all_eq(a))



if __name__ == '__main__':
    main()