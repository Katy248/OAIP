#include "iostream"
#include "random"

/// <summary>
/// Generate number on range from first to second
/// </summary>
/// <param name="first">minimum number on range</param>
/// <param name="second">maximum number on range</param>
/// <returns></returns>
uint generate_numbers(uint first, uint second) {
	uint number = rand() % (second - first + 1) + first;
	return number;
}