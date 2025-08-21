#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

// Function Definitions
void init();

// Global Variables
bool balanced;
char line[101];
deque<char> stack;

int main() {
    // Initial Setting
	ios::sync_with_stdio(false);

	// Initialize
	init();
}


// Function Implementations
void init() {
    // Read Input
    while (true) {
        // Initialize Global Variables
        balanced = true;
        for (int i = 0; i < 100; i++) line[i] = 0;
        stack.clear();

        // Read Character
        cin.getline(line, 101);

        // Check Stop Condition
        if (line[0] == '.') break;

        // Processing (, ), [, ]
        for (int i = 0; line[i] != '.'; i++) {
            // Push Condition
            if ((line[i] == '(') || (line[i] == '[')) stack.push_front(line[i]);

            // Pop Condition
            if ((line[i] == ')') || (line[i] == ']')) {
                // Check Stack
                if (stack.empty()) {
                    balanced = false;
                    break;
                }

                // Pop
                char temp = stack.front();
                stack.pop_front();

                // Compare
                if ((temp == '(' && line[i] != ')') || (temp == '[' && line[i] != ']')) {
                    balanced = false;
                    break;
                }
            }
        }

        // Print Result
        cout << ((balanced && stack.empty()) ? "yes\n" : "no\n");
    }
}