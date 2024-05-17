def f(a: list[int], x: int):
    for i in range(0, len(a)-1):
        if not isinstance(a[i], int):
            return -1
        if a[i] <= x and a[i+1] > x:
            return a[i]
    return -1


def main():
    a = [3, 4, 6, 9, 10, 12, 14, 15, 17, 19, 21]

    test_values = [12, 13, 19, 20, 11, 0, 1, 3, -6, -5, -2, -3]

    for value in test_values:
        print(f(a, value))


if __name__ == '__main__':
    main()
