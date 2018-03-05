#include <iostream>

unsigned int digitsCount(int num) {

	num = abs(num);

	return (unsigned int)(1 + log10(num));
}

bool rec_onlySameDig(int num, int last) {

	if (num < 10)
		return num == last;

	if (num % 10 != last)
		return false;

	return rec_onlySameDig(num / 10, last);
}

bool onlySameDig(int num) {

	num = abs(num);

	if (num < 10)
		return true;

	return rec_onlySameDig(num / 10, num % 10);
}

int rec_longestSameDigNum(int* arr, size_t size, size_t i, int best) {

	if (i >= size)
		return best;

	if (onlySameDig(arr[i]) &&
		digitsCount(arr[i]) > digitsCount(best))
		best = arr[i];

	return rec_longestSameDigNum(arr, size, i + 1, best);

}


int longestSameDigNum(int *arr, size_t size) {

	return rec_longestSameDigNum(arr, size, 0, 0);

}


int main() {

	int arr[] = { 11, 22, 333, 666, 21, 4444, -55, 545555 };

	std::cout << "Longest number with same digits only is : "
		<< longestSameDigNum(arr, sizeof(arr) / sizeof(int));

	return 0;
}