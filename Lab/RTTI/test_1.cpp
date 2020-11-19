#include <iostream>
#include <typeinfo>

class test_Parent
{
private:
	std::string name;
public:
	test_Parent()
	{
		setName("Parent");
	}
	test_Parent(std::string name)
	{
		setName(name);
	}
	~test_Parent()
	{
		
	}
	void setName(std::string name)
	{
		this->name = name;
	}
	std::string getName()
	{
		return name;
	}
	virtual void hello()
	{
		std::cout << "This is test_Parent." << std::endl;
	}
};

class test_1: public test_Parent
{
public:
	test_1()
	{
		setName("test_1");
	}
	void hello()
	{
		std::cout << "This is test_1." << std::endl;
	}
};

int main()
{
	using namespace std;

	test_Parent *t_1 = new test_Parent();
	test_Parent *t_2 = new test_1();
	test_1 *t_3 = new test_1();
	int i = 1;
	float j = 0.5;
	char c = 'a';


	cout << "t_1: " << typeid(t_1).name() << endl;
	cout << "*t_1: " << typeid(*t_1).name() << endl;
	cout << "t_2: " << typeid(t_2).name() << endl;
	cout << "*t_2: " << typeid(*t_2).name() << endl;
	cout << "t_3: " << typeid(t_3).name() << endl;
	cout << "*t_3: " << typeid(*t_3).name() << endl;
	cout << "i: " << typeid(i).name() << endl;
	cout << "j: " << typeid(j).name() << endl;
	cout << "c: " << typeid(c).name() << endl;
	cout << "i*j: " << typeid(i * j).name() << endl;	//隐式转换为 float
	cout << "string: name: " << typeid(t_1->getName()).name() << endl;
}