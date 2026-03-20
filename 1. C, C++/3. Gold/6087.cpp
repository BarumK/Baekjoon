#include <iostream>
#include <deque>
#include <string>

using namespace std;

// Macros
#define MAX_WH 100
#define MAX_VAL 100000007
typedef pair<int, int> coor;
typedef pair<coor, int> QueueElement;

// Function Definitions
void init();
void bfs();
bool inRange(coor point);

// Global Variables
int H, W, result;
int visited[MAX_WH][MAX_WH][4];
coor points[2];
string map[MAX_WH];
deque<QueueElement> queue;
int direction[2][4] = {
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

	// Print Result
	cout << result << endl;
}


// Function Implementations
void init() {
	// Read H, W
	cin >> W >> H;

	// Initialize Variables
	result = MAX_VAL;
	queue.clear();

	// Temporal Variables
	int point = 0;

	// Read Entire Map
	for (int row = 0; row < H; row++) {
		// Read Line
		cin >> map[row];

		// Find 'C'
		for (int col = 0; col < W; col++) {
			if (map[row][col] == 'C') {
				points[point].first = row;
				points[point].second = col;
				point++;
			}
		}
	}

	// Initialize Visited Map
	for (int row = 0; row < H; row++) {
		for (int col = 0; col < W; col++) {
			for (int dir = 0; dir < 4; dir++) visited[row][col][dir] = -1;
		}
	}
}

void bfs() {
	// Mark Start Point as Visited & Push Start Point's Near Point to Queue
	for (int dir = 0; dir < 4; dir++) {
		// Mark Start Point
		visited[points[0].first][points[0].second][dir] = 0;

		// Next Point
		coor next = make_pair(points[0].first + direction[0][dir], points[0].second + direction[1][dir]);

		// Pass Condition
		if (!inRange(next) || (map[next.first][next.second] == '*')) continue;

		// Mark Near Point as Visited
		visited[next.first][next.second][dir] = 0;

		// Push Near Point to Queue
		queue.push_back(make_pair(next, dir));
	}

	// Loop While Queue is not Empty
	while (!queue.empty()) {
		// Pop Element
		QueueElement element = queue.front();
		queue.pop_front();

		// Current Information
		coor cur = element.first;
		int fromDir = element.second;

		// Seek Near Points
		for (int dir = 0; dir < 4; dir++) {
			// Next Point
			coor next = make_pair(cur.first + direction[0][dir], cur.second + direction[1][dir]);
			bool sameDirection = (dir == fromDir);
			int count = sameDirection ? visited[cur.first][cur.second][fromDir] : visited[cur.first][cur.second][fromDir] + 1;

			// Pass Condition
			if (!inRange(next) || (map[next.first][next.second] == '*')) continue;
			if ((visited[next.first][next.second][dir] != -1) && (visited[next.first][next.second][dir] <= count)) continue;

			// Mark Next Point as Visited
			visited[next.first][next.second][dir] = count;

			// Push to Queue
			queue.push_back(make_pair(next, dir));
		}
	}

	// Find Result
	for (int dir = 0; dir < 4; dir++) {
		if ((visited[points[1].first][points[1].second][dir] != -1) && (result > visited[points[1].first][points[1].second][dir])) result = visited[points[1].first][points[1].second][dir];
	}
}

bool inRange(coor point) {
	if (point.first < 0 || point.first >= H) return false;
	if (point.second < 0 || point.second >= W) return false;
	return true;
}

/*
알고리즘 선택 사고 과정
	visited 배열을 "단순히 해당 노드 방문 여부만을 판단" -> "특정 방향으로부터 들어온 상태로의 방문 여부"로 생각을 확장
	또한 그 안에 담는 값은 그 방향으로 들어오면서의 거울 개수를 의미
	BFS를 돌리면서 이전에 들어왔던 방향과 비교하고, 같으면 그대로 값을 넘겨주고 아닐 경우엔 거울을 둬야 하니 +1을 해서 넘겨줌
	마지막으로 그 visited 값을 업데이트할 때 기존에 먼저 값이 들어와있는 값이 최적이 아닐 수 있으니 갱신이 가능하다면 갱신하고 큐에 추가
		사실 이 부분은 먼저 왔다면 그 것이 최적이라는 것만 증명하면 되나 증명할 방법을 모르고 귀찮아서 그냥 이러한 방식으로 구현함

알고리즘 적용 방식
	1. init() 함수 통해 변수 및 배열 초기화
	2. bfs() 함수 통해 탐색
	3. 결과 출력
*/