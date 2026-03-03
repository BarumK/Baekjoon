#include <iostream>
#include <string>

using namespace std;

// Macros
#define MAX_LEN 100
#define MAX_TARGET 20

// Function Definitions
void init();
void dp();

// Global Variables
int targetSize, lineSize, result;
string target, line1, line2;
int dpTable[MAX_TARGET][MAX_LEN][2];


// Main Function
int main() {
	// Initial Setting
	ios::sync_with_stdio(false);

	// Initialization
	init();

	// Perform Dynamic Programming & Find Result
	dp();

	// Print Result
	cout << result << endl;
}


// Function Implementations
void init() {
	// Read Target String & Input Strings
	cin >> target >> line1 >> line2;

	// Initialize Variables
	targetSize = target.size();
	lineSize = line1.size();
	result = 0;
}

void dp() {
	// Base Condition
	for (int idx = 0; idx < lineSize; idx++) {
		dpTable[0][idx][0] = (line1[idx] == target[0]) ? 1 : 0;
		dpTable[0][idx][1] = (line2[idx] == target[0]) ? 1 : 0;
	}

	// Fill DP Table
	for (int cur = 1; cur < targetSize; cur++) {
		for (int idx = 0; idx < lineSize; idx++) {
			// Default: 0
			dpTable[cur][idx][0] = 0;
			dpTable[cur][idx][1] = 0;

			// If Same, Sum Up Previous Entry
			if (line1[idx] == target[cur]) {
				for (int prevIdx = 0; prevIdx < idx; prevIdx++) dpTable[cur][idx][0] += dpTable[cur - 1][prevIdx][1];
			}
			if (line2[idx] == target[cur]) {
				for (int prevIdx = 0; prevIdx < idx; prevIdx++) dpTable[cur][idx][1] += dpTable[cur - 1][prevIdx][0];
			}
		}
	}

	// Find Result
	for (int idx = 0; idx < lineSize; idx++) {
		result += dpTable[targetSize - 1][idx][0];
		result += dpTable[targetSize - 1][idx][1];
	}
}

/*
알고리즘 선택 사고 과정
	뭔가 한번 보고 돌아오지 않는다는 점에서 DP일거 같다는 생각이 듦
	점화식을 생각해 보자
		기저 조건은? -> 주어진 타겟 스트링의 첫 단어일 경우 1
		점화식은?
			-> 자기 라인이 아닌 다른 라인의 돌다리이면서,
			   나의 인덱스보다 앞이면서,
			   타겟 단어 상에서 내가 바로 위치한 그 직전 단어들의 위치의 dp값을 모두 더한 값
		이렇게 할 경우 봉착하는 난관
			1. 결과를 어떻게 추합할 것인가?
			2. 만약에 타겟 값에 동일한 알파벳이 중복된다면, 그게 몇 번째의 것인지 어떻게 아는가?
			3. 계속 반복하니까 시간 복잡도가 생각보다 좋지 않을 수도 있는데...
		이 문제를 해결하기 위해서 그러면 dp 테이블을 차원을 한차원 더 늘리자
			입력 길이 * 2 -> 타겟의 길이 * 입력 길이 * 2
			타겟의 길이를 추가하는 이유는 위에서 말한 몇 번째의 것인지를 구분하기 위해서 추가함
			이렇게 할 경우 최종 결과 추합 또한 마지막 입력 길이 * 2 배열의 모든 요소의 합으로 명확해짐
	최종 점화식
		기저 조건: 맨 첫번째 "입력 길이 * 2" 테이블에 대해,
			1. 현재 입력의 값이 타겟의 첫 단어랑 같으면 1
			2. 다르면 0
		점화식: 현재 "입력 길이 * 2" 테이블에 대해,
			1. 현재 입력의 값이 타겟의 현재 단어랑 같으면, 이전 단계의 다른 라인에서 자기 인덱스보다 앞의 값들을 더한 값
			2. 다르면 0
		최종 답: 마지막 "입력 길이 * 2" 테이블 요소 값들의 총합


알고리즘 적용 방식
	1. init() 함수를 통해 입력을 받고 변수들을 초기화함
	2. dp() 함수를 통해 dp 수행하고 결과를 계산함
	3. 결과 출력
*/