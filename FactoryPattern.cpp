#include <iostream>
#include <string>

using namespace std;

class Pizza
{
public:
	virtual void prepare() = 0;
	void bake()
	{
		cout << "bake it." << endl;
	}
	void cut()
	{
		cout << "cut it." << endl;
	}
	void box()
	{
		cout << "box it." << endl;
	}
	string GetName();
	void SetName(string name);
private:
	string name;
};

class SHCheesePizza : public Pizza
{
public:
	void prepare()
	{
		cout << "SHCheesePizza prepare." << endl;
	}
};

class BJCheesePizza : public Pizza
{
public:
	void prepare()
	{
		cout << "BJCheesePizza prepare." << endl;
	}
};

class PizzaShop
{
public:
	void OrderPizze(string name)
	{
		Pizza* pizza = CreatePizza(name);
		if (!pizza)
		{
			cout << "there is no the type pizza." << endl;
			return;
		}
		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();
	}
private:
	Pizza* CreatePizza(string name)
	{
		if (name == "SH")
		{
			return new SHCheesePizza;
		}
		else if (name == "BJ")
		{
			return new BJCheesePizza;
		}
		else
		{
			return nullptr;
		}
	}

};

int main()
{
	PizzaShop shop;
	shop.OrderPizze("SH");

	getchar();

	return 0;
}