#include <iostream>

using namespace std;

int main() {
    // Setting for Faster Speed
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    // Variables
    string ISBN;
    int res = 0;
    int mul, saved_mul;

    // Take Input
    cin >> ISBN;

    // Calculate
    for(int i = 0; i < 13; i++) {
        if (i % 2 == 0) mul = 1;
        else mul = 3;
        
        if (ISBN[i] == '*') saved_mul = mul;
        else res += mul * (int)(ISBN[i] - 48);
    }

    // Print Result
    for (int x = 0; x < 10; x++) {
        if ((res + saved_mul * x) % 10 == 0) {
            cout << x << endl;
            break;
        }
    }
}