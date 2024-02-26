#include <iostream>
#include <vector>
using namespace std;

void floydWarshall();
vector<vector<int>> graph;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int g[N];

    int weight;

    for(int i=0; i<N; i++){
        vector<int> v;
        for(int j=0; j<N; j++){
            cin >> weight;
            v.push_back(weight);
        }
        graph.push_back(v);
    }

    floydWarshall();

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

// 가중치가 존재하지 않으므로, 플로이드-워셜 방법에서 비교 연산자가 아닌 거쳐갈 수 있는 경로가 있는지 없는를 단순 조사하는 방식으로 변경
void floydWarshall(){
    int size = graph.size();

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++) {
            for(int k=0; k<size; k++){
                if(graph[j][i]+graph[i][k] == 2)
                    graph[j][k] = 1;
            }
        }
    }
}
