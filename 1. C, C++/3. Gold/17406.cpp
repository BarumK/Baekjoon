#include <iostream>
#include <algorithm>

using namespace std;

// Macros
#define MAX_NM 50
#define MAX_K 6
#define MAX_VAL 100000007

// Function Definitions
void init();
void permutation();
void copy();
void rotate(int commandNum);
void check();

// Global Variables
int N, M, K, result;
int originalMap[MAX_NM][MAX_NM];
int copyMap[MAX_NM][MAX_NM];
int rotateCommand[MAX_K][MAX_K];
int rotateOrder[MAX_K] = { 0, 1, 2, 3, 4, 5 };


// Main Function
int main() {
	// Initial Setting
	ios::sync_with_stdio(false);

	// Initialization
	init();

	// Perform Permutation & Find Result
	permutation();

	// Print Result
	cout << result << endl;
}


// Function Implementations
void init() {
	// Read N, K
	cin >> N >> M >> K;

	// Read Original Map
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) cin >> originalMap[row][col];
	}

	// Read Rotate Commands
	for (int idx = 0; idx < K; idx++) {
		cin >> rotateCommand[idx][0] >> rotateCommand[idx][1] >> rotateCommand[idx][2];
		rotateCommand[idx][0]--;
		rotateCommand[idx][1]--;
	}

	// Sort Rotate Order Array
	sort(rotateOrder, rotateOrder + MAX_K);

	// Initialize Array
	result = MAX_VAL;
}

void permutation() {
	do {
		copy();
		for (int idx = 0; idx < K; idx++) rotate(rotateOrder[idx]);
		check();
	} while (next_permutation(rotateOrder, rotateOrder + K));
}

void copy() {
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) copyMap[row][col] =  originalMap[row][col];
	}
}

void rotate(int commandNum) {
	// Variables
	int centerRow = rotateCommand[commandNum][0];
	int centerCol = rotateCommand[commandNum][1];
	int scale = rotateCommand[commandNum][2];

	// Rotate
	for (int s = 1; s <= scale; s++) {
		// Temporal Variables
		int top = centerRow - s;
		int bottom = centerRow + s;
		int left = centerCol - s;
		int right = centerCol + s;
		int swapTarget = copyMap[top][left];
		int temp;

		// Up
		for (int idx = left + 1; idx <= right; idx++) {
			temp = copyMap[top][idx];
			copyMap[top][idx] = swapTarget;
			swapTarget = temp;
		}

		// Right
		for (int idx = top + 1; idx <= bottom; idx++) {
			temp = copyMap[idx][right];
			copyMap[idx][right] = swapTarget;
			swapTarget = temp;
		}

		// Down
		for (int idx = right - 1; idx >= left; idx--) {
			temp = copyMap[bottom][idx];
			copyMap[bottom][idx] = swapTarget;
			swapTarget = temp;
		}

		// Left
		for (int idx = bottom - 1; idx >= top; idx--) {
			temp = copyMap[idx][left];
			copyMap[idx][left] = swapTarget;
			swapTarget = temp;
		}
	}
}

void check() {
	// Variables
	int curMin = MAX_VAL;
	int temp;

	// Find Current Min Value
	for (int row = 0; row < N; row++) {
		temp = 0;
		for (int col = 0; col < M; col++) temp += copyMap[row][col];
		if (temp < curMin) curMin = temp;
	}

	// Compare to Global Min Value
	if (curMin < result) result = curMin;
}

/*
알고리즘 선택 사고 과정
	완탐 시뮬레이션 문제로밖에 안보인다...

알고리즘 적용 방식
	1. init() 함수 사용으로 초기화
	2. permutation() 함수를 통해 모든 경우의 수 완탐
		2.1. copy() 함수 통해 원래 배열 복사
		2.2. rotate() 함수 통해 배열 회전
		2.3. check() 함수 통해 결과 비교
	3. 결과 출력
*/