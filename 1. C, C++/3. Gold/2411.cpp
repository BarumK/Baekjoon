#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

// Macros
#define MAX_NM 100

// Function Definitions
void init();
void dp();

// Global Variables
int N, M, A, B;
int dpTable[MAX_NM + 1][MAX_NM + 1];
pair<int, int> items[MAX_NM * MAX_NM];
set<pair<int, int>> block;

// Main Function
int main() {
	// Initial Setting
	ios::sync_with_stdio(false);

	// Initialization
	init();

	// Perform Dynamic Programming
	dp();

	// Print Result
	cout << dpTable[N][M] << '\n';
}


// Function Implementations
void init() {
	// Read N, M, A, B
	cin >> N >> M >> A >> B;

	// Initalize dp Table
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) dpTable[i][j] = 0;
	}
	dpTable[1][1] = 1;

	// Read Items
	for (int i = 0; i < A; i++) {
		// Read
		int x, y;
		cin >> x >> y;

		// Add to Array
		items[i] = make_pair(x, y);
	}

	// Add Start Point & End Point to Items Array, Sort Array
	items[A++] = make_pair(1, 1);
	items[A++] = make_pair(N, M);
	sort(items, items + A);

	// Initialize & Read Block Points
	block.clear();
	for (int i = 0; i < B; i++) {
		// Read
		int x, y;
		cin >> x >> y;

		// Add to Hash Set
		block.insert(make_pair(x, y));
	}
}

void dp() {
	// Perform DP for Smaller Areas
	for (int i = 1; i < A; i++) {
		// Select Current Range
		pair<int, int> start = items[i - 1];
		pair<int, int> end = items[i];

		for (int i = start.first; i <= end.first; i++) {
			for (int j = start.second; j <= end.second; j++) {
				// Pass For Initial Point
				if ((start.first == i) && (start.second == j)) continue;
				
				// Update DP Table From Previous Points
				if (block.find(make_pair(i, j)) != block.end()) dpTable[i][j] = 0;
				else dpTable[i][j] = dpTable[i - 1][j] + dpTable[i][j - 1];
			}
		}
	}
}

/*
알고리즘 선택 사고 과정
	어릴 적에 수학 시간에 풀었던 격자 길에서 경로의 개수 찾는거 더하는 문제가 생각이 남
	그 방식을 그대로 DP 점화식으로 활용하면 되겠다 싶었음
	또한 문제 조건 보니까 모든 아이템을 다 줍고 지나가야 한다 하길래, 무조건 아이템들끼리는 우상향만 할거라는 생각
	따라서 받아둔 다음에 정렬하고 보면, 구간들 내에서 DP를 연쇄적으로 적용하면 될거라는 생각
	시작점 -> 아이템1 -> 아이템2 -> ... -> 아이템A -> 종착점 순서로
	그 외의 부분은 혹시 모르니 0으로 만들어 두고 점화식에서도 일관성을 유지하게끔 0-Padding도 추가
	참고) 문제에서는 좌하단에서 시작해 우상단으로 가는 형태이나, 여기서는 배열의 특성 상 좌상단에서 우하단으로 가는 형태(상하대칭)

알고리즘 적용 방식
	1. 초기 입력을 받고
	2. 변수들을 초기화를 하고	
	3. 아이템들 좌표를 받아서 저장
		3.1. pair(int, int)의 형태
		3.2. 다 받은 이후에는 시작점과 종착점의 위치를 추가한 후 sort 진행
	4. 장애물 좌표를 받아서 set에 저장
		4.1. 그 자리에 장애물이 있는지 용도로만 사용할 것이기에 빠른 조회가 필요하여 set을 선택
		4.2. 원래 해시 set을 사용해야 하나 pair<int, int>의 경우엔 그걸 매핑하는 해시 함수가 없다길래 귀찮아서 그냥 set 사용함
	5. DP 진행
		5.1. 시작점 값을 1로 정하고 시작
		5.2. 부분 구간에 대해 반복적으로 DP 진행 -> 아이템 배열에서 순차적으로 하나씩 뽑아가며
			5.2.1. 만약 해당 지점에 장애물이 존재하면 해당 DP 테이블의 값은 0, 그 길을 통해 가는 경우는 없기 때문
			5.2.2. 그게 아니라면 현재 경로로 오는 경우의 수는 위에서 오는 경우의 수 + 왼쪽에서 오는 경우의 수
	6. DP 테이블의 종점 값이 곧 결과이므로 출력
*/