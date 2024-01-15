#include <iostream>

using namespace std;
const int TREE_SIZE = (1 << 20) + 1;
bool Village[TREE_SIZE];

int posDuck(int target);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q;
    int target;

    cin >> N >> Q;

    for (int i = 0; i < Q; i++) {
        cin >> target;
        cout << posDuck(target) << '\n';
    }

    return 0;
}

int posDuck(int target) {
    int currentIndex = target;
    int result = 0;

    // 목표 노드부터 루트 노드까지 올라가면서 검사
    while (currentIndex > 0) {
        // 만약 목표 노드까지 가는 길에 오리가 이미 있는 노드가 있다면 result를 해당 노드의 인덱스로 갱신
        if (Village[currentIndex])
            result = currentIndex;
        // 부모 노드로 올라가기
        currentIndex /= 2;
    }

    // 만약 오리를 목표 노드에 배치하는 것이 가능하다면 목표의 값을 false에서 true로 갱신
    if(!result)
        Village[target] = true;

    return result;
}