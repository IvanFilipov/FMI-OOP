#include "Engineer.h"



Engineer::Engineer(){
}


Engineer::~Engineer(){

}

Engineer & Engineer::operator=(const Engineer & other){

	if (this != &other) {
		EngName = other.EngName;
		PossibleExtras = other.PossibleExtras;
		SingleExtraCost = other.SingleExtraCost;
		SingleHpCost = other.SingleHpCost;
	}

	return *this;
}

Engineer::Engineer(const Engineer &other){
	EngName = other.EngName;
	PossibleExtras = other.PossibleExtras;
	SingleExtraCost = other.SingleExtraCost;
	SingleHpCost = other.SingleHpCost;

}

void Engineer::SetParams(std::string px, unsigned int ec, unsigned int hc){

	PossibleExtras = px;
	SingleExtraCost = ec;
	SingleHpCost = hc;


}


void Engineer::GetParams(std::string& n,std::string& ex,unsigned int& ec, unsigned int& hc)const {

	ex = PossibleExtras;
	n = EngName;
	ec = SingleExtraCost;
	hc = SingleHpCost ;

}

long long Engineer::GetProfitFromSportCars(const std::vector<SportCar>& sCars) const{

	 long long profit = 0;

	 for (int i = 0; i < sCars.size(); i++)
		 profit += (static_cast<long long>(sCars[i].GetTuningLimit() * SportCar::GetSingleHpProfit()) -
			        static_cast<long long>(sCars[i].GetTuningLimit() *SingleHpCost));

	return profit;

	
}

long long Engineer::GetProfitFromLuxuryCars(const std::vector<LuxuryCar>& lc) const {

	long long profit = 0;
	
	for (int i = 0; i < lc.size(); i++)
		profit += (lc[i].HowManyDifferent(PossibleExtras.c_str()) *
			      static_cast<long long>(LuxuryCar::GetSingleExtraProfit() - SingleExtraCost));


	return profit;
}

void Engineer::Tuning(std::vector<SportCar>& sCars) const {

	for (int i = 0; i < sCars.size(); i++)
		sCars[i].Tuning();
}

void Engineer::AddExtras(std::vector<LuxuryCar>& lCars) const{

	for (int i = 0; i < lCars.size(); i++)
		lCars[i].AddExtras(PossibleExtras.c_str());

}

void Engineer::ReadFromFile(std::ifstream & ifs){

	ifs >> EngName >> PossibleExtras >> SingleExtraCost >> SingleHpCost;

}
