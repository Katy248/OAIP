def tpl_sort(tpl_old: tuple):
    if not isinstance(tpl_old, tuple):
        return -1
    tpl = list(tpl_old)
    last_index = len(tpl)
    step = len(tpl)//2
    while step > 0:
        for i in range(step, last_index, 1):
            j = i
            delta = j - step
            if not isinstance(tpl[j], int):
                print("Error. Return")
                return tpl_old
            while delta >= 0 and tpl[delta] > tpl[j]:
                tpl[delta], tpl[j] = tpl[j], tpl[delta]
                j = delta
                delta = j - step
        step //= 2
    return tuple(tpl)


def main():
    a = (3,4,15,17,19,21,6,9,10,12,14)
    print(a)
    print(tpl_sort(a))
    b = (3, 7, 12, 4, "Vova")
    print(b)
    print(tpl_sort(b))


if __name__ == '__main__':
    main()