#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <direct.h>
#include <io.h>
#include <windows.h>
#include <unistd.h>
#include <iomanip>

using namespace std;

void TandC();

class customer
{

private:
    string fullname;
    string address;

public:
    string name;
    string carmodel;
    char carnumber[20];

    void set_details(string fn, string addr)
    {
        fullname = fn;
        address = addr;
    }
};

class rent : public customer
{
public:
    string brand;
    string days;
    string charge;
    void LogIn();
    void login_RegisterPortal();
    void available();
    void choose();
    void Register(string, string, string, string);
    void Information();
    void total_rent();
    void showbill();
};

void rent ::available()
{
    rent ob;
    cout << "|=================================>> Cars available <<=================================|\n"
         << endl;
    fstream available;
    available.open("Cars.txt", ios::in);
    if (available.is_open())
    {
        string str;
        while (getline(available, str))
        {
            cout << str << "\n";
        }
        available.close();
    }
    choose();
}

void rent ::choose()
{
    string sl;
    char s2;
    cout << "\nChoose the serial number as per your Brand choice : ";
    cin >> sl;
    system("CLS");
    ifstream cars;
    cars.open("../Car Rental System/Cars/" + sl + ".txt", ios::in);

    if (cars.is_open())
    {
        string str;
        while (getline(cars, str))
        {
            cout << str << "\n";
        }
        cars.close();
    }
    cout << "\nChoose the serial number as per your model choice : ";
    cin >> s2;
    cout << endl;

    cars.open("../Car Rental System/Cars/" + sl + ".txt", ios::in);
    if (cars.is_open())
    {
        string in;
        //for performance
        in.reserve(20);

        //skip N lines
        int n = 7 + (s2 - '0');
        for (int i = 1; i < n; ++i)
        {
            getline(cars, in);
        }
        getline(cars, in);
        cout << "\nYour Choice : \n";
        cout << in << endl;
        cars.close();
    }
    Information();
    total_rent();
}

void rent ::Information()
{
    rent ob;
    cout << endl;
    cout << "\n===========>>FOR CONFIRMATION PLEASE ENTER THE FOLLOWING DETAILS<<===========\n";

    cout << "\nEnter your full name : ";
    getline(cin >> ws, name);
    cout << "\nNumber of days to rent the car : ";
    cin >> days;
    cout << "\nModel number of the car you selected : ";
    cin >> carmodel;
    cout << "\nNumber plate of the car you selected : ";
    cin >> carnumber;
}

int calculate(string cm, int day)
{
    int fee = 0;
    //===========HONDA===========
    if (cm == "HO124")
        fee = day * 2120;
    else if (cm == "HO231")
        fee = day * 2530;
    else if (cm == "HO234")
        fee = day * 2460;
    else if (cm == "HO245")
        fee = day * 3100;
    else if (cm == "HO423")
        fee = day * 2890;

    //==============TATA============
    else if (cm == "TA124")
        fee = day * 2220;
    else if (cm == "TA231")
        fee = day * 2430;
    else if (cm == "TA234")
        fee = day * 3800;
    else if (cm == "TA245")
        fee = day * 4600;
    else if (cm == "TA423")
        fee = day * 4600;

    //============HYUNDAI===========
    else if (cm == "HY124")
        fee = day * 2540;
    else if (cm == "HY231")
        fee = day * 2140;
    else if (cm == "HY234")
        fee = day * 1800;
    else if (cm == "HY245")
        fee = day * 2600;
    else if (cm == "HY423")
        fee = day * 2850;

    //==========MARUTI SUZUKI===========
    else if (cm == "MS124")
        fee = day * 1540;
    else if (cm == "MS231")
        fee = day * 2100;
    else if (cm == "MS234")
        fee = day * 2300;
    else if (cm == "MS245")
        fee = day * 1600;
    else if (cm == "MS423")
        fee = day * 3450;
    else
        fee = 0;

    return fee;
}

void rent ::total_rent()
{
    rent ob;
    int day = stoi(days);
    string cm = carmodel;
    int fee = calculate(cm, day);
    charge = to_string(fee);
    Sleep(1);
    cout << "\nCalculating rent......." << endl;
    Sleep(1);
    cout << "\nCreating Bill. Please wait......" << endl;
    Sleep(1);

    system("CLS");
    showbill();
}

void rent ::showbill()
{
    system("CLS");
    cout
        << "\n\t\t                       Car Rental - Customer Invoice                  " << endl;
    cout << "\t\t=========================================================================" << endl;
    cout << endl;
    cout << "\t\t	 Customer Name:"
         << "----------------->> " << setw(10) << name << endl;
    cout << "\t\t	 Car Model :"
         << "-------------------->>" << setw(10) << carmodel << endl;
    cout << "\t\t	 Car No. :"
         << "---------------------->>" << setw(10) << carnumber << endl;
    cout << "\t\t	 Number of days :"
         << "--------------->>" << setw(10) << days << endl;
    cout << "\t\t	 Your Rental Amount is :"
         << "-------->>" << setw(10) << "Rs. " << charge << endl;
    cout << endl;
    cout << "\t\t	 ________________________________________________________" << endl;
    cout << "\n";
    cout << "\t\t	| Total Rental Amount is :"
         << "-------|" << setw(10) << "Rs. " << charge << " |" << endl;
    cout << "\t\t	 ________________________________________________________" << endl;
    cout << " " << endl;
    cout << " " << endl;
    cout << "\t\t	======================================================================" << endl;
    cout << "\t\t	You are advised to pay up the amount before due date." << endl;
    cout << "\t\t	Otherwise penelty fee will be applied" << endl;
    cout << "\t\t	======================================================================" << endl;

    cout << endl;
    Sleep(1);
    cout << "Thanks for renting a car..." << endl;
    Sleep(2);
    cout << "Hope you have a safe journey... " << endl;
}

void TandC()
{
    rent ob;
    string choice;
    cout << "!!ACCEPT THE TERMS AND CONDITION BEFORE PROCEEDING FURTHER!!";
    cout << endl
         << endl;
    cout << "|=================================>> Terms And Conditions <<=================================|";
    cout << endl;
    cout << "\n1. MINIMUM RENT TIME IS 3 HOURS";
    cout << "\n2. RISK BY YOUR OWN";
    cout << "\n3. INCASE ACCIDENT, ALL COSTING IS PAID BY THE DRIVER";
    cout << "\n4. PREPARE ITEM AS BELOW";
    cout << "\n\t\ta. COPY OF IC, LICENSE";
    cout << "\n\t\tb. DEPOSIT (BASED ON CAR TYPE)";
    cout << "\n5. ADDITIONAL CHARGE IF LATE";
    cout << "\n6. SAFE DRIVE!";

    cout << endl
         << endl;
    cout << "Do you agree with the T&C?\nIf yes then Type 'YES' or 'NO': ";
    cin >> choice;

    if (choice == "YES")
    {
        system("PAUSE");
        system("CLS");
        ob.available();
    }
    else
    {
        cout << endl
             << "You cannot rent cars without accepting the Terms and Conditions...";
    }
}

void welcum()
{
    fstream wel;
    wel.open("welcome.txt", ios ::in); //open the welcome.txt file to read
    if (wel.is_open())                 //if the welcome.txt file is open
    {
        string str;
        while (getline(wel, str))
        {
            cout << str << "\n";
        }
        wel.close();
    }
    Sleep(1);
    cout << "\nStarting the program please wait....." << endl;
    Sleep(1);
    cout << "\nloading up files....." << endl;
    Sleep(1);      //function which waits for (n) seconds
    system("CLS"); //cleares screen
}

bool exist(string username)
{
    ifstream duplicate;
    duplicate.open(username + ".txt", ios::in);
    if (duplicate.is_open())
    {
        string str;
        while (getline(duplicate, str))
        {
            if (username == str)
                return true;
        }
        duplicate.close();
    }
    return false;
}

void rent ::Register(string username, string password, string customer_name, string addr)
{
    rent ob;
    bool valid = exist(username);
    if (valid == false)
    {
        fstream user;
        user.open(username + ".txt", ios::out); //write a file
        if (user.is_open())
        {
            user << username << endl;
            user << password << endl;
            user << customer_name << endl;
            user << endl;
            user << addr << endl;
            user.close();
        }
        ob.set_details(customer_name, addr);
        cout
            << endl
            << "You are registered successfully."
            << endl;
        system("CLS");
        LogIn();
    }
    else
    {
        cout << "Username is already taken. Try Again!!" << endl;
        login_RegisterPortal();
    }
}

void rent ::LogIn()
{
    rent ob;
    string un, pass, u, p;

    cout << "======================================================================";
    cout << "\n|                                                                    |";
    cout << "\n|                               LOGIN                                |";
    cout << "\n|                                                                    |";
    cout << "\n======================================================================";
    cout << endl;
    cout << "\n\n\t\tEnter username : ";
    cin >> un;
    cout << "\n\t\tEnter password : ";
    cin >> pass;

    bool valid = exist(un);
    if (valid == true)
    {
        ifstream user(un + ".txt");

        if (user.is_open())
        {
            getline(user, u);
            getline(user, p);
            if (u == un && p == pass)
            {
                cout << "\nYou are successfully logged in." << endl
                     << endl;
                system("PAUSE");
                system("CLS");
                TandC();
            }
            else
            {
                cout << "Wrong username or password.\nTry Again!!." << endl;
                system("PAUSE");
                system("CLS");
                LogIn();
            }
        }
    }
    else
    {
        cout << "Account does not exist.\nPlease Register!!." << endl;
        system("PAUSE");
        system("CLS");
        ob.login_RegisterPortal();
    }
}

int main()
{
    rent ob;
    customer cust;
    system("CLS");
    welcum();
    ob.login_RegisterPortal();
}

void rent ::login_RegisterPortal()
{
    rent ob;
    int ch;
    cout << "Press 1 for Register Id.";
    cout << "\nPress 2 for Login Id." << endl;
    cout << endl
         << "Enter your choice : ";
    cin >> ch;
    cout << endl;

    fstream user;
    if (ch == 1)
    {
        string username, password, customer_name, addr;
        cout << "Enter your full name : ";
        getline(cin >> ws, customer_name);
        cout << "Create a username : ";
        cin >> username;
        cout << "Create a password (Password should be of minimum 8 digits) : ";
        cin >> password;
        cout << "Enter you address : ";
        getline(cin >> ws, addr);
        cout << endl;

        if (password.length() >= 8 && username.size() != 0)
        {
            Register(username, password, customer_name, addr);
            LogIn();
        }
        else if (username.size() == 0)
        {
            cout << "\nEnter username." << endl;
            main();
        }
        else
        {
            cout << "\nInvalid password.\nPassword should be of minimum 8 digits.\nTry Again!!" << endl;
            main();
        }
    }
    if (ch == 2)
    {
        system("PAUSE");
        system("CLS");
        ob.LogIn();
    }
}
