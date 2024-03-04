#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 32001
using namespace std;

void insertInDgree0();
void topologySort();

int N, M;
int inDegree[MAX];      // 진입차수 배열
vector<int> graph[MAX]; // 학생들 간 키 관계 그래프
queue<int> q;           // 위상정렬용 큐
int result[MAX];        // 결과 배열

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    int A, B;

    for (int i=0; i<M; i++){
        cin >> A >> B;
        graph[A].push_back(B);  // 그래프 작성
        inDegree[B]++;          // 진입차수 작성
    }

    topologySort(); // 진입차수에 따른 큐 방식 위상정렬

    for (int i=1; i<=N; i++)
        cout << result[i] << " ";

    return 0;
}

// 진입차수가 0인 노드 번호 큐에 삽입하는 함수
void insertInDgree0(){
    for (int i=1; i<=N; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
            inDegree[i]--;
        }
    }
}

// 위상 정렬 함수
void topologySort(){
    // STEP 1: 초기 진입차수가 0인 노드 번호 큐에 삽입
    insertInDgree0();

    for (int i=1; i<=N; i++){
        // STEP 2: 큐에서 pop한 뒤, 해당 노드와 연결된 간선 모두 제거하고 해당 노드를 result에 저장
        int node = q.front();
        q.pop();

        for (auto& connected : graph[node])
            inDegree[connected]--;

        result[i] = node;

        // STEP 3: 간선이 제거된 뒤, 진입차수가 0인 노드 번호 큐에 삽입
        insertInDgree0();
    }
}