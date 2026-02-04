#include <iostream>
#include <deque>
#include <unordered_set>

using namespace std;

// Macros
#define MAX_N 300000

// Function Definitions
void init();
void bfs();
bool inRangeCheck(long long index);

// Global Variables
int N, K;
long long L, light1, light2;
deque<pair<long long, int>> queue;
unordered_set<long long> visited;


// Main Function
int main() {
	// Initial Setting
	ios::sync_with_stdio(false);

	// Initialization
	init();

	// Perform BFS
	bfs();
}


// Function Implementations
void init() {
	// Read L, N, K(First Line)
	cin >> L >> N >> K;

	// Initialize STL Objects
	queue.clear();
	visited.clear();

	// Read Light Points & Add to Queue
	for (int idx = 0; idx < N; idx++) {
		// Read Light Point
		long long temp;
		cin >> temp;

		// Mark As Visited & Add to Queue
		visited.insert(temp);
		queue.push_back(make_pair(temp, 0));
	}
}

void bfs() {
	// Do While Queue is Not Empty And K is Not 0
	while ((!queue.empty()) && (K > 0)) {
		// Pop Element
		long long coordinate = queue[0].first;
		int darkness = queue[0].second;
		queue.pop_front();

		// Print Darkness & Decrease K
		cout << darkness << '\n';
		K--;

		// Push Near Node If Not Visited Yet
		if (inRangeCheck(coordinate + 1)) {
			visited.insert(coordinate + 1);
			queue.push_back(make_pair(coordinate + 1, darkness + 1));
		}
		if (inRangeCheck(coordinate - 1)) {
			visited.insert(coordinate - 1);
			queue.push_back(make_pair(coordinate - 1, darkness + 1));
		}
	}
}

bool inRangeCheck(long long index) {
	if (index < 0) return false;
	if (index > L) return false;
	if (visited.find(index) != visited.end()) return false;
	return true;
}

/*
알고리즘 선택 사고 과정
- 1차 판단:
	L이 엄청나게 크고(long long 범위 안)
	어두운 정도는 단순히 가로등과의 거리로만 고려하기 때문에
	가로등을 2개씩만 저장해 두고 그 안에서 처리하면 될 것으로 생각을 했었음
		왜? 어차피 두 좌표 주어지면 그 안에서는 밝기가 무조건 대칭적이니까
	그래서 구현을 했는데, 그 결과들을 저장하는 과정에서 엄청나게 큰 오버헤드가 소요
		배열이든 map이든 매번 새로운 어두움 정도가 나오면 그거의 위치를 찾아서 넣고 밀기가 필요해서
		그래서 구현을 해서 제출해봤더니 타임아웃이 뜨더라
- 2차 판단: 도저히 생각이 안나서 BFS라는 것까지는 힌트를 인터넷에서 구함
	처음에 받는 가로등을 기준으로, 좌표와 어두움 정도의 pair를 구성해서 큐에 넣고 BFS 돌리면 되겠다는 생각
	그렇게 될 경우 인접한 노드는 좌우 뿐이며, 방문하지 않았을 경우에만 큐에 추가하는 방식으로 진행
	그렇게 구현을 했더니 답은 맞았는데 또 타임아웃이 뜨더라
	알고보니 endl 사용해서 그런 거라는 것을 까먹고 있었다, endl 대신 '\n'을 쓰자

알고리즘 적용 방식
초기에 전부 초기화하고
처음 가로등 위치들은 {좌표, 어두움정도(0)}의 pair로 바로 큐에 push함
push하며 visited를 true로 바꿈
이후 큐가 비거나 출력 제한인 K회에 도달하기 전까지만 반목문 진행
	pop하고
	좌표랑 어두움 정도 뽑아낸 다음에
	출력하고
	만약 인접 노드가 아직 방문 전이라면 방문했다고 마킹하고 큐에 집어넣기
*/