#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
#include "Bill.h"
#include "Menu.h"
#include "ForOrder.h"

using namespace std;

class userIDRegister
{
public:
    int userIDDataset[1000];
    string userPasswords[1000];
    int userID;
    bool loginResult = false;
    char registerChoice;

    void RegisterChoice()
    {
        cout << "Are you a Registered User\n";
        cout << "Or Would You like To Register?\n";
        cout << "Enter Y if you are registered and N is you are not.\n";
        cin >> registerChoice;
        if (registerChoice == 'n' || registerChoice == 'N')
        {
            void RegisterUser();
        }
        else
        {
            void userLOGIN();
        }
    }

    void RegisterUser()
    {
        cout << "Please Enter Your User ID here : ";
        cin >> userID;

        string password;
        cout << "Please Set a password: ";
        cin >> password;

        bool isRegistered = false;

        for (int i = 0; i < sizeof(userIDDataset); i++)
        {
            if (userIDDataset[i] == userID)
            {
                isRegistered = true;
                break;
            }
        }

        if (isRegistered)
        {
            cout << "This ID is already Rrgistered\n";
            cout << "Please Enter A new ID, if You are a Registered User, then Please Login\n";
            cout << "THANK YOU\n";

            char loginregisterChoice;
            cout << "Would You like to LOGIN, or REGISTER?";
            cin >> loginregisterChoice;
            if (loginregisterChoice == 'Y' || loginregisterChoice == 'y')
            {
                userLOGIN(); //
            }
            else
            {
                RegisterUser();
            }
        }
        else
        {
            for (int i = 0; i < sizeof(userIDDataset); i++)
            {
                if (userIDDataset[i] == 0)
                {
                    userIDDataset[i] = userID;
                    userPasswords[i] = password;
                    break;
                }
            }
            cout << "Registration SUCCESSFUL, You can now Login as a USER\n";
            userLOGIN();
        }
    }

    void userLOGIN()
    {
        // Logic of userLOGIN here.
        while (!loginResult)
        {
            cout << "Enter Your User ID: ";
            cin >> userID;

            string enteredPassword;
            cout << "Enter Your Password:  ";
            char ch;
            enteredPassword = "";
            while ((ch = _getch()) != '\r')
            {
                if (ch == 8)
                {
                    if (!enteredPassword.empty())
                    {
                        enteredPassword.pop_back();
                        cout << "\b \b";
                    }
                }
                else
                {
                    enteredPassword.push_back(ch);
                    cout << '*';
                }
            }

            for (int i = 0; i < sizeof(userIDDataset); i++)
            {
                if (userIDDataset[i] == userID && userPasswords[i] == enteredPassword)
                {
                    cout << "You are a Registered User, Thanks for LOGIN IN\n";
                    loginResult = true;
                    break;
                }
            }
            if (!loginResult)
            {
                cout << "\nSorry But we did not find that ID or the password is incorrect \n";
                cout << "Would You like to Register or Re - LOGIN ? \n";

                char loginregisterChoice;

                cout << "Please Enter Y for LOGIN IN again, else Enter N : ";
                cin >> loginregisterChoice;

                if (loginregisterChoice == 'Y' || loginregisterChoice == 'y')
                {
                    userLOGIN();
                }
                else
                {
                    RegisterUser();
                }
            }
        }
    }
};

int main()
{
    userIDRegister userRegister;
    Menu menu;
    ForOrder order;
    Bill bill;

    userRegister.RegisterChoice();

    if (userRegister.registerChoice == 'N' || userRegister.registerChoice == 'n')
    {

        char registerOrLogin;
        cout << "Your are not a registered user. \nDo you want to register (R) or Login (L)? ";
        cin >> registerOrLogin;

        if (registerOrLogin == 'R' || registerOrLogin == 'r')
        {
            userRegister.RegisterUser();
        }
        else if (registerOrLogin == 'L' || registerOrLogin == 'l')
        {
            userRegister.userLOGIN();
        }
        else
        {
            cout << "Invalid choice. Wxiting the program.";
            return 0;
        }
    }
    else
    {
        userRegister.userLOGIN();
    }

    char orderDecision = 'N';

    if (userRegister.loginResult)
    {
        menu.displayMenu();

        cout << "Would You like To Order? ";
        cin >> orderDecision;
        if (orderDecision == 'Y' || orderDecision == 'y')
        {
            order.takeOrder();
        }
    }
    return 0;
}
