#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

// Macros
#define MAX_N 100000
#define MAX 100000001
#define MIN -100000001

// Function Definitions
void init();
void dp();

// Global Variables
int N, K;
int win[MAX_N + 1];
int len[MAX_N + 1];
bool forbidden[MAX_N + 1];


// Main Function
int main() {
	// Initial Setting
	ios::sync_with_stdio(false);

	// Initialization
	init();

    // Calculate DP
    dp();

    // Print Result
    cout << len[0] << endl;
}


// Function Implementations
void init() {
	// Read N, K
	cin >> N >> K;
	cin.ignore();

	// Initialize Variables
	for (int i = 0; i <= N; i++) {
		win[i] = 0;
		len[i] = 0;
        forbidden[i] = false;
	}

	// Read Inhibited Points
	string line;
	if (getline(cin, line)) {
		stringstream ss(line);
		int x;
		while (ss >> x) {
			if (1 <= x && x <= N) forbidden[x] = true;
		}
	}

    // Initialize DP Table
    win[N] = 0;
    len[N] = 0;
}

void dp() {
    // First K - 1 Elements
    for (int i = N - 1; i >= 0; i--) {
        // Pass Inhibited Point
        if (i != 0 && forbidden[i]) continue;

        // Calculate win[i]
        bool flag = true;
        int count = 0;
        for (int j = i + 1; j <= min(N, i + K); j++) {
            // Pass Inhibited Point
            if (forbidden[j]) continue;

            count++;
            if (win[j] == 0) {
                flag = false;
                break;
            }
        }
        if (count == 0) win[i] = 0;
        else win[i] = flag ? 0 : 1;

        // Calculate len[i]
        int res = (win[i] == 1) ? MAX : MIN;
        for (int j = i + 1; j <= min(N, i + K); j++) {
            // Pass Inhibited Point
            if (forbidden[j]) continue;
            if (win[i] == 1 && win[j] != 0) continue;

            if (win[i] == 0) res = (res < len[j]) ? len[j] : res;
            else res = (res > len[j]) ? len[j] : res;
        }
        len[i] = (count > 0) ? (res + 1) : 0;
    }
}

/*
알고리즘 선택 사고 과정
    이실직고 하자면 생각하다 도저히 생각이 안나서 지피티의 힘을 빌렸습니다...
    일단 점화식을 떠올리기 위한 아이디어들은 다음과 같습니다
        1. 우선 한 번 선택하면, 다음 사람은 그 뒤에 숫자들 중에서만 선택이 가능함
        2. 따라서 숫자가 결정나는 것을 뒤에서부터 보자는 마인드로 생각을 해봅시다
        3. win[x]: 현재 이 x라는 숫자를 이전 턴의 사람이 선택을 한 상태일 때, 지금 차례인 사람이 이길 수 있는가?(1: 가능, 0: 불가능)
            이 값은 x 이후의 K개를 보면 답이 나옵니다
            만약 앞의 K개 중에서 win[]값이 하나라도 0이 나온다면, 그 값을 선택했을 때 다음 턴의 사람(상대방)은 이길 수가 없다는 뜻입니다. 그러니 이 경우 win[x]는 1이 됩니다
                부연설명: 서로는 무조건 자신이 이기는 쪽으로 선택을 할 것이기 때문에, 자신이 이길 수 있는 수(상대가 질 수 있는 수)로만 선택을 한다는 전제 조건이 있기에 가능함
            만약 모든 값이 1이라면, 지금 '나'는 어떤 수를 고르더라도 상대방이 이기는 수가 존재하기에 '나'는 이길 수가 없는 상황입니다. 따라서 이 경우 win[x]는 0이 됩니다
            기저 조건 -> win[N]은 현재 이 점이 이전 턴 사람에 의해 지목된 상태이고, '나'는 고를 수가 없기 때문에 무조건 패배니까 0이 됩니다
        4. 그렇다면 이 win[x]에 금지된 점을 넣는 방식은?
            forbidden[x]가 참일 경우, 그 점은 금지된 점이기에 단순히 그 지점에서의 모든 연산을 제외하고 보면 됩니다
            또한 K개를 볼 때, 그 사이의 모든 값이 금지 점일 수도 있으니, 카운팅한 점의 개수가 0개가 아닌지 또한 고려하면 됩니다. 0개일 경우 고를 수 있는 점이 없다는 것이니 0
        5. 그래서 답을 어떻게 구하는데?
            이 win[x]를 가지고 답을 구해 나가면 됩니다. win[x]의 값이 주어졌을 때, len[x]의 값도 구할 수 있습니다
            len[x]의 정의는 현재 숫자가 x일 때, 두 플레이어가 최적의 전략으로 플레이한다고 가정하면 게임이 종료될 때까지 앞으로 더 외쳐질 숫자의 총 개수를 의미합니다.
            문제 조건에 "현재 학생이 이길 수 있는 정수가 있으면 현재 학생이 이기면서 두 명의 학생이 앞으로 외칠 정수 개수의 합이 최소가 되도록 플레이하고, 
            현재 학생이 이길 수 있는 숫자가 없으면 두 명의 학생이 앞으로 외칠 정수 개수의 합이 최대가 되도록 플레이한다." 라는 조건이 여기에서 쓰이게 됩니다.
                현재 학생이 이길 수 있는 정수가 있으면 == win[x]가 1이다
                    현재 학생이 이기면서 두 명의 학생이 앞으로 외칠 정수 개수의 합이 최소가 되도록 플레이 == 앞의 K개 중 가장 작은 len 값을 찾아 그 값에 +1한 값
                현재 학생이 이길 수 있는 숫자가 없으면 == win[x]가 0이다
                    두 명의 학생이 앞으로 외칠 정수 개수의 합이 최대가 되도록 플레이 == 앞의 K개 중 가장 큰 len 값을 찾아 그 값에 +1한 값
                왜 +1이냐면 단순합니다, 현재 턴에서 외치는 1회가 추가되었기 때문입니다
            len[x]는 위의 점화식을 그대로 따라갑니다
                win[x] == 0이면 (앞의 K개 중 가장 큰 len[]값 + 1)
                win[x] == 1이면 (앞의 K개 중 가장 작은 len[]값 + 1)
                기저 조건 -> 현재 수가 N일 때는 더 외칠 수가 없으므로 len[N] = 0

알고리즘 적용 방식
    위의 아이디어를 그대로 적용만 한 것입니다...
*/