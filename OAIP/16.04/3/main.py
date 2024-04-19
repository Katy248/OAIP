#!/usr/bin/env python
import sys

def get_numbers(end: int):
	for i in range(0, end + 1):
		if i % 5 == 0 and i % 7 == 0:
			yield i	

	
def main():
	n = 0;
	if len(sys.argv) > 1:
		n = int(sys.argv[1])
	else:
		n = int(input("Enter n: "))

	numbers = get_numbers(n)
	for i in numbers:
		print(i)

if __name__ == "__main__":
	main()
