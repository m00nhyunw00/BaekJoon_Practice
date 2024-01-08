# import heapq
#
# priority_queue = []
# heapq.heapify(priority_queue)
#
# N = int(input())
# matrix = []
#
# for i in range(N):
#     for item in list(map(int, input().split())):
#         heapq.heappush(priority_queue, -item)
#
#     print(priority_queue)
#
# for i in range(N-1):
#     heapq.heappop(priority_queue)
#
# print(-heapq.heappop(priority_queue))

# 위에 있는 기존의 방식은 NxN개의 원소를 전부 우선순위 큐에 넣은 뒤 heapq.heappop()을 N번 실행하여 N번째 수를 찾는 방식이었다.
# heapq의 경우 기본적으로 minheap 구조이기 때문에 -를 취해주어 maxheap의 효과를 내보았다.
# 하지만 NxN개의 원소를 전부 우선순위 큐에 넣으면 어떤 방식을 취하더라도 백준에서 메모리 초과 문제가 발생하였다.

# 따라서 밑에 있는 새로운 방식은 발상을 전환하여 NxN개의 원소를 전부 우선순위 큐에 넣는 것이 아닌 N개의 수만 우선순위 큐에 남도록 하는 것이다.
# 만약 초과된다면 heappop()을 한다. 계속 이 과정을 반복하면 minheap의 원리에 따라 가장 작은 수가 항상 pop이 되므로 최종적으로 남는 N개의 원소는 NxN개의 원소들 중 1~5번쨰로 큰 원소만 남게 된다.
# 따라서 이 상태에서 heappop()을 하게 되면 전체에서 5번째로 큰 원소가 추출된다.

import heapq

N = int(input())
priority_queue = []

for _ in range(N):
    tmp = list(map(int, input().split()))
    for i in range(N):
        heapq.heappush(priority_queue, tmp[i])
        if len(priority_queue) > N:     # N개의 수만 우선순위 큐에 유지
            heapq.heappop(priority_queue)

print(heapq.heappop(priority_queue))