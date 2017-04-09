//Сортираме числата от единия файл в другия
//като ги дръпваме в рамта , но там изрично не правим размени (swaps)  , 
//което има приложение когато обектите ,които сортираме
//са доста големи и операцията по размяната е скъпа

#include<fstream>

int main(){

	std::ifstream Nums("nums.txt");

	if (!Nums.is_open())
		return -1;

	std::ofstream Sorted("sorted.txt");

	int howMany;

	Nums >> howMany;

//заделяме си паметта за числата
	int* arr = new int[howMany];

//изчитаме числата
	for (int i = 0; i < howMany; i++){

//ако някоя операция с файловия поток пропадне ,
//изчистваме паметта и приключваме изпълнението на програмата
		if (!Nums){

			Sorted << " sorting failed!";

			delete[] arr;
			Sorted.close();
			Nums.close();
			return -1;
		}

		Nums >> arr[i];

	}


//на всяка стъпка опеделяме индекса на най - малкото число
	int curMinIndex = 0;
	for (int i = 0; i < howMany; i++){

		for (int j = 0; j < howMany; j++){

			if (arr[j] <= arr[curMinIndex]){

				curMinIndex = j;
			}
		}

//записваме го във файла
		Sorted << arr[curMinIndex] << '\n';

//задаваме на клетката със минималното число максимална голяма стойност
//за да не зачитаме при следващите обхожданя
		arr[curMinIndex] = INT_MAX;

	}

//почистваме паметта и затваряме потоците
	delete[]arr;
	Sorted.close();
	Nums.close();

	return 0;
}
