#include <iostream>
#include <vector>
using namespace std;

#define INF 100000001

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    vector<pair<int, int>> stack;
    stack.push_back({ INF,0 });

    cin >> N;

    for (int i=0; i<N; ++i){
        int input;
        cin >> input;
        while (stack.back().first < input) {
            stack.pop_back();
        }
        cout << stack.back().second << " ";
        stack.push_back({ input, i + 1 });
    }

    return 0;
}
