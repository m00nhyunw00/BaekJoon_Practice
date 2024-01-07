def print_medians(size_arr, arr):
    num_medians = 0
    medians = []

    for i in range(0, size_arr):
        if i % 2 == 0:
            medians.append(find_median(0, i, arr))
            num_medians += 1

    print(num_medians)
    for i in range(0, num_medians, 10):
        print(*medians[i:i + 10])


    # for i in medians:
    #     print(i, end=" ")
    # print()

def find_median(start, end, arr):
    sorted_arr = sorted(arr[start : end + 1])

    size_arr = len(sorted_arr)
    median = sorted_arr[size_arr // 2]

    return median

def main():
    num_testcase = int(input())

    for _ in range(num_testcase):
        while True:
            size_arr = int(input())
            if size_arr % 2 == 0:
                print("수열의 크기는 홀수만 가능합니다. 다시 입력해주세요.")
                continue

            arr = []
            while len(arr) < size_arr:
                # 한 줄에 최대 10개 숫자 입력받기
                arr += list(map(int, input().split()))

            print_medians(size_arr, arr)
            break

if __name__ == "__main__":
    main()
