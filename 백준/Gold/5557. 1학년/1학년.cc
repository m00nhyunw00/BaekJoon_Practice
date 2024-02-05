#include<iostream>
using namespace std;

int N;
int num[100];
long long dp[100][21];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> num[i];
    }

    // 밑에 있는 반복문의 시작점이다. 가능한 등식 각각을 1로 카운팅할 것이므로 1로 설정한다.
    dp[0][num[0]] = 1;

    // 가장 마지막 계산은 N-3번째 인덱스의 수와 N-2번째 인덱스의 수를 비교해야하므로 i의 범위를 아래와 같이 설정
    for (int i = 0; i < N - 2; i++){
        // j의 범위가 0 이상 20 이하이므로  j의 범위를 아래와 같이 설정
        for (int j = 0; j < 21; j++){
            // 만약 dp[i][j]가 0 이상이라면 주어진 숫자의 조합으로 나올 수 있는 경우의 수라는 의미이다.
            // 반대로 0이라면 주어진 숫자의 조합으로는 나올 수 없는 숫자라는 의미이다.
            if (dp[i][j] > 0){
                int add = j + num[i + 1];
                int sub = j - num[i + 1];
                // 이전 숫자가 이미 0 이상 20 이하의 숫자이기에 더한 숫자는 20 이하 여부만 검사하면 된다.
                if (add < 21)
                    dp[i + 1][add] += dp[i][j];
                // 이전 숫자가 이미 0 이상 20 이하의 숫자이기에 뺀 숫자는 0 이상 여부만 검사하면 된다.
                if (sub >= 0)
                    dp[i + 1][sub] += dp[i][j];
            }
        }
    }

    cout << dp[N - 2][num[N - 1]];

    return 0;
}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//long long calculateNum(vector<int>& v, int index, int value);
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    int N;
//    cin >> N;
//
//    vector<int> v(N);
//
//    for(auto& i : v)
//        cin >> i;
//
//    return 0;
//}
//
//long long calculateNum(vector<int>& v, int index, int value){
//    if(value < 0 || value > 20)
//        return 0;
//
//    if(index == v.size()-1){
//        if(v[index] == value)
//            return 1;
//        return 0;
//    }
//
//
//    long long count = 0;
//    count += calculateNum(v, index+1, value + v[index]);
//    count += calculateNum(v, index+1, value - v[index]);
//    return count;
//}
