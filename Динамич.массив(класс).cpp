#include <iostream>
#include <string>
using namespace std;

class Employee 
{
private:
	int id;
	string FIO;

public:
	
	void setId(int z) { id = z; };
	int getId() { return id; };

	void setFIO(string Name) { FIO = Name; };
	string getFIO() { return FIO; };
};

int main() {


	int size, i;
	int id; string name;

	cout << "Enter number of employes: ";
	cin >> size;

	Employee* arr = new Employee[size];

	for (i = 0; i < size; i++) {

		cout << "Input id  ";
		cin >> id;

		cout << "Employee's Name, please  ";
		cin.ignore();
		getline(cin, name);

		arr[i].setId(id);
		arr[i].setFIO(name);
	}

	cout << "Array of Employee : \n";

	for (i = 0; i < size; i++) 
	{
		cout << arr[i].getId() << " " << arr[i].getFIO() << "  ";
		cout << endl;
	}

	return 0;
}