#include <iostream>
#include <deque>
#include <string>

using namespace std;

// Macros
#define MAX_NM 25

// Function Definitions
void init();
void bfs();
void find();
int convert(char c);
bool inRange(pair<int, int> coor);

// Global Variables
int N, M, T, D, result;
int map[MAX_NM][MAX_NM], fromHotel[MAX_NM][MAX_NM], toHotel[MAX_NM][MAX_NM];
deque<pair<int, int>> queue;
int delta[2][4] = {
	{-1, 0, 1, 0},
	{0, 1, 0, -1}
};


// Main Function
int main() {
	// Initial Setting
	ios::sync_with_stdio(false);

	// Initialization
	init();

	// Perform BFS
	bfs();

	// Find Result
	find();

	// Print Result
	cout << result << endl;
}


// Function Implementations
void init() {
	// Read N
	cin >> N >> M >> T >> D;

	// Read Map & Convert to Integer
	for (int row = 0; row < N; row++) {
		// Read Line
		string line;
		cin >> line;

		// Convert to Integer
		for (int col = 0; col < M; col++) map[row][col] = convert(line[col]);
	}

	// Initialize Variables
	result = 0;

	// Initialize Visited Array
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			fromHotel[row][col] = -1;
			toHotel[row][col] = -1;
		}
	}
}

void bfs() {
	// Hotel -> Each Point
	// Initialize Queue
	queue.clear();

	// Push Start Point to Queue & Mark As Visited
	queue.push_back(make_pair(0, 0));
	fromHotel[0][0] = 0;

	// Loop While Queue is Not Empty
	while (!queue.empty()) {
		// Pop Element
		pair<int, int> cur = queue.front();
		queue.pop_front();

		// Seek Near Edges
		for (int dir = 0; dir < 4; dir++) {
			// Next Coordinate
			pair<int, int> next = make_pair(cur.first + delta[0][dir], cur.second + delta[1][dir]);

			// Pass Condition
			if (!inRange(next)) continue;
			if ((map[cur.first][cur.second] - map[next.first][next.second] > T) || (map[cur.first][cur.second] - map[next.first][next.second] < -1 * T)) continue;

			// Cost to Move
			int cost;
			if (map[cur.first][cur.second] >= map[next.first][next.second]) cost = fromHotel[cur.first][cur.second] + 1;
			else cost = fromHotel[cur.first][cur.second] + (map[cur.first][cur.second] - map[next.first][next.second]) * (map[cur.first][cur.second] - map[next.first][next.second]);

			// Push Next Point to Queue & Mark As Visited
			if ((fromHotel[next.first][next.second] == -1) || (fromHotel[next.first][next.second] > cost)) {
				queue.push_back(next);
				fromHotel[next.first][next.second] = cost;
			}
		}
	}

	// Each Point -> Hotel
	// Initialize Queue
	queue.clear();

	// Push Start Point to Queue & Mark As Visited
	queue.push_back(make_pair(0, 0));
	toHotel[0][0] = 0;

	// Loop While Queue is Not Empty
	while (!queue.empty()) {
		// Pop Element
		pair<int, int> cur = queue.front();
		queue.pop_front();

		// Seek Near Edges
		for (int dir = 0; dir < 4; dir++) {
			// Next Coordinate
			pair<int, int> next = make_pair(cur.first + delta[0][dir], cur.second + delta[1][dir]);

			// Pass Condition
			if (!inRange(next)) continue;
			if ((map[cur.first][cur.second] - map[next.first][next.second] > T) || (map[cur.first][cur.second] - map[next.first][next.second] < -1 * T)) continue;

			// Cost to Move
			int cost;
			if (map[cur.first][cur.second] <= map[next.first][next.second]) cost = toHotel[cur.first][cur.second] + 1;
			else cost = toHotel[cur.first][cur.second] + (map[cur.first][cur.second] - map[next.first][next.second]) * (map[cur.first][cur.second] - map[next.first][next.second]);

			// Push Next Point to Queue & Mark As Visited
			if ((toHotel[next.first][next.second] == -1) || (toHotel[next.first][next.second] > cost)) {
				queue.push_back(next);
				toHotel[next.first][next.second] = cost;
			}
		}
	}
}

void find() {
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			// Pass Condition
			if ((fromHotel[row][col] == -1) || (toHotel[row][col] == -1)) continue;
			if (fromHotel[row][col] + toHotel[row][col] > D) continue;

			// Check & Update
			if (result < map[row][col]) result = map[row][col];
		}
	}
}

int convert(char c) {
	if (c >= 'A' && c <= 'Z') return (int)(c - 'A');
	return (int)(c - 'a') + 26;
}

bool inRange(pair<int, int> coor) {
	if (coor.first < 0 || coor.first >= N) return false;
	if (coor.second < 0 || coor.second >= M) return false;
	return true;
}

/*
알고리즘 선택 사고 과정
	어디서 본 문제 같은데...
	BFS를 두 번 돌려서 확인하는 방식으로 가보는 것이 어떨까
		  호텔 -> 각 점 도달하는 최소 시간
		+ 각 점 -> 호텔 도달하는 최소 시간
		--------------------------------
		호텔 -> 각 점 -> 호텔 도달하는 최소 시간
		이 값을 가지고 해당 좌표 값이 D보다 작은 값에 대해서 도달 가능한 최대 높이를 구하는 방식으로 가보자

알고리즘 적용 방식
	1. init() 함수 사용으로 초기화
	2. bfs() 함수 사용으로 이동 시간 계산
	3. find() 함수 사용으로 최대 높이 찾기
	4. 결과 출력
*/