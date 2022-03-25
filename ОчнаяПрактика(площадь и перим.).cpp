#include <iostream>
using namespace std;

class Pryamoug
{
private:
	int a;
	int b;

public:
	void setAB(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	void Ploshad()
	{
		int s;
		s = a * b;
		cout << "S = " << s << endl;
	}
	void Perimetr()
	{
		int p;
		p = 2 * (a + b);
		cout << "P = " << p << endl;
	}
	
};

int main()
{
	Pryamoug pr1;
	pr1.setAB(10, 8);

	pr1.Ploshad();
	pr1.Perimetr();
	return 0;
}