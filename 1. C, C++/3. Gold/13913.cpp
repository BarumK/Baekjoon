#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

// Macros
#define MAX_NK 100000

// Function Definitions
void init();
void bfs();
bool inRange(int idx);

// Global Variables
int N, K, result;
int parent[MAX_NK + 1];
bool visited[MAX_NK + 1];
deque<pair<int, int>> queue;
deque<int> resultTrace;


// Main Function
int main() {
	// Initial Setting
	ios::sync_with_stdio(false);

	// Initialization
	init();

	// Perform BFS
	bfs();

	// Print Result
	cout << result << endl;
	for (int idx = 0; idx < resultTrace.size(); idx++) cout << resultTrace[idx] << " ";
}


// Function Implementations
void init() {
	// Read N, K
	cin >> N >> K;

	// Initizlize Queue
	queue.clear();
	resultTrace.clear();

	// Initialize Visited Array
	for (int idx = 0; idx <= MAX_NK; idx++) {
		parent[idx] = idx;
		visited[idx] = false;
	}
}

void bfs() {
	// Add Start Point to Queue
	queue.push_back(make_pair(N, 0));
	visited[N] = true;

	// Loop While Queue is Not Empty
	while (!queue.empty()) {
		// Pop Element
		int cur = queue.front().first;
		int depth = queue.front().second;
		queue.pop_front();

		// Stop Condition
		if (cur == K) {
			result = depth;
			for (int idx = cur; ; idx = parent[idx]) {
				resultTrace.push_front(idx);
				if (idx == parent[idx]) break;
			}
			return;
		}

		// Push Next Point to Queue
		if (inRange(cur + 1) && !visited[cur + 1]) {
			queue.push_back(make_pair(cur + 1, depth + 1));
			visited[cur + 1] = true;
			parent[cur + 1] = cur;
		}
		if (inRange(cur - 1) && !visited[cur - 1]) {
			queue.push_back(make_pair(cur - 1, depth + 1));
			visited[cur - 1] = true;
			parent[cur - 1] = cur;
		}
		if (inRange(cur * 2) && !visited[cur * 2]) {
			queue.push_back(make_pair(cur * 2, depth + 1));
			visited[cur * 2] = true;
			parent[cur * 2] = cur;
		}
	}
}

bool inRange(int idx) {
	if (idx < 0 || idx > MAX_NK) return false;
	return true;
}

/*
알고리즘 선택 사고 과정
	BFS 돌리면 될 것 같은데? 라는 생각

알고리즘 적용 방식
	1. init() 함수 사용으로 초기화
	2. bfs() 함수 통해 탐색
	3. 결과 출력
*/