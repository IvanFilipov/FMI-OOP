#include "Sheikh.h"

const int Sheikh::myCarsPriceExpectation = 2000000;


Sheikh::Sheikh(const char * n, long long b) : name(n), budget(b) {

}


void Sheikh::buyCars(const char * Fpath) {

	std::ofstream file(Fpath);

	if (!file.is_open()) {
		std::cout << "problem with file opening!";
		return;
	}

	buyCars(file);
}

void Sheikh::buyCars(std::ostream& report) {

	//loading cars while there is still budget left

	std::vector<SportCar> sportCars;
	std::vector<LuxuryCar> luxuryCars;

	SportCar curSportCar;
	LuxuryCar curLuxuryCar;

	std::ifstream carsFile(CARBASEPATH);

	if (!carsFile.is_open()) {

		report << "There aren't any cars to buy!\n";
		std::cerr << "error : see report file.\n";
		return;
	}

	char type;
	while (carsFile) {

		carsFile >> type;

		switch (type) {

		case 'S':
		case 's':

			curSportCar.readSp(carsFile);

			if (carsFile && budget >= curSportCar.getPrice()) {

				sportCars.push_back(curSportCar); //adding it to the collection
				budget -= curSportCar.getPrice(); //calculate new budget
			}
			break;

		case 'L':
		case 'l':

			curLuxuryCar.readLux(carsFile);
			if (carsFile && budget >= curLuxuryCar.getPrice()) {

				luxuryCars.push_back(curLuxuryCar);
				budget -= curLuxuryCar.getPrice();
			}

		default:
			//wrong type skipping the line
			char c;
			do { c = carsFile.get(); }
			while (c != '\n' && carsFile);
			break;
		}

		std::cout << "cur budget : " << budget << '\n';
	}

	if (sportCars.empty() && luxuryCars.empty()) {

		report << "There aren't any cars to buy!\n";
		std::cerr << "error : see report file.\n";
		return;
	}

	carsFile.close();

	//processing with each engineer

	std::ifstream engFile(ENGINEERBASEPATH);

	if (!engFile.is_open()) {

		report << "Profit : 0 , there isn't a proper engineer!\n";
		std::cerr << "error : see report file.\n";
		return;
	}


	std::string bestEngName;
	std::string bestExtras;
	unsigned int bestHpCost = 0;
	unsigned int bestExtraCost = 0;
	long long bestProfit = 0;
	long long curProfit = 0;

	while (engFile) {

		Engineer::readFromFile(engFile); //loading the data for the engineer

		if (!engFile)
			break;

		//how much we gonna earn hiring this engineer
		curProfit = Engineer::getProfitFromSportCars(sportCars) +
			Engineer::getProfitFromLuxuryCars(luxuryCars);

		if (curProfit > bestProfit) {

			bestProfit = curProfit;
			Engineer::getParams(bestEngName, bestExtras, bestExtraCost, bestHpCost);
		}
	}

	engFile.close();

	if (bestProfit == 0) {

		report << "Profit : 0 , there isn't a proper engineer!\n";
		std::cerr << "error : see report file.\n";
		return;
	}

	//proceeding to tuning 

	Engineer::setParams(bestExtras, bestExtraCost, bestHpCost);

	Engineer::tuning(sportCars);
	Engineer::addExtras(luxuryCars);


	//best choice for our beloved sheikh
	SportCar* bestSportCar = &sportCars[0];

	for (int i = 1; i < sportCars.size(); i++)
		if (bestSportCar->getHorsePower() < sportCars[i].getHorsePower())
			bestSportCar = &sportCars[i];

	LuxuryCar* bestLuxuryCar = &luxuryCars[0];

	for (int i = 1; i < luxuryCars.size(); i++)
		if (bestLuxuryCar->getExtrasCount() < luxuryCars[i].getExtrasCount())
			bestLuxuryCar = &luxuryCars[i];

	report << "The hired engineer is " << bestEngName << "\n";

	if (bestSportCar) {

		report << "\nThe SPORT car which suits You the best is : \n";
		bestSportCar->printSp(report);
	}

	if (bestLuxuryCar) {

		report << "\nThe most luxurious car which suits You the best is : \n";
		bestLuxuryCar->printLux(report);
	}

	long long myCarsPrice = static_cast<long long>(bestLuxuryCar->getPrice() + bestSportCar->getPrice());

	myCarsPrice = (myCarsPriceExpectation > myCarsPrice) ? 0 : myCarsPrice - myCarsPriceExpectation;

	report << "\nYours profit from buying all the cars written into \"bought.txt\" is : \n"
		<< bestProfit - myCarsPrice;

	std::ofstream buy("Bought.txt");

	if (!buy.is_open()) {

		report << "can't write the bought cars info!\n";
		std::cerr << "error : see report file.\n";
		return;
	}

	for (int i = 0; i < sportCars.size(); i++)
		sportCars[i].printSp(buy);

	for (int i = 0; i < luxuryCars.size(); i++)
		luxuryCars[i].printLux(buy);

	if (buy && report) {

		report << "everything went all right!\n";
		std::cout << "done, see the report file.\n";
	}
}
