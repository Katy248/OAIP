package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	if len(os.Args) > 1 {
		str := concat(os.Args[1:])
		fmt.Println(parse(str))
	} else {
		line, err := bufio.NewReader(os.Stdin).ReadString('\n')
		if err != nil {
			fmt.Errorf("%v\n", err)
			return
		}
		fmt.Println(parse(line))
	}
}

func concat(strings []string) string {
	var result string
	for i, arg := range os.Args {
		if i == 0 {
			continue
		}
		result += " " + arg
	}
	return result
}

func parse(value string) []int {
	result := []int{}
	currentValue := 0
	isEmpty := true
	for _, ch := range value {
		if int(ch) >= 48 && int(ch) <= 57 {
			currentValue *= 10
			currentValue += int(ch) - 48
			isEmpty = false
		} else if !isEmpty {
			result = append(result, currentValue)
			isEmpty = true
			currentValue = 0
		}
	}
	if !isEmpty {
		result = append(result, currentValue)
	}
	return result
}
