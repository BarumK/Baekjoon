#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// Function Definitions
void init();

// Global Variables
int TC, N, M, acc;
deque<int> q;
priority_queue<int> pq;

int main() {
    // Initial Setting
	ios::sync_with_stdio(false);

    // Read TC
    cin >> TC;

	// Initialize for Each Test Case
    for (int tc = 0; tc < TC; tc++) init();
}


// Function Implementations
void init() {
    // Read N, M
    cin >> N >> M;

    // Initialize Variables
    acc = 1;
    q.clear();
    while (!pq.empty()) pq.pop();

    // Get Initial Array
    for (int n = 0, temp; n < N && cin >> temp; n++) {
        q.push_back(temp);
        pq.push(temp);
    }

    // Calculate
    while (true) {
        // Get Front Value
        int cur = q.front();

        // Compare Priority
        if (M == 0) {
            if (cur == pq.top()) {
                cout << acc << '\n';
                return;
            }
            else {
                q.pop_front();
                q.push_back(cur);
                M = q.size() - 1;
            }
        }
        else {
            if (cur == pq.top()) {
                q.pop_front();
                pq.pop();
                M--;
                acc++;
            }
            else {
                q.pop_front();
                q.push_back(cur);
                M--;
            }
        }
    }
}