#include <iostream>

using namespace std;

class Singleton3
{
public:
	static Singleton3& GetInstance()
	{
		static Singleton3 instance;
		return instance;
	}

	void dosomething()
	{
		cout << "this is a singleton" << endl;
	}

private:
	Singleton3()
	{
		cout << "singleton constraction" << endl;
	};
};

int main3()
{
	Singleton3 &ins = Singleton3::GetInstance();
	ins.dosomething();
	Singleton3 &ins2 = Singleton3::GetInstance();
	ins2.dosomething();

	getchar();
	return 0;
}