#include <iostream>

using namespace std;

int main() {
    // Setting for Faster Speed
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    // Variables
    string line;
    int number;

    // Take Input
    for (int i = 0; i < 3; i++) {
        cin >> line;
        
        if ((line[0] == 'B') || (line[0] == 'F')) continue;
        else {
            number = stoi(line) + (3 - i);
            break;
        }
    }

    // Print Result
    if (number % 3 == 0) {
        if (number % 5 == 0) cout << "FizzBuzz" << endl;
        else cout << "Fizz" << endl;
    }
    else {
        if (number % 5 == 0) cout << "Buzz" << endl;
        else cout << number << endl;
    }
}