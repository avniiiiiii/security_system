#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main()
{          // two integer variables a and i, where a is uninitialized and i is initialized to 0.
    int a; // a is the choice input
    int i = 0;

    string text, old, password1, password2, pass, name, password0, user, age, word, word1; // we'll use these variables later on
    string creds[2], cp[2];
    // create an interface which will show 4 options://
    cout << "╔══════════════════════════════════╗" << endl;
    cout << "║          Security System          ║" << endl;
    cout << "╠══════════════════════════════════╣" << endl;
    cout << "║ 1. Register                       ║" << endl;
    cout << "║ 2. Login                          ║" << endl;
    cout << "║ 3. Change Password                ║" << endl;
    cout << "║ 4. End Program                    ║" << endl;
    cout << "╚══════════════════════════════════╝" << endl;
    // now the user has to enter any one option as an input so we will use a do while loop//
    do
    {
        cout << endl
             << endl;
        cout << "Enter your choice: ";
        cin >> a;

        switch (a)
        {
        case 1:
        {
            cout << " Please enter your username: ";
            cin >> name;
            cout << " Please enter your password: ";
            cin >> password0;
            cout << " Please enter your age: ";
            cin >> age;

            // Open file for writing
            ofstream of1;         // declares an object named of1 of type ofstream, which stands for output file stream. This object will be used to write data to a file.
            of1.open("file.txt"); // opens a file named "file.txt" in write mode.
            // conditional statement checks if the file was successfully opened. The is_open() function returns true if the file is open and false otherwise.
            if (of1.is_open())
            {
                of1 << name << "\n";
                of1 << password0 << "\n";

                of1.close(); // Close the file after writing
                cout << "Registration successful" << endl;
            }
            else
            {
                cout << "Error: Unable to open file for writing" << endl;
            }
            break;
        }

        case 2:
        {
            i = 0;
            cout << "_______________________________" << endl;
            cout << "|          login             |" << endl;
            cout << "|----------------------------|" << endl;
            cout << "|____________________________|" << endl;
            ifstream of2; // Objects of type ifstream are used to open, read from, and close files.
            of2.open("file.txt");
            cout << "please enter your username:" << endl;
            cin >> user;
            cout << "please enter your username:" << endl;
            cin >> pass;
            if (of2.is_open())
            {
                while (!of2.eof())
                {
                    while (getline(of2, text)) // get line() reads line by line. a loop is used to read lines from the file using getline(). Each line is stored in the variable text.
                    {
                        istringstream iss(text); // An istringstream object iss is created using the line read from the file. This object can be used to parse the contents of the line further if needed.
                                                 // The >> operator is the extraction operator, and it reads data from the stream (iss in this case) into the variable word.
                        iss >> word;             // this  line extracts the first word from the string text and stores it in the variable word.//  // The >> operator is the extraction operator, and it reads data from the stream (iss in this case) into the variable word.
                        creds[i] = word;         // After extracting the word from the string, it is stored in the creds array at index i. The creds array is likely intended to store the credentials (e.g., username, password) read from the file.
                        i++;                     // increments the value of i to move to the next index in the creds array.first username will be stored then password i.e why we used increament operator
                    }
                    // we have to check ikf registered username matches with the login username or not //
                    if (user == creds[0] && pass == creds[1]) // zero position pr username hai aur 1 par password//
                    {
                        cout << "------------Login successful-----------";
                        cout << endl
                             << endl;
                        cout << "Details:" << endl;
                        cout << "Username:" + name << endl;
                        cout << "Password:" + pass << endl;
                        cout << "Age:" + age << endl;
                    }
                    else
                    {
                        cout << endl
                             << endl;
                        cout << "Incorrect Credentials" << endl;
                        cout << "|    1.Press 2 to login  |" << endl;
                        cout << "|    2.Press 3 to change password  |" << endl;
                    }
                }
            }
            break;
        }
        case 3:
        {
            i = 0;

            cout << "_______________________________" << endl;
            cout << "|        Change Password     |" << endl;
            cout << "|----------------------------|" << endl;
            cout << "|____________________________|" << endl;
            ifstream of3;
            of3.open("file.txt");
            cout << "Enter the old password:" << endl;
            cin >> old;
            if (of3.is_open())
            {
                while (of3.eof())
                { // endoffile operation
                    while (getline(of3, text))
                    {
                        istringstream iss(text);
                        iss >> word1;
                        cp[i] = word1;
                        i++;
                    }
                    if (old == cp[1]) // zero par username hai ,1 par password//we are saying if old password is same as current password that user  has entered then do this
                    {
                        of3.close();
                        ofstream of1; // ofstream bcz we want to write something//
                        if (of1.is_open())
                        {
                            cout << "Enter your new password:" << endl;
                            cin >> password1;
                            cout << "Enter your password again:" << endl;
                            cin >> password1;
                        }
                    }
                }
            }
        }

        break;

        } // Add more cases for other options if needed
    }
}
while (a != 4)
    ; // Exit loop when user chooses option 4
}