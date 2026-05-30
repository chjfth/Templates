#include <stdio.h>

class MyClass
{
public:
	// boilerplate ctor/dtor code, no need to modify >>>
	MyClass()                         // ctor
	{                                 //////////////
		_ct0r();                      //////////////
		_ctor_init_once();            //////////////
	}                                 //////////////
	virtual ~MyClass()                // dtor
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
	// boilerplate ctor/dtor code, no need to modify <<<

public:
	// ... more public methods here ...

private: 
	// ct0r-style supplementary
	void _ct0r() {
		m_buf = nullptr;
	}
	void _ctor_init_once() {
		m_buf = new char[1];
	}
	void _dtor() {
		delete[] m_buf;
	}
	void _copy_from_old(const MyClass& old) {
		if(old.m_buf) 
			m_buf = new char[1], m_buf[0] = old.m_buf[0];
		else
			m_buf = nullptr;
	}
	void _steal_from_old(MyClass& old) {
		m_buf = old.m_buf;
	}

	//
	// Leave data members at end of class body
	//
private:
	char* m_buf;
};


int main(int argc, char* argv[])
{
	MyClass obj1;

	return 0;
}

