#include <iostream>
#include <cstdio>
#define MAX 1000
#define NUM_TEAM 15
#define INF 1000000
using namespace std;

int info[MAX + 1][2];
int DP[MAX + 1][NUM_TEAM + 1][NUM_TEAM + 1];
int N;

int makeAvengers(int i, int wNum, int bNum);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i = 0;
    int w, b;
    while (scanf("%d %d", &w, &b) == 2) {
        info[i][0] = w;
        info[i++][1] = b;
    }

    N = i;
    cout << makeAvengers(0, 0, 0);

    return 0;
}

int makeAvengers(int i, int wNum, int bNum){
    if (wNum == 15 && bNum == 15)
        return 0;
    if (i == N)
        return 0;
    if (DP[i][wNum][bNum])
        return DP[i][wNum][bNum];
    int result = 0;
    if (wNum < 15)
        result = makeAvengers(i+1, wNum + 1, bNum) + info[i][0];
    if (bNum < 15)
        result = max(result, makeAvengers(i+1, wNum, bNum + 1) + info[i][1]);
    return DP[i][wNum][bNum] = max(result, makeAvengers(i+1, wNum, bNum));
}