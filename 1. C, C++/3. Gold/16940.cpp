#include <iostream>
#include <deque>
#include <unordered_set>

using namespace std;

// Macros
#define MAX_N 100000

// Function Definitions
void init();
void chunkBFS();

// Global Variables
int N, result;
int target[MAX_N];
unordered_set<int> graph[MAX_N + 1];
deque<int> queue;


// Main Function
int main() {
	// Initial Setting
	ios::sync_with_stdio(false);

	// Initialization
	init();

	// Check
	chunkBFS();

	// Print Result
	cout << result << endl;
}


// Function Implementations
void init() {
	// Read N
	cin >> N;

	// Initizlize Variables
	result = 0;
	queue.clear();
	for (int idx = 0; idx <= N; idx++) graph[idx].clear();

	// Read N - 1 Edges
	for (int idx = 0; idx < N - 1; idx++) {
		// Read Edge
		int from, to;
		cin >> from >> to;

		// Add to Graph
		graph[from].insert(to);
		graph[to].insert(from);
	}

	// Read Target String
	for (int idx = 0; idx < N; idx++) cin >> target[idx];
}

void chunkBFS() {
	// Push First Element to Queue
	queue.push_back(1);
	for (int idx = 1; idx <= N; idx++) graph[idx].erase(1);

	// Early Stopping
	if (target[0] != 1) return;

	// Loop for N Nodes of Target String
	for (int idx = 1; idx < N; idx++) {
		// Variables
		int curTarget = target[idx];
		while (!queue.empty() && graph[queue.front()].empty()) queue.pop_front();
		if (queue.empty()) return;
		int curNodeNum = queue.front();

		// Check If Graph Search is Valid
		if (graph[curNodeNum].find(curTarget) != graph[curNodeNum].end()) {
			graph[curTarget].erase(curNodeNum);
			graph[curNodeNum].erase(curTarget);
			queue.push_back(curTarget);
		}
		else return;
	}

	// Set Result
	result = 1;
}

/*
알고리즘 선택 사고 과정
	방문한 자식들 순서대로 넣는 방식이 탐색 순서를 결정하는 방식이라면, 자식을 한 번에 묶어서 배열로 큐에 넣으면 되지 않을까?라는 생각
	그러고 나서 자식이 빌 때까지 진행하는 방식으로 생각 -> 해시 셋을 사용하여 빠르게 탐색 가능하지 않을까라는 생각
	또한 1부터 N까지 자연수가 한 번씩만 등장한다고 되어있으니, 이미 방문한 곳을 탐색하는 경우는 배제해도 될 것으로 보임

알고리즘 적용 방식
	1. init() 함수로 변수 및 배열 초기화
	2. chunkBFS() 함수로 체크
	3. 결과 출력
*/