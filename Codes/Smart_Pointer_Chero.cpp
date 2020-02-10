
#include <iostream>
#include<memory>
#include<string>

using namespace std;

class Unique_Entity
{
public:
	Unique_Entity()
	{
		cout << "Created Entity";
	}
	~Unique_Entity()
	{
		cout << "Destroyed Entity";
	}
	void Print()
	{
		cout << "Printed";
	}
};

class Shared_Entity
{
public:
	Shared_Entity()
	{
		cout << "Created Shared Entity";
	}

	~Shared_Entity()
	{
		cout << "Destroyed Shared Entity";
	}
	void Print()
	{
		cout << "Printed Shared Entity";
	}
};

class Weak_Entity
{
public:
	Weak_Entity()
	{
		cout << "Created Shared Entity";
	}

	~Weak_Entity()
	{
		cout << "Destroyed Shared Entity";
	}
	void Print()
	{
		cout << "Printed Shared Entity";
	}
};
int main1()
{
	shared_ptr<Shared_Entity> E1 = make_shared<Shared_Entity>();// Won't delete it unless it has a reference count in code
	weak_ptr<Weak_Entity> W1;
	{
		shared_ptr<Shared_Entity> E2(new Shared_Entity()); // Allowed but needs two memory access cosof control block
		shared_ptr<Shared_Entity> E3 = E2;//Copying allowed
		W1 = E3;
	}
	{ // Scope limited for unique_ptr
		unique_ptr<Unique_Entity> U1 = make_unique<Unique_Entity>();// Preferred Exception Safety
		U1->Print();
		unique_ptr<Unique_Entity> U2(new Unique_Entity()); // explicit constructor call = new Entity() not allowed
		//unique_ptr<Entity> U3 = U2;// Copying not allowed
	}

	std::cin.get();

}

