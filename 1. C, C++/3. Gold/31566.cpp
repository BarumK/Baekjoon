#include <iostream>

using namespace std;

// Macros
#define MAX_N 100
#define INF 100000001

// Function Definitions
void init();
void floyd();
void query();

// Global Variables
int N, M, Q;
int map[MAX_N][MAX_N][MAX_N];


// Main Function
int main() {
	// Initial Setting
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// Initialization
	init();

	// Calculate Floyd-Warshall Algorithm
	floyd();

	// Process Each Queries
	for (int i = 0; i < Q; i++) query();
}


// Function Implementations
void init() {
	// Read N, M, Q
	cin >> N >> M >> Q;

	// Initialize Map
	for (int exclude = 0; exclude < N; exclude++) {
		for (int start = 0; start < N; start++) {
			for (int end = 0; end < N; end++) {
				if (start == end) map[exclude][start][end] = 0;
				else map[exclude][start][end] = INF;
			}
		}
	}

	// Read M Edge Informations
	for (int i = 0; i < M; i++) {
		// Local Variables
		int start, end, weight;

		// Read Edge Informations
		cin >> start >> end >> weight;
		start--; end--;

		// Store to Map
		for (int exclude = 0; exclude < N; exclude++) {
			if ((start == exclude) || (end == exclude)) continue;
			map[exclude][start][end] = weight;
		}
	}
}

void floyd() {
	// For All Exclude Cases
	for (int exclude = 0; exclude < N; exclude++) {
		// Calculate Floyd-Warshall Algorithm
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					// Pass Condition
					if ((map[exclude][i][k] == INF) || (map[exclude][k][j] == INF)) continue;

					// Update Condition
					if ((map[exclude][i][j] > map[exclude][i][k] + map[exclude][k][j])) 
						map[exclude][i][j] = map[exclude][i][k] + map[exclude][k][j];
				}
			}
		}
	}
}

void query() {
	// Local Variables
	int start, target, end;

	// Read Query
	cin >> start >> target >> end;
	start--; target--; end--;

	// Print Answer of Query
	int ans = map[target][start][end];
	if (ans < INF) cout << ans << '\n';
	else cout << "No\n";
}

/*
알고리즘 선택 사고 과정
	플로이드 워셜로 푸는 것임을 알게 된 상태에서 문제 풀이를 시작해서 선택 과정은 딱히 없습니다
	cin.tie(nullptr)를 넣어야만 시간초과가 안나는데 다른 방식이 있지는 않는건가에 대한 생각이 듦...

알고리즘 적용 방식
	1. 입력을 받을 때 플로이드 워셜을 위한 Map을 4개를 만듦
		1.1. 각 방식은 0번부터 N - 1번까지 하나의 노드를 배제한 케이스의 그래프
	2. 각각의 Map에 대해서 플로이드 워셜을 돌림(총 N회)
	3. 각 쿼리를 입력받아 답 바로 출력
*/