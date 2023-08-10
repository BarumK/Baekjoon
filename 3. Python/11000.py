import heapq, sys                                                   # heapq, sys 모듈 import 하기

def classroom_assignment():                                         # 강의실 배정 함수
    C = []                                                          # 강의 리스트: [시작 시간, 종료 시간]
    N = int(sys.stdin.readline())                                   # 총 강의의 개수 입력받기
    for i in range(N):                                              # 강의의 개수만큼 강의의 시작, 종료시간 입력받기
        startTime, endTime = map(int, sys.stdin.readline().split()) # 시작 시간과 입력 시간 입력받기
        C.append([startTime, endTime])                              # 강의 리스트에 저장하기
    C.sort(key = lambda x: x[0])                                    # 시작 시간을 기준으로 리스트 정렬
    result = []                                                     # 결과 리스트: Heap으로 구현
    heapq.heappush(result, C[0][1])                                 # 첫 번째 강의실 추가 후 Heap에 종료 시각 추가
    for i in range(1, len(C)):                                      # C 안의 모든 강의에 대해 탐색
        if C[i][0] < result[0]:                                     # 현재 강의의 시작 시간이 이전 강의의 종료 시간보다 빠르면
            heapq.heappush(result, C[i][1])                         # 추가 강의실이 필요하므로 현재 강의의 종료 시간을 Heap에 추가(새 강의실 마련과 같은 의미)
        else:                                                       # 현재 강의의 시작 시간보다 일찍 끝나는 이전 강의가 있다면
            heapq.heappop(result)                                   # 그 강의실에 현재 수업을 할당함; 이전 강의의 종료 시간을 Heap에서 제거하고
            heapq.heappush(result, C[i][1])                         # 현재 강의의 종료 시간을 Heap에 추가함(결론적으로 종료시간을 갈아끼운 셈)
    print(len(result))                                              # Heap의 길이 출력: 결과적으로는 강의실의 수

if __name__ == "__main__":
    classroom_assignment()                                          # 강의실 배정 결과 출력: 최소 강의실 수 출력