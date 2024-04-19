#!/usr/bin/env python
def bin_search(array, value):
	first = 0
	last = len(array)
	while first <= last:
		middle = first + (last - first) // 2
		if array[middle] == value:
			return middle
		elif array[middle] < value:
			first = middle + 1
		else:
			last = middle - 1
	return -1

def main():
	array = range(1, 200)
	element = int(input("Search for: "))
	index = bin_search(array, element)
	if index >= 0:
		print(index)
	else:
		print("No such element")

if __name__ == "__main__":
	main()
