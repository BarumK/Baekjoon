#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

// Macros
#define MAX_N 20000

// Function Definitions
void init();
bool compare(string a, string b);

// Global Variables
int N, M;
string letters[MAX_N];
unordered_set<string> letterSet;

int main() {
    // Initial Setting
	ios::sync_with_stdio(false);

	// Initialize
	init();

    // Sort
    sort(letters, letters + M, compare);

    // Print Result
    for (int i = 0; i < M; i++) cout << letters[i] << endl;
}


// Function Implementations
void init() {
    // Temporal Variable
    string temp;

    // Read N
    cin >> N;

    // Initialize Hash Map
    letterSet.clear();

    // Read Each Letters
    for (int i = 0; i < N; i++) {
        cin >> temp;
        letterSet.insert(temp);
    }

    // Calculate Real Letters' Size
    M = letterSet.size();

    // Add to Letter List
    int idx = 0;
    for (auto i = letterSet.begin(); i != letterSet.end(); i++) letters[idx++] = *i;
}

bool compare(string a, string b) {
    if (a.size() != b.size()) return (a.size() < b.size());
    else {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) return (a[i] < b[i]);
        }
    }
}