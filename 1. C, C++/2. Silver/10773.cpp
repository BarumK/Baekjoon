#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

// Function Definitions
void init();

// Global Variables
int K, sum;
deque<int> stack;

int main() {
    // Initial Setting
	ios::sync_with_stdio(false);

	// Initialize
	init();
}


// Function Implementations
void init() {
    // Initialize Global Variables
    sum = 0;
    stack.clear();

    // Read K
    cin >> K;

    // Process
    for (int i = 0, temp; i < K && cin >> temp; i++) (temp == 0) ? stack.pop_front() : stack.push_front(temp);

    // Calculate Result
    for (int i = 0; i < stack.size(); i++) sum += stack[i];

    // Print Result
    cout << sum;
}