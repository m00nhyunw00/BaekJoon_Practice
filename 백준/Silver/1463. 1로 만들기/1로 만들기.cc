#include <iostream>
#define MAX 1000000
using namespace std;

int DP[1000000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 2; i <= N; i++) {
        // STEP 1: 1을 뺀다.
        DP[i] = DP[i - 1] + 1;

        // STEP 2: 2로 나누어지면 -> 2로 나누어진 값의 DP값 vs 1을 뺀 값의 DP값
        if (i % 2 == 0) {
            DP[i] = min(DP[i], DP[i / 2] + 1);
        }

        // STEP 3: 3으로 나누어지면 -> 3으로 나누어진 값의 DP값 vs 1을 뺀 값의 DP값
        if (i % 3 == 0) {
            DP[i] = min(DP[i], DP[i / 3] + 1);
        }
    }

    cout << DP[N];

    return 0;
}