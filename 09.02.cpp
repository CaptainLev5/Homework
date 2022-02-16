#include <iostream>

using namespace std;

class Dog
{
public:

    string Breed;
    string Size;
    string Age;
    string Color;

public:

    Dog() {
        cout << " \n ";
    };


    void Eat();
    void Sleep();
    void Sit();
    void Run();

    void show_dog_param();

    ~Dog() { cout << " Bye" << endl; };

};

class Owner : public Dog
{
private:
    string Name;
public:
    void setName(string s)
    {
        Name = s;
        cout << "Name of owner - " << s << endl << endl;
    };
    
};





void Dog::Eat() {
    cout << "I'm hungry!\n " << endl;
}

void Dog::Sleep() {
    cout << "I'm so sleeping...\n " << endl;
}

void Dog::Sit() {
    cout << "I'm sitting\n " << endl;
}

void Dog::Run() {
    cout << "I'm running!\n" << endl;
};

void Dog::show_dog_param()
{

    cout << "\n\n**** Parameters of Dog ****";
    cout << "\nDog Breed     :  " << Breed;
    cout << "\nDog Size    :  " << Size;
    cout << "\nDog Age       :  " << Age;
    cout << "\nDog Color       :  " << Color;

    cout << "\n-------------------------------";

}




int main()

{
    Dog dog1;
    dog1.Breed = "Neapolitan Mastiff";
    dog1.Size = "Large";
    dog1.Age = "5 years";
    dog1.Color = "Black";

    dog1.show_dog_param();

    Owner owner1;
  

    Dog dog2;
    dog2.Breed = "Maltese";
    dog2.Size = "Small";
    dog2.Age = "2 years";
    dog2.Color = "White";

    dog2.show_dog_param();

    Owner owner2;
    


    Dog dog3;
    dog3.Breed = "Chow Chow";
    dog3.Size = "Medium";
    dog3.Age = "3 years";
    dog3.Color = "Brown";

    dog3.show_dog_param();

    Owner owner3;
    
    cout << endl << endl;


    

    int b; 
    int a = 0;
    int d = 0;
    int f = 0; 

    cout << "Which dog to choose?\n\n";
    cout << "1 - Neapolitan Mastiff\n\n";
    cout << "2 - Maltese\n\n";
    cout << "3 - Chow Chow\n\n";

    cin >> b;

    switch (b)
    {
    case 1:
        cout << "You chose a " << dog1.Breed << endl << endl;;

        owner1.setName("Petr");
        void setName(string s);

        cout << "What do you want to know about this dog?\n";
        cout << "1 - Eat\n";
        cout << "2 - Sleep\n";
        cout << "3 - Sit\n";
        cout << "4 - Run\n";
        cin >> a;

        break;
    case 2:
        cout << "You chose a " << dog2.Breed << endl << endl;

        owner2.setName("Ivan");
        void setName(string s);

        cout << "What do you want to know about this dog?\n";
        cout << "1 - Eat\n";
        cout << "2 - Sleep\n";
        cout << "3 - Sit\n";
        cout << "4 - Run\n";
        cin >> d;

        break;
    case 3:
        cout << "You chose a " << dog3.Breed << endl << endl;

        owner3.setName("John");
        void setName(string s);

        cout << "What do you want to know about this dog?\n";
        cout << "1 - Eat\n";
        cout << "2 - Sleep\n";
        cout << "3 - Sit\n";
        cout << "4 - Run\n";
        cin >> f;
        break;

    default:
        cout << "Not correct number\n\n";
        system("pause");
        main();
    }


    if (a == 1 || d == 1 || f == 1)
    {
        cout << "Dog is saying...\n\n";
        dog1.Eat();
    }
    else if (a == 2 || d == 2 || f == 2)
    {
        cout << "Dog is saying...\n\n";
        dog2.Sleep();
    }
    else if (a == 3 || d == 3 || f == 3)
    {
        cout << "Dog is saying...\n\n";
        dog3.Sit();
    }
    else if (a == 4 || d == 4 || f == 4)
    {
        cout << "Dog is saying...\n\n";
        dog3.Run();
    }


    return 0;

}