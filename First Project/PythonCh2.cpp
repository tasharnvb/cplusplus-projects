#include "PythonCh2.h"
#include <iostream>
#include <string>

using namespace std;

PythonCh2::PythonCh2()
{
    cout << "New PythonCh2 object created" << endl;
    cout << "\n" << endl;
}

void PythonCh2::personalGreeter()
{
    string name;

    cout << "Hi! What's your name? ";
    while (name == "")
    {
        cin >> name;
    }

    cout << "\nHello " << name << ", I am your personal greeter :)" << endl;
}

void PythonCh2::systemBell()
{
    cout << "\a";
}

void PythonCh2::newFood()
{
    string food1;
    string food2;

    cout << "Enter the name of your first favourite food" << endl;
    cin >> food1;
    cout << "\nEnter the name of your second favourite food" << endl;
    cin >> food2;

    cout << "\n\nHave you ever tried combining them to make " << food1 << " " << food2 << "?" << endl;
    cout << "Or you could try " << food2 << " " << food1 << ". That might be good." << endl;
}
