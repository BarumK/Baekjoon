#include <iostream>
#include <deque>
#include <string>

using namespace std;

// Macros
#define MAX_NAME 20

// Function Definitions
void init();
void readAndCheck();

// Global Variables
int N, K;
long result;
int hashMap[MAX_NAME + 1];
string input;
deque<int> queue;

// Main Function
int main() {
	// Initial Setting
	ios::sync_with_stdio(false);

	// Initialization
	init();

	// Read and Check for Good Friend
	readAndCheck();

	// Print Result
	cout << result << endl;
}


// Function Implementations
void init() {
	// Read N, K
	cin >> N >> K;

	// Initialize Variables
	result = 0;
	queue.clear();
	for (int i = 0; i <= MAX_NAME; i++) hashMap[i] = 0;
}

void readAndCheck() {
	// Variable for Loop Count
	int readedIndex = 0;

	// Read First K Names
	for (; readedIndex < K; readedIndex++) {
		// Read Name
		cin >> input;
		int length = input.length();

		// Add to Queue & Hash Map
		queue.push_back(length);
		hashMap[length]++;
	}

	// After Reading K Names, Check for Number of Front Person's Good Friends & Read Next Name
	for (; !queue.empty(); ) {
		// If Input Remains, Continue Reading
		if (readedIndex < N) {
			// Read Name
			cin >> input;
			int length = input.length();

			// Add to Queue & Hash Map
			queue.push_back(length);
			hashMap[length]++;

			// Update Readed Index
			readedIndex++;
		}

		// Pop Current Person & Delete Current Person's Name From Hash Map
		int cur = queue.front();
		queue.pop_front();
		hashMap[cur]--;

		// Update # of Good Friends
		result += hashMap[cur];
	}
}

/*
알고리즘 선택 사고 과정
	좋은 친구의 조건: 등수 차이(즉 인덱스 차이)가 K 이내이며 이름의 길이가 동일한 사람
	그러면 본인을 기준으로 K명씩만 보면 되겠구나라는 생각을 처음 함
	근데 생각해 보니 계속 양옆으로 가게 될 경우 중복이 발생함
		그렇다면 양방향 말고 한 쪽 방향만 판단하면 됨
		반대편 K명은 그 전의 사람이 이미 판단했을거기 때문에 그렇게 해도 됨
	그러면 계속 큐를 사이즈 K + 1씩 유지해 가면서 해시맵을 통해 그 큐 안에 있는 길이 정보를 함께 저장하고,
	큐에서 하나를 Pop하면 그 안에 있는 나머지 K명의 정보가 해시맵에 있기에 그거로 좋은 친구를 찾으면 됨
	그러고 난 이후에 다음 사람을 받아 또 큐에 넣는 과정을 반복하면 됨

알고리즘 적용 방식
	1. 변수들을 초기화함
	2. 처음 K개의 이름을 받으며, 큐에 Push함과 동시에 해시맵에 길이 정보를 저장
	3. 이후부터는 큐가 빌때까지 다음 과정을 반복
		3.1. 입력이 남아있다면, 다음 이름을 받아 큐와 해시맵에 반영
		3.2. 이후 큐의 맨 앞에서 다음 사람 정보를 뽑고 그 사람의 이름 길이에 해당하는 해시맵 값을 1 뺌(본인 정보 제거)
		3.3. 이후 그 사람 이름 길이에 대응되는 해시맵에 있는 수가 곧 좋은 친구의 수, 따라서 전체 결과에 더해주며 반영
	4. 마지막에 다 돌고 난 이후에 남은 결과 값이 곧 답이므로 출력
*/