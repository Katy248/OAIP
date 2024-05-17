import math
from sympy import *

def sum_decimals(num, den):
    num_digits = 0
    digit_sum = 0
    while True:
        num *= 10
        temp = math.floor(num/den)
        digit_sum += temp
        num_digits += 1
        num -= temp*den
        if num == 1:
            break
    return digit_sum, num_digits
    
def compute():
    start = int((10**11/138))
    end = int((10**11/137))
    for x in range(start, end):
        if pow(2, x, x) == 2 and pow(3, x, x) == 3:
            if isprime(x):
                if (56789 * x) % 100000 == 99999 and (((56789 * x) + 1) % 100000) == 0:
                    digit_sum, num_digits = sum_decimals(1, x)
                    if num_digits == (x-1):
                        print("Простое число (p) для формулы расчета циклического числа ((10^(p-1)-1)/p - {x}")
                        print("Сумма цифр циклического числа - {digit_sum}")
                        return digit_sum
                    
compute()