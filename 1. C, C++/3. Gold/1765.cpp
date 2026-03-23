#include <iostream>
#include <deque>

using namespace std;

// Macros
#define MAX_N 1000

// Function Definitions
void init();
void find();

// Global Variables
int N, M, result;
bool visited[MAX_N + 1];
deque<int> friendGraph[MAX_N + 1];
deque<int> enemyGraph[MAX_N + 1];
deque<int> queue;


// Main Function
int main() {
	// Initial Setting
	ios::sync_with_stdio(false);

	// Initialization
	init();

	// Perform BFS
	find();

	// Print Result
	cout << result << endl;
}


// Function Implementations
void init() {
	// Read N, M
	cin >> N >> M;

	// Initialize Variables
	result = 0;
	queue.clear();

	// Initialize Arrays
	for (int idx = 0; idx <= N; idx++) {
		visited[idx] = false;
		friendGraph[idx].clear();
		enemyGraph[idx].clear();
	}

	// Read Each Line
	for (int idx = 0; idx < M; idx++) {
		// Variables
		char command;
		int node1, node2;

		// Read
		cin >> command >> node1 >> node2;

		// Make 2 Graph
		if (command == 'F') {
			friendGraph[node1].push_back(node2);
			friendGraph[node2].push_back(node1);
		}
		else {
			enemyGraph[node1].push_back(node2);
			enemyGraph[node2].push_back(node1);
		}
	}
}

void find() {
	// Traverse All Nodes
	for (int idx = 1; idx <= N; idx++) {
		// Pass Condition: Already Visited
		if (visited[idx]) continue;

		// Update Count
		result++;

		// Mark Current Node As Visited & Push Current Node to Queue
		visited[idx] = true;
		queue.push_back(idx);

		// Loop While Queue is Not Empty
		while (!queue.empty()) {
			// Pop Element
			int cur = queue.front();
			queue.pop_front();

			// Add Friend Node of Current Node
			for (int friendIdx = 0; friendIdx < friendGraph[cur].size(); friendIdx++) {
				// Next Node
				int next = friendGraph[cur][friendIdx];

				// Pass Condition
				if (visited[next]) continue;

				// Mark As Visited
				visited[next] = true;

				// Add to Queue
				queue.push_back(next);
			}

			// Add Enemy Node of Current Node's Enemy Node
			for (int enemyIdx = 0; enemyIdx < enemyGraph[cur].size(); enemyIdx++) {
				// Enemy Node
				int enemy = enemyGraph[cur][enemyIdx];

				// Loop Enemy Node's Enemies
				for (int friendIdx = 0; friendIdx < enemyGraph[enemy].size(); friendIdx++) {
					// Next Node
					int next = enemyGraph[enemy][friendIdx];

					// Pass Condition
					if (visited[next]) continue;

					// Mark As Visited
					visited[next] = true;

					// Add to Queue
					queue.push_back(next);
				}
			}
		}
	}
}

/*
알고리즘 선택 사고 과정
	전형적인 Bipartite Graph 문제로 보이되, 그래프가 모두 이어진 그래프가 아니고 여러 개로 분리되어 있는 것으로 보임
	인 줄 알았으나 Union-Find를 사용해야 할 것 같다는 생각으로 변경
	으로 해보려고 했으나 풀리지가 않아 다시 그래프로 돌아옴 -> 친구 그래프와 적 그래프 2개를 만들어 탐색
		현재 탐색 시에 친구를 탐색하고, 적의 적 또한 탐색

알고리즘 적용 방식
	1. init() 함수 통해 변수 및 배열 초기화
	2. find() 함수 통해 두 개의 그래프를 활용하여 BFS 탐색
	3. 결과 출력
*/