#include <iostream>
#include <algorithm>

using namespace std;

int numOfCases[100001];
int values[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;

    cin >> n >> k;


    for(int i = 0; i < n; i++)
        cin >> values[i];

    numOfCases[0]=1;

    // 보통 2차원 배열로 푸는 문제를 같은 원리에 입각하여 1차원 배열로만 바꾼 형태
    for(int i=0; i<n; i++){
        for(int j=values[i]; j<=k; j++){
            numOfCases[j] += numOfCases[j-values[i]];
        }
    }

    cout << numOfCases[k];

    return 0;
}
