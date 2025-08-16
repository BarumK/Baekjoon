#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

// Macros
#define MAX_N 50
#define MAX_HEIGHT 200
#define OFFSET 256

// Function Definitions
void init();
bool compare(pair<int, int> a, pair<int, int> b);
int query(int index);
void update(int index, int delta);
void calculate();

// Global Variables
int N;
int idxTree[2 * OFFSET], ord[MAX_N], ans[MAX_N];
pair<int, int> people[MAX_N], sortedPeople[MAX_N];

int main() {
    // Initial Setting
	ios::sync_with_stdio(false);

	// Initialize
	init();

    // Calculate & Print Result
    calculate();
}


// Function Implementations
void init() {
    // Temporal Variables
    int temp[2];

    // Read N
    cin >> N;

    // Initialize Indexed Tree
    for (int i = 0; i < 2 * OFFSET; i++) idxTree[i] = 0;

    // Read Each Line
    for (int i = 0; i < N; i++) {
        cin >> temp[0] >> temp[1];
        people[i] = { temp[0], temp[1] };
        sortedPeople[i] = { temp[0], temp[1] };
    }

    // Sort By Weight(Ascending Order)
    sort(sortedPeople, sortedPeople + N, compare);

    // Get Sorted->Original Map
    for (int i = 0; i < N; i++) ord[i] = i;
    sort(ord, ord + N, [&](int a, int b) {
        if (people[a].first != people[b].first) return people[a].first > people[b].first;
        else return (people[a].second > people[b].second);
    });
}

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) return (a.first > b.first);
    else return (a.second > b.second);
}

int query(int index) {
    // Variables
    int start = OFFSET + index;
    int end = OFFSET + MAX_HEIGHT;
    int sum = 0;

    // Calculate Interval Sum
    while (start <= end) {
        if (start % 2 != 0) sum += idxTree[start++];
        if (end % 2 == 0) sum += idxTree[end--];
        start/= 2;
        end /= 2;
    }

    return sum;
}

void update(int index) {
    // Variables
    int idx = OFFSET + index;

    // Update
    while (idx > 0) {
        idxTree[idx] += 1;
        idx /= 2;
    }
}

void calculate() {
    // Calculate & Print Result
    for (int i = 0; i < N;) {
        // Check Number of Duplicate Pair
        int j = i;
        while ((j < N) && (sortedPeople[j].first == sortedPeople[i].first)) j++;

        // Query
        for (int k = i; k < j; k++) ans[ord[k]] = query(sortedPeople[k].second + 1) + 1;

        // update
        for (int k = i; k < j; k++) update(sortedPeople[k].second);

        // Adjust i
        i = j;
    }
    
    // Print Result
    for (int i = 0; i < N; i++) cout << ans[i] << ' ';
}