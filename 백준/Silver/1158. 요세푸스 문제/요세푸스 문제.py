import sys

sys.setrecursionlimit(10**6)

def print_by_baekjoonformat(list):
    print("<", end="")
    for i in range(len(list)):
        print(list[i], end="")
        if i != len(list)-1:
            print(", ", end="")
    print(">")

# 요세푸스 순열을 반환하는 함수 - 재귀함수
def get_Josephus_array(arr, K):
    result = []
    new_arr = []

    if len(arr) == 0:   # 만약 모든 요소가 다 제거되었다면 재귀 종료
        return result

    remove_index = (K - 1) % len(arr)     # % 연산을 이용하면 순환 큐를 구현 가능
    result.append(arr.pop(remove_index))    # K번째 요소 제거

    # 재귀를 위해 제거된 요소를 제외한 새로운 리스트 생성
    for i in range(len(arr)):
        index = remove_index % len(arr) # 똑같이 % 연산을 이용하여 새로운 리스트 생성 가능
        new_arr.append(arr[index])
        remove_index += 1

    extra = get_Josephus_array(new_arr, K)  # 재귀

    result.extend(extra)    # 순열 갱신
    return result

def main():
    N, K = list(map(int, input().split()))
    circle = []

    for i in range(N):
        circle.append(i+1)

    # print(get_Josephus_array(circle, K))
    print_by_baekjoonformat(get_Josephus_array(circle, K))

if __name__ == "__main__":
    main()