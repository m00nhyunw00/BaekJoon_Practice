#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 8

vector<vector<int>> Laboratory;
vector<pair<int, int>> virus;

void bfs();
void simulation(int extraNum);
int getSafetyArea(vector<vector<int>> lab, int N, int M);

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int N, M;
int result = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int lab[MAX][MAX];

    cin >> N >> M;
    Laboratory.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> Laboratory[i][j];
            if (Laboratory[i][j] == 2) virus.push_back(make_pair(i, j));
        }
    }

    simulation(3);

    cout << result;

    return 0;
}

void bfs()
{
    vector<vector<int>> lab = Laboratory;
    queue<pair<int, int>> q;

    for (pair<int, int> virusPos : virus)
        q.push(virusPos);

    while (!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (size_t i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (0 <= ny
                && N > ny
                && 0 <= nx
                && M > nx
                && 0 == lab[ny][nx])
            {
                lab[ny][nx] = lab[y][x] + 1;
                q.push({ ny, nx });
            }
        }
    }

    int SafeArea = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (lab[i][j] == 0)
            {
                SafeArea++;
            }
        }
    }

    result = max(result, SafeArea);
}

void simulation(int extraNum) {
    if (extraNum == 0) {
        bfs();
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (Laboratory[i][j] == 0) {
                Laboratory[i][j] = 1;
                simulation(extraNum - 1);
                Laboratory[i][j] = 0;
            }
        }
    }
}