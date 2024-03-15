#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    int a, i = 0; // two integer variables a and i, where a is uninitialized and i is initialized to 0.

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
}