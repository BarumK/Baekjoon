#include <iostream>

using namespace std;

// Macros
#define MAX_GP 100000
#define MAX(A, B) ((A) > (B) ? (A) : (B))

// Function Definitions
void init();
void find();
int query(int target);
void update(int target);

// Global Variables
int G, P, offset, flight, result;
bool stop;
int flights[MAX_GP];
int indexTree[4 * MAX_GP];


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
	// Read G, P
	cin >> G >> P;

	// Initialize Variables
	result = 0;
	stop = false;

	// Calculate Offset
	for (offset = 1; offset < G; offset *= 2);

	// Initizlize Indexed Tree
	for (int idx = offset; idx < 2 * offset; idx++) indexTree[idx] = idx;
	for (int idx = offset - 1; idx > 0; idx--) indexTree[idx] = MAX(indexTree[2 * idx], indexTree[2 * idx + 1]);
}

void find() {
	// Loop For All Flights
	for (int p = 0; p < P; p++) {
		// Read Flight Information
		cin >> flight;

		// If Not Closed
		if (!stop) {
			// Find Target Gate's Number
			int gateNum = query(flight);

			// Check If Gate is Available
			if (gateNum != -1) {
				update(gateNum);
				result++;
			}
			else stop = true;
		}
	}
}

int query(int target) {
	// Local Variables
	int start = offset;
	int end = offset + target - 1;
	int result = -1;

	// Find Largetst Point by Traversing Tree
	while (start <= end) {
		// Adjust
		if (start % 2 != 0) {
			result = MAX(result, indexTree[start]);
			start++;
		}
		if (end % 2 == 0) {
			result = MAX(result, indexTree[end]);
			end--;
		}

		// Follow Parent
		start /= 2;
		end /= 2;
	}

	return result;
}

void update(int target) {
	// Update Leaf Node
	indexTree[target] = -1;

	// Update Parent Nodes
	for (int idx = target / 2; idx > 0; idx /= 2) indexTree[idx] = MAX(indexTree[2 * idx], indexTree[2 * idx + 1]);
}

/*
알고리즘 선택 사고 과정
	1부터 gi까지의 게이트 중에 선택하면 되니까 선택 가능한 것 중 가장 큰 수의 게이트를 선택하면 될 것 같은데?라는 생각
	단순하게 gi부터 내려가면서 가장 크게 비어있는 값을 선택하면 시간 초과가 발생
		-> 그렇다면 O(logN) 혹은 O(1)의 시간 안에 저장할 위치를 찾는 방식을 선택해야 함
		-> 값이 자주 변하는 배열에서 구간의 대표값을 자주 조회해야 하는?
		-> 이거 완전 인덱스트리???? 지금이다 인덱스트리 드가자

알고리즘 적용 방식
	1. init() 함수 사용으로 초기화
	2. find() 함수 사용으로 결과 계산
	3. 결과 출력
*/