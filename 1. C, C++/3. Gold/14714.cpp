#include <iostream>
#include <deque>

using namespace std;

// Macros
#define MAX_N 500

// User-Defined Structure
struct State {
	int depth;
	int turn; // 0: A Move, 1: B Move
	int A;
	int B;
};

// Function Definitions
void init();
int next(int cur, int delta);
void bfs();

// Global Variables
int N, A, B, DA, DB;
int result, findAnswer;
bool visited[2][MAX_N][MAX_N];
deque<State> queue;


// Main Function
int main() {
	// Initial Setting
	ios::sync_with_stdio(false);

	// Initialization
	init();

	// Perform BFS
	bfs();

	// Print Result
	if (findAnswer) cout << result;
	else cout << "Evil Galazy";
}


// Function Implementations
void init() {
	// Read Input Variables
	cin >> N >> A >> B >> DA >> DB;
	
	// Use 0-Index
	A--; B--;

	// Initialize Variables
	result = -1;
	findAnswer = 0;

	// Initialize Visited Map
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[0][i][j] = false;
			visited[1][i][j] = false;
		}
	}
}

int next(int cur, int delta) {
	// Return Index of Point "delta" Amount Far Away From cur
	return ((cur + N) + delta) % N;
}

void bfs() {
	// Push Initial State
	queue.push_back({0, 0, A, B});

	// Loop While Queue is Empty
	while (!queue.empty()) {
		// Pop Element
		State cur = queue.front();
		queue.pop_front();

		// Set Visited
		visited[cur.turn][cur.A][cur.B] = true;

		// Check Infinity
		if (cur.depth && (cur.turn == 0) && (cur.A == A) && (cur.B == B)) continue;

		// Check Turn
		if (cur.turn == 0) {
			// Break Condition: Game Ends
			if ((next(cur.A, DA) == cur.B) || (next(cur.A, -DA) == cur.B)) {
				result = cur.depth + 1;
				findAnswer = 1;
				break;
			}

			// Set Visited & Add Next State to Queue
			if (visited[1][next(cur.A, DA)][cur.B] == false) {
				visited[1][next(cur.A, DA)][cur.B] = true;
				queue.push_back({ cur.depth + 1, 1, next(cur.A, DA), cur.B });
			}
			if (visited[1][next(cur.A, -DA)][cur.B] == false) {
				visited[1][next(cur.A, -DA)][cur.B] = true;
				queue.push_back({ cur.depth + 1, 1, next(cur.A, -DA), cur.B });
			}
		}
		else {
			// Break Condition: Game Ends
			if ((next(cur.B, DB) == cur.A) || (next(cur.B, -DB) == cur.A)) {
				result = cur.depth + 1;
				findAnswer = 1;
				break;
			}

			// Add Next State to Queue
			if (visited[0][cur.A][next(cur.B, DB)] == false) {
				visited[0][cur.A][next(cur.B, DB)] = true;
				queue.push_back({ cur.depth + 1, 0, cur.A, next(cur.B, DB) });
			}
			if (visited[0][cur.A][next(cur.B, -DB)] == false) {
				visited[0][cur.A][next(cur.B, -DB)] = true;
				queue.push_back({ cur.depth + 1, 0, cur.A, next(cur.B, -DB) });
			}
		}
	}
}

/*
알고리즘 선택 사고 과정
	초기 접근
		1. 완전탐색? 무한 루프도 있으니 불가하지 않을까? 컽
		2. 서로가 무조건 가까워지는 쪽으로 이동하면 될까? 첫 예제부터 반례네? 컽
		3. 그냥 모두 다 시뮬레이션? 어떻게? 컽
		4. 그렇다면 한 번에 구할 수 있는 수학 공식인가? 아무리 생각해도 생각이 안나네? 컽
		5. DP? 점화식이 가능은 한가? 한쪽도 아니고 양방향으로 두 개가 날뛰는데? 컽
		6. 무한 루프가 되는 조건? 모르겠는데? 컽
	이렇게 아무 해답을 찾지 못한 상황에서 "최소 턴 수"를 구하는 것이기에 BFS를 쓰라는 스터디원들의 팁을 받음
	그래서 일단 BFS로 구현을 하자라는 생각으로 코딩을 함
		근데 구현하고 보니까 DFS라서 메모리도 터지고 시간도 터지고 답도 틀리고 멘탈도 터져버림
		DFS가 아니면 어떻게 두 방향의 선택지를 탐색 후 복구 없이 쭉 트리 안쪽으로 파고 들어갈 수만 있을까?
		그냥 현재 턴 진행 수, 누구 턴인지, 현재 A 좌표가 어딘지, 현재 B 좌표가 어딘지의 값을 묶어서 하나의 State로 두면 되겠구나!
			-> 이 4개를 묶은 하나의 구조체 생성
	그렇게 종료 조건을 턴, A좌표, B좌표가 초기랑 동일하게 하면 답은 맞으나 매우 큰 케이스에서 메모리랑 시간이 터지는 문제가 발생함
		그러면 분기 쳐내는 것을 더 빡세게 해야 할 듯 싶은데, 어떻게 해야 할까?
		생각해 보니까 턴, 현재 A 좌표, 현재 B 좌표가 동일하면 그 이후는 똑같은 반복이 계속되는 점
		그러니까 그 3개를 변수로 가지는 visited를 만들고 기록하면 가지치기가 빨라지겠구나 싶었음
	그래서 했더니 문제가 해결됨
	아니? 사실 해결 안됨
		testcase.ac에서는 문제없는데 백준가서 제출 갈기니까 메모리 터짐
		그래서 visited를 int -> bool로 했는데도 터짐
		알고보니 visited 마킹 순서를 잘못 지정했던 것이었던 것...

알고리즘 적용 방식
	1. 일단 변수들 받고 초기화 전부 싹 때려준 다음에
	2. BFS 호출을 때려준다
		2.1. State를 Pop해서
		2.2. 종료가 가능한지 체크
			2.2.1. 가능하다면 결과 기록하고 바로 스탑
			2.2.2. 불가능하다면 다음 State를 큐에 넣고 패스
	3. 다 끝나고 나서 결과 따라 출력
*/