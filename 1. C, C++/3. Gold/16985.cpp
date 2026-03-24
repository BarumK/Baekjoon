#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

// Macros
#define MAP_SIZE 5
#define POINT_NUM 4
#define ROTATE_DIR 4
struct coor { int x, y, z; };

// Function Definitions
void init();
void findIdx();
void findDir(int depth);
void makeMap();
void bfs(int point);
bool inRange(coor point);

// Global Variables
int result;
int selectedDir[MAP_SIZE];
int selectedIdx[MAP_SIZE];
int input[MAP_SIZE][MAP_SIZE][MAP_SIZE];
int map[MAP_SIZE][MAP_SIZE][MAP_SIZE];
bool visited[MAP_SIZE][MAP_SIZE][MAP_SIZE];
deque<pair<coor, int>> queue;
coor startPoint[POINT_NUM] = { 
	{0, 0, 0},
	{0, 0, MAP_SIZE - 1},
	{0, MAP_SIZE - 1, 0},
	{0, MAP_SIZE - 1, MAP_SIZE - 1}
};
coor endPoint[POINT_NUM] = {
	{MAP_SIZE - 1, MAP_SIZE - 1, MAP_SIZE - 1},
	{MAP_SIZE - 1, MAP_SIZE - 1, 0},
	{MAP_SIZE - 1, 0, MAP_SIZE - 1},
	{MAP_SIZE - 1, 0, 0}
};
int delta[6][3] = {
	{1, 0, 0}, 
	{-1, 0, 0},
	{0, 1, 0},
	{0, -1, 0},
	{0, 0, 1},
	{0, 0, -1}
};


// Main Function
int main() {
	// Initial Setting
	ios::sync_with_stdio(false);

	// Initialization
	init();

	// Perform BFS
	findIdx();

	// Print Result
	cout << result << endl;
}


// Function Implementations
void init() {
	// Read Entire Map
	for (int idx = 0; idx < MAP_SIZE; idx++) {
		for (int row = 0; row < MAP_SIZE; row++) {
			for (int col = 0; col < MAP_SIZE; col++) cin >> input[idx][row][col];
		}
	}

	// Initialize Variables
	result = -1;
	queue.clear();
}

void findIdx() {
	// Initialize Selected Array
	for (int idx = 0; idx < MAP_SIZE; idx++) selectedIdx[idx] = idx;

	// Select Stack Index Using Next Permutation
	do {
		findDir(0);
	} while (next_permutation(selectedIdx, selectedIdx + MAP_SIZE));
}

void findDir(int depth) {
	// Break Condition
	if (depth == MAP_SIZE) {
		makeMap();
		for (int point = 0; point < POINT_NUM; point++) bfs(point);
		return;
	}

	// Select
	for (int idx = 0; idx < ROTATE_DIR; idx++) {
		selectedDir[depth] = idx;
		findDir(depth + 1);
	}
}

void makeMap() {
	// Rotate Map
	for (int idx = 0; idx < MAP_SIZE; idx++) {
		for (int row = 0; row < MAP_SIZE; row++) {
			for (int col = 0; col < MAP_SIZE; col++) {
				// Rotate & Copy Map
				switch (selectedDir[idx]) {
					// Degree 0
					case 0:
						map[selectedIdx[idx]][row][col] = input[idx][row][col];
						break;
					// Degree 90
					case 1:
						map[selectedIdx[idx]][col][MAP_SIZE - 1 - row] = input[idx][row][col];
						break;
					// Degree 180
					case 2:
						map[selectedIdx[idx]][MAP_SIZE - 1 - row][MAP_SIZE - 1 - col] = input[idx][row][col];
						break;
					// Degree 270
					case 3:
						map[selectedIdx[idx]][MAP_SIZE - 1 - col][row] = input[idx][row][col];
						break;
					// Default Case: Not Use
					default: break;
				}
			}
		}
	}
}

void bfs(int point) {
	// Initialize Queue
	queue.clear();

	// Initizlize Visited Array
	for (int idx = 0; idx < MAP_SIZE; idx++) {
		for (int row = 0; row < MAP_SIZE; row++) {
			for (int col = 0; col < MAP_SIZE; col++) visited[idx][row][col] = false;
		}
	}

	// Start & End Point
	coor start = startPoint[point];
	coor end = endPoint[point];

	// Early Stopping
	if ((map[start.x][start.y][start.z] == 0) || (map[end.x][end.y][end.z] == 0)) return;

	// Mark As Visited & Push Start to Queue
	visited[start.x][start.y][start.z] = true;
	queue.push_back(make_pair(start, 0));

	// Loop While Queue is Not Empty
	while (!queue.empty()) {
		// Pop Element
		coor cur = queue.front().first;
		int distance = queue.front().second;
		queue.pop_front();

		// Check Current Point is End Point
		if ((cur.x == end.x) && (cur.y == end.y) && (cur.z == end.z)) {
			if ((result == -1) || (distance < result)) result = distance;
			return;
		}

		// Seek Near Nodes
		for (int dir = 0; dir < 6; dir++) {
			// Next Point
			coor next = {cur.x + delta[dir][0], cur.y + delta[dir][1], cur.z + delta[dir][2]};

			// Pass Condition
			if (!inRange(next) || (map[next.x][next.y][next.z] == 0) || (visited[next.x][next.y][next.z] == true)) continue;

			// Mark As Visited & Push to Queue
			visited[next.x][next.y][next.z] = true;
			queue.push_back(make_pair(next, distance + 1));
		}
	}
}

bool inRange(coor point) {
	if (point.x < 0 || point.x >= MAP_SIZE) return false;
	if (point.y < 0 || point.y >= MAP_SIZE) return false;
	if (point.z < 0 || point.z >= MAP_SIZE) return false;
	return true;
}

/*
알고리즘 선택 사고 과정
	완탐을 하자 + BFS를 하자

알고리즘 적용 방식
	1. init() 함수 통해 변수 및 배열 초기화
	2. findIdx() 함수 통해 판 쌓는 순서 결정
	3. findDir() 함수 통해 각 회전 방향 결정
	4. makeMap() 함수 통해 회전 방향에 맞는 맵 생성
	5. bfs() 함수 통해 그 맵에서의 최단거리 계산 후 최소값 갱신 여부 판단
	6. 결과 출력
*/