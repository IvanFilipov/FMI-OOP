//тук четем числа от един файл и ги записваме сортирани в друг ,
//като искаме да използваме минимално количество RAM 

#include<fstream>

int main(){

	std::ifstream Nums("nums.txt");

	if (!Nums.is_open())
		return -1;

//кое е текущото минимално число и кое е било най-малкото число от предното обхождане
	int curMin = INT_MAX;

	int lastMin = INT_MIN;


	std::ofstream Sorted("sorted.txt");


	int howMany;

	Nums >> howMany;
//колко пъти се среща минималното число
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
//четем елемент по елемент файла с числата
			Nums >> curElem;

//ако вече сме срещали такова число и то е текущото минимално
//запомняме ,че ще трябва да го запишем повече от веднъж
			if (curElem == curMin)
				times++;

//търсим нов минимум , който да бъде по - голям от последния намерен минимум

			if (curElem < curMin && curElem > lastMin){
				curMin = curElem;
//рестартираме брояча за честотата на срещане
                                times = 1;
			}
		}

//записваме текущия намерен миминум необходимия брой пъти
		while (times--)
		  Sorted << curMin << '\n';

//запазваме си текъщия минимум като предходен за следващтата итерация
		lastMin = curMin;

		curMin = INT_MAX;

		times = 0;
		
//връщаме се в началото на файла 
		Nums.seekg(0, std::ios::beg);

		int dummy;
//налага се да си прочетем броя на елементите , който се намира в началото на файла
		Nums >> dummy;


	}


	Sorted.close();
	Nums.close();

	return 0;
}
