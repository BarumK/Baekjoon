#include <iostream>

using namespace std;

// Macros
#define MAX_NK 100

// Function Definitions
void init();
void dp();
void print();

// Global Variables
int T, N, K;
int dpTable[MAX_NK + 1][MAX_NK + 1][2];


// Main Function
int main() {
	// Initial Setting
	ios::sync_with_stdio(false);

	// Initialization
	init();

	// Perform DP
	dp();

	// Print Result
	print();
}


// Function Implementations
void init() {
	// Read T
	cin >> T;

	// Initialize DP Table
	dpTable[1][0][0] = 1;
	dpTable[1][0][1] = 1;
}

void dp() {
	for (int n = 2; n <= MAX_NK; n++) {
		for (int k = 0; k <= MAX_NK; k++) {
			// Last Bit Is 0
			dpTable[n][k][0] = dpTable[n - 1][k][0] + dpTable[n - 1][k][1];

			// Last Bit Is 1
			dpTable[n][k][1] = dpTable[n - 1][k][0];
			if (k > 0) dpTable[n][k][1] += dpTable[n - 1][k - 1][1];
		}
	}
}

void print() {
	for (int t = 0; t < T; t++) {
		// Read N, K
		cin >> N >> K;

		// Print Result
		cout << (dpTable[N][K][0] + dpTable[N][K][1]) << '\n';
	}
}

/*
알고리즘 선택 사고 과정
	또 DP
	점화식 설명
		길이가 n인 이진 수열은 길이 n-1 수열 뒤에 0 또는 1을 붙여 만들 수 있다.

		1. 마지막 비트가 0인 경우
			0을 붙이면 인접한 1의 개수는 증가하지 않으므로
			dp[n][k][0] = dp[n-1][k][0] + dp[n-1][k][1]

		2. 마지막 비트가 1인 경우
			이전 비트가 0이면 증가 없음
			이전 비트가 1이면 인접한 1의 개수 +1 증가

			dp[n][k][1] = dp[n-1][k][0] + dp[n-1][k-1][1]

		최종 결과
			dp[n][k][0] + dp[n][k][1]

알고리즘 적용 방식
	1. init() 함수 사용으로 초기화
	2. dp() 함수 사용으로 dp 계산
	3. print() 함수 사용으로 결과 출력
*/