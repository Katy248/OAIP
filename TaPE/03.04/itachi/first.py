

def f(a:list, x: int):
    for i in range(0, len(a)-1):
        if not isinstance(a[i], int):
            return -1
        if a[i] <= x and a[i+1] > x:
            return a[i]
    return -1

def main():
    a = [3,4,6,9,10,12,14,15,17,19,21]

    print(f({}, 12))
    print(f(a, 13))
    print(f(a, 19))
    print(f(a, 20))
    print(f(a, 11))
    print(f(a, 0))
    print(f(a, 1))
    print(f(a, 3))
    print(f(a, -6))
    print(f(a, -5))
    print(f(a, -2))
    print(f(a, -3))




if __name__ == '__main__':
    main()