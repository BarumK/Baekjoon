#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

// Macros
#define MAX_N 100

// Custom Data Structure
class Block {
	// Class Variables
	public:
		int area, height, weight, index;
};

// Function Definitions
void init();
void dp();
void print();
bool compare(Block a, Block b);

// Global Variables
int N, maxIndex;
int dpTable[MAX_N + 1][3];
Block blocks[MAX_N + 1];
deque<int> result;


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
	// Read N
	cin >> N;

	// Initialize Variables
	maxIndex = 0;
	result.clear();

	// Read Blocks
	for (int idx = 1; idx <= N; idx++) {
		cin >> blocks[idx].area >> blocks[idx].height >> blocks[idx].weight;
		blocks[idx].index = idx;
	}

	// Sort Blocks by Ascending Order of Area
	sort(blocks + 1, blocks + N + 1, compare);

	// Initialize DP Table
	for (int idx = 0; idx <= N; idx++) {
		// Maximum Height When Current Block is At The Bottom
		dpTable[idx][0] = 0;
		
		// # of Stacked Blocks
		dpTable[idx][1] = 0;
		
		// Index of The Block Directly Above
		dpTable[idx][2] = 0;
	}
}

void dp() {
	// Loop For All Blocks
	for (int cur = 1; cur <= N; cur++) {
		// Temporal Variables
		int prev = 0;
		
		// Check Maximum Height
		for (int idx = 1; idx < cur; idx++) {
			if ((dpTable[prev][0] < dpTable[idx][0]) && (blocks[idx].weight <= blocks[cur].weight)) prev = idx;
		}

		// Calculate Current Point's DP Table
		if (prev == 0) {
			// Base Condition
			dpTable[cur][0] = blocks[cur].height;
			dpTable[cur][1] = 1;
		}
		else {
			// Recurrence Relation
			dpTable[cur][0] = dpTable[prev][0] + blocks[cur].height;
			dpTable[cur][1] = dpTable[prev][1] + 1;
			dpTable[cur][2] = prev;
		}
	}
}

void print() {
	// Find Max Index
	for (int i = 1; i <= N; i++) {
		if (dpTable[maxIndex][0] < dpTable[i][0]) maxIndex = i;
	}

	// Print # of Stacked Block
	cout << dpTable[maxIndex][1] << '\n';

	// Stack Blocks
	for (int idx = maxIndex; idx != 0; idx = dpTable[idx][2]) result.push_front(blocks[idx].index);

	// Print Stacked Blocks
	for (int idx = 0; idx < result.size(); idx++) cout << result[idx] << '\n';
}

bool compare(Block a, Block b) { return (a.area < b.area); }

/*
알고리즘 선택 사고 과정
	아무리 봐도 어떻게 푸는 지 몰라서 지피티 찬스 사용했습니다
	지피티를 통해 DP로 진행해야 하는 방법을 확인했고, 각 포인트에 담아야 하는 점화식의 값이 "현재 블록을 맨 바닥으로 했을 때, 가능한 탑의 최대 높이"라는 점을 확인함
	따라서 DP 테이블을 다음과 같이 구성함:
		[0]: 현재 블록을 맨 바닥으로 했을 때, 가능한 탑의 최대 높이
		[1]: 현재 블록을 맨 바닥으로 했을 때, 쌓은 블록의 수
		[2]: 현재 블록을 맨 바닥으로 했을 때, 지금 블록 바로 위에 오는 블록의 인덱스

알고리즘 적용 방식
	1. init() 함수 사용으로 변수 및 배열 초기화
	2. dp() 함수 사용으로 최적 값 구하기
	3. print() 함수 사용으로 결과 출력
*/