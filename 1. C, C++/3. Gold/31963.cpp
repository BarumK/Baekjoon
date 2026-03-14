#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

// Macros
#define MAX_N 250000
typedef pair<int, long long> number;

// Function Definitions
void init();
void greedy();

// Global Variables
int N;
long long result;
number numbers[MAX_N];


// Main Function
int main() {
	// Initial Setting
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// Initialization
	init();

	// Perform Greedy algorithm
	greedy();

	// M Queries
	cout << result << endl;
}


// Function Implementations
void init() {
	// Read N & Target Array
	cin >> N;

	// Read Target Array
	for (int idx = 0; idx < N; idx++) {
		// Initial Setting
		cin >> numbers[idx].first;
		numbers[idx].second = 0;

		// Extract 2
		while (numbers[idx].first % 2 == 0) {
			numbers[idx].first /= 2;
			numbers[idx].second++;
		}
	}

	// Initialize Variables
	result = 0;

	//for (int idx = 0; idx < N; idx++) cout << numbers[idx].first << " " << numbers[idx].second << endl;
}

void greedy() {
	for (int idx = 1; idx < N; idx++) {
		// Variables
		number prev = numbers[idx - 1];
		number cur = numbers[idx];

		// Adjust
		long long diff = max((int) ceill(log2((long double)prev.first / (long double)cur.first) + (prev.second - cur.second)), 0);

		// Update
		result += diff;
		numbers[idx].second += diff;
	}
}

/*
알고리즘 선택 사고 과정
	그냥 앞에서부터 늘리면 될 것 같은데? 라는 생각
	어차피 앞에보다 크기만 하면 된다는 조건이니까, 앞에가 바뀌면 뒤에도 영향을 받기에 앞부분부터 최소한의 변경을 하며 확정해 나가면 됨
	다만 고려해야 할 점은 2의 거듭제곱으로 곱해 나가는 것이기에, 정수 오버플로우를 고려해야 함
		샤라웃 투 https://velog.io/@piazzi/BaekJoon-31963%EB%B2%88-%EB%91%90-%EB%B0%B0-G4
		숫자를 2의 거듭제곱과 그 외의 수의 곱으로 표현한 후 로그를 취해 계산하는 방식

알고리즘 적용 방식
	1. init() 함수 통해 변수 및 배열 초기화
	2. greedy() 함수 통해 계산
	3. 결과 출력
*/