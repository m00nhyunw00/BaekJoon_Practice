#include <iostream>
//#include <cmath>

using namespace std;

int gcd(int a, int b);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num = 0;
    int x, y;

    cin >> x >> y;

//    float slope = y / x;
//
//    float before_value = 0;
//    float current_value = 0;
//    int num = 0;
//
//    // x = i + 1일 때의 f(i+1)값을 올림한 값에서 x = i일 때의 f(i)값을 내림한 값으로 빼주면 i < x <= i + 1 구간에서 대각선이 지나가는 타일의 개수를 구할 수 있다.
//    for (int i = 0; i < x; i++) {
//        current_value = slope * (i + 1);
//        num += ceil(current_value) - floor(before_value);
//        before_value = current_value;
//    }

    // 유클리드 호제법을 이용한 풀이 - 규칙성을 찾는데 시간이 오래 걸림. 그냥 암기하는 것 추천.
    num = x + y - gcd(x, y);

    cout << num;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}