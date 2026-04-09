#include <iostream>
#include <algorithm>

using namespace std;

// Macros
#define MAX_HP 60
#define MAX_VAL 100000007

// Function Definitions
void init();
int search(int a, int b, int c);

// Global Variables
int N;
int input[3];
int dpTable[MAX_HP + 1][MAX_HP + 1][MAX_HP + 1];
int attack[3] = {1, 3, 9};


// Main Function
int main() {
	// Initial Setting
	ios::sync_with_stdio(false);

	// Initialization
	init();

	// Print Result
	cout << search(input[0], input[1], input[2]) << endl;
}


// Function Implementations
void init() {
	// Read N
	cin >> N;

	// Read HP
	int idx;
	for (idx = 0; idx < N; idx++) cin >> input[idx];
	for (; idx < 3; idx++) input[idx] = 0;

	// Initialze DP Table
	for (int x = 0; x <= input[0]; x++) {
		for (int y = 0; y <= input[1]; y++) {
			for (int z = 0; z <= input[2]; z++) dpTable[x][y][z] = -1;
		}
	}

	// Base Condition
	dpTable[0][0][0] = 0;
}

int search(int a, int b, int c) {
	// Adjust Minus Value
	if (a < 0) a = 0;
	if (b < 0) b = 0;
	if (c < 0) c = 0;

	// Early Return(Memoization)
	if (dpTable[a][b][c] != -1) return dpTable[a][b][c];

	// Calculates
	dpTable[a][b][c] = MAX_VAL;
	sort(attack, attack + 3);
	do {
		dpTable[a][b][c] = min(dpTable[a][b][c], 1 + search(a - attack[0], b - attack[1], c - attack[2]));
	} while (next_permutation(attack, attack + 3));

	return dpTable[a][b][c];
}

/*
알고리즘 선택 사고 과정
	현재 값 순으로 그냥 9 3 1 배치하면 최적의 해에 도달할 수 없음
	따라서 그리디는 아니고, BFS 탐색 또는 DP의 방식으로 풀어야 함
	DP 점화식을 이렇게 구성
		각 칸의 의미: dpTable[a][b][c] = SCV 체력이 a, b, c 일 때 모두 파괴하는 최소 공격 횟수
		Base Condition: dpTable[0][0][0] = 0
		점화식: dp[a][b][c] =
				1 + min(
					dpTable[a-9][b-3][c-1],
					dpTable[a-9][b-1][c-3],
					dpTable[a-3][b-9][c-1],
					...
				)

알고리즘 적용 방식
	1. init() 함수 사용으로 초기화
	2. search() 함수 리턴값 통해 결과 출력
*/