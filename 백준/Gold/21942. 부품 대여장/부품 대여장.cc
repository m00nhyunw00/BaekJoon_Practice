#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

int N, F;                   // N: 정보의 개수, F: 초과분(minute) 당 벌금
string L;                   // L: 최대 대여 가능 기간
string D, T, P, M;          // D: 대여 날짜, T: 대여 시각, P: 부품 이름, M: 대여자 이름
int maxMinutes;             // 최대 대여 가능 기간 -> 분으로 변환
bool isExist = false;       // 벌금 납부해야하는 사람이 있는지 없는지 확인하는 flag 변수
int accumulatedDays[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365}; // 월별 누적 일수
map<string, long long> results;     // 초과자 명단


int time2Minutes(string L);     // DDD/hh:mm 포맷 분으로 변환 후 반환
int time2Minutes(string D, string T);   // yyyy-MM-dd hh:mm 포맷 분으로 변환 후 반환

// 대여장 정보 저장 클래스
class info{
public:
    string name;        // 대여자 이름
    string part;        // 대여 부품 이름
    string startD;      // 대여 시작일
    string startT;      // 대여 시작시각

    // 생성자
    info(string name, string part, string startD, string startT){
        this->name = name;
        this->part = part;
        this->startD = startD;
        this->startT = startT;
    }

    // 대여 종료 시 초과분 계산 함수
    void calculate(string endD, string endT){
        long long exceededMinutes = time2Minutes(endD, endT) - time2Minutes(startD, startT) - maxMinutes;   // 초과분

        // 초과분 > 0일 경우 대여 기간을 초과하였다는 뜻이므로 초과자 명단 갱신 및 isExit값 갱신
        if (exceededMinutes > 0){
            results[name] += exceededMinutes;
            isExist = true;
        }
    }
};

map<pair<string, string>, info> recordBook;     // 대여장

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L >> F;

    maxMinutes = time2Minutes(L);

    // 대여장을 입력받아 정보를 map에 저장
    for (int i = 0; i < N; i++){
        cin >> D >> T >> P >> M;

        // 입력받은 정보가 이미 대여장에서 검색
        auto target = recordBook.find(make_pair(M, P));

        if (target != recordBook.end()){    // 만약 입력받은 정보가 대여장에 있다면
            target->second.calculate(D, T);    // 초과분을 계산하여 필요하다면 초과자 명단을 갱신
            recordBook.erase(make_pair(M, P));    // 대여장에서 정보를 삭제
        }
        else    // 만약 입력받은 정보가 대여장에 없다면
            recordBook.emplace(make_pair(M, P), info(M, P, D, T));  // 대여장에 새로운 정보 기입
    }

    // 결과 출력
    if(isExist){    // 초과자가 있다면
        for (const auto& result : results)
            cout << result.first << " " << result.second * F << "\n";
    }
    else    // 초과자가 없다면
        cout << -1;

    return 0;
}

int time2Minutes(string L){
    // DDD/hh:mm 형식에서 일(day), 시(hour), 분(minute)을 추출
    stringstream ss(L);
    string token;

    getline(ss, token, '/');
    int day = stoi(token);
    getline(ss, token, ':');
    int hour = stoi(token);
    getline(ss, token, ':');
    int minute = stoi(token);

    // 일(day)을 분으로 변환하고, 시(hour)을 분으로 변환하여 분(minute)으로 통합
    long long totalMinutes = day * 24 * 60 + hour * 60 + minute;
    return totalMinutes;
}

int time2Minutes(string D, string T){
    // yyyy-MM-dd hh:mm 형식에서 월(month), 일(day), 시(hour), 분(minute)을 추출
    stringstream ss1(D);
    stringstream ss2(T);
    string token;

    getline(ss1, token, '-');
    int year = stoi(token);
    getline(ss1, token, '-');
    int month = stoi(token);
    getline(ss1, token, '-');
    int day = stoi(token);

    getline(ss2, token, ':');
    int hour = stoi(token);
    getline(ss2, token, ':');
    int minute = stoi(token);

    long long totalMinutes = (accumulatedDays[month-1] + day) * 24 * 60 + hour * 60 + minute;
    return totalMinutes;
}