#include<fstream>

int main(){

	std::ifstream Nums("nums.txt");

	if (!Nums.is_open())
		return -1;

	std::ofstream Sorted("sorted.txt");

	int howMany;

	Nums >> howMany;

	int* arr = new int[howMany];

	for (int i = 0; i < howMany; i++){

		if (!Nums){

			Sorted << " sorting failed!";

			delete[] arr;
			Sorted.close();
			Nums.close();
			return -1;
		}

		Nums >> arr[i];

	}

	int curMinIndex = 0;
	for (int i = 0; i < howMany; i++){

		for (int j = 0; j < howMany; j++){

			if (arr[j] <= arr[curMinIndex]){

				curMinIndex = j;
			}
		}

		Sorted << arr[curMinIndex] << '\n';


		arr[curMinIndex] = INT_MAX;

	}


	delete[]arr;
	Sorted.close();
	Nums.close();

	return 0;
}