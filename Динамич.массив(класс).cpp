#include <iostream>
#include <string>
using namespace std;

class Student {
private:
	int id;
	string FIO;

public:
	//Student() {
	// cout << " Hi, Student " << FIO << endl;
	//};


	//~Student() { cout << endl << " GoodBye, Student" << endl; };
	void setId(int z) { id = z; };
	int getId() { return id; };

	void setFIO(string Name) { FIO = Name; };
	string getFIO() { return FIO; };

};

int main() {


	int size, i;
	int id; string name;


	cout << "Enter number of students: ";
	cin >> size;

	Student* arr = new Student[size];

	for (i = 0; i < size; i++) {

		cout << "Input id  ";
		cin >> id;

		cout << "Student's Name, please  ";
		cin.ignore();
		getline(cin, name);

		arr[i].setId(id);
		arr[i].setFIO(name);


	}//for

	cout << "Array of Student : \n";
	for (i = 0; i < size; i++) {
		cout << arr[i].getId() << " " << arr[i].getFIO() << "  ";
		cout << endl;
	}

	//delete arr;

	return 0;
}