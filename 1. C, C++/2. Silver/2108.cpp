#include <iostream>
#include <deque>
#include <cmath>
#include <algorithm>

using namespace std;

// Macros
#define MAX_N 500000

// Function Definitions
void init();

// Global Variables
int N;
int mean, median, mode, range;
int nums[MAX_N];
deque<pair<int, int>> pairs;

int main() {
    // Initial Setting
	ios::sync_with_stdio(false);

	// Initialize
	init();
}


// Function Implementations
void init() {
    // Initialization
    mean = 0;
    pairs.clear();

    // Read N
    cin >> N;

    // Read Numbers
    for (int i = 0; i < N; i++) cin >> nums[i];

    // Sort by Value
    sort(nums, nums + N);

    // Calculate Mean
    for (int i = 0; i < N; i++) mean += nums[i];
    mean = round((float)mean / N);

    // Calculate Median
    median = nums[N / 2];

    // Calculate Mode
    for (int i = 0; i < N; i++) {
        if (pairs.empty() || pairs.back().second != nums[i]) pairs.push_back({-1, nums[i]});
        else pairs.back().first--;
    }
    stable_sort(pairs.begin(), pairs.end());
    mode = pairs[0].second;
    if ((pairs.size() != 0) && (pairs[0].first == pairs[1].first)) mode = pairs[1].second;

    // Calculate Range
    range = nums[N - 1] - nums[0];

    // Print Result
    cout << mean << '\n';
    cout << median << '\n';
    cout << mode << '\n';
    cout << range << '\n';
}