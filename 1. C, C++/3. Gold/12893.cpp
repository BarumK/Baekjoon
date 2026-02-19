#include <iostream>
#include <deque>

using namespace std;

// Macros
#define MAX_N 2000
#define MAX_M 1000000

// Function Definitions
void init();
void bfs();

// Global Variables
int N, M, result;
deque<int> graph[MAX_N + 1];
int visited[MAX_N + 1];
deque<pair<int, int>> queue;


// Main Function
int main() {
	// Initial Setting
	ios::sync_with_stdio(false);

	// Initialization
	init();

	// Perform BFS & Judge If Graph is Bipartite Graph
	bfs();

	// Print Result
	cout << result << endl;
}


// Function Implementations
void init() {
	// Initialize Variables
	result = 1;
	queue.clear();

	// Read N, M
	cin >> N >> M;

	// Initialize Graph & Visited Array
	for (int i = 0; i <= N; i++) {
		graph[i].clear();
		visited[i] = 0;
	}

	// Read Edge Information
	for (int idx = 0; idx < M; idx++) {
		// Read Edge
		int from, to;
		cin >> from >> to;

		// Add Edge Information to Graph
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
}

void bfs() {
	// For All Nodes
	for (int start = 1; start <= N; start++) {
		// Pass Condition: Already Visited
		if (visited[start] != 0) continue;

		// If Not Visited, Mark As 1 and Add to Queue
		visited[start] = 1;
		queue.push_back(make_pair(start, visited[start]));

		// Loop While Queue is Empty
		while (!queue.empty()) {
			// Pop Element
			int cur = queue.front().first;
			int curColor = queue.front().second;
			queue.pop_front();

			// For All Adjancy Nodes of Current Node
			for (int idx = 0; idx < graph[cur].size(); idx++) {
				// Next Point & Color
				int next = graph[cur][idx];
				int nextColor = (curColor == 1) ? 2 : 1;

				// Not Visited -> Mark & Add to Queue
				if (visited[next] == 0) {
					visited[next] = nextColor;
					queue.push_back(make_pair(next, nextColor));
				}

				// Visited -> Check Color
				else {
					if (visited[next] != nextColor) {
						result = 0;
						return;
					}
				}
			}
		}
	}
}

/*
알고리즘 선택 사고 과정
	예시 그래프 그려보니까 Bipartite Graph의 형태로 되는 것을 확인함 -> 그러면 받은 그래프가 Bipartite Graph가 되는지 확인하면 될 듯
	그래프를 받고 -> 그 그래프가 Bipartite Graph인지 확인해서 결과를 출력
	BFS를 적용하되 한 단계 더 보는 식을 적용하면 되지 않을까 싶음
		visited를 단순히 "방문했다"가 아니라 "색깔 칠하기"로 감
		방문 안하면, 색칠하고(기존의 BFS)
		방문했다면, 기록된 색이랑 지금 노드에 의해 칠해야 하는 색이 동일한지 판단하기(추가)
			다르다면, 더 볼 필요도 없이 Bipartite Graph가 아닌거고
			끝까지 유지된다면 Bipartite Graph라는거고

알고리즘 적용 방식
	1. 입력을 받는다
		1.1. 그걸 가지고 그래프를 일단 만든다
		1.2. 변수들을 초기화해서 세팅해준다
	2. BFS를 돌린다
		2.1. 초기 점 아무거나 임의로 1로 색칠하여 시작하고
		2.2. 큐가 빌 때까지 무한반복
			2.2.1. 만약 자식 노드가 방문하지 않았다면 지금 노드의 색과 반대되는 색으로 마킹
			2.2.2. 만약 자식 노드가 이미 방문했다면, 지금 노드의 색에 반대되는 색과 이미 기록되어 있는 색이 일치한지를 확인
				2.2.2.1. 일치하지 않는다면 Break하고 결과를 False로 함
		2.3. 모순 없이 다 돌았다면, 결과가 True임
	3. 결과에 따라 가능한지 불가능한지 출력
*/