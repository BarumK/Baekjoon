#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// Macros
#define MAX_N 100002
typedef pair<int, int> timeline; // <start, end>
typedef pair<int, int> computer; // <endtime, count>
typedef pair<int, int> mapping; // <endtime, index>

// Function Definitions
void init();
void greedy();
int findNext();

// Global Variables
int N, result, pointer;
timeline timelines[MAX_N];
computer computers[MAX_N];
priority_queue<mapping> pq;

// Main Function
int main() {
	// Initial Setting
	ios::sync_with_stdio(false);

	// Initialization
	init();

	// Perform Greedy algorithm
	greedy();

	// Print Result
	cout << result << endl;
	for (int idx = 1; idx <= result; idx++) cout << computers[idx].second << " ";
}


// Function Implementations
void init() {
	// Read N
	cin >> N;

	// Initialize Variables
	result = 0;
	pointer = 1;
	while (!pq.empty()) pq.pop();

	// Initialize Array
	for (int idx = 1; idx <= N + 1; idx++) {
		computers[idx].first = -1;
		computers[idx].second = 0;
	}

	// Read Information
	for (int idx = 0; idx < N; idx++) cin >> timelines[idx].first >> timelines[idx].second;

	// Sort Timeline Array
	sort(timelines, timelines + N);
}

void greedy() {
	// Loop for All Timelines
	for (int idx = 0; idx < N;) {
		// Current Timeline
		timeline cur = timelines[idx];
		mapping top = (pq.empty()) ? mapping{-1, -1} : pq.top();

		// Compare
		if ((top.first == -1) || (cur.first < -1 * top.first)) {
			// Mark
			computers[pointer].first = cur.second;
			computers[pointer].second++;

			// Push
			pq.push(make_pair(-cur.second, pointer));

			// Update Pointer
			pointer = findNext();

			// Adjust Index
			idx++;
		}
		else {
			// Unmark
			computers[top.second].first = -1;

			// Update Pointer
			if (top.second < pointer) pointer = top.second;

			// Pop
			pq.pop();
		}
	}

	// Find Result
	for (int idx = 1; idx <= N + 1; idx++) {
		if (computers[idx].second == 0) {
			result = idx - 1;
			break;
		}
	}
}

int findNext() {
	for (int idx = pointer + 1; idx <= N; idx++) {
		if (computers[idx].first == -1) return idx;
	}
	return N + 1;
}

/*
알고리즘 선택 사고 과정
	시간 정렬해서 최대한으로 놀이기구를 타는 문제가 오마주되었음
	그래서 우선 시작 시간 순으로 정렬하고 그 이후에 현재 사용중인 애들만 우선순위 큐에 넣어서 넣을지 뺄지를 비교하는 방식을 사용
	다음 번호를 찾는 부분이 약간 느려질 요소가 보이긴 함

알고리즘 적용 방식
	1. init() 함수 통해 변수 및 배열 초기화
	2. greedy() 함수 통해 계산
	3. 결과 출력
*/