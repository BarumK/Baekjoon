#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Macros
#define MAX_N 100000

// Function Definitions
void init();
bool compare(pair<int, string> a, pair<int, string> b);

// Global Variables
int N;
pair<int, string> members[MAX_N];

int main() {
    // Initial Setting
	ios::sync_with_stdio(false);

	// Initialize
	init();

    // Print Result
    for (int i = 0; i < N; i++) cout << members[i].first << " " <<  members[i].second << endl;
}


// Function Implementations
void init() {
    // Read N
    cin >> N;

    // Read Member Informations
    for (int i = 0; i < N; i++) cin >> members[i].first >> members[i].second;

    // Sort Array
    stable_sort(members, members + N, compare);
}

bool compare(pair<int, string> a, pair<int, string> b) {
    return (a.first < b.first);
}