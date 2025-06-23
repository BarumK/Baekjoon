#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Variables
    long rank = 1;
    long modulo = 1234567891;
    long result = 0;
    long N;
    string arr;

    // Take Input
    cin >> N;
    cin >> arr;

    // Character-Integer Matching + Rank Multiplication
    for (int i = 0; i < N; i++) {
        result += (((long)arr[i] - 96) * rank) % modulo;
        rank = (rank * 31) % modulo;
    }

    // Print Result
    cout << result % modulo;
}


/*
* modulo 연산에서는 분배법칙과 결합법칙이 성립함
* 이로 인해 rank를 매번 곱해가는 방식으로 변경함
*/