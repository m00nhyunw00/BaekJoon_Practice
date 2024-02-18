#include <iostream>
#include <cmath>
using namespace std;

// '첫째 줄에 가능한 A의 최댓값을 출력한다. 절대/상대 오차는 10^-9까지 허용한다.' 라는 조건에 맞추어 구현하였으나 백준에서 정답 처리를 안해줌. 어느 부분이 문제인지 파악이 안됨.

double findMin(int N, int W, int H);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int N, L, W, H;

    cin >> N >> L >> W >> H;

    double left = 0;
    double right = findMin(L, W, H);
    double mid;
    long long temp;
    int max = log2(1000000000);

    for(int i = 0; i < max + 1; i++){
        mid = (left + right) / 2;

        temp = (long long)(L / mid) * (long long)(W / mid) * (long long)(H / mid);

        if (N <= temp)
            left = mid;
        else
            right = mid;
    }

    cout << fixed;
    cout.precision(10);
    cout << left;

    return 0;
}

double findMin(int N, int W, int H) {
    double result = static_cast<double>(N);

    if (W < result) {
        result = static_cast<double>(W);
    }

    if (H < result) {
        result = static_cast<double>(H);
    }

    return result;
}
