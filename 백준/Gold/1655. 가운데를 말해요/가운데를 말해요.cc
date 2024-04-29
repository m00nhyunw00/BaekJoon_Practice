#include <iostream>
#include <queue>
#define MIN -10000
#define MAX 10000

using namespace std;

int N;
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

void equalify();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int input;
    for (int i=0; i<N; i++){
        cin >> input;

        maxHeap.push(input);
        equalify();

        cout << maxHeap.top() << "\n";
    }

    return 0;
}

void equalify(){
    if (maxHeap.size() - minHeap.size() > 1){
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }

    if (!minHeap.empty() && maxHeap.top() > minHeap.top()) {
        int maxTop = maxHeap.top();
        int minTop = minHeap.top();
        maxHeap.pop();
        minHeap.pop();
        maxHeap.push(minTop);
        minHeap.push(maxTop);
    }
}

