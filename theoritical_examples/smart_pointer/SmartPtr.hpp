#pragma once

//a simple version of the old C++ smart pointer - 
//auto_ptr, which is deprecated since C++11 and
//fully removed after C++17

//originally there wasn't standard support of arrays
//for example new [] ...


//nowadays std::unique_ptr, std::shared_ptr and 
//std::weak_ptr are used
template<typename T>
class SmartPtr {

private:

	T* rawPtr;

public:

	explicit SmartPtr(T* p = nullptr);
	SmartPtr(SmartPtr&); //notice not constant, because we will take the ownership
	SmartPtr& operator=(SmartPtr&);
	~SmartPtr();

public :

	T* release();
	void reset(T* p = nullptr);
	
	T& operator*() const;
	T* operator->() const;
};

template<typename T>
SmartPtr<T>::SmartPtr(T* p) : rawPtr(p) {

}

template<typename T>
SmartPtr<T>::SmartPtr(SmartPtr<T>& other) : rawPtr(other.release()) {
	
	//gets the ownership of the resource from the other object
}

template<typename T>
SmartPtr<T>::~SmartPtr() {

	delete rawPtr;
}

template<typename T>
SmartPtr<T>& SmartPtr<T>::operator=(SmartPtr<T>& other) {

	if (this != &other)
		reset(other.release()); //frees our resource and gets other's

	return *this;
}

template<typename T>
T& SmartPtr<T>::operator*() const {

	return *rawPtr;
}

template<typename T>
T* SmartPtr<T>::operator->() const {

	return rawPtr;
}

template<typename T>
T* SmartPtr<T>::release() {

	//transfer the ownership
	T* old = rawPtr;
	rawPtr = nullptr;
	
	return old;
}

template<typename T>
void SmartPtr<T>::reset(T* p) {

	if (p != rawPtr) {

		delete rawPtr;
		rawPtr = p;
	}
}