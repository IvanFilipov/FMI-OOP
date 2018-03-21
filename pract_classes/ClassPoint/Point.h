#ifndef __POINT_H__
#define __POINT_H__

//the declaration of the class goes in here

class Point{


private:
	//these variables are hidden from the outside world
	int x;
	int y;

public:

	//a class constructor tells how to create an object
	//with what values the data members should be initialized
	Point(); //same name as the class's one, no return value
	
	Point(int, int);

	//the clients of our class will be able to see only the public part
	
	//reads the coordinates from STDIN
	void read();
	//outputs to STDOUT, this method won't change
	//the state of the object ( member data )
	//so it should be a const method
	void print()const;

	//gives the distance to (0,0)
	double distToBeg()const;

	//returns the distance to the "other" point
	double pntToPntDist(const Point& other);

	//accessors
	int getX()const;
	int getY()const;

	//mutators
	void setX(int);
	void setY(int);
};

#endif