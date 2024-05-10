#include <iostream>

using namespace std;

int T;
int westNum, eastNum;
int result;

void DP(int west, int east);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for (int i=0; i<T; i++){
        cin >> westNum >> eastNum;

        result = 1;

//        DP(0, 0);

        // 처음에는 Top-Down DP 기법, 즉 재귀를 이용하여 해결하려고 하였으나 시간 초과가 발생하였다.
        // 알고보니 그냥 단순히 동쪽 마을들 중 서쪽 마을의 개수만큼 선택만 하면 순서는 하나로 고정되므로 Combination을 이용하면 끝나는 문제였다.
        for (int i=0; i<westNum; i++){
            result *= eastNum-i;
            result /= i+1;
        }

        cout << result << "\n";
    }

    return 0;
}

//void DP(int west, int east){
//    if (west == westNum){
//        result++;
//        return;
//    }
//
//    for (int i=east; i<eastNum-(westNum-west)+1; i++)
//        DP(west+1, i+1);
//}