#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, input;

    cin >> K;

    int numCities = pow(2, K) - 1;        // 도시 개수
    int size = numCities + pow(2, K);     // 도시 정보 트리 사이즈

    pair<int, int> info[size];

    for (int i=0; i<numCities; i++)
        info[i] = make_pair(0,0);   // (도시 번호, 방문 여부)
    for (int i=numCities; i<size; i++)
        info[i] = make_pair(-1, -1);

    int present = 0;
    bool flag;

    for (int i=0; i<numCities; i++){
        cin >> input;
        flag = false;

        while (!flag){
            if (info[present * 2 + 1].second == 0){
                present = present * 2 + 1;
                continue;
            }
            else{
                if (info[present].second == 0){
                    info[present].first = input;
                    info[present].second = 1;
                    flag = true;
                    continue;
                }
                else if (info[present * 2 + 2].second == 0){
                    present = present * 2 + 2;
                    continue;
                }
                else{
                    present = (present - 1) / 2;
                    continue;
                }
            }
        }
    }

    int count=0;
    for (int k=0; k<K; k++){
        for (int i=0; i<pow(2,k); i++){
            cout << info[count++].first << " ";
        }
        cout << "\n";
    }

    return 0;
}
