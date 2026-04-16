#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

// Macros
#define MAX_N 50
#define MAX_LEN 50
#define MAX_VAL 100000007

// Function Definitions
void init();
void dp();

// Global Variables
int N, len;
int dpTable[MAX_LEN + 1];
int sizes[MAX_N];
string target;
string words[MAX_N];
deque<int> prefix[MAX_LEN + 1];
deque<int> wordMap[MAX_N];


// Main Function
int main() {
	// Initial Setting
	ios::sync_with_stdio(false);

	// Initialization
	init();

	// Perform Permutation & Find Result
	dp();

	// Print Result
	cout << ((dpTable[len] == MAX_VAL) ? -1 : dpTable[len]) << endl;
}


// Function Implementations
void init() {
	// Read Target String
	cin >> target;
	len = target.size();

	// Read N
	cin >> N;

	// Read Words
	for (int idx = 0; idx < N; idx++) {
		cin >> words[idx];
		sizes[idx] = words[idx].size();
	}

	// Initialize DP Table
	dpTable[0] = 0;
	for (int idx = 1; idx <= len; idx++) dpTable[idx] = MAX_VAL;

	// Initialize Prefix Array
	prefix[0].clear();
	for (int alphabet = 0; alphabet < 26; alphabet++) prefix[0].push_back(0);
	for (int idx = 1; idx <= len; idx++) {
		// Copy Previous Value
		prefix[idx].clear();
		for (int alphabet = 0; alphabet < 26; alphabet++) prefix[idx].push_back(prefix[idx - 1][alphabet]);

		// Add Current Character
		prefix[idx][target[idx - 1] - 'a']++;
	}

	// Initialize Word Map Array
	for (int idx = 0; idx < N; idx++) {
		wordMap[idx].clear();
		for (int alphabet = 0; alphabet < 26; alphabet++) wordMap[idx].push_back(0);
		for (int c = 0; c < sizes[idx]; c++) wordMap[idx][words[idx][c] -'a']++;
	}
}

void dp() {
	for (int idx = 1; idx <= len; idx++) {
		for (int word = 0; word < N; word++) {
			// Pass Condition
			if (idx < sizes[word]) continue;
			if (dpTable[idx - sizes[word]] == MAX_VAL) continue;

			// Temporal Variables
			deque<int> cnt(26, 0);
			int cost = 0;

			// Calculate Prefix
			for (int c = 0; c < 26; c++) cnt[c] = prefix[idx][c] - prefix[idx - sizes[word]][c];

			// If Not Possible Combination, Pass
			if (cnt != wordMap[word]) continue;

			// Calculate
			for (int j = 0; j < sizes[word]; j++) {
				if (target[idx - sizes[word] + j] != words[word][j]) cost++;
			}

			// Update
			dpTable[idx] = min(dpTable[idx], dpTable[idx - sizes[word]] + cost);
		}
	}
}

/*
알고리즘 선택 사고 과정
	어려워서 지피티의 도움을 받았습니다
	DP 점화식은 다음과 같음
		dpTable[i] = s의 앞에서부터 i번째까지 해석하는 최소 비용
		기저 조건: dpTable[0] = 0, 나머지 = INF
		점화식: dp[i] = min(dp[i], 모든 dp[i-L] + cost 케이스)
	이를 위한 Prefix는 다음과 같음
		prefix[i][c] = s[0 ~ i-1]에서 문자 c의 개수

알고리즘 적용 방식
	1. init() 함수 사용으로 초기화
	2. dp() 함수를 통해 결과 계산
	3. 결과 출력
*/