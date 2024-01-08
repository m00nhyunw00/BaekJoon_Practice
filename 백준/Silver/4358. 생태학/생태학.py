import sys

def main():
    dictionary = {}     # 나무들의 이름과 개체수를 저장하는 딕셔너리
    list_trees = []     # 나무들의 이름을 받아 사전식으로 정렬하기 위해 딕셔너리에서 key값을 받아와 저장하는 리스트
    num_tree = 0        # 나무의 총 개체수

    while True:
        tree = str(sys.stdin.readline().rstrip())

        if not tree:
            break
        # 딕셔너리에 이미 있는 개체라면 개체수 증가, 없는 개체라면 새로 추가
        if tree in dictionary:
            dictionary[tree] += 1
        else:
            dictionary[tree] = 1
            list_trees.append(tree)
        num_tree += 1

    # 나무의 이름 사전식으로 정렬
    list_trees.sort()

    # 사전식으로 정렬된 나무 순으로 분포도를 계산하여 출력
    for name_tree in list_trees:
        print(name_tree + " " + str(format(dictionary[name_tree] / num_tree * 100, ".4f")))

if __name__ == "__main__":
    main()