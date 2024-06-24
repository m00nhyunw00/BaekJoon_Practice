#include <iostream>
#include <cstring>
#define MAX_VALUE 20
#define MAX_TOTAL 10001

using namespace std;

int T, N, M;                // 테스트 케이스 수 / 화폐 단위 종류의 개수 / 테스트 케이스 별 목표 금액

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for (int i=0; i<T; i++){
        cin >> N;

        int DP[MAX_TOTAL];          // 바텀-업 DP 테이블
        int cost[MAX_VALUE];       // 화페 단위 종류
        memset(DP, 0, sizeof(DP));
        memset(cost, 0, sizeof(cost));
        DP[0] = 1;

        for (int j=0; j<N; j++)
            cin >> cost[j];

        cin >> M;

        // cost[0]원짜리로 DP테이블 축적 -> cost[0], cost[1]원짜리들로 DP테이블 축적 -> ...
        for (int i = 0; i < N; i++) {
            for (int j = cost[i]; j <= M; j++) {
                DP[j] += DP[j - cost[i]];
            }
        }

        cout << DP[M] << "\n";
    }

    return 0;
}
