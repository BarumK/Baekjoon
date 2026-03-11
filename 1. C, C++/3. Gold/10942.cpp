#include <iostream>

using namespace std;

// Macros
#define MAX_N 2000

// Function Definitions
void init();
void dp();
void query();

// Global Variables
int N, M, S, E;
int target[MAX_N + 1];
int dpTable[MAX_N + 1][MAX_N + 1];


// Main Function
int main() {
	// Initial Setting
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// Initialization
	init();

	// Fill DP Table
	dp();

	// M Queries
	query();
}


// Function Implementations
void init() {
	// Read N
	cin >> N;

	// Read Target Array
	for (int idx = 1; idx <= N; idx++) cin >> target[idx];
	
	// Read M
	cin >> M;
}

void dp() {
	for (int gap = 0; gap < N; gap++) {
		for (int start = 1; start <= N - gap; start++) {
			// Variables
			int end = start + gap;

			// Fill DP Table
			if (start == end) dpTable[start][end] = 1;
			else if (start + 1 == end) dpTable[start][end] = (target[start] == target[end]) ? 1 : 0;
			else {
				if (dpTable[start + 1][end - 1] == 0) dpTable[start][end] = 0;
				else dpTable[start][end] = (target[start] == target[end]) ? 1 : 0;
			}
		}
	}
}

void query() {
	for (int idx = 0; idx < M; idx++) {
		// Read S, E
		cin >> S >> E;

		// Print Result
		cout << dpTable[S][E] << '\n';
	}
}

/*
알고리즘 선택 사고 과정
	시간이 엄청 타이트하고 동일한 배열에 대해 M개의 여러 구간에 대한 쿼리가 들어오는 조건이라 단순히 하라고 하면 무조건 타임아웃 날 것으로 보임
	그래서 DP 느낌으로 가야하지 않을까라는 생각을 함
	KMP 알고리즘이랑 Failure Function을 써야 하나? 라는 생각이 잠시 스쳐 지나감
	일단은 KMP 관련은 패스하고, 점화식을 생각해 보자
		dpTable: [start][end]의 2차원 배열 -> dpTable[start][end]는 "start번째 수부터 end번째 까지 수가 팰린드롬을 이루는지의 여부"를 의미, 1이면 참이고 0이면 거짓
		기저 조건:
			(start == end)이면 1
			(start + 1 == end)이면 (target[start] == target[end]) ? 1 : 0
		점화식: 
			(dpTable[start + 1][end - 1] == 0)이면 0
			(dpTable[start + 1][end - 1] == 1)이면 (target[start] == target[end]) ? 1 : 0
		점화식 써가면서 테이블이 채워지는 방식을 보니 사선 DP인 것을 확인해버림
	시간초과 난 것은 cin.tie() 안 한 것과 \n을 안쓰고 처음에 endl을 사용하려 했던 것 때문

알고리즘 적용 방식
	1. init()으로 변수 및 배열 초기화하고
	2. dp() 함수로 테이블을 구성하고
	3. M개의 Query에 대해 query() 함수 호출하여 결과 출력
*/