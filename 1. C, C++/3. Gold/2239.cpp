#include <iostream>
#include <string>

using namespace std;

// Macros
#define SIZE 9

// Function Definitions
void init();
void find(int depth);

// Global Variables
int remain;
int map[SIZE][SIZE];
pair<int, int> blanks[SIZE * SIZE];
int rowExist[SIZE][SIZE + 1];
int colExist[SIZE][SIZE + 1];
int boxExist[SIZE][SIZE + 1];


// Main Function
int main() {
	// Initial Setting
	ios::sync_with_stdio(false);

	// Initialization
	init();

	// Find Result
	find(0);
}


// Function Implementations
void init() {
	// Initialize Variables
	remain = 0;

	// Initialize Hash Maps
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j <= SIZE; j++) {
			rowExist[i][j] = 0;
			colExist[i][j] = 0;
			boxExist[i][j] = 0;
		}
	}

	// Read Sudoku Map
	for (int row = 0; row < SIZE; row++) {
		// Read Line
		string line;
		cin >> line;

		// Read Each Numbers
		for (int col = 0; col < SIZE; col++) {
			// Read
			int curNum = line[col] - '0';
			map[row][col] = curNum;

			// Mark
			if (curNum == 0) blanks[remain++] = make_pair(row, col);
			else {
				rowExist[row][curNum] = 1;
				colExist[col][curNum] = 1;
				boxExist[(row / 3) * 3 + (col / 3)][curNum] = 1;
			}
		}
	}
}

void find(int depth) {
	// Break Condition
	if (depth == remain) {
		// Print Result
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) cout << map[i][j];
			cout << endl;
		}

		// Terminate Program
		exit(0);
	}

	//Current Point
	int curRow = blanks[depth].first;
	int curCol = blanks[depth].second;

	// Select
	for (int num = 1; num <= SIZE; num++) {
		// Pass Condition
		if (rowExist[curRow][num] == 1) continue;
		if (colExist[curCol][num] == 1) continue;
		if (boxExist[(curRow / 3) * 3 + (curCol / 3)][num] == 1) continue;

		// Mark
		rowExist[curRow][num] = 1;
		colExist[curCol][num] = 1;
		boxExist[(curRow / 3) * 3 + (curCol / 3)][num] = 1;
		map[curRow][curCol] = num;

		// Visit
		find(depth + 1);

		// Unmark
		rowExist[curRow][num] = 0;
		colExist[curCol][num] = 0;
		boxExist[(curRow / 3) * 3 + (curCol / 3)][num] = 0;
		map[curRow][curCol] = 0;
	}
}

/*
알고리즘 선택 사고 과정
	완전탐색 갈기자

알고리즘 적용 방식
	1. init()으로 입력을 받고 변수를 초기화
	2. find() 함수로 완전탐색 돌리기
		2.1. 모든 빈칸이 채워지면 출력
		2.2. 빈 칸이 존재한다면 해시맵으로 확인하고, 가능하다면 값 넣어보고 다음 재귀 호출
*/