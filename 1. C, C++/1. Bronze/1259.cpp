#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // Variables
    string a, b;

    while(true) {
        // Take Input
        cin >> a;
        b = a;

        // Loop Break Condition
        if ((a.length() == 1) && (a[0] == '0')) break;

        // Reverse
        reverse(b.begin(), b.end());

        // Print Result
        if (equal(a.begin(), a.end(), b.begin())) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}