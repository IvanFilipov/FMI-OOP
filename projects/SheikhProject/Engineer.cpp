#include "Engineer.h"


void Engineer::setParams(std::string px, unsigned int ec, unsigned int hc) {

	possibleExtras = px;
	singleExtraCost = ec;
	singleHpCost = hc;
}


void Engineer::getParams(std::string& n, std::string& ex, unsigned int& ec, unsigned int& hc) const {

	ex = possibleExtras;
	n = engName;
	ec = singleExtraCost;
	hc = singleHpCost;

}

long long Engineer::getProfitFromSportCars(const std::vector<SportCar>& sCars) const {

	long long profit = 0;

	for (int i = 0; i < sCars.size(); i++)
		profit += (static_cast<long long>(sCars[i].getTuningLimit() * SportCar::getSingleHpProfit()) -
			static_cast<long long>(sCars[i].getTuningLimit() * singleHpCost));

	return profit;
}

long long Engineer::getProfitFromLuxuryCars(const std::vector<LuxuryCar>& lc) const {

	long long profit = 0;

	for (int i = 0; i < lc.size(); i++)
		profit += (lc[i].howManyDifferent(possibleExtras.c_str()) *
			static_cast<long long>(LuxuryCar::getSingleExtraProfit() - singleExtraCost));

	return profit;
}

void Engineer::tuning(std::vector<SportCar>& sCars) const {

	for (int i = 0; i < sCars.size(); i++)
		sCars[i].tuning();
}

void Engineer::addExtras(std::vector<LuxuryCar>& lCars) const {

	for (int i = 0; i < lCars.size(); i++)
		lCars[i].addExtras(possibleExtras.c_str());
}

void Engineer::readFromFile(std::ifstream & ifs) {

	ifs >> engName >> possibleExtras >> singleExtraCost >> singleHpCost;
}
