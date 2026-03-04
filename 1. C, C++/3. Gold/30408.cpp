#include <iostream>
#include <deque>
#include <unordered_set>
#include <string>

using namespace std;

// Macros


// Function Definitions
void init();
void check();

// Global Variables
long long N, M;
string result;
deque<long long> queue;
unordered_set<long long> alreadyChecked;

// Main Function
int main() {
	// Initial Setting
	ios::sync_with_stdio(false);

	// Initialization
	init();

	// Check
	check();

	// Print Result
	cout << result << endl;
}


// Function Implementations
void init() {
	// Read N, M
	cin >> N >> M;

	// Initialize Queue & Hash Set
	queue.clear();
	alreadyChecked.clear();
}

void check() {
	// Add Initial Point to Queue
	alreadyChecked.insert(N);
	queue.push_back(N);

	// Loop While Queue is Empty
	while (!queue.empty()) {
		// Pop Element
		long long cur = queue.front();
		queue.pop_front();

		// Check
		if (cur == M) {
			result = "YES";
			return;
		}

		// Push Next Number to Queue
		if (alreadyChecked.find(cur / 2) == alreadyChecked.end()) {
			alreadyChecked.insert(cur / 2);
			queue.push_back(cur / 2);
		}
		if ((cur % 2 != 0) && (alreadyChecked.find((cur / 2) + 1) == alreadyChecked.end())) {
			alreadyChecked.insert((cur / 2) + 1);
			queue.push_back((cur / 2) + 1);
		}
	}

	// If Not Found, Set Result to "NO"
	result = "NO";
}

/*
알고리즘 선택 사고 과정
	일단 가장 먼저 짚고 넘어가야 하는 점: 입력 N이 무지막지하게 크다, int 범위 안에 안들어가니까 long long으로 처리해야 할듯
	중복되는 값이 많아서 그 상태에서 DP를 적용할까 생각했으나 굳이 DP를 사용해서 전부 구하는 데는 너무 과잉으로 컴퓨팅 자원을 소모하는 느낌
		-> 따라서, 이 대신 메모이제이션을 가져와 팔요한 값만 계산하고 이미 탐색한 적 있는지 확인하는 용도로만 사용하자
			M을 다른 값으로 계속 쿼리를 주는 구조였다면 DP 쓰는 것도 좋았을 것으로 생각됨
		-> 또한 계속 절반씩 줄여나가고 호출하는 구조이기에, 어떻게 보면 호출 구조가 트리같아서 BFS를 활용하면 될 것으로 보임
			정말 최악의 경우에 만에 하나 재귀로 구현했다가 스택 오버플로가 날 수 있기에 큐를 사용하는 것이 나아 보임
				사실 저 최대 입력의 log 깊이만큼만 줄여나가는거라 그렇게 오버헤드가 발생할 것 같진 않음
				그리고 함수 재귀 호출로 하면 오버헤드가 있기 때문에 그 부분을 줄이기도 해서 나쁘지 않을 것으로 보임
	또한 이 탐색 자체가 정수를 절반으로 쪼개는거라 짝수의 경우 동일한 값 하나만 탐색해도 됨

알고리즘 적용 방식
	1. init() 통해 입력 받고
	2. check() 통해 확인하고
	3. 결과 출력
*/