#include <iostream>

using namespace std;

int main() {
    // Setting for Faster Speed
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    // Variables
    int N, temp;
    int res[10001] = {0};

    // Take Inputs
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        res[temp] += 1;
    }

    // Print Result
    for (int i = 1; i < 10001; i++) {
        for (int j = 0; j < res[i]; j++) cout << i << "\n";
    }
}