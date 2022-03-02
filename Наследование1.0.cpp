#include <iostream>

using namespace std;

class Dog
{
private:
    string Size;
    string Age;
    string Color;

private:

    string Breed;

public:

    Dog() {
        cout << " \n ";
    };

    void Eat();
    void Sleep();
    void Sit();
    void Run();

    void show_dog_param();


    void setBreed(string Breed)
    {
        this->Breed = Breed;
    }

    void setSize(string Size)
    {
        this->Size = Size;
    }

    void setAge(string Age)
    {
        this->Age = Age;
    }

    void setColor(string Color)
    {
        this->Color = Color;
    }


    ~Dog() { cout << " Bye" << endl; };

};

void Dog::show_dog_param()
{
    cout << "\n\n**** Parameters of Dog ****";
    cout << "\nDog Breed  :  " << Breed;
    cout << "\nDog Size   :  " << Size;
    cout << "\nDog Age    :  " << Age;
    cout << "\nDog Color  :  " << Color;
}

class HomeDog : public Dog
{
private:
    string Name; // хоз€ин
    string Nickname; // кличка

public:

    void setName(string s, string b)
    {
        Name = s;
        Nickname = b;
    };

    void show_dog_param();
    ~HomeDog() { cout << " Gav" << endl; };
};


void HomeDog::show_dog_param()
{
    {
        cout << "\n\n**** Parameters of Home Dog ****";
        cout << "\nDog Nickname  :    " << Name;
        cout << "\nOwner name    :    " << Nickname;

        cout << "\n----------------------------------";
        cout << "\n----------------------------------";
    };
}


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


int main()

{
    Dog dog1;
    dog1.setBreed("Neapolitan Mastiff");

    dog1.setSize("Large");
    dog1.setAge("5 years");
    dog1.setColor("Black");

    dog1.show_dog_param();

    HomeDog homedog1;
    homedog1.setName("Sharik", "John");
    homedog1.show_dog_param();
    cout << endl << endl << endl;



    Dog dog2;
    dog2.setBreed("Maltese");

    dog2.setSize("Small");
    dog2.setAge("2 years");
    dog2.setColor("White");

    dog2.show_dog_param();

    HomeDog homedog2;
    homedog2.setName("Bobik", "James");
    homedog2.show_dog_param();
    cout << endl << endl << endl;




    Dog dog3;
    dog3.setBreed("Chow Chow");

    dog3.setSize("Medium");
    dog3.setAge("3 years");
    dog3.setColor("Brown");

    dog3.show_dog_param();

    HomeDog homedog3;
    homedog3.setName("Haski", "Jason");
    homedog3.show_dog_param();
    cout << endl << endl << endl;



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
        cout << "You chose a Neapolitan Mastiff" << endl << endl;;


        void setName(string s);

        cout << "What do you want to know about this dog?\n";
        cout << "1 - Eat\n";
        cout << "2 - Sleep\n";
        cout << "3 - Sit\n";
        cout << "4 - Run\n";
        cin >> a;

        break;
    case 2:
        cout << "You chose a Maltese" << endl << endl;


        void setName(string s);

        cout << "What do you want to know about this dog?\n";
        cout << "1 - Eat\n";
        cout << "2 - Sleep\n";
        cout << "3 - Sit\n";
        cout << "4 - Run\n";
        cin >> d;

        break;
    case 3:
        cout << "You chose a Chow Chow" << endl << endl;


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