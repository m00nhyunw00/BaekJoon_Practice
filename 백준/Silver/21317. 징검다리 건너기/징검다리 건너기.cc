#include <iostream>
//#include <queue>
using namespace std;
#define INF 2147483647

//void calculateTotalCost(int currentNum, int maxNum, int flag, int result, int jumpCost[][2]);
//priority_queue<int> totalCosts;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int smallJump, bigJump;

    cin >> N;

    int jumpCost[N][2];

    for(int i=1; i<N; i++){
        cin >> smallJump >> bigJump;
        jumpCost[i][0] = smallJump;
        jumpCost[i][1] = bigJump;
    }

    cin >> jumpCost[0][0];

    int totalCost[N][2];

    totalCost[1][0] = 0;
    totalCost[1][1] = INF;
    totalCost[2][0] = totalCost[1][0] + jumpCost[1][0];
    totalCost[2][1] = INF;
    totalCost[3][0] = min(totalCost[1][0] + jumpCost[1][1], totalCost[2][0] + jumpCost[2][0]);
    totalCost[3][1] = INF;
    totalCost[4][0] = min(totalCost[2][0] + jumpCost[2][1], totalCost[3][0] + jumpCost[3][0]);
    totalCost[4][1] = jumpCost[0][0];
    totalCost[5][0] = min(totalCost[3][0] + jumpCost[3][1], totalCost[4][0] + jumpCost[4][0]);
    totalCost[5][1] = min(totalCost[2][0] + jumpCost[0][0], totalCost[4][1] + jumpCost[4][0]);

    for(int i=6; i<N+1; i++) {
        totalCost[i][0] = min(totalCost[i-1][0] + jumpCost[i-1][0], totalCost[i-2][0] + jumpCost[i-2][1]);
        totalCost[i][1] = min(totalCost[i-3][0] + jumpCost[0][0], min(totalCost[i-1][1] + jumpCost[i-1][0], totalCost[i-2][1] + jumpCost[i-2][1]));
    }
    
    cout << min(totalCost[N][0], totalCost[N][1]);

//    calculateTotalCost(1,N,0,0,jumpCost);
//
//    cout << -totalCosts.top();

    return 0;
}

//void calculateTotalCost(int currentNum, int maxNum, int flag, int result, int jumpCost[][2]){
//    int remainNum = maxNum - currentNum;    // 남은 돌 갯수
//    if(remainNum == 0){     // 만약 남은 돌 갯수가 0이라면 총 사용된 에너지를 우선순위 큐에 저장 후 함수 종료
//        totalCosts.push(-result);   // 기본적으로 maxHeap이므로 - 연산을 통해 minHeap의 기능을 하도록 구현
//        return;
//    }
//    if(flag==0){    // 만약 아직 매우 큰 점프를 하지 않았다면
//        if(remainNum >= 3)  // 남은 돌 갯수가 3 이상이라면 매우 큰 점프 실행, flag 값 1로 갱신 후 재귀
//            calculateTotalCost(currentNum + 3, maxNum, 1, result + jumpCost[0][0], jumpCost);
//        if(remainNum >= 2)  // 남은 돌 갯수가 2 이상이라면 큰 점프 실행 후 재귀
//            calculateTotalCost(currentNum + 2, maxNum, 0, result + jumpCost[currentNum][1], jumpCost);
//        // 남은 돌 갯수가 1 이상이라면 작은 점프 실행 후 재귀
//        calculateTotalCost(currentNum + 1, maxNum, 0, result + jumpCost[currentNum][0], jumpCost);
//    }
//    else{   // 만약 매우 큰 점프를 이미 했다면
//        if(remainNum >= 2)  // 만약 남은 돌 갯수가 2 이상이라면 큰 점프 실행 후 재귀
//            calculateTotalCost(currentNum + 2, maxNum, 0, result + jumpCost[currentNum][1], jumpCost);
//        // 만약 남은 돌 갯수가 1 이상이라면 작은 점프 실행 후 재귀
//        calculateTotalCost(currentNum + 1, maxNum, 0, result + jumpCost[currentNum][0], jumpCost);
//    }
//}
