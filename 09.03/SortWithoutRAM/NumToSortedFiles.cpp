#include<fstream>

int main(){

	std::ifstream Nums("nums.txt");

	if (!Nums.is_open())
		return -1;

	int curMin = INT_MAX;

	int lastMin = INT_MIN;


	std::ofstream Sorted("sorted.txt");


	int howMany;

	Nums >> howMany;

	int times = 0;

	for (int i = 0; i < howMany; i++){

		if (!Nums){

			Sorted << " sorting failed!";

			Sorted.close();
			Nums.close();
			return -1;
		}


		for (int j = 0; j < howMany; j++){

			int curElem;

			Nums >> curElem;

			if (curElem == curMin)
				times++;

			if (curElem < curMin && curElem > lastMin){
				curMin = curElem;
				times = 1;
			}
		}

		while (times--)
		  Sorted << curMin << '\n';

		lastMin = curMin;

		curMin = INT_MAX;

		times = 0;

		Nums.seekg(0, std::ios::beg);

		int dummy;

		Nums >> dummy;


	}


	Sorted.close();
	Nums.close();

	return 0;
}