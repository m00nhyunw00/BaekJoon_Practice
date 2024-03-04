#include <iostream>
#define V_MAX 1000001

using namespace std;

int parent[V_MAX];              // Union-Find 자료구조 테이블
void initializeParent();        // Union-Find 자료구조 테이블 초기화하는 함수
int getParent(int index);       // Union-Find 자료구조에서 index 노드의 부모를 찾는 함수
void unionParent(int a, int b); // Union-Find 자료구조에서 두개의 노드를 연결하는 함수
bool findParent(int a, int b);  // Union-Find 자료구조에서 특정한 두개의 노드가 같은 그래프에 속하는지 검사하는 함수

int n, m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n >> m;

    initializeParent();

    for (int i=0; i<m; i++){
        int mode, a, b;
        cin >> mode >> a >> b;

        if (mode == 0){
            unionParent(a, b);
        }
        else if (mode == 1){
            if(findParent(a, b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}

// Union-Find 자료구조 테이블 초기화하는 함수
void initializeParent(){
    for (int i=0; i<=n; i++)
        parent[i] = i;
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

    if (a > b)
        parent[a] = b;
    else
        parent[b] = a;
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