#include "Sheikh.h"

const int Sheikh::myCarsPriceExpectation = 2000000;


Sheikh::Sheikh(const char * n, long long b) : Name(n) , budget(b){

}


void Sheikh::BuyCars(const char * Fpath){

	std::ofstream File(Fpath);

	if (!File.is_open()) {
		std::cout << "problem with file opening!";
		return;
	}

	BuyCars(File);

}

void Sheikh::BuyCars(std::ostream& report){

	//loading cars while there is still budget left

	std::vector<SportCar> SportCars;
	std::vector<LuxuryCar> LuxuryCars;

	SportCar CurSportCar;
	LuxuryCar CurLuxuryCar;

	std::ifstream CarsFile(CARBASEPATH);

	if (!CarsFile.is_open()) {

		report << "There aren't any cars to buy!\n";
		return;
	}

	while (CarsFile) {

		char type;

		CarsFile >> type;

		switch (type){

		case 'S' :
		case 's' :
			
			CurSportCar.Read(CarsFile);

			if (CarsFile && budget >= CurSportCar.GetPrice()) {
				SportCars.push_back(CurSportCar);
				budget -= CurSportCar.GetPrice();
			}
			break;

		case 'L' :
		case 'l' :
			CurLuxuryCar.Read(CarsFile);
			if (CarsFile && budget >= CurLuxuryCar.GetPrice()) {

				LuxuryCars.push_back(CurLuxuryCar);
				budget -= CurLuxuryCar.GetPrice();

			}
		//wrong type skipping the line
 		default:
			char c;
			do {
				c = CarsFile.get();
			} while (c != '\n' && CarsFile);
			break;
					
		}

		std::cout << "cur budget : " << budget << '\n';
	}

	if (SportCars.empty() && LuxuryCars.empty()) {

		report << "There aren't any cars to buy!\n";
		return;
	}

	CarsFile.close();

	//processing with each engineer
	
	std::ifstream EngFile(ENGINEERBASEPATH);


	if (!EngFile.is_open()) {

		report << "Profit : 0 , there isn't a proper engineer!\n";
		return;
	}
	

	std::string bestEngName;
	std::string bestExtras;
	unsigned int bestHpCost = 0;
	unsigned int bestExtraCost = 0;
	long long bestProfit = 0;
	long long curProfit = 0;

	while (EngFile) {

		Engineer::ReadFromFile(EngFile); //loading the data for the engineer

		if (!EngFile)
			break;

		curProfit = Engineer::GetProfitFromSportCars(SportCars) +
			        Engineer::GetProfitFromLuxuryCars(LuxuryCars);

		if (curProfit > bestProfit) {

			bestProfit = curProfit;
			Engineer::GetParams(bestEngName, bestExtras,bestExtraCost, bestHpCost);

		 }
	}

	EngFile.close();

	if (bestProfit == 0) {

		report << "Profit : 0 , there isn't a proper engineer!\n";
		return;

	}

	//proceeding to tuning 

	Engineer::SetParams(bestExtras, bestExtraCost, bestHpCost);

	Engineer::Tuning(SportCars);
	Engineer::AddExtras(LuxuryCars);


	//best choice for our beloved sheikh
	SportCar* BestSportCar = &SportCars[0];

	for (int i = 1; i < SportCars.size(); i++)
		if (BestSportCar->GetHorsePower() < SportCars[i].GetHorsePower())
			BestSportCar = &SportCars[i];


	LuxuryCar* BestLuxuryCar = &LuxuryCars[0];

	for (int i = 1; i < LuxuryCars.size(); i++)
		if (BestLuxuryCar->GetExtrasCount() < LuxuryCars[i].GetExtrasCount())
			BestLuxuryCar = &LuxuryCars[i];


	report << "The hired engineer is " << bestEngName << "\n";

	if (BestSportCar) {
		report << "\nThe SPORT car which suits You the best is : \n";
		BestSportCar->Print(report);
	}

	if (BestLuxuryCar) {
		report << "\nThe most luxurious car which suits You the best is : \n";
		BestLuxuryCar->Print(report);
	}

	long long myCarsPrice = static_cast<long long>(BestLuxuryCar->GetPrice() + BestSportCar->GetPrice());

	myCarsPrice = (myCarsPriceExpectation > myCarsPrice) ? 0 : myCarsPrice - myCarsPriceExpectation;

	report << "\nYours profit from buying all the cars written into \"bought.txt\" is : \n"
		   << bestProfit - myCarsPrice;

	std::ofstream Buy("Bought.txt");

	for (int i = 0; i < SportCars.size(); i++)
			SportCars[i].Print(Buy);

	for (int i = 0; i < LuxuryCars.size(); i++)
			LuxuryCars[i].Print(Buy);

	Buy.close();

}
