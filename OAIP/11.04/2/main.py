def print_number_in_all_bases(number, n):
    for base in range(2, n + 1):
        print(f"{number} в {base}-ой системе счисления: {number_to_base(number, base)}")

def number_to_base(number, base):
    if number == 0:
        return "0"
    digits = []
    while number:
        digits.append(str(number % base))
        number //= base
    return "".join(digits[::-1])


def is_super(number, n):
    for base in range(2, n + 1):
        for check in range(0, base):
            if not str(number_to_base(number, base)).__contains__(str(check)):
                return False
    return True

def main():
    sum = 0
    num = 1093265783
    i = 0
    while i < 11:
        if is_super(num, 10):
            sum += num
            i += 1
            print(str(num) + " " + str(is_super(num, 10)))
        num += 1
    print_number_in_all_bases(1093268475, 10)
    #print(is_super(1093265784, 10))

if __name__ == '__main__':
    main()