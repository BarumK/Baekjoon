#include <iostream>

using namespace std;

// Macros
#define MAX_N 500000
#define MIN_VAL 0

// Function Definitions
void init();
void find();
void initTree();
pair<int, int> query(int from, int to);
void update(int index, int value);
void swap(int a, int b);
bool compare();

// Global Variables
int N, offset, incorrect, result;
pair<int, int> indexTree[4 * MAX_N];
int target[MAX_N];


// Main Function
int main() {
	// Initial Setting
	ios::sync_with_stdio(false);

	// Initialization
	init();

	// Find Result
	find();

	// Print Result
	cout << result << endl;
}


// Function Implementations
void init() {
	// Initialize Variables
	result = 0;

	// Read N
	cin >> N;

	// Initialize Indexed Tree
	initTree();

	// Read B(Target Array)
	for (int idx = 0; idx < N; idx++) cin >> target[idx];

	// Find # of Incorrect Point
	incorrect = 0;
	for (int idx = 0; idx < N; idx++) {
		if (indexTree[offset + idx].first != target[idx]) incorrect++;
	}
}

void find() {
	// Check Initial State
	if (incorrect == 0) {
		result = 1;
		return;
	}

	// Perform Selection Sort & Check
	for (int idx = N - 1; idx > 0; idx--) {
		// Find Maximum Value
		pair<int, int> swapTarget = query(offset, offset + idx);

		// Swap
		swap(swapTarget.second, offset + idx);

		// Compare
		if (incorrect == 0) {
			result = 1;
			return;
		}
	}
}

void initTree() {
	// Find Offset
	for (offset = 1; offset <= N; offset *= 2);

	// Initialize Indexed Tree & Read A
	for (int idx = 0; idx < 2 * offset; idx++) indexTree[idx] = make_pair(MIN_VAL, idx);
	for (int idx = 0; idx < N; idx++) {
		// Read
		int value;
		cin >> value;

		// Store: {Value, Index}
		indexTree[offset + idx] = make_pair(value, offset + idx);
	}

	// Make Indexed Tree
	for (int idx = offset - 1; idx > 0; idx--) 
		indexTree[idx] = (indexTree[2 * idx].first > indexTree[2 * idx + 1].first) ? indexTree[2 * idx] : indexTree[2 * idx + 1];
}

pair<int, int> query(int from, int to) {
	// Temporal Value
	pair<int, int> min = make_pair(MIN_VAL, MIN_VAL);

	// Find Maximun Value in Subarray
	while (from <= to) {
		if (from % 2 != 0) {
			if (min.first < indexTree[from].first) min = indexTree[from];
			from++;
		}
		if (to % 2 == 0) {
			if (min.first < indexTree[to].first) min = indexTree[to];
			to--;
		}
		from /= 2;
		to /= 2;
	}

	return min;
}

void update(int index, int value) {
	// Insert to Leaf Node
	indexTree[index] = make_pair(value, index);

	// Update Non-Leaf Nodes
	for (int idx = index / 2; idx > 0; idx /= 2) {
		indexTree[idx] = (indexTree[2 * idx].first > indexTree[2 * idx + 1].first) ? indexTree[2 * idx] : indexTree[2 * idx + 1];
	}
}

void swap(int a, int b) {
	// Temporal Variable
	int temp = indexTree[b].first;

	// Temporal Update: Incorrect
	if (indexTree[a].first != target[a - offset]) incorrect--;
	if (indexTree[b].first != target[b - offset]) incorrect--;
	
	// Swap
	update(b, indexTree[a].first);
	update(a, temp);

	// Update Incorrect
	if (indexTree[a].first != target[a - offset]) incorrect++;
	if (indexTree[b].first != target[b - offset]) incorrect++;
}

/*
알고리즘 선택 사고 과정
	N의 값이 너무 커서 그냥 하라는 대로 하면 무조건 타임아웃이 발생할 것으로 보임
	그래서 N^2의 기존 방식에서 NlogN으로 줄이는 방식을 생각해야 할 것으로 판단했음
	결국엔 선택 정렬이 구간 내 최솟값을 찾아 그것을 현재 정렬해야 하는 위치랑 바꾼다는 점이라서,
		값의 변경이 잦은 배열에서 구간 내 최솟값을 빠르게 logN의 시간 안에 조회할 수 있는 인덱스트리(세그트리)를 사용해 보면 어떨까 생각했음
	그래서 구현을 했더니 배열의 일치를 비교하는 부분에서 시간이 오래 걸려서 N^2이 발생해서 TO 발생, 이 부분을 해결해야 했음
		그래서 전부 일일이 비교하지 말고 일치하지 않는 부분의 개수를 저장하여 그것이 0이면 일치라고 보는 방식으로 변경함

알고리즘 적용 방식
	1. init() 함수 사용으로 변수들 초기화하고 인덱스트리 초기화
		1.1. 인덱스 트리에 담는 대표값은 구간 최댓값
	2. find() 함수 사용으로 결과 변수 파악
		2.1. 로직 자체는 기존 선택 정렬과 동일
		2.2. N-1부터 1까지 줄여가며
			2.2.1. 맨 앞부터 지금 위치까지의 최솟값을 query() 함수를 통해 찾고
			2.2.2. swap() 함수로 그 두 값을 변경하며 동시에 불일치 개수 업데이트
				2.2.3. swap()에서 건드리는 부분만 변경이 적용되므로 그 부분만 확인하고 업데이트
			2.2.3. 만약 불일치 개수가 0이면 모두 일치이므로 바로 종료
	3. 결과 출력
*/