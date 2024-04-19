#!/usr/bin/env python

def get_count(heads, legs) -> (int, int):
    for rabbits in range(heads + 1):
        chickens = heads - rabbits
        if (rabbits * 4 + chickens * 2 == legs):
            return (chickens, rabbits)
def main():
    (chickens, rabbits) = get_count(35, 94);
    print(chickens, "chickens")
    print (rabbits, "rabbits")

if __name__ == "__main__":
    main()
