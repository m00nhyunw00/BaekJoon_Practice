#include <iostream>
#include <limits>
#include <algorithm>
#define INF 1000000
#define MAX_C 1500
#define MAX_N 20
using namespace std;

int DP[MAX_C + 1];      // bottom-up DP 테이블
int info[MAX_N][2];     // 홍보 비용/효과 정보 테이블

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int C, N;

    cin >> C >> N;

    int cost, reward;

    for (int i = 0; i < N; i++){
        cin >> cost >> reward;
        info[i][0] = cost;
        info[i][1] = reward;
    }


    fill(DP, DP + MAX_C + 1, INF); // DP 배열 초기화

    DP[0] = 0; // 초기값 설정

    for (int i = 0; i <= C; i++){
        for (int j = 0; j < N; j++){
            DP[i + info[j][1]] = min(DP[i + info[j][1]], DP[i] + info[j][0]); // 최소 비용 갱신
        }
    }

    cout << *min_element(DP + C, DP + MAX_C);

    return 0;
}
