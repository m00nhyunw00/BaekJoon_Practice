#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, input;
    priority_queue<int> maxHeap;

    cin >> N;

    for (int i=0; i<N; i++){
        cin >> input;

        if (input == 0){
            if (maxHeap.empty()){
                cout << 0 << "\n";
                continue;
            }

            cout << maxHeap.top() << "\n";
            maxHeap.pop();
        }
        else{
            maxHeap.push(input);
        }
    }

    return 0;
}