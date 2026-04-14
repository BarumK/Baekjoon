#include <iostream>
#include <deque>

using namespace std;

// Macros
#define MAX_N 200
#define MAX_VAL 100000007

// Function Definitions
void init();
void floyd();
void find();

// Global Variables
int N, M, K, value;
int friends[MAX_N];
int forwardFloyd[MAX_N + 1][MAX_N + 1];
int reverseFloyd[MAX_N + 1][MAX_N + 1];
int totalFloyd[MAX_N + 1][MAX_N + 1];
deque<int> result;

// Main Function
int main() {
	// Initial Setting
	ios::sync_with_stdio(false);

	// Initialization
	init();

	// Perform Floyd-Warshall Algorithm
	floyd();

	// Find Result
	find();

	// Print Result
	for (int idx = 0; idx < result.size(); idx++) cout << result[idx] << " ";
}


// Function Implementations
void init() {
	// Read N, K
	cin >> N >> M;

	// Initialize Floyd-Warshall Table
	for (int row = 0; row <= N; row++) {
		for (int col = 0; col <= N; col++) {
			if (row == col) {
				forwardFloyd[row][col] = 0;
				reverseFloyd[row][col] = 0;
			}
			else {
				forwardFloyd[row][col] = MAX_VAL;
				reverseFloyd[row][col] = MAX_VAL;
			}
		}
	}

	// Initialize Variables
	result.clear();
	value = MAX_VAL;

	// Read Graph
	for (int idx = 0; idx < M; idx++) {
		// Variables
		int from, to, weight;

		// Read
		cin >> from >> to >> weight;

		// Make Edge
		forwardFloyd[from][to] = weight;
		reverseFloyd[to][from] = weight;
	}

	// Read K
	cin >> K;

	// Read K Friends Information
	for (int idx = 0; idx < K; idx++) cin >> friends[idx];
}

void floyd() {
	// Forward
	for (int middle = 1; middle <= N; middle++) {
		for (int from = 1; from <= N; from++) {
			for (int to = 1; to <= N; to++) {
				if ((forwardFloyd[from][middle] != MAX_VAL) && (forwardFloyd[middle][to] != MAX_VAL)) {
					// Variables
					int direct = forwardFloyd[from][to];
					int detour = forwardFloyd[from][middle] + forwardFloyd[middle][to];

					// Update
					if (direct > detour) forwardFloyd[from][to] = detour;
				}
			}
		}
	}

	// Reverse
	for (int middle = 1; middle <= N; middle++) {
		for (int from = 1; from <= N; from++) {
			for (int to = 1; to <= N; to++) {
				if ((reverseFloyd[from][middle] != MAX_VAL) && (reverseFloyd[middle][to] != MAX_VAL)) {
					// Variables
					int direct = reverseFloyd[from][to];
					int detour = reverseFloyd[from][middle] + reverseFloyd[middle][to];

					// Update
					if (direct > detour) reverseFloyd[from][to] = detour;
				}
			}
		}
	}

	// Total
	for (int from = 1; from <= N; from++) {
		for (int to = 1; to <= N; to++) totalFloyd[from][to] = forwardFloyd[from][to] + reverseFloyd[from][to];
	}
}

void find() {
	for (int point = 1; point <= N; point++) {
		// Temporal Variables
		int curMax = -1;

		// Find Maximum Distance
		for (int idx = 0; idx < K; idx++) {
			int cur = totalFloyd[friends[idx]][point];
			if (curMax < cur) curMax = cur;
		}

		// Update
		if (curMax < value) {
			result.clear();
			value = curMax;
			result.push_back(point);
		}
		else if (curMax == value) result.push_back(point);
	}
}

/*
알고리즘 선택 사고 과정
	순방향 플로이드 워셜 적용해서 시작점 -> 각 포인트까지 시간 구하고
	역방향 플로이드 워셜 적용해서 각 포인트 -> 시작점까지 시간 구하고
	이 둘을 더해서 갔다가 돌아오는 시간을 구하고
	이후 그 중에서 최소가 되는 값을 취하면 되지 않을까라는 생각

알고리즘 적용 방식
	1. init() 함수 사용으로 초기화
	2. floyd() 함수 통해 최단거리 탐색
	3. find() 함수 통해 결과 계산
	4. 결과 출력
*/