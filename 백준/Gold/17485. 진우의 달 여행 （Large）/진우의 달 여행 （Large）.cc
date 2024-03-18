#include <iostream>
#include <vector>
#define MAX 1000
#define INF 100001
using namespace std;

int dp[MAX][MAX+2][3];  // 공간 별 연료 최솟값 저장 dp 테이블 (bottom-up)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> info;   // 공간 별 연료양 정보 테이블

    for (int i=0; i<N; i++){
        vector<int> tmp;
        int input;
        for (int j=0; j<M; j++){
            cin >> input;
            tmp.push_back(input);
        }
        info.push_back(tmp);
    }

    // dp 테이블 초기화
    for (int i = 0; i < N; i++) {
        // 열의 양끝단 즉, 0열과 M+1열은 INIT으로 초기화
        for (int k = 0; k < 3; ++k) {
            dp[i][0][k] = INF;
            dp[i][M+1][k] = INF;
        }
        // 1~M열은 각 공간에 해당하는 info값을 대입하여 초기화
        for (int j = 1; j <= M; j++) {
            for (int k = 0; k < 3; ++k) {
                dp[i][j][k] = info[i][j-1];
            }
        }
    }

    // [i][j][0]: 만약 0번 방향으로 왔을 경우, 이전 행의 0번 방향의 [i-1][][1], [i-1][][2] 중 작은 것을 택하여 [i][j][0]에 더해주기 ([][][1]. [][][2]도 같은 원리)
    for(int i=1; i<N; i++){
        for(int j=1; j<=M; j++){
            dp[i][j][0] += ( dp[i-1][j+1][1] < dp[i-1][j+1][2] ? dp[i-1][j+1][1] : dp[i-1][j+1][2] );
            dp[i][j][1] += ( dp[i-1][j][0] < dp[i-1][j][2] ? dp[i-1][j][0] : dp[i-1][j][2] );
            dp[i][j][2] += ( dp[i-1][j-1][0] < dp[i-1][j-1][1] ? dp[i-1][j-1][0] : dp[i-1][j-1][1] );
        }
    }

//    for(int i=0; i<N; i++){
//        for(int j=1; j<=M; j++){
//            cout << "( ";
//            for(int k=0; k<3; k++)
//                cout << dp[i][j][k] << " ";
//            cout << ") ";
//        }
//        cout << endl;
//    }

    int result = INF;

    // 마지막 행에서 가장 작은 값을 찾아 출력
    for(int i=1; i<=M; i++){
        for(int j=0; j<3; j++){
            result = ( result < dp[N-1][i][j] ? result : dp[N-1][i][j] );
        }
    }

    cout << result;

    return 0;
}
