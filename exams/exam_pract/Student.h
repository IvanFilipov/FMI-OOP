class Student {

public: 
	 
	unsigned int fn;
	char* name;

public:

	//no default constructor on purpose!!!
	Student(const char*, unsigned int fn);
	Student(Student);  
	void operator=(Student&); 
	virtual ~Student(); 
	
public:

	unsigned int getFn() { 

		return fn;
	}

	char* getName() const { 

		return name;
	}

	void setName(const char*) const;  
};

//ten mistakes at all - 10x 0.1 = 1 point