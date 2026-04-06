#include <iostream>
#include <algorithm>

using namespace std;

// Macros
#define MAX_N 1000

// Function Definitions
void init();
int dp(int left, int right, int turn);

// Global Variables
int TC, N, result;
int cards[MAX_N];
int dpTable[MAX_N][MAX_N][2];


// Main Function
int main() {
	// Initial Setting
	ios::sync_with_stdio(false);

	// Read # of Test Cases
	cin >> TC;

	// Loop for Each Test Cases
	for (int tc = 1; tc <= TC; tc++) {
		// Initialization
		init();

		// Print Result
		cout << dp(0, N - 1, 0) << endl;
	}
}


// Function Implementations
void init() {
	// Read N
	cin >> N;

	// Read Entire Cards
	for (int idx = 0; idx < N; idx++) cin >> cards[idx];

	// Initialize DP Table
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			dpTable[row][col][0] = -1;
			dpTable[row][col][1] = -1;
		}
	}
}

int dp(int left, int right, int turn) {
	// Base Condition
	if (left == right) {
		if (turn % 2 == 0) dpTable[left][right][turn % 2] = cards[left];
		else dpTable[left][right][turn % 2] = 0;
		return dpTable[left][right][turn % 2];
	}

	// Memoization
	if (dpTable[left][right][turn % 2] != -1) return dpTable[left][right][turn % 2];

	// My Turn
	if (turn % 2 == 0) return (dpTable[left][right][turn % 2] = max(cards[left] + dp(left + 1, right, turn + 1), cards[right] + dp(left, right - 1, turn + 1)));
	// Opposite Turn
	else return (dpTable[left][right][turn % 2] = min(dp(left + 1, right, turn + 1), dp(left, right - 1, turn + 1)));
}

/*
알고리즘 선택 사고 과정
	어디서 본 문제 같은데...
	단순히 현재 선택 가능한 것들 중 큰 값을 취하는 것만으로는 반례가 생김
		두 플레이어 모두 최선의 전략으로 임했다는 조건이 존재하기 때문
	점화식을 다음과 같이 정의해 보자: dp[l][r] = l ~ r 카드만 남았을 때 내가 얻을 수 있는 최대 점수

알고리즘 적용 방식
	1. init() 함수 사용으로 초기화
	2. dp() 함수 사용으로 결과 계산
	3. 결과 출력
*/