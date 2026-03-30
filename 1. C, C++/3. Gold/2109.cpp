#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Macros
#define MAX_VAL 10000

// Function Definitions
void init();
void greedy();
bool compare(pair<int, int> a, pair<int, int> b);

// Global Variables
int N, result;
pair<int, int> suggests[MAX_VAL];
priority_queue<int, vector<int>, greater<int>> pq;


// Main Function
int main() {
	// Initial Setting
	ios::sync_with_stdio(false);

	// Initialization
	init();

	// Perform Greedy Algorithm
	greedy();

	// Print Result
	cout << result << endl;
}


// Function Implementations
void init() {
	// Read N
	cin >> N;

	// Read Days & Pays
	for (int idx = 0; idx < N; idx++) cin >> suggests[idx].second >> suggests[idx].first;
	sort(suggests, suggests + N, compare);

	// Initialize Variables
	result = 0;
	while (!pq.empty()) pq.pop();
}

void greedy() {
	for (int idx = 0; idx < N; idx++) {
		// Current Information
		int curTime = suggests[idx].first;
		int curPay = suggests[idx].second;

		// Seek Priority Queue
		if (pq.size() < curTime) {
			pq.push(curPay);
			result += curPay;
		}
		else {
			if (pq.top() < curPay) {
				result -= pq.top();
				pq.pop();
				pq.push(curPay);
				result += curPay;
			}
		}
	}
}

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return (a.second > b.second);
	return (a.first < b.first);
}

/*
알고리즘 선택 사고 과정
	그리디인가?
	우선 모든 제안들을 데드라인 오름차순(같을 경우 페이 내림차순)으로 정렬
	타임라인을 하나씩 늘려가면서, 저 제안들 중에서 가능한 선택지 중 빠른 순서대로 페이가 높은 것을 기준으로 매 타임라인마다 갈 강연을 선택
	하려고 했으나 반례가 발생해버림: 빠른거 먼저 선택 말고 늦게 끝나는 쪽에 더 값이 높은 것들이 몰려서 그거를 선택하는 게 더 가치있다면?
		즉 "지금 넣는 선택이 나중의 더 큰 이익을 막을 수 있음"을 고려하지 못함
	그래서 바꾼 방식
		정렬 자체는 동일함
		하지만 이 시간 순으로 정렬된 값들에 대해, "현재 데드라인까지는 최대 "현재 데드라인"개만큼의 강의만 뛸 수 있음"
		만약 우선순위 큐의 크기가 현재 데드라인보다 크거나 같으면서 현재 보고 있는 값이 큐의 Top보다 더 크다면, 저 MIN Heap으로 구현된 Top 값을 빼고 지금 더 페이를 잘 주는 강의를 선택

알고리즘 적용 방식
	1. init() 함수 사용으로 초기화
	2. greedy() 함수 사용으로 최댓값 계산
	3. 결과 출력
*/