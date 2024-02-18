#include <iostream>
#include <string>
#include <vector>
using namespace std;

void makeQuardTree(int x1, int y1, int x2, int y2);
char checkPixels(int x1, int y1, int x2, int y2);

int N;
vector<string> V;
vector<char> QT;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    string str;
    for (int i=0; i<N; i++){
        cin >> str;
        V.push_back(str);
    }

    makeQuardTree(0,0,N-1,N-1);

    return 0;
}

void makeQuardTree(int x1, int y1, int x2, int y2){
    char flag = checkPixels(x1, y1, x2, y2);
    // 검사한 영역에 복수의 색상이 존재할 경우
    if(flag == 'F'){
        cout << '(';
        makeQuardTree(x1, y1, (x1 + x2)/2, (y1 + y2)/2);    // 오른쪽 위
        makeQuardTree(x1, (y1 + y2)/2 + 1, (x1 + x2)/2, y2);    // 왼쪽 위
        makeQuardTree((x1 + x2)/2 + 1, y1, x2, (y1 + y2)/2);    // 오른쪽 아래
        makeQuardTree((x1 + x2)/2 + 1, (y1 + y2)/2 + 1, x2, y2);    // 왼쪽 아래
        cout << ')';
    }
    // 검사한 영역의 색상이 모두 흰색일 경우
    else if(flag == '0')
        cout << 0;
    // 검사한 영역의 색상이 모두 검정색일 경우
    else
        cout << 1;
}

char checkPixels(int x1, int y1, int x2, int y2){
    char result = V[x1][y1];

    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            if(result != V[i][j]){
                result = 'F';
                return result;
            }
        }
    }

    return result;
}
