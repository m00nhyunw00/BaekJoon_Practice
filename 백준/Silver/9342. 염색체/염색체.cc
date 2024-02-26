#include <iostream>
#include <regex>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    // 정규표현식 정의
    regex pattern("(^[A-F]?A+F+C+[A-F]?$)");

    cin >> T;

    string str;

    for(int i=0; i<T; i++){
        cin >> str;
        // 만약 입력 받은 문자열이 정규표현식의 패턴과 일치한다면 True 반환
        if(regex_match(str, pattern))
            cout << "Infected!" << "\n";
        else
            cout << "Good" << "\n";
    }

    return 0;
}