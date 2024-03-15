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
        cout << "enter your choice :" << endl;
        cin >> a;
        switch (a)
        {
        case 1:
        {
            cout << "_______________________________" << endl;
            cout << "|        Register            |" << endl;
            cout << "|----------------------------|" << endl;
            cout << "|____________________________|" << endl;
            cout << " Please enter your username: " << endl;
            cin >> name;
            cout << "please enter your password: " << endl;
            cin >> password0;
            cout << "please enter your age: " << endl;
            cin >> age;
            break;
            // we can store these creadentials in file , so we will use file handling//
        }
        }
    }
}
}