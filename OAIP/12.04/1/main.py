def main():
    f = open("./triangle_6.txt", "r")
    lines = f.readlines()

    print(sorted(list("0000000013772980989156789")))
    print(sorted(list(str(13772980989156789*2))))

    sum = 0
    for line in lines:
        tmp = list(map(int, line.split(" ")))
        sum += max(tmp)

    print(sum)

if __name__ == '__main__':
    main()
