#include "MegaString.h"



//solves the problem with nullptr checks everywhere
MegaString::MegaString(){

	str = new char;
	*str = '\0';

}

MegaString::MegaString(const MegaString &other){

		str = new char[strlen(other.str) + 1];
		strcpy(str, other.str);

}

MegaString::MegaString(const char *src){

	if (src != nullptr) {

		str = new char[strlen(src) + 1];
		strcpy(str, src);
	}
	else {

		str = new char;
		*str = '\0';
	}

}

MegaString& MegaString::operator=(const MegaString& other){
		
	if (this != &other) {

		delete[]str;

		str = new char[strlen(other.str) + 1];
		strcpy(str, other.str);

	}

	return *this;

}


MegaString::~MegaString(){

	delete[] str;
}

MegaString& MegaString::operator+=(const MegaString &other){

	char* temp = str;

	str = new char[strlen(temp) + strlen(other.str) + 1];

	strcpy(str, temp);
	strcat(str, other.str);

	delete[] temp;

	return *this;
}

MegaString & MegaString::operator*=(int k){

	if(k < 0)
		return *this;

	char* temp = str;

	str = new char[strlen(temp)*k + 1];

	strcpy(str, temp);

	for (int i = 1; i < k; i++)
		strcat(str, temp);

	delete[]temp;

	return *this;
}


long MegaString::GetW() const{

	long weight = 0;
	int  i = 0;

	while (str[i] != '\0')
		weight += str[i++];
	
	return weight;


}

bool MegaString::ContainSym(char c) const{

	int i = 0;

	while (str[i] != '\0')
		if (c == str[i++])
			return true;

	return false;
}



bool operator==(const MegaString &lhs, const MegaString &rhs)
{
	return lhs.GetW() == rhs.GetW();
}

bool operator!=(const MegaString &lhs, const MegaString &rhs)
{
	return lhs.GetW() != rhs.GetW();
}

std::ostream & operator<<(std::ostream& os, const MegaString &obj){

	return os << obj.str;
}

std::istream & operator >> (std::istream& is, MegaString &obj){
	
	char buff[1024];

	is.getline(buff, 1024);

	delete[]obj.str; // clears the old data !!!
	
	obj.str = new char[strlen(buff) + 1];

	strcpy(obj.str, buff);

	return is;
}

const MegaString operator+(const MegaString &lhs, const MegaString &rhs){

	//maybe not the best implementation , because makes 
	//one unnecessary allocation
	return MegaString(lhs)+=rhs;
}

const MegaString operator*(const MegaString & obj , int k){

	return MegaString(obj)*=k;
}

const MegaString operator*(int k, const MegaString &obj){

	return MegaString(obj)*=k;

}


MegaString& MegaString::operator%=(const MegaString& other){

	char* concat = new char[strlen(str) + strlen(other.str) + 1];
	strcpy(concat, str);
	strcat(concat, other.str);
	
	char* result = new char[strlen(str) + strlen(other.str) + 1];

	int cIt = 0;
	int resIt = 0;
	bool found = false;

	while (concat[cIt] != '\0') {

		for (int i = resIt - 1; i >= 0 && !found ; i--)
			if (result[i] == concat[cIt])
				found = true;

		if (!found)
			result[resIt++] = concat[cIt];

		cIt++;
		found = false;
	}

	result[resIt] = '\0';

	delete[] str;

	str = new char[strlen(result) + 1];
	strcpy(str, result);

	delete[]result;
	delete[]concat;

	return *this;

}

MegaString& MegaString::operator/=(const MegaString& other) {

	char* result = new char[strlen(str) + 1]; //max possible length

	int it = 0; // result iterator
	int i = 0;

	while (str[i] != '\0') {

		if (!other.ContainSym(str[i]))
			result[it++] = str[i];

		i++;
	}

	result[it] = '\0';

	delete[] str;

	str = new char[strlen(result) + 1];
	strcpy(str, result);

	delete[]result;

	return *this;
} 

const MegaString operator/(const MegaString& lhs, const MegaString& rhs){

	return MegaString(lhs)/=rhs;
}

const MegaString operator%(const MegaString& lhs, const MegaString& rhs) {

	return MegaString(lhs)%=rhs;
}

