#include <iostream>
#include <limits>   
using namespace std;

double add(double a, double b)        { return a + b; }
double subtract(double a, double b)   { return a - b; }
double multiply(double a, double b)   { return a * b; }
double divide(double a, double b)     { return b != 0 ? a / b
                                                      : numeric_limits<double>::quiet_NaN(); }
double percentage(double a, double b) { return (a * b) / 100.0; }

void showMenu()
{
    cout << "\n===== Enhanced Calculator Menu =====\n";
    cout << "1. Add\n";
    cout << "2. Subtract\n";
    cout << "3. Multiply\n";
    cout << "4. Divide\n";
    cout << "5. Percentage (num1% of num2)\n";
    cout << "6. Clear (AC)\n";
    cout << "0. Exit\n";
    cout << "Choose an operation (0-6): ";
}

int main()
{
    double num1 = 0.0, num2 = 0.0;
    bool   numbersReady = false;   
    int    choice       = -1;      

    while (true)
    {
        showMenu();
        cin >> choice;

        if (cin.fail() || choice < 0 || choice > 6)
        {
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "❌ Invalid choice. Please select between 0 and 6.\n";
            continue;
        }

        if (choice == 0)
        {
            cout << "Thanks for using this calculator. We will improve the more features!\n";
            break;
        }

        if (choice == 6)
        {
            num1 = num2 = 0.0;
            numbersReady = false;
            cout << "Calculator cleared. Enter new numbers when ready.\n";
            continue;
        }

        if (!numbersReady)
        {
            cout << "Enter Your first number:  ";
            cin  >> num1;
            cout << "Enter Your second number: ";
            cin  >> num2;
            numbersReady = true;
        }

        switch (choice)
        {
            case 1:  
                cout << "Result: " << add(num1, num2) << '\n';
                break;

            case 2: 
                cout << "Result: " << subtract(num1, num2) << '\n';
                break;

            case 3:  
                cout << "Result: " << multiply(num1, num2) << '\n';
                break;

            case 4: 
                if (num2 == 0)
                    cout << " Error: Division by zero is not allowed.\n";
                else
                    cout << "Result: " << divide(num1, num2) << '\n';
                break;

            case 5:  
                cout << "Result: " << num1 << "% of " << num2
                     << " = " << percentage(num1, num2) << '\n';
                break;

            default:
               
                cout << "Unexpected option.\n";
        }

        char reuse;
        cout << "\nReuse these numbers for another operation? (y/n): ";
        cin  >> reuse;
        if (reuse == 'n' || reuse == 'N')
        {
            numbersReady = false;  
        }
    }

    return 0;
}