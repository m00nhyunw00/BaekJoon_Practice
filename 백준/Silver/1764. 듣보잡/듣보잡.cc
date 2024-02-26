#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    vector<string> v;
    vector<string> result;

    cin >> N >> M;

    string str;

    // 듣도 못한 사람 입력
    for (int i=0; i<N; i++){
        cin >> str;
        v.push_back(str);
    }

    // 이분탐색을 이용해 듣도 못한 사람과 보도 못한 사람의 교집합을 빠르게 탐색하기 위해 듣도못한 사람을 정렬
    sort(v.begin(), v.end());

    // 보도 못한 사람 입력 -> 듣도 못한 사람들 중 입력 받은 값이 존재하는지 이분탐색을 실시 -> 존재한다면 결과 벡터에 push
    for (int i=0; i<M; i++){
        cin >> str;

        if(binary_search(v.begin(), v.end(), str))
            result.push_back(str);
    }

    // 결과 벡터 정렬
    sort(result.begin(), result.end());

    cout << result.size() << "\n";

    for(string str : result)
        cout << str << "\n";

    return 0;
}
