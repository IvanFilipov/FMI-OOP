#include "stdafx.h"
#include "Group.h"
#include "FigureCreator.h"

Group::Group() :vec(), x(0), y(0){
	/*...*/
}


void Group::Read(std::ifstream &ifs){


	std::string buff;

	//reading "in"
	ifs >> buff;

	ifs >> x >> y;

	ifs >> buff;

	do{

		Figure* curFig = FigureCreator::Create(buff.c_str());

		if (ifs && curFig) {

		 vec.push_back(curFig);
		 vec.back()->Read(ifs);
		 vec.back()->translate(x, y);

		}

		//reading "out"
		ifs >> buff;

	} while (strcmp(buff.c_str(), "group") != 0);

	//reading "out"
	ifs >> buff;

}


void Group::Print()const{
 
	 std::cout << "group " << x << ' ' << y << '\n';

	 for (int i = 0; i < vec.size(); i++){

		 vec[i]->Print();
	 }
 
 }

void Group::isIn(double _x, double _y)const{
 
	 for (int i = 0; i < vec.size(); i++){

		 vec[i]->isIn(_x,_y);
	 }

 }


Figure* Group::At(int pos){

	if (pos == 0){
		return this;
	}

	if (pos - 1 < vec.size()){

		return vec[pos-1];
	}
	else{
		return NULL;
	}


}