#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

// Global variables for contact information
string firstName, lastName, phoneNumber;

// Function prototypes
void addContact();
void searchContact();
void displayHelp();
void exitProgram();
bool hasValidLength(string str);
bool containsOnlyDigits(string str);

int main()
{
    short int choice;
    system("cls");
    system("color 0A");
    cout << "\n\n\n\t\t\tContact Management.";
    cout << "\n\n\t1. Add Contact\n\t2. Search Contact\n\t3. Help\n\t4. Exit\n\t> ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        addContact();
        break;
    case 2:
        searchContact();
        break;
    case 3:
        displayHelp();
        break;
    case 4:
        exitProgram();
        break;
    default:
        cout << "\n\n\tInvalid Input !";
        cout << "\n\tPress Any Key To Continue..";
        getch();
        main();
    }
    return 0;
}

void exitProgram()
{
    system("cls");
    cout << "\n\n\n\t\tThank You For Using !";
    exit(1);
}

void displayHelp()
{
    cout << "This displays help";
}

void addContact()
{
    ofstream contactFile("contacts.txt", ios::app);
    system("cls");
    cout << "\n\n\tEnter First Name : ";
    cin >> firstName;
    cout << "\n\tEnter Last Name : ";
    cin >> lastName;
    cout << "\n\tEnter 10-Digit Phone Number : ";
    cin >> phoneNumber;

    if (hasValidLength(phoneNumber))
    {
        if (containsOnlyDigits(phoneNumber))
        {
            if (contactFile.is_open())
            {
                contactFile << firstName << " " << lastName << " " << phoneNumber << endl;
                cout << "\n\tContact Saved Successfully !";
            }
            else
            {
                cout << "\n\tError Opening File !";
            }
        }
        else
        {
            cout << "\n\tA Phone Number Must Contain Numbers Only !";
        }
    }
    else
    {
        cout << "\n\tA Phone Number Must Contain 10 Digits.";
    }
    contactFile.close();
}

void searchContact()
{
    bool found = false;
    ifstream contactFile("contacts.txt");
    string keyword;
    cout << "\n\tEnter Name To Search : ";
    cin >> keyword;
    while (contactFile >> firstName >> lastName >> phoneNumber)
    {
        if (keyword == firstName || keyword == lastName)
        {
            system("cls");
            cout << "\n\n\n\t\tContact details..";
            cout << "\n\n\tFirst Name : " << firstName;
            cout << "\n\tLast Name : " << lastName;
            cout << "\n\tPhone Number : " << phoneNumber;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "\n\tNo Such Contact Found";
}

bool hasValidLength(string str)
{
    return (str.length() == 10);
}

bool containsOnlyDigits(string str)
{
    for (char ch : str)
    {
        if (!(isdigit(ch)))
        {
            return false;
        }
    }
    return true;
}
