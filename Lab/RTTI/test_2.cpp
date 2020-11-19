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

class test_Child: public test_Parent
{
public:
	test_Child()
	{
		setName("test_Child");
	}
	void hello()
	{
		std::cout << "This is test_Child." << std::endl;
	}
};

int main()
{
	using namespace std;

	test_Parent *t_1 = new test_Parent();
	test_Parent *t_2 = new test_Child();
	test_Child *t_3 = new test_Child();
	int *pi = new int;
	float *pf = new float;
	char *pc = new char;
	*pi = 1;
	*pf = 0.5;
	*pc = 'a';

	test_Parent *t_3P = dynamic_cast<test_Parent *>(t_3);	//upcasting
	test_Child *t_2C = dynamic_cast<test_Child *>(t_2);		//downcasting
	test_Parent *t_2P = dynamic_cast<test_Parent *>(t_2);

	cout << "t_3: " << t_3 << endl;
	cout << "t_3P: " << t_3P << endl;
	cout << "t_2: " << t_2 << endl;
	cout << "t_2C: " << t_2C << endl;
	cout << "t_2P: " << t_2P << endl;

	test_Child &t_2R = dynamic_cast<test_Child &>(*t_2);	//通过 dynamic_cast 创造一个指向 t_2 对象的引用

	cout << "t_2R: " << t_2R.getName() << endl;

	t_2R.setName("Modified test_Child.");	//通过引用修改子类名字

	cout << "t_2: " << t_2->getName() << endl;
	cout << "t_2R: " << t_2R.getName() << endl;

	return 0;
}