#include <iostream>
#include <queue>

using namespace std;

int N, K;
priority_queue<int> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    int total;
    int temp;
    int prior = 0;

    cin >> temp;
    prior = temp; total = temp;

    for (int i=1; i<N-1; i++){
        cin >> temp;
        pq.emplace(temp-prior);
        prior = temp;
    }

    cin >> temp;
    pq.emplace(temp-prior);
    prior = temp; total = temp - total;

    for (int i=0; i<K-1; i++){
        int value = pq.top();
        pq.pop();
        total -= value;
    }

    cout << total;

    return 0;
}