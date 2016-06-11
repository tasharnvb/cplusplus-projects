#include <iostream>
#include <string>
#include "PythonCh2.h"

#include <cstdlib>
#include <ctime>

using namespace std;

// Asks the user for two numbers and calculates the sum
void sumCalculator()
{
    int a, b, sum;

    cout << "Please enter a number.\n    ";
    cin >> a;

    cout << "\nPlease enter another number.\n    ";
    cin >> b;

    sum = a + b;
    cout << "\n  Sum = " << sum << endl;
}

// A random number generator
int rng(int minimum, int maximum)
{
    srand(time(0));

    // http://www.cplusplus.com/forum/beginner/85134/
    // cire (near the bottom) explains this well
    // Note to self: The brackets aren't needed
    int range = (maximum - minimum) + 1;
    int num = (rand() % range) + minimum;

    return num;
}

// The c++ version of the game I modified in python
void guessYourNumber()
{
    cout << "\t\tGuess You Number" << endl;
    cout << "Think of a number between 1 and 100." << endl;
    // Make program wait for a keypress here

    int oldGuess = 0;
    int lowerLimit = 1;
    int upperLimit = 100;

    int compGuess = rng(lowerLimit, upperLimit);

    string yourNumber;

    // Make sure that the user types either yes or no
    cout << "\n\nMy guess is... " << compGuess << "\nIs that your number?";

    while (yourNumber != "yes" && yourNumber != "no")
    {
        cout << " Please type either yes or no ";
        cin >> yourNumber;
    }

    if (yourNumber == "yes")
    {
        cout << "\nWell that's the end of the game then :)" << endl;
    }
    else if (yourNumber == "no")
    {
        while (yourNumber != "yes")
        {
            oldGuess = compGuess;

            string hol;
            // Make sure that the user types either h or l
            while (hol != "h" && hol != "l")
            {
                cout << "\nHigher or lower? (Type h or l) ";
                cin >> hol;
            }

            if (hol == "h")
            {
                if (oldGuess == upperLimit)
                {
                    cout << "\nIt can't be any higher!!! Play the game properly next time";
                    break;
                }
                lowerLimit = oldGuess + 1;
            }
            else if (hol == "l")
            {
                if (oldGuess == lowerLimit)
                {
                    cout << "\nIt can't be any lower!!! Play the game properly next time";
                    break;
                }
                upperLimit = oldGuess - 1;
            }

            // Generate a new random number making sure it is not the same as the old one
            while (compGuess == oldGuess)
            {
                compGuess = rng(lowerLimit, upperLimit);
            }

             // Make sure that the user types either yes or no
            cout << "\n\nMy guess is... " << compGuess << "\nIs that your number?";

            while (yourNumber != "yes" && yourNumber != "no")
            {
                cout << " Please type either yes or no ";
                cin >> yourNumber;
            }
            if (yourNumber == "yes")
            {
                cout << "\nWell that's the end of the game then :)" << endl;
                break;
            }
            else if (yourNumber == "no")
            {
                if ((upperLimit - lowerLimit) == 0)
                {
                    cout << "\nEither " << compGuess << " is your number, or you lied during an earlier question." << endl;
                    cout << "Either way i'm ending the game." << endl;
                    break;
                }
            }
            else
            {
                cout << "\nError. String yourNumber is something other than yes or no. Game ending." << endl;
                // Display some info about some of the game's variables. It may help with debugging if this else is reached
                cout << "\noldGuess = " << oldGuess << "\nlowerLimit = " << lowerLimit << "\nupperLimit = " << upperLimit << "\nyourNumber = " << yourNumber << endl;
            }
        }
    }
    else
    {
        cout << "\nError. String yourNumber is something other than yes or no. Game ending." << endl;
        // Display some info about some of the game's variables. It may help with debugging if this else is reached
        cout << "\noldGuess = " << oldGuess << "\nlowerLimit = " << lowerLimit << "\nupperLimit = " << upperLimit << "\nyourNumber = " << yourNumber << endl;
    }
}

// A class with some simple functions
class BeginnerClass
{
private:
    string name;
public:
    void firstProgram()
    {
        cout << "Hello World!" << endl;
    }

    void addition(int x, int y)
    {
        int sum = x + y;
        cout << x << " + " << y << " = " << sum << endl;
    }

    void subtraction(int x, int y)
    {
        int difference = x - y;
        cout << x << " - " << y << " = " << difference << endl;
    }

    void multiplication(int x, int y)
    {
        int product = x * y;
        cout << x << " * " << y << " = " << product << endl;
    }

    void division(int x, int y)
    {
        int quotient = x / y;
        cout << x << " / " << y << " = " << quotient << endl;
    }

    void setName(string newName)
    {
        name = newName;
    }

    string getName()
    {
        return name;
    }
};

// A new class demonstrating the use of private variables with a getter and a setter
class NewClass1
{
private:
    string name;
public:
    NewClass1(string x)
    {
        setName(x);
    }
    void setName(string newName)
    {
        name = newName;
    }

    string getName()
    {
        return name;
    }
};

void sentinalControlledProgram()
{
    int age;
    int ageTotal = 0;
    int numberOfPeopleEntered = 0;

    cout << "Enter first persons age or -1 to quit" << endl;
    cin >> age;

    while (age != -1)
    {
        ageTotal += age;
        numberOfPeopleEntered++;

        cout << "Enter next persons age or -1 to quit" << endl;
        cin >> age;
    }

    cout << "Number of people entered = " << numberOfPeopleEntered << endl;
    cout << "Average age = " << ageTotal/numberOfPeopleEntered << endl;
}

// Finds a factorial (Demonstrating recursion)
int factorialFinder(int x)
{
    if (x <= 1)
    {
        return 1;
    }

    int y = factorialFinder(x - 1);

    return (x * y);
}

int main()
{
    //sumCalculator();

    //guessYourNumber();

    /*
    BeginnerClass beginner;
    beginner.firstProgram();
    int x = 3;
    int y = 14;
    beginner.addition(x, y);
    beginner.subtraction(x, y);
    beginner.multiplication(x, y);
    beginner.division(x, y);
    beginner.setName("Tasharn Vidal Brown");
    cout << beginner.getName();
    */

    /*
    NewClass1 mBlackman("Malorie Blackman");
    cout << mBlackman.getName();
    */

    /*
    PythonCh2 pch2;
    pch2.personalGreeter();
    pch2.systemBell();
    pch2.newFood();
    */

    //sentinalControlledProgram();

    cout << factorialFinder(5) << endl;

}
