#include <iostream>
#include <string>

using namespace std;

// Macros
#define MAX_LEN 100

// Function Definitions
void init();
void dp();
int max(int a, int b, int c);

// Global Variables
string target[3];
int lengths[3];
int dpTable[MAX_LEN + 1][MAX_LEN + 1][MAX_LEN + 1];


// Main Function
int main() {
	// Initial Setting
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// Initialization
	init();

	// Perform DP
	dp();

	// M Queries
	cout << dpTable[lengths[0]][lengths[1]][lengths[2]] << endl;
}


// Function Implementations
void init() {
	// Read Target Strings
	for (int idx = 0; idx < 3; idx++) {
		cin >> target[idx];
		lengths[idx] = target[idx].size();
	}

	// Initialize DP Table
	for (int i = 0; i <= lengths[0]; i++) {
		for (int j = 0; j <= lengths[1]; j++) {
			for (int k = 0; k <= lengths[2]; k++) dpTable[i][j][k] = 0;
		}
	}
}

void dp() {
	for (int i = 1; i <= lengths[0]; i++) {
		for (int j = 1; j <= lengths[1]; j++) {
			for (int k = 1; k <= lengths[2]; k++) {
				if ((target[0][i - 1] == target[1][j - 1]) && (target[1][j - 1] == target[2][k - 1])) dpTable[i][j][k] = dpTable[i - 1][j - 1][k - 1] + 1;
				else dpTable[i][j][k] = max(dpTable[i - 1][j][k], dpTable[i][j - 1][k], dpTable[i][j][k - 1]);
			}
		}
	}
}

int max(int a, int b, int c) {
	if (a > b) return (a > c) ? a : c;
	else return (b > c) ? b : c;
}

/*
알고리즘 선택 사고 과정
	단순하게 2개일 때의 LCS를 3개로 확장한 방식이라 차원 1개 늘리는 것 빼고는 큰 차이 없을 것으로 보임

알고리즘 적용 방식
	1. init() 함수 통해 변수 및 배열 초기화
	2. dp() 함수 통해 DP 테이블 채우기
	3. 결과 출력
*/