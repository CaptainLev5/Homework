#include<iostream>
#include<string>
using namespace std;

class Employee
{
public:
	string Name;
	double Salary;
	int hours;
	double oplata;

public:
	void info()
	{
		Salary = hours * oplata;
		cout << Salary << endl;
	}
};

class Manager:public Employee
{
public:
	int dop;
public:
	void info()
	{
		double managerSalary;
		managerSalary = (hours * oplata) + dop;
		cout << managerSalary << endl;
	}
};

int main()
{
	int size, i;
	cout << "Enter number of employes: ";
	cin >> size;

	Employee* mass = new Employee[size];
	

	for (i = 0; i < size; i++)
	{
		cout << i + 1 << " Employee" << endl;

		cout << "Enter Name: " << endl;
		cin.ignore();
		getline(cin, mass[i].Name);
		cout << "Enter hours: " << endl;
		cin >> mass[i].hours;

		cout << "Enter oplata: " << endl;
		cin >> mass[i].oplata;
	}

	for (i = 0; i < size; i++)
	{
		cout << "Name: " << ' ' << mass[i].Name << ' ';
		mass[i].info();
	}


	/* 
	Employee emp1;
	emp1.Name = "John";
	emp1.hours = 20;
	emp1.oplata = 180;
	cout << "Salary of Employee John is ";
	emp1.info();

	Manager man1;
	man1.Name = "Jason";
	man1.hours = 18;
	man1.oplata = 150;
	man1.dop = 1200;

	cout << "Salary of Manager Jason is ";
	man1.info();
	*/

	return 0;
}
