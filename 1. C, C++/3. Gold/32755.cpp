#include <iostream>
#include <deque>

using namespace std;

// Macros
#define MAX_N 500

// Function Definitions
void init();
void search();

// Global Variables
int N, result;
bool visited[MAX_N + 1];
bool tree[MAX_N + 1][MAX_N + 1];
deque<int> queue;


// Main Function
int main() {
	// Initial Setting
	ios::sync_with_stdio(false);

	// Initialization
	init();

	// Search Max Warp Count
	search();

	// Print Result
	cout << result;
}


// Function Implementations
void init() {
	// Read N
	cin >> N;

	// Initialize Variables
	result = -1;
	for (int i = 0; i <= N; i++) visited[i] = false;
	queue.clear();

	// Read Edge Information
	for (int i = 0; i < N - 1; i++) {
		// Read Input
		int start, end;
		cin >> start >> end;

		// Add Edge Information to Tree
		tree[start][end] = true;
		tree[end][start] = true;
	}

	// Reverse Tree
	for (int row = 1; row <= N; row++) {
		for (int col = 1; col <= N; col++) {
			if (row == col) tree[row][col] = false;
			else tree[row][col] = (tree[row][col] == true) ? false : true;
		}
	}
}

void search() {
	// Select Node to Traverse
	for (int idx = 1; idx <= N; idx++) {
		// Pass Condition: Already Visited Node
		if (visited[idx] == true) continue;

		// Initialize Queue
		queue.clear();

		// Mark As Visited & Add to Queue (Start Point)
		visited[idx] = true;
		queue.push_back(idx);

		// Local Max Depth Definition
		int localCount = 0;

		// Loop While Queue is Empty(BFS)
		while (!queue.empty()) {
			// Pop Element
			int curNode = queue.front();
			queue.pop_front();

			// Update Count
			localCount++;

			// If Unvisited Adjancy Node Exists, Add to Queue
			for (int next = 1; next <= N; next++) {
				// Pass Condition: Already Visited or Not Connected
				if (visited[next] || !tree[curNode][next]) continue;

				// Mark As Visited & Add to Queue
				visited[next] = true;
				queue.push_back(next);
			}
		}

		// Update Max Depth
		if (localCount > result) result = localCount;
	}
}

/*
알고리즘 선택 사고 과정
	초기 접근
		N -> MAX 500개, 완탐은 뭔가 시간 초과 뜰 것 같긴 한데...
		Binary Tree라는 보장이 없으니, 과연 Binary Tree 취급을 해도 되는 걸까?
		시작 지점을 정하는 것 또한 문제 -> 그냥 BFS나 DFS를 진행해야 하나? 라기엔 워프라는 조건이...
		"현재 위치"에서 "기존의 Selected"라는 조건들에 따라 다음 선택의 선택지가 다 달라짐 -> DP는 힘들지 않을까 싶음
		일단 그러니 완탐으로 구현이라도 해보자
		하지만 역시나 타임아웃하며 개같이 멸망
	대 황 킹 갓 짱 건희 형님의 조언: 그래프를 리버스해라
		연결되어 있는 것들을 연결되지 않음 처리하고
		연결되지 않은 것들을 연결됨 처리해버리면
		이 그래프는 곧 워프 가능한 포인트가 된다는 소리임
		또한 이렇게 될 경우 하나였던 트리가 여러 개의 그래프로 쪼개질 가능성이 생김
		그 그래프들을 모두 탐색해 주면 됨
			그 그래프들 안에서는 워프가 자유롭게 가능함, 따라서 그 그래프에 연결된 노드 개수가 곧 최대 워프 가능 횟수
		또한 그래프들이 여러 개로 쪼개질 수도 있다는 점이 있는데 최대 워프 횟수는 어떻게 되는가?
			그 모든 그래프들을 더해가며 보는 게 아니라, 그 그래프들 중 최대 규모만 찾으면 됨
			왜냐? 그 리버스 그래프에서 연결되어 있는 애들끼리만 워프가 가능하고, 그 다른 그래프들끼리는 워프가 불가능하다는 뜻

알고리즘 적용 방식
	1. 입력을 받고
	2. 그래프를 리버스한다
	3. 그 각각의 쪼개진 그래프들에 대해 BFS를 갈김
		3.1. 모든 노드를 보되 visited면 패스
		3.2. 아니면 BFS 갈기면서 최대 워프 횟수 구함
		3.3. 반복문을 탈출하여 BFS가 끝났을 때, 그 트리에서의 최대 워프 횟수가 기존 최대 워프 횟수보다 크면 갱신
	4. 결과 출력
*/