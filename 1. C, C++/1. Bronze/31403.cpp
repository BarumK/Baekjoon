#include <iostream>
#include <string>

using namespace std;

int main() {
    // Variables
    int var[3];

    // Take Input
    for (int i = 0; i < 3; i++)
        cin >> var[i];

    // Print Result
    cout << var[0] + var[1] - var[2] << endl;
    cout << stoi(to_string(var[0]) + to_string(var[1])) - var[2] << endl;
}