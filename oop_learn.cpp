#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class cat
{
public:
	string name;
	int speed;
	bool escaped = 0;

	void SetData()
	{
		cout << "CAT" << endl;
		cout << "Enter the name:";
		cin >> name;
		randSpeed();
	}

	void GetData()
	{
		cout << "Name: " << name << endl;
		cout << "Speed: " << speed << endl;
	}

	void ifCatching(bool catchByDog, string dogName, string catName)
	{
		if (catchByDog == 0)
		{
			cout << catName << " has been escaped from " << dogName << endl;
			catching();
		}
	}

private:

	void randSpeed()
	{
		speed = rand() % 10 + 1;
	}

	void catching()
	{
		escaped = 1;
	}
};

class dog
{
public:
	string name;
	int speed;
	bool catchCat = 0;

	void SetData()
	{
		cout << "DOG" << endl;
		cout << "Enter the name:";
		cin >> name;
		randSpeed();
	}

	void GetData()
	{
		cout << "Name: " << name << endl;
		cout << "Speed: " << speed << endl;
	}

	void ifCatching(bool catchByDog, string dogName, string catName)
	{
		if (catchByDog == 1)
		{
			cout << catName << " has been catched by " << dogName << endl;
			catching();
		}
	}

private:

	void randSpeed()
	{
		speed = rand() % 10 + 1;
	}

	void catching()
	{
		catchCat = 1;
	}
};

class fish
{
public:
	string name;
	int weight;
	bool eat = 0;

	void SetData()
	{
		cout << "FISH" << endl;
		cout << "Enter the name:";
		cin >> name;
		randWeight();
	}

	void GetData()
	{
		cout << "Name: " << name << endl;
		cout << "Weight: " << weight << endl;
	}

	void ifEatenFish(bool ate, string catName)
	{
		if (ate == 1)
		{
			cout << name << " has been eaten by cat " << catName << endl;
			cout << "Dog, who supposed to guard the fish, want to catch the cat" << endl;
			catching();
		}
	}

private:

	void randWeight()
	{
		weight = rand() % 10 + 1;
	}

	void catching()
	{
		eat = 1;
	}
};

int main()
{
	srand(time(NULL));

	cat Mursik;
	dog Barsik;
	fish Nemo;

	Mursik.SetData();
	Barsik.SetData();
	Nemo.SetData();
	cout << endl;
	cout << endl;

	Mursik.GetData();
	Barsik.GetData();
	Nemo.GetData();
	cout << endl;
	cout << endl;

	if (Nemo.weight >= 5)
	{
		Nemo.ifEatenFish(1, Mursik.name);
	}
	cout << endl;
	cout << endl;

	if (Nemo.eat == 1)
	{
		if (Barsik.speed > Mursik.speed)
		{
			Barsik.ifCatching(1, Barsik.name, Mursik.name);
		}
		else
		{
			Mursik.ifCatching(0, Barsik.name, Mursik.name);
		}
	}
}
