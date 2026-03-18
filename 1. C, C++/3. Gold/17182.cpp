#include <iostream>

using namespace std;

// Macros
#define MAX_N 10
#define MAX_VAL 100000001

// Function Definitions
void init();
void traverse(int depth, int cur, int curSum);

// Global Variables
int N, K, result;
int graph[MAX_N][MAX_N];
int visited[MAX_N];


// Main Function
int main() {
	// Initial Setting
	ios::sync_with_stdio(false);

	// Initialization
	init();

	// Traverse
	visited[K] = 1;
	traverse(1, K, 0);

	// Print Result
	cout << result << endl;
}


// Function Implementations
void init() {
	// Read N
	cin >> N >> K;

	// Read Entire Map & Initialize Visited Array
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) cin >> graph[row][col];
		visited[row] = 0;
	}

	// Use Floyd-Warshall Algorithm to Update Shortest Path
	for (int mid = 0; mid < N; mid++) {
		for (int start = 0; start < N; start++) {
			for (int end = 0; end < N; end++) {
				if (graph[start][end] > graph[start][mid] + graph[mid][end]) graph[start][end] = graph[start][mid] + graph[mid][end];
			}
		}
	}

	// Initialize Variables
	result = MAX_VAL;
}

void traverse(int depth, int cur, int curSum) {
	// Break Condition
	if (depth == N) {
		if (result > curSum) result = curSum;
		return;
	}

	// Select
	for (int idx = 0; idx < N; idx++) {
		// Pass Condition
		if (visited[idx] == 1) continue;

		// Select
		visited[idx] = 1;
		traverse(depth + 1, idx, curSum + graph[cur][idx]);
		visited[idx] = 0;
	}
}

/*
알고리즘 선택 사고 과정
	N이 엄청 작으니까 그냥 완탐 때리자
	근데 다시 지나갈 수 있다는 점을 고려 안했어서, 플로이드 워셜을 써서 최단 거리로 업데이트 해두고 생각하자

알고리즘 적용 방식
	1. init() 함수 통해 변수 및 배열 초기화
	2. greedy() 함수 통해 계산
	3. 결과 출력
*/