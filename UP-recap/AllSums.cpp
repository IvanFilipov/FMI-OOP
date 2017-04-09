//all possible ways of presenting a number as a sum of other positive numbers

#include<iostream>

int const MAXN = 100;

int Addends[MAXN];

void Print(unsigned int len){


	for (int i = 1; i < len; i++)
		std::cout << Addends[i] << '+' ;

	std::cout << Addends[len] << '\n';

}

void CreatSum(unsigned int n, int pos){

	if (n == 0){
		Print(pos - 1);
		return;
	}

	for (int k = n; k >= 1; k--){

		Addends[pos] = k;

		if (Addends[pos] <= Addends[pos - 1])
			CreatSum(n - k, pos + 1);
		
	}
}


int main(){

	unsigned int n = 7;

	Addends[0] = n + 1;

	CreatSum(n, 1);

	return 0;
}
