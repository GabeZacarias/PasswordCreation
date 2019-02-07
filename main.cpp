#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>

using namespace std;

void prompt_input();

void get_input(string& userPassword);

void validate_Password(string userPassword, bool& correct_Password);

bool user_Validate(string userPassword, string& userPassword2);

void attempts_reached();

int main()
{
    string userPassword;
    string userPassword2;
    bool correct_Password = false;
    int attempts = 3;

    prompt_input();

    while (attempts > 0 && correct_Password == false)
        {

            if (attempts > 0 && correct_Password == false)
                {
                    get_input(userPassword);
                    validate_Password(userPassword, correct_Password);
                    attempts--;
                }

            if (attempts == 0 && correct_Password == false)
                {
                    attempts_reached();
                }

            if (correct_Password == true)
                {
                    user_Validate(userPassword, userPassword2);
                }
        }

	return 0;
}


void prompt_input()
    {
        cout <<  endl << setw(45) << "-------------------------------------------" << endl;
        cout << setw(33) << "Enter a password that contains:" << endl;
        cout << setw(45) << "At least eight (8) characters, one number, " << endl;
        cout << setw(50) << "one upper case letter, and one lower case letter" << endl;

    }

void get_input(string& userPassword)
    {
        cout << endl << setw(12) << "Password: ";
        cin >> userPassword;
        cout << endl;
    }

void validate_Password(string userPassword, bool& correct_Password)
    {
        int index;
        int uppercase = 0;
        int lowercase = 0;
        int digit = 0;

        for (index = 0; index < userPassword.length(); index++)
            {
                if (isupper(userPassword[index]))
                    uppercase++;
                if (islower(userPassword[index]))
                    lowercase++;
                if (isdigit(userPassword[index]))
                    digit++;
            }

        if (userPassword.length() < 8 || uppercase == 0 || lowercase == 0 || digit == 0)
            {
                cout << "      " << userPassword;
                cout << " is not a valid password." << endl;
            }
        if (userPassword.length() < 8)
            {
                cout  << setw(48) << "It must be at least eight characters long." << endl;
            }

        if (uppercase == 0)
            {
                cout  << setw(47) << "It does not contain an upper case letter." << endl;
            }

        if (lowercase == 0)
            {
                cout  << setw(46) << "It does not contain a lower case letter." << endl;
            }

        if (digit == 0)
            {
                cout  << setw(34) << "It does not contain a digit." << endl;
            }

        if (userPassword.length() >= 8 && uppercase > 0 && lowercase > 0 && digit > 0)
            {
                cout << setw(10) << userPassword;
                cout << " is a valid password." << endl;
                cout << endl << setw(38) << "Re-enter the password for validation" << endl;
                correct_Password = true;
            }

}

void attempts_reached()
{
        cout << endl <<setw(73) << ">>>>   That was the third attempt. This session has been locked.   <<<<" << endl << endl;
}

bool user_Validate(string userPassword, string& userPassword2)
{
        bool match = false;
        cout << endl << setw(12) << "Re-Entry: ";
        cin >> userPassword2;
        cout << endl;


    if (userPassword == userPassword2)
        {
            cout << setw(46) << "****  The password has been approved.  *****" << endl;
            match = true;
        }

    if (userPassword != userPassword2)
        {
            cout << setw(23) << "<<<   This password '" << userPassword2 << "' does not match '" << userPassword << "'   >>>" << endl;
        }
    return match;
}
