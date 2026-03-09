#include <iostream>

using namespace std;

// Macros
#define MAX_N 1000

// Function Definitions
void init();
void check();

// Global Variables
int N, P, K, D, result;
int target[MAX_N];


// Main Function
int main() {
	// Initial Setting
	ios::sync_with_stdio(false);

	// Initialization
	init();

	// Check
	check();

	// Print Result
	if (result == 0) cout << "Wrong information" << endl;
	else {
		for (int idx = 0; idx < N; idx++) cout << target[idx] << endl;
	}
}


// Function Implementations
void init() {
	// Read Inputs
	cin >> N >> P >> K >> D;

	// Initizlize Variables
	result = 0;
	for (int idx = 0; idx < N; idx++) target[idx] = 0;
}

void check() {
	if (D == 1) {
		// Calculate Quotient & Remainder
		int quotient = P / K;
		int remainder = P % K;

		// Fill K Quotients
		for (int idx = 0; idx < K; idx++) target[idx] = quotient;

		// Fill Remainders
		if (remainder == 0) result = 1;
		else if (N > K) {
			target[K] = remainder;
			result = 1;
		}
	}
	else {
		// Temporal Variables
		int tempSum = 0;
		
		// Make D Groups
		for (int idx = 0; idx < D; idx++) {
			target[idx] = D - 1 - idx;
			tempSum += target[idx];
		}
		
		// Add Remainder If Possible
		if (tempSum <= P) {
			target[0] += (P - tempSum);
			result = 1;
		}
	}
}

/*
알고리즘 선택 사고 과정
	접근 방법을 못찾아서 첫 접근을 지피티를 사용함
	핵심 접근 방식은 "첫 값에 몰빵하자"
		일단 합이 최소가 되는 D개의 그룹을 만든다 -> 0, 1, ... , D - 1 -> 이 그룹은 D개로 만들 수 있는 그룹 중 가장 합이 최소가 됨
		이 그룹의 합보다 P가 넘치는 순간 어떤 수를 써도 불가능하니까 불가하다고 출력
		넘지 않는다면, 그 누적 합과 P의 차이를 전부 첫 요소에 몰빵함
	하지만 D = 1의 경우는 따로 처리해야 함
		K개가 모두 같은 값이어야 한다는 뜻이기에, P를 우선 K로 나눔
		이후 그 나눈 값으로 첫 K개를 모두 채움
		그 이후에 나누고 남은 나머지를 비교하여, 이 값이 그 다음 인덱스에 모두 들어가면 됨
		하지만 그 다음 인덱스가 존재하지 않는다면, 불가하다고 출력

알고리즘 적용 방식
	1. init() 함수로 변수 및 배열 초기화
	2. check() 함수로 체크
	3. 결과 출력
*/