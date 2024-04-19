#!/usr/bin/env python
def generate() -> dict:
    result = dict()
    for i in range(1, 20 + 1):
        result[i] = i ** 2

    return result

def main():
    dictionary = generate()

    for i in dictionary:
        print(i, dictionary[i])

if __name__ == "__main__":
    main()
