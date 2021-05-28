#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;



struct Person
{
		Person() { }
		Person(string ff, string ll, int aa);

		string first_name() const {return first;}
		string last_name() const {return last;}
		int age() const {return a;}

	private:
		string first;
		string last;
		int a;
};

Person::Person(string ff, string ll, int aa) : first{ff}, last{ll}, a{aa}
{
	if (aa < 0 || 150 < aa) error("invalid age");

	string fullname = ff + ll;
	for (char c : fullname)
	{
		switch(c)
		{
		case ';' : case ':' : case '"' : case '[' : case ']' : case '*' : case '&' : case '^' : case '%' : case '$' : case '#' : case '@' : case '!' :
			error("bad char in one or both name(s)");
			break;
		default:
			break;
		}
	}
}


ostream& operator << (ostream& os, const Person& p)
{
	return os << p.first_name() << " " << p.last_name() << " " << p.age(); 
}

istream& operator >> (istream& is, Person& p)
{
	string f;
	string l;
	int a;

	is >> f >> l >> a;

	if (!is) error ("cant read into: Person");

	p = Person(f, l, a);

	return is;
}


int main()
{
	try
	{
		vector<Person> vp;

		cout << "Adj meg egy nevet, majd egy életkort (Kis Ferenc 12). a 'q' gombbal kiléphet. " << endl;

	for (Person p; cin >> p;)
	{
		if (p.first_name()=="q") break;
		vp.push_back(p);
	}

	for (Person p : vp)
		cout << p << '\n';



catch (exception& e)
{
	cerr<<"exception: " << e.what() << endl;
	return 1;
}
catch(...)
{
	cerr << "unknown error! \n";
	return 2;
}
}
return 0;
}