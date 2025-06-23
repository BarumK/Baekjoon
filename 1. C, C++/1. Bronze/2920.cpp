#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // Variables
    int var[8];
    int val[8];

    // Take Input
    for (int i = 0; i < 8; i++) {
        cin >> var[i];
        val[i] = var[i];
    }

    // Sort List
    stable_sort(val, val + 8);

    // Print Result
    if (equal(var, var + 8, val)) cout << "ascending" << endl;
    else {
        reverse(val, val + 8);
        if (equal(var, var + 8, val)) cout << "descending" << endl;
        else cout << "mixed" << endl;
    }
}