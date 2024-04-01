#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 1000

bool graph[MAX_N+1][MAX_N+1];   // 그래프
bool visited[MAX_N+1];          // 방문 여부 확인 테이블
queue<int> q;                   // BFS용 큐
int N, M, V;

void reset();           // 방문 여부 확인 테이블 리셋 함수
void DFS(int target);
void BFS(int target);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> V;

    for (int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        // 양방향 간 정보 저장
        graph[a][b] = true;
        graph[b][a] = true;
    }

    DFS(V);

    cout << "\n";

    reset();
    BFS(V);

    return 0;
}

void reset() {
    for (int i=1; i<=N; i++)
        visited[i] = false;
}

void DFS(int target){
    visited[target] = true;
    cout << target << " ";

    for (int i=1; i<=N; i++){
        // 간선의 번호가 작은 간선부터 차례대로 탐색
        if (graph[target][i] && !visited[i]){
            DFS(i);
        }
    }
}

void BFS(int target){
    q.push(target);
    visited[target] = true;

    cout << target << " ";

    while (!q.empty()) {
        target = q.front();
        q.pop();

        for (int i=1; i<=N; i++) {
            // 간선의 번호가 작은 간선부터 차례대로 탐색
            if (graph[target][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
                cout << i << " ";
            }
        }
    }
}