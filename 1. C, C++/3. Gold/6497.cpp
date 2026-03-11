#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

// Macros
#define MAX_NODE_EDGE 200000
typedef pair<int, int> nodepair;
typedef pair<int, nodepair> edge;

// Function Definitions
void init();
void kruskal();
int find(int target);
void unionParent(int a, int b);
bool compare(edge a, edge b);

// Global Variables
int numHouses, numRoads, result;
edge edges[MAX_NODE_EDGE];
int parents[MAX_NODE_EDGE];


// Main Function
int main() {
	// Initial Setting
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// Loop While 0 0 Comes in
	while (true) {
		// Read # of Houses & # of Roads
		cin >> numHouses >> numRoads;

		// Break Condition
		if ((numHouses == 0) && (numRoads == 0)) break;

		// Initialization
		init();

		// Fill DP Table
		kruskal();

		// M Queries
		cout << result << endl;
	}
}


// Function Implementations
void init() {
	

	// Initialize Variables
	result = 0;

	// Read Road Information & Sort By Weight
	for (int idx = 0; idx < numRoads; idx++) {
		cin >> edges[idx].second.first >> edges[idx].second.second >> edges[idx].first;
		result += edges[idx].first;
	}
	sort(edges, edges + numRoads, compare);

	// Initialze Parents Array
	for (int idx = 0; idx < numHouses; idx++) parents[idx] = idx;
}

void kruskal() {
	for (int count = 0, index = 0; (count < numHouses - 1) && (index < numRoads); index++) {
		// Current Edge Information
		edge cur = edges[index];
		int weight = cur.first;
		nodepair nodes = cur.second;

		// Pass Condition
		if (find(nodes.first) == find(nodes.second)) continue;

		// Union
		unionParent(nodes.first, nodes.second);
		result -= weight;
	}
}

int find(int target) {
	if (parents[target] == target) return target;
	return (parents[target] = find(parents[target]));
}

void unionParent(int a, int b) {
	parents[find(a)] = parents[find(b)];
}

bool compare(edge a, edge b) {
	return a.first < b.first;
}

/*
알고리즘 선택 사고 과정
	문제 읽어 보니까 최소신장트리 냄새가 씨게 났음
	그래서 그냥 크루스칼 알고리즘 사용하자는 생각

알고리즘 적용 방식
	1. init()으로 변수 및 배열 초기화하고 그래프 구성
	2. kruskal() 함수로 최소신장트리의 합 계산
	3. 결과 출력
*/