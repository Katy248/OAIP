#!/usr/bin/env python
def delete_nums(array):
	nums_to_del = []
	for i in array:
		if i % 5 == 0 and i % 7 == 0:
			nums_to_del.append(i)

	for i in nums_to_del:
		array.remove(i)

	return array
	

def main():
	array = [12, 24, 35, 70, 88, 120, 155]

	array = delete_nums(array)

	print(array)

if __name__ == "__main__":
	main()
