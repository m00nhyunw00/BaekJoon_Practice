#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;

int n, m;
int info[MAX][MAX]; // 배열 정보 테이블
int dp[MAX][MAX];   // 최대 정사각형의 변의 길이 정보를 저장하는 dp 테이블 (bottom-up)
//int findMax(int min_i, int min_j, int max_i, int max_j);    // info[min_i][min_j]를 가장 좌측상단의 원소로 하는 최대 정사각형의 변의 길이를 반환하는 함수

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    string tmp;
    for (int i=0; i<n; i++){
        cin >> tmp;

        for(int j=0; j<m; j++)
            info[i][j] = tmp[j] - '0';
    }

    // 첫번째 시도한 방법: 시간 초과 -> 약간 무식한 방법

//    int result = 1; // 최대 정사각형의 넓이를 저장할 변수
//
//    // info 테이블 전수 조사를 통해 최대 정사각형의 넓이 구하기
//    for (int i=0; i<n; i++){
//        for (int j=0; j<m; j++){
//            if (info[i][j] == 1){
//                int tmp = findMax(i, j, i+1, j+1);  // [i][j]에서의 최대 정사각형의 변의 길이 반환
//                tmp *= tmp;     // 위에서 도출한 정사각형의 넓이 계산
//                result = result > tmp ? result : tmp;   // 방금 도출한 정사각형의 넓이와 result를 비교하여 더 큰 값으로 갱신
//            }
//        }
//    }
//
//    cout << result;

    // 두번째 시도한 방법: 성공 -> bottom-up 방법

    int length = dp[0][0];

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            // dp 테이블 디폴트값 설정
            dp[i][j] = info[i][j];

            // i나 j가 0일 경우, 좌측/좌상단/상단 중 일부 혹은 전부 검사가 불가능하므로 검사
            if (dp[i][j] && i != 0 && j != 0){
                // info[i][j] = 1이면 정사각형 검사
                if (info[i][j] == 1){
                    // dp[i][j] = dp[i][j]의 좌측, 좌상단, 상단 중 가장 작은 값 + 1
                    dp[i][j] = min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]}) + 1;
                }
            }

            // 최댓값 검사 및 갱신
            length = max(length, dp[i][j]);
        }
    }

    cout << length * length;

    return 0;
}

//int findMax(int min_i, int min_j, int max_i, int max_j){
//    // 확장된 정사각형의 껍데기 우측 검사
//    for (int i = min_i; i <= max_i; i++){
//        if (info[i][max_j] != 1)    // 껍데기의 우측에서 1이 아닌 숫자 발견 시, 껍데기에 공백이 존재 -> 함수 종료
//            return max_i - min_i;
//    }
//
//    // 확장된 정사각형의 껍데기 하단 검사
//    for (int j = min_j; j < max_j; j++){
//        if (info[max_i][j] != 1)    // 껍데기의 하단에서 1이 아닌 숫자 발견 시, 껍데기에 공백이 존재 -> 함수 종료
//            return max_j - min_j;
//    }
//
//    return findMax(min_i, min_j, max_i+1, max_j+1);     // 만약 껍데기에 공백이 존재하지 않을 경우, 정사각형을 한층 더 확장하여 검사
//}