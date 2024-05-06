#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<int> pq;
int result;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i=0; i<N; i++){
        int input;
        cin >> input;
        pq.emplace(input);
    }

    int temp;
    int k = 0;
    result = 0;

    for (int i=0; i<N; i++){
        temp = pq.top();
        pq.pop();
        k++;

        result = max(result, temp * k);
    }

    cout << result;

    return 0;
}
