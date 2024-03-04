#include <iostream>
#include <algorithm>
#include <vector>
#define V_MAX 10001

using namespace std;

int V, E;

void Kruskal();                 // Kruskal 알고리즘을 이용한 최소 스패닝 트리 도출 함수
int result = 0;                 // 최소 스패닝 트리의 가중치합 (최단경로 총 길이)
int parent[V_MAX];              // Union-Find 자료구조를 이용한 KrusKal 알고리즘 사이클 검사 테이블

int getParent(int index);       // Union-Find 자료구조에서 index 노드의 부모를 찾는 함수
void unionParent(int a, int b); // Union-Find 자료구조에서 두개의 노드를 연결하는 함수
bool findParent();              // Union-Find 자료구조에서 특정한 두개의 노드가 같은 그래프에 속하는지 검사하는 함수

// 간선의 정보를 저장하기 위한 클래스 정의
class Edge {
public:
    int node[2];
    int distance;

    Edge(int a, int b, int distance){
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }

    // sort()를 위한 operator 정의
    bool operator<(const Edge &edge) const {
        return this->distance < edge.distance;
    }
};

vector<Edge> edges;     // 간선의 정보

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;

    int A, B, C;
    for (int i=0; i<E; i++){
        cin >> A >> B >> C;
        edges.push_back(Edge(A, B, C));
    }

    sort(edges.begin(), edges.end());   // 간선의 가중치를 기준으로 오름차순 정렬

    Kruskal();  // Kruskal 알고리즘 실행

    cout << result;

    return 0;
}

// Union-Find 자료구조에서 index 노드의 부모를 찾는 함수
int getParent(int index){
    if (index == parent[index])
        return index;
    return parent[index] = getParent(parent[index]);
}

// Union-Find 자료구조에서 두개의 노드를 연결하는 함수
void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);

    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

// Union-Find 자료구조에서 특정한 두개의 노드가 같은 그래프에 속하는지 검사하는 함수
bool findParent(int a, int b){
    a = getParent(a);
    b = getParent(b);

    if (a == b)
        return true;
    else
        return false;
}

// Kruskal 알고리즘을 이용한 최소 스패닝 트리 도출 함수
void Kruskal(){
    // 사이클 체크 테이블 초기화
    for (int i=1; i<=V; i++)
        parent[i] = i;

    for (auto& edge : edges){
        if (!findParent(edge.node[0], edge.node[1])){
//            cout << edge.node[0] << " - " << edge.node[1] << " connected!\n";
            result += edge.distance;
            unionParent(edge.node[0], edge.node[1]);
        }
    }
}
