#include <iostream>
#include <cstring>
#include <queue>
#define MAX 102

using namespace std;

int W, H;                   // Width / Height
int graph[MAX][MAX];        // 집 배치도 그래프
void bfs(int sx, int sy);   // 빈 공간이 건물 내부인지 외부인지 판별하여 전자일 경우 0, 후자일 경우 2로 그래프 상에 표기해주는 함수
int calculate();            // 건물 외벽의 길이를 반환하는 함수

// y좌표 기준으로 홀수일 경우와 짝수일 경우 변화량이 다름
int oddDx[6] = {1, 1, 1, 0, -1, 0};
int oddDy[6] = {-1, 0, 1, 1, 0, -1};
int evenDx[6] = {0, 1, 0, -1, -1, -1};
int evenDy[6] = {-1, 0, 1, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(graph, -1, sizeof(graph));   // 그래프 전체를 -1로 초기화

    cin >> W >> H;
    for (int i=1; i<=H; i++)
        for (int j=1 ; j<=W; j++)
            cin >> graph[j][i];

    // 가장 자리에 있는 빈 공간을 대상으로 bfs를 실시하여 가장 자리의 빈 공간과 이어져 있는 빈 공간은 모두 건물 외부로 판단
    // 만약 외부로 판단되면 0이었던 값을 2로 변경
    for (int i=1; i<=W; i++){
        if (graph[i][1] == 0)
            bfs(i, 1);
        if (graph[i][H] == 0)
            bfs(i, H);
    }
    for (int i=2; i<H; i++){
        if (graph[1][i] == 0)
            bfs(1, i);
        if (graph[W][i] == 0)
            bfs(W, i);
    }

//    for (int i=1; i<=H; i++) {
//        for (int j = 1; j <= W; j++) {
//            cout << graph[j][i] << " ";
//        }
//        cout << endl;
//    }

    cout << calculate();

    return 0;
}

void bfs(int sx, int sy){
    bool visited[MAX][MAX];
    queue<pair<int, int>> q;

    memset(visited, false, sizeof(visited));

    visited[sx][sy] = true;
    graph[sx][sy] = 2;
    q.push({sx, sy});

    while (!q.empty()) {
        pair<int, int> node = q.front();
        q.pop();

        for (int i = 0; i < 6; i++){
            // y좌표 기준으로 홀수일 경우와 짝수일 경우 다른 변화량을 사용
            int nx = node.first + (node.second % 2 ? oddDx[i]: evenDx[i]);
            int ny = node.second + (node.second % 2 ? oddDy[i]: evenDy[i]);

            // 만약 인접한 노드가 bfs 중 이미 방문을 했거나 검사할 필요가 없는 노드일 경우, 해당 노드 무시 (-1: 그래프의 외부 | 1: 건물이 놓여있는 위치 | 2: 이미 판별이 끝난 위치)
            if (visited[nx][ny] || graph[nx][ny] != 0)
                continue;

            visited[nx][ny] = true;
            graph[nx][ny] = 2;
            q.push({nx, ny});
        }
    }
}

int calculate(){
    int result = 0;

    for (int x=1; x<=W; x++){
        for (int y=1 ; y<=H; y++) {
            int wall = 6;
            // 현재 검사 중인 노드가 건물 노드일 경우만 계산
            if (graph[x][y] == 1){
                for (int i = 0; i < 6; i++){
                    int nx = x + (y % 2 ? oddDx[i]: evenDx[i]);
                    int ny = y + (y ? oddDy[i]: evenDy[i]);

                    // 인접한 노드가 1 또는 0의 값을 가지는 경우 해당 노드와 인접한 노드 사이에 벽이 존재하지 않음
                    if (graph[nx][ny] == 1 || graph[nx][ny] == 0)
                        wall--;
                }
                result += wall;
            }
        }
    }

    return result;
}
