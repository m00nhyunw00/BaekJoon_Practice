#include <iostream>
#include <vector>
using namespace std;
#define INF 100000

void floydWarshall();

int findMax();

vector<vector<int>> graph;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    char weight;

    string str;

    for (int i = 0; i < N; i++) {
        cin >> str;
        vector<int> v;
        for (int j = 0; j < N; j++) {
            if (i == j)
                v.push_back(0);
            else if (str[j] == 'Y')
                v.push_back(1);
            else
                v.push_back(INF);
        }
        graph.push_back(v);
    }

    floydWarshall();
    cout << findMax() << '\n';

    return 0;
}

void floydWarshall(){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (graph[j][i] + graph[i][k] < graph[j][k])
                    graph[j][k] = graph[j][i] + graph[i][k];
            }
        }
    }
}

int findMax(){
    int max = 0;
    for (int i = 0; i < N; i++) {
        int count = 0;
        for (int j = 0; j < N; j++) {
            if (i == j)
                continue;
            // 3 이상일 경우 j-k / j-a-k 가 아닌 j-a-b-k가 나올 가능성이 존재
            if (graph[i][j] <= 2)
                count++;
        }
        if (max < count)
            max = count;
    }
    return max;
}