#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct User
{
    string name;
    string password;
    string age;
};

void registerUser()
{
    User user;
    cout << "Enter your username: ";
    cin >> user.name;
    cout << "Enter your password: ";
    cin >> user.password;
    cout << "Enter your age: ";
    cin >> user.age;

    ofstream outputFile("file.txt", ios::app);
    if (!outputFile.is_open())
    {
        cout << "Error: Unable to open file for writing" << endl;
        return;
    }

    outputFile << user.name << " " << user.password << " " << user.age << endl;
    outputFile.close();
    cout << "Registration successful" << endl;
}

bool authenticateUser(string username, string password)
{
    ifstream inputFile("file.txt");
    if (!inputFile.is_open())
    {
        cout << "Error: Unable to open file for reading" << endl;
        return false;
    }

    string name, pass, age;
    while (inputFile >> name >> pass >> age)
    {
        if (username == name && password == pass)
        {
            cout << "Login successful" << endl;
            cout << "Details:" << endl;
            cout << "Username: " << name << endl;
            cout << "Age: " << age << endl;
            inputFile.close();
            return true;
        }
    }

    inputFile.close();
    cout << "Incorrect Credentials" << endl;
    return false;
}

void changePassword(string username, string oldPassword)
{
    ifstream inputFile("file.txt");
    ofstream tempFile("temp.txt");
    if (!inputFile.is_open() || !tempFile.is_open())
    {
        cout << "Error: Unable to open files for password change" << endl;
        return;
    }

    string name, pass, age;
    bool passwordChanged = false;
    while (inputFile >> name >> pass >> age)
    {
        if (username == name && oldPassword == pass)
        {
            string newPassword;
            cout << "Enter your new password: ";
            cin >> newPassword;
            tempFile << name << " " << newPassword << " " << age << endl;
            passwordChanged = true;
        }
        else
        {
            tempFile << name << " " << pass << " " << age << endl;
        }
    }

    inputFile.close();
    tempFile.close();
    remove("file.txt");
    rename("temp.txt", "file.txt");

    if (passwordChanged)
    {
        cout << "Password changed successfully" << endl;
    }
    else
    {
        cout << "Invalid old password" << endl;
    }
}

int main()
{
    int choice;
    do
    {
        cout << "╔══════════════════════════════════╗" << endl;
        cout << "║          Security System          ║" << endl;
        cout << "╠══════════════════════════════════╣" << endl;
        cout << "║ 1. Register                       ║" << endl;
        cout << "║ 2. Login                          ║" << endl;
        cout << "║ 3. Change Password                ║" << endl;
        cout << "║ 4. End Program                    ║" << endl;
        cout << "╚══════════════════════════════════╝" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            registerUser();
            break;
        case 2:
        {
            string username, password;
            cout << "Enter your username: ";
            cin >> username;
            cout << "Enter your password: ";
            cin >> password;
            authenticateUser(username, password);
            break;
        }
        case 3:
        {
            string username, oldPassword;
            cout << "Enter your username: ";
            cin >> username;
            cout << "Enter your old password: ";
            cin >> oldPassword;
            changePassword(username, oldPassword);
            break;
        }
        case 4:
            cout << "Thank you!" << endl;
            break;
        default:
            cout << "Enter a valid choice" << endl;
        }
    } while (choice != 4);

    return 0;
}
