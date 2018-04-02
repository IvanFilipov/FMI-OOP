#ifndef __FOOTBALLSHIRT_H__
#define __FOOTBALLSHIRT_H__

class FootballShirt {

	unsigned int number;
	char* name;

public:

	FootballShirt();
	FootballShirt(const FootballShirt&);
	FootballShirt(unsigned int, const char*);
	FootballShirt& operator=(const FootballShirt&);

	~FootballShirt();

private:

	void setDefaultName();
	void copyFrom(const FootballShirt&); 
	void clean(); 

public:
	const char* getName() const;
};

#endif