#include <iostream>

using namespace std;

int main() {
    // Variables
    int value[3];

    while (true) {
        // Take Input & Square Values
        for (int i = 0; i < 3; i++) {
            cin >> value[i];
            value[i] *= value[i];
        }
        
        // Loop Break Condition
        if ((value[0] == 0) && (value[1] == 0) && (value[2] == 0)) break;

        // Judgement
        if (value[0] == value[1] + value[2]) cout << "right" << endl;
        else if (value[1] == value[0] + value[2]) cout << "right" << endl;
        else if (value[2] == value[0] + value[1]) cout << "right" << endl;
        else cout << "wrong" << endl;
    }
}