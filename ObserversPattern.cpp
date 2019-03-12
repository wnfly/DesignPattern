// ObserversPattern.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <set>

using namespace std;

template <typename T>
class Observer;
class Subject
{
public:
	virtual ~Subject() {};
	virtual void RegisterObserver(Observer<int>* ob) = 0;
	virtual void RemoveObserver(Observer<int>* ob) = 0;
	virtual void NotifyObservers() = 0;
};

template <typename T>
class Observer
{
public:
	virtual ~Observer() { printf("an observer discontruct.\n"); };
	virtual void Update(T data) = 0;
};

class Sponsor : public Subject
{
public:
	Sponsor(){};
	virtual ~Sponsor() {};
	virtual void RegisterObserver(Observer<int> *ob)
	{
		observers.insert(ob);
	}
	virtual void RemoveObserver(Observer<int>* ob)
	{
		observers.erase(ob);
	}
	virtual void NotifyObservers()
	{
		for (set<Observer<int>*>::iterator item = observers.begin(); item != observers.end(); ++item)
		{
			(*item)->Update(latestData);
		}
	}

	void TestNotify()
	{
		latestData = 123;
		NotifyObservers();
	}

private:
	set<Observer<int>*> observers;
	int latestData;
};

class FirstObserver : public Observer<int>
{
public:
	FirstObserver(Subject* sub)
	{
		if (!sub)
			return;
		pSubject = sub;
		pSubject->RegisterObserver(this);
	};
	virtual ~FirstObserver()
	{
		pSubject->RemoveObserver(this);	// 没有这句的话，update时会出错
	};
	virtual void Update(int data)
	{
		printf("FirstObserver update data:%d\n", data);
	}
private:
	Subject *pSubject;
};


int _tmainob(int argc, _TCHAR* argv[])
{
	Sponsor *psp = new Sponsor;
	FirstObserver *ob1 = new FirstObserver(psp);
	FirstObserver *ob2 = new FirstObserver(psp);

	//getchar();

	psp->TestNotify();

	delete ob1;

	psp->TestNotify();

	delete ob2;
	getchar();
	return 0;
}

