#include <iostream>
#include <vector>
using namespace std;

int N, S;
vector<int> v;

int search(int i, int sum);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S;

    int num;
    for (int i=0; i<N; i++){
        cin >> num;
        v.push_back(num);
    }

    cout << search(0, 0);

    return 0;
}

// i: 현재 탐색 중인 인덱스 / sum: 부분 수열의 요소합
int search(int i, int sum){
    if (i == N)
        return 0;

    int a, b;

    // a: 현재 원소는 더하지 않고 다음 인덱스 탐색
    a = search(i + 1, sum);
    // b: 현재 원소를 더하고 다음 인덱스 탐색
    b = search(i + 1, sum + v[i]);

    // 만약 현재 인덱스를 더했을 때, S와 같다면 count
    if(sum + v[i] == S)
        return a + b + 1;
    // S와 같지 않다면 count X
    else
        return a + b;
}