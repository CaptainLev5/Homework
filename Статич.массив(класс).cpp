#include <iostream>
#include <string>

using namespace std;

class Employee {
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
	Employee emp1[3];

	for (int i = 0; i < 3; i++) {
		emp1[i].setId(i);
		emp1[i].setFIO("Ivanov Ivan Ivanovich");
		cout << endl << emp1[i].getId() << " " << emp1[i].getFIO() << " ";
	}
	return 0;
}
