#include <iostream>
#include <string>

using namespace std;

class B1
{

public:

	virtual void pvf() = 0;

	virtual void vf()
	{
		cout << "B1::vf()"<<endl;
	}

	void f()
	{
		cout << "B1::f()"<<endl;
	}
};

class D1 : public B1
{
public:

	void pvf()
	{
		cout << "D1::pvf()"<<endl;
	}

	void vf()
	{
		cout << "D1::vf()"<<endl;

	}

	void f()
	{
		cout << "D1::f()"<<endl;
	}
};

class D2 : public D1
{

public:

	void pvf()
	{
		cout << "D2::pvf()" << endl;
	}
};

class B2 
{

public:
	virtual void pvf() = 0;
};

class D21 : public B2
{
public:

	string s = "D21::pvf()";
	void pvf()
	{
		cout << s << endl;
	}
};

class D22 : public B2
{
public:

	int i = 22;
	void pvf()
	{
		cout << i << endl;
	}
};

void f(B2& b2)
{
	b2.pvf();
};

int main()
{
	/*B1 b1;
	b1.vf();
	b1.f();*/


	D1 d1;
	d1.pvf();
	d1.vf();
	d1.f();

	B1& bref = d1;
	bref.pvf();
	bref.vf();
	bref.f();

	D2 d2;
	d2.pvf();
	d2.vf();
	d2.f();

	D21 d21;
	d21.pvf();

	D22 d22;
	d22.pvf();

	f(d21);
	f(d22);


}