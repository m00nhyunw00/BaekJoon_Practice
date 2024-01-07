# key : A~Z, value : 정수
dictionary = {}

# 후위 연산 함수
def calculate_postfix(postfix):
    stack = []

    for char in postfix:
        if char.isalpha():  # 피연산자인 경우
            stack.append(dictionary[char])
        else:  # 연산자인 경우
            num1 = stack.pop()
            num2 = stack.pop()
            # '-', '/'의 경우 숫자의 순서 주의
            if char == '+':
                result = num1 + num2
            elif char == '-':
                result = num2 - num1
            elif char == '*':
                result = num1 * num2
            elif char == '/':
                result = num2 / num1

            stack.append(result)

    return stack.pop()

def main():
    num_operands = int(input()) # 피연산자 갯수
    postfix = input()   # 후위연산식

    num_ascii = 65  # ASCII 코드로 'A'
    # ASCII 코드로 key를 알파벳 순으로 생성하고 value를 입력받아 dictionary에 저장
    for _ in range(num_operands):
        num = int(input())
        key = chr(num_ascii)
        num_ascii += 1
        dictionary[key] = num

    result = calculate_postfix(postfix)
    print(format(result, ".2f"))    # 소수점 둘쨰자리까지 결과 출력

if __name__ == "__main__":
    main()