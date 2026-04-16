#include <stdio.h>

class MyClass
{
public:
	// boilerplate code, no need to modify >>>
	MyClass() { _ct0r(); }            //////////////
	virtual ~MyClass()                //////////////
	{                                 //////////////
		_dtor();                      //////////////
		_ct0r();                      //////////////
	}                                 //////////////
	MyClass(const MyClass& old)            // copy-ctor
	{                                      //////////////
		_copy_from_old(old);               //////////////
	}                                      //////////////
	MyClass& operator=(const MyClass& old) // copy-assign
	{                                      //////////////
		if (this != &old) {                //////////////
			_dtor();                       //////////////
			_copy_from_old(old);           //////////////
		}                                  //////////////
		return *this;                      //////////////
	}                                      //////////////
	MyClass(MyClass&& old)            // move-ctor
	{                                 //////////////
		_steal_from_old(old);         //////////////
		old._ct0r();                  //////////////
	}                                 //////////////
	MyClass& operator=(MyClass&& old) // move-assign
	{                                 //////////////
		if (this != &old) {           //////////////
			_dtor();                  //////////////
			_steal_from_old(old);     //////////////
			old._ct0r();              //////////////
		}                             //////////////
		return *this;                 //////////////
	}                                 //////////////
	// boilerplate code, no need to modify <<<

private:
	void _copy_from_old(const MyClass& old) {
		if(old.m_buf) 
			m_buf = new char[1], m_buf[0] = old.m_buf[0];
		else
			m_buf = nullptr;
	}

	void _steal_from_old(MyClass& old) {
		m_buf = old.m_buf;
	}

public:
	// ... more public methods here ...

	//
	// Leave below at end of class body
	//
private: // data members
	char* m_buf;

private:
	void _ct0r() {
		m_buf = nullptr;
	}

	void _dtor() {
		delete[] m_buf;
	}
};


int main(int argc, char* argv[])
{
	MyClass obj1;

	return 0;
}

