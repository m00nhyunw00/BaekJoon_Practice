from queue import Queue

def get_order(target, priorities):
    queue = Queue()
    result = 0

    for i in range(len(priorities)):     # 큐에 중요도와 중요도가 입력된 순서 정보 put
        queue.put((i, priorities[i]))

    while True:
        current_doc = queue.get()   # FIFO에 따라 큐에서 문서 하나 get
        current_doc_index, current_doc_priority = current_doc   # 해당 문서의 입력 순서, 해당 문서의 중요도

        if any(priority > current_doc_priority for _, priority in queue.queue):
            # any(iterable) : 반복 가능한 자료형(iterable)의 모든 요소가 참(True)이면 참(True)을 반환하는 함수
            # priority > current_doc_priority for _, priority in queue.queue : Python의 list comprehension 문법으로 반복문과 조건문에 따라 리스트를 생성해줌
            queue.put(current_doc)  # 중요도가 높은 문서가 하나라도 있다면 현재 문서를 큐에 다시 put
        else:
            result += 1     # 프린터기에서 나오는 순서
            if current_doc_index == target:     # 만약 찾고자하는 문서를 발견했다면 해당 문서가 프린트된 순서 반환
                return result

def main():
    num_testcase = int(input())

    for _ in range(num_testcase):
        num_documents, target = map(int, input().split())
        priorities = list(map(int, input().split()))

        print(get_order(target, priorities))

if __name__ == "__main__":
    main()