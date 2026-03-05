#include <iostream>
#include <string>

using namespace std;

// Macros
#define MAX_N 100
#define MAX_TARGET 80
typedef pair<int, int> coordinate;

// Function Definitions
void init();
void dp();
bool inRange(coordinate coor);

// Global Variables
int N, M, K, result, targetLen;
int dpTable[MAX_TARGET][MAX_N][MAX_N];
string target;
string map[MAX_N];
int direction[2][4] = {
	{-1, 0, 1, 0},
	{0, 1, 0, -1}
};


// Main Function
int main() {
	// Initial Setting
	ios::sync_with_stdio(false);

	// Initialization
	init();

	// Check
	dp();

	// Print Result
	cout << result << endl;
}


// Function Implementations
void init() {
	// Read N, M
	cin >> N >> M >> K;

	// Read Entire Map & Clear DP Table
	for (int row = 0; row < N; row++) cin >> map[row];

	// Read Target String
	cin >> target;

	// Initialize Variables
	result = 0;
	targetLen = target.size();

	// Initialize DP Tables
	for (int t = 0; t < targetLen; t++) {
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < M; col++) {
				if ((t == targetLen - 1) && (map[row][col] == target[t])) dpTable[t][row][col] = 1;
				else dpTable[t][row][col] = 0;
			}
		}
	}
}

void dp() {
	for (int t = targetLen - 2; t >= 0; t--) {
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < M; col++) {
				// If Not Match, Pass
				if (map[row][col] != target[t]) continue;

				// Add From Previous Step
				for (int dir = 0; dir < 4; dir++) {
					for (int delta = 1; delta <= K; delta++) {
						// Next Coordinate
						coordinate next = make_pair(row + delta * direction[0][dir], col + delta * direction[1][dir]);

						// Pass Condition
						if (!inRange(next)) continue;

						// Add
						dpTable[t][row][col] += dpTable[t + 1][next.first][next.second];
					}
				}

				// If Last Loop, Add to Result
				if (t == 0) result += dpTable[t][row][col];
			}
		}
	}
}

bool inRange(coordinate coor) {
	if (coor.first < 0 || coor.first >= N) return false;
	if (coor.second < 0 || coor.second >= M) return false;
	return true;
}

/*
알고리즘 선택 사고 과정
	N이 100 이하라는 다소 좀 큰 형태의 조건이긴 하나,
	K 값이 생각보다 매우 작기 때문에 계속 파고 들어가는 완전 탐색 방식을 사용해도 괜찮아 보였음
	따라서,
		입력을 2차원 배열로 받고 타겟 문자열의 첫 단어를 저장해 두었다가,
		그 점들을 시작점으로 해서 도달 가능한 점들에 대해 visited 배열을 사용하여
		마킹 -> 탐색 -> 돌아와서 마킹 해제하는 백트래킹하는 방식으로 모든 경우의 수를 조사
	로 했더니 시간 초과가 떠버림
		그래서 DP로 선회, 중복 계산이 많기 때문에
		dpTable[k][i][j]: 문자판의 [i][j] 위치에서 시작하여, 목표(target) 문자열의 k번째 위치부터 끝까지 일치시킬 수 있는 경우의 수
			기저 조건: (문자판의 [i][j] 위치 값 == target의 맨 마지막 값) ? 1 : 0
			점화식: (문자판의 [i][j] 위치 값 == target[t]) ? (dpTable[t + 1]에서 도달 가능한 부분의 총합) : 0
			최종 결과: dpTable[0]의 총합

알고리즘 적용 방식
	1. init() 함수로 입력 받고 변수 초기화
	2. dp() 함수로 결과값 계산
	3. 결과 출력
*/