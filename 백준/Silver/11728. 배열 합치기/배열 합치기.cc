#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> v1(N), v2(M);

    // 벡터의 크기만큼 순서대로 입력받음
    for (auto& c : v1)
        cin >> c;

    for (auto& c : v2)
        cin >> c;

    // 10^9보다 작거나 같은 숫자들로만 이루어진 배열끼리의 비교이므로 10^9 + 1 값을 push하여 배열의 끝임을 명시
    v1.push_back(1000000000 + 1);
    v2.push_back(1000000000 + 1);

    int a = 0, b = 0;
    while (a < N || b < M) {
        if (a != 0 || b != 0) cout << ' ';

        if (v1[a] == v2[b]) {
            cout << v1[a] << ' ' << v1[a];
            ++a, ++b;
        }
        else if (v1[a] < v2[b]) {
            cout << v1[a];
            ++a;
        }
        else {
            cout << v2[b];
            ++b;
        }
    }

    return 0;
}
