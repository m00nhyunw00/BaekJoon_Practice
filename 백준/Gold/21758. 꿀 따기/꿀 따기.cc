#include <iostream>
#include <vector>
#define MAX 100001

using namespace std;

int N;
int ans = 0;
int getTotal(int A, int B, int goal);
int info[MAX];
int sums[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i=1; i<=N; i++){
        cin >> info[i];
        sums[i] = sums[i-1] + info[i];
    }

    // 1. [1]꿀통-[i]벌-[N]벌
    for (int i=2; i<=N-1; i++){
        int temp = sums[i-1];                      // i번째 벌
        temp += sums[N-1] - info[i];               // N번째 벌
        ans = max(ans, temp);
    }
    // 2. [1]벌-[i]꿀통-[N]벌
    for (int i=2; i<=N-1; i++){
        int temp = sums[i] - sums[1];              // 1번째 벌
        temp += sums[N-1] - sums[i-1];             // N번째 벌
        ans = max(ans, temp);
    }
    // 1. [1]벌-[i]벌-[N]꿀통
    for (int i=2; i<=N-1; i++){
        int temp = sums[N] - sums[1] - info[i];    // 1번째 벌
        temp += sums[N] - sums[i];                 // i번째 벌
        ans = max(ans, temp);
    }

    cout << ans;

    return 0;
}