#include <iostream>
#include <queue>
#include <deque>
#include <map>
#include <cmath>

using namespace std;

// Macros
#define MAX_N 50000
#define INF 999999999

// Function Definitions
void init();
void makeGraph();
void dijkstra();
void find();

// Global Variables
int N, F;
double result;
int coordinates[MAX_N + 1][2];
double dist[MAX_N + 1];
deque<int> finishPoints;
deque<pair<int, double>> graph[MAX_N + 1];
map<pair<int, int>, int> existance;
priority_queue<pair<double, int>> pq;
int delta[2][24] = {
	{-2, -1, 0, 1, 2, -2, -1, 0, 1, 2, -2, -1, 1, 2, -2, -1, 0, 1, 2, -2, -1, 0, 1, 2, },
	{-2, -2, -2, -2, -2, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2}
};


// Main Function
int main() {
	// Initial Setting
	ios::sync_with_stdio(false);
	
	// Initialization
	init();

	// Make Graph
	makeGraph();

	// Find Shortest Distance Using Dijkstra Algorithm
	dijkstra();

	// Find Result
	find();

	// Print Result
	cout << round(result) << endl;
}


// Function Implementations
void init() {
	// Read N, F
	cin >> N >> F;

	// Initialize STL Objects
	finishPoints.clear();
	for (int i = 0; i <= N; i++) graph[i].clear();
	existance.clear();
	while (!pq.empty()) pq.pop();

	// Initialize Lists
	coordinates[0][0] = 0;
	coordinates[0][1] = 0;
	dist[0] = 0;
	existance.insert({{0, 0}, 0});
	for (int i = 1; i <= N; i++) dist[i] = INF;

	// Read Each Points
	for (int i = 1; i <= N; i++) {
		cin >> coordinates[i][0] >> coordinates[i][1];
		if (coordinates[i][1] == F) finishPoints.push_back(i);
		existance.insert({{coordinates[i][0], coordinates[i][1]}, i});
	}
}

void makeGraph() {
	// Find Adjancy Nodes for Each Nodes
	for (int i = 0; i <= N; i++) {
		// Current Node Coordinate
		int curX = coordinates[i][0];
		int curY = coordinates[i][1];

		// If Adjancy Node Exists, Then Add to Graph
		for (int d = 0; d < 24; d++) {
			auto search = existance.find({curX + delta[0][d], curY + delta[1][d]});
			if (search != existance.end()) {
				// Calculate Distance
				pair<int, int> target = (*search).first;
				int index = (*search).second;
				double distance = sqrt((curX - target.first) * (curX - target.first) + (curY - target.second) * (curY - target.second));
				
				// Add Edge to Graph
				graph[i].push_back({index, distance});
			}
		}
	}

	// Free for Memory
	existance.clear();
}

void dijkstra() {
	// Push Start Point: {Cost, Desination Node #}
	pq.push({0, 0});

	while (!pq.empty()) {
		// Pop Element
		double cost = -pq.top().first;
		int current = pq.top().second;
		pq.pop();

		// If Not Shorter, Then Pass This Loop
		if (dist[current] < cost) continue;

		// Check & Update Adjancy List
		for (int i = 0; i < graph[current].size(); i++) {
			// Get Node Information
			int next = graph[current][i].first;
			double weight = graph[current][i].second;
			double updateDist = cost + weight;

			// If Found Shortest Path, Update Distance & Push to Priority Queue
			if (updateDist < dist[next]) {
				dist[next] = updateDist;
				pq.push({-updateDist, next});
			}
		}
	}
}

void find() {
	result = INF;
	for (int i = 0; i < finishPoints.size(); i++) result = (result < dist[finishPoints[i]]) ? result : dist[finishPoints[i]];
	result = (result == INF) ? -1 : result;
}

/*
알고리즘 선택 사고 과정
1. N이 최대 50000 -> BFS나 DFS로 갈 경우 N^2이 되기에 25억이 됨, 제한시간 2초이기에 무조건 타임아웃 발생
2. 따라서 무조건 NlogN 이하로 가야 한다는 생각
3. 그 과정에서 그래프 이론을 적용하려 하니까 NlogN의 시간 복잡도를 갖는 다익스트라 알고리즘이 생각남
4. 그러려면 좌표 상에 있는 점들을 그래프로 변환해야 하는데?
5. 한 번에 점프 가능한 범위: x, y좌표의 값 차이가 2 이내여야 한다는 조건을 확인함
6. 그렇게 된다면 좌표 상으로 24개씩만 보면 됨 -> 그래프를 형성하는 과정은 N개 점에 대해 24번씩 확인이기에 24N, 오버헤드가 다소 크더라도 선형임
7. 따라서 그래프화하는 과정은 주된 시간을 차지하지 않음, 다익스트라 알고리즘 적용을 최종 결정

알고리즘 적용 방식
1. 좌표를 전부 받음
2. 받는 과정에서 Map 하나를 같이 기록함 -> Key는 {x좌표, y좌표}의 pair이고 Value는 해당 노드의 인덱스 번호
3. 인덱스를 받은 후 그래프화 진행: 현재 위치 기준으로 주변 그 위치에 Map에 존재하면 그 좌표에 위치하는 노드의 인덱스 번호와 그 노드까지의 거리를 그래프에 추가
4. 최종적으로 형성된 그래프는 deque<pair<int, double>> graph[MAX_N + 1] 형태; 각 노드 인덱스 별로 인접 노드의 인덱스 및 거리 정보를 모아서 저장
5. 이 그래프를 이용해서 Priority Queue를 사용한 다익스트라 알고리즘 적용
	5.1. {거리 0, 시작점 인덱스 0} 을 초기에 pq에 넣고
	5.2. pq가 빌 때까지 계속 pop해가며 진행
	5.3. pop한 노드를 기준으로, 인접한 노드를 현재 그 노드를 통해 그 인접한 노드로 가는 경로가 기존에 알려진 경로보다 짧다면 최단거리 정보를 업데이트하고 pq에 그 정보를 push함
6. 마지막에 y좌표가 F인 점들 기준으로, 가장 최소인 거리를 확인. 만약 모두 INFINITY라면 도달 불가능하다는 것이기에 -1로 세팅
7. 최소 거리 출력
*/