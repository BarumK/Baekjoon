#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

// Function Definitions
void init();
void process();

// Global Variables
int N, K;
deque<int> queue;

int main() {
    // Initial Setting
	ios::sync_with_stdio(false);

	// Initialize
	init();
}


// Function Implementations
void init() {
    // Read N, K
    cin >> N >> K;

    // Initialization
    queue.clear();
    for (int i = 1; i <= N; i++) queue.push_back(i);

    // Process
    cout << '<';
    process();
    cout << '>';
}

void process() {
    while (!queue.empty()) {
        for (int i = 1; i <= K; i++) {
            // Pop
            int temp = queue.front();
            queue.pop_front();

            // Push Back or Print
            if (i == K) cout << temp << (!queue.empty() ? ", " : "");
            else queue.push_back(temp);
        }
    }
}