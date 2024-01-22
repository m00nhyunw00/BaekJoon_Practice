#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector<int> arr;

    cin >> n;

    int num;
    for(int i=0; i<n; i++){
        cin >> num;
        arr.push_back(num);
    }

    int sum = arr[0];
    int temp = arr[0];

    for(int i=1; i<n; i++){
        int value = arr[i];
        temp = max(value, temp + value);    // 현재 탐색 중인 원소 > (현재 탐색 중인 원소 + 현재까지의 임시합)일 경우를 판단
        sum = max(sum, temp);   // 현재 탐색 중인 원소가 음수일 경우는 sum이 temp보다 클 수밖에 없음
    }

    cout << sum;

    return 0;
}