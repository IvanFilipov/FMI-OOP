//<-- no guards ...

class Student {

public: // <-- no encapsulation

	 
	unsigned int fn;
	char* name;

public:

	//no default constructor on purpose!!!
	Student(const char*, unsigned int fn);
	Student(Student); //<-- const & 
	void operator=(Student&); //<-- return type + const
	virtual ~Student(); //<-- shouldn't be virtual

public:

	unsigned int getFn() { //<-- const method

		return fn;
	}

	char* getName() const { //<-- return type

		return name;
	}

	void setName(const char*) const; //<-- const?! 
};

//ten mistakes at all - 10x 0.1 = 1 point