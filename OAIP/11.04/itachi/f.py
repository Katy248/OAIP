

def H(n):
    sum = 0
    for i in range(1, n-1):
        sum+=i
    return sum

def A(n): return sum(range(1, n-1))

def main():
    print("H(3):", H(3))
    print("H(6):", H(6))
    print("H(20):", H(20))
    print("H(50):", H(50))

    sum = 0
    for i in range(3, 12345):
        sum += H(i)
    print(sum)


if __name__ == '__main__':
    main()