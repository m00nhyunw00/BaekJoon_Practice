#include <iostream>
#include <vector>

using namespace std;

int N;
int ans = 0;
int getTotal(int A, int B, int goal);
vector<int> info;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    info.resize(N);

    for (int i=0; i<N; i++)
        cin >> info[i];

    for (int i=0; i<N; i++){
        int goal = i;

        for (int j=0; j<N; j++){
            if (j == i)
                continue;
            for (int k=0; k<N; k++){
                if (k == i || k == j)
                    continue;
                ans = max(ans, getTotal(j, k, i));
            }
        }
    }

    cout << ans;

    return 0;
}

int getTotal(int A, int B, int goal){
    int result = 0;

    if (A < goal){
        for (int i=A+1; i<=goal; i++){
            if (i == B)
                continue;
            result += info[i];
        }
    }
    else{
        for (int i=A-1; i>=goal; i--){
            if (i == B)
                continue;
            result += info[i];
        }
    }

    if (B < goal){
        for (int i=B+1; i<=goal; i++){
            if (i == A)
                continue;
            result += info[i];
        }
    }
    else{
        for (int i=B-1; i>=goal; i--){
            if (i == A)
                continue;
            result += info[i];
        }
    }

    return result;
}