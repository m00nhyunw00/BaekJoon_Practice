import heapq

# 중앙값 출력 함수 (arr : 중앙값들을 출력하고자 하는 리스트)
def print_medians(arr):
    num_medians = 0 # 중앙값 갯수
    medians = []    # 중앙값 리스트

    # 리스트를 읽음
    for i in range(0, len(arr)):
        if i % 2 == 0:  # 홀수일 경우, 0번째 ~ i번째 수들의 중앙값을 구하여 medians 리스트에 저장
            medians.append(find_median(0, i, arr))
            num_medians += 1

    print(num_medians)  # 중앙값 갯수 출력
    for i in range(0, num_medians, 10):
        print(*medians[i : i + 10])   # 중앙값들을 출력하되, 한 줄에 최대 10개의 수만 출력

# 중앙값 구하는 함수 (start : 중앙값을 구하고자 하는 리스트의 시작 index, end : 중앙값을 구하고자 하는 리스트의 끝 index, arr : 중앙값들을 출력하고자 하는 리스트)
def find_median(start, end, arr):
    # 우선순위 큐(heapq)를 이용한 중앙값 도출 방법
    priority_queue = [] # 우선순위 큐 사용을 위한 리스트

    for i in range(start, end + 1):
        heapq.heappush(priority_queue, arr[i])  # 우선순위 큐에 push

    size_arr = end - start + 1

    for _ in range(size_arr // 2):
        heapq.heappop(priority_queue)   # 우선순위 큐에서 pop

    median = priority_queue[0]

    return median

def main():
    num_testcase = int(input())

    for _ in range(num_testcase):   # 입력한 테스트 케이스의 수만큼만 반복문 실행
        size_arr = int(input())

        arr = []
        while len(arr) < size_arr:
            arr += list(map(int, input().split()))

        print_medians(arr)  # 중앙값들 출력


if __name__ == "__main__":
    main()
