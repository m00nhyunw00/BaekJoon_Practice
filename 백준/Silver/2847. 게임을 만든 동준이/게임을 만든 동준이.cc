#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int count = 0;

    cin >> N;

    int scores[N];

    for(int i=0; i<N; i++)
        cin >> scores[i];

    for(int i=N-2; i>=0; i--){
        while(scores[i] >= scores[i+1]){
            count++;
            scores[i]--;
        }
    }

    cout << count;

    return 0;
}