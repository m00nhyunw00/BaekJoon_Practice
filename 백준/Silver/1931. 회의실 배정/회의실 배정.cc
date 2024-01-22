#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// pair의 두번째 인수, 즉 끝나는 시간 기준으로 정렬, 같을 경우 첫번째 인수 기준으로 정렬
bool compare(pair<int, int>a, pair<int, int>b) {
    if (a.second == b.second)
        return a.first < b.first;
    else return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int startTime, endTime;
    int num = 0;
    vector<pair<int, int>> meetings;

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> startTime >> endTime;
        meetings.push_back(pair<int, int>(startTime, endTime));
    }

    // 끝나는 시간 기준으로 정렬
    sort(meetings.begin(),meetings.end(), compare);

    num++;
    int end = meetings[0].second;

    // 가장 최근에 확정된 회의 종료 시간 < 현재 탐색 중인 회의 시작 시간 -> 회의 확정
    for(int i=1; i<meetings.size(); i++){
        if (meetings[i].first >= end){
            end = meetings[i].second;
            num++;
        }
    }

    cout << num;

    return 0;
}