
def all_divisors(number):
    if isinstance(number, int):
        return [i for i in range(1, number + 1) if number % i == 0]


def main():
    print(all_divisors(23436))
    #print(all_divisors(190187200))
    #print(all_divisors(380457890232))


if __name__ == '__main__':
    main()