#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

// Function Definitions
void init();

// Global Variables
int TC;
bool valid;
string line;
deque<int> stack;

int main() {
    // Initial Setting
	ios::sync_with_stdio(false);

	// Initialize
	init();
}


// Function Implementations
void init() {
    // Get Number of Test Case
    cin >> TC;

    // For Each Test Case
    for (int tc = 0; tc < TC; tc++) {
        // Initialize Global Variables
        valid = true;
        stack.clear();

        // Read Line
        cin >> line;

        // Processing
        int size = line.size();
        for (int i = 0; i < size; i++) {
            // Push Condition
            if (line[i] == '(') stack.push_front(1);

            // Pop Condition
            else {
                // Check Stack
                if (stack.empty()) {
                    valid = false;
                    break;
                }

                // Pop
                stack.pop_front();
            }
        }

        // Print Result
        cout << ((valid && stack.empty()) ? "YES\n" : "NO\n");
    }
}