#include <iostream>
#include <set>
#include <stack>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

#define MAX 200

string input;
int parentheses[10][2];
set<string> results;
int num = 0;

void getExpressions(string input, int index, bool isRemove);
void getExpressions(string str, int index);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> input;

    stack<int> stack;

    for (int i = 0; i < input.size(); ++i){
        if (input[i] == '('){
            parentheses[num][0] = i;
            stack.push(num++);
        }

        else if (input[i] == ')'){
            parentheses[stack.top()][1] = i;
            stack.pop();
        }
    }

//    for(int i=0; i<10;i++)
//        cout << parentheses[i][0] << " " << parentheses[i][1] << endl;

    getExpressions(input, 0);

    for(const auto& result : results)
        cout << result << "\n";

//    getExpressions(input, 0, true);
//    getExpressions(input, 0, false);
//
//    for(const auto& result : results) {
//        if (result == input)
//            continue;
//        cout << result << "\n";
//    }

    return 0;
}

void getExpressions(string input, int index, bool isRemove){
    if (index >= num){
        input.erase(remove(input.begin(), input.end(), 'X'), input.end());
        results.insert(input);
    }
    else{
        if (isRemove){
            input.replace(parentheses[index][0], 1, "X");
            input.replace(parentheses[index][1], 1, "X");
        }

        getExpressions(input, index + 1, true);
        getExpressions(input, index + 1, false);
    }
}

void getExpressions(string str, int index){
    if(index >= num){
        if(str == input)
            return;

        str.erase(remove(str.begin(), str.end(), 'X'), str.end());

//        string result;
//
//        for(const auto& item : str){
//            if(item != 'X')
//                result.push_back(item);
//        }

        results.insert(str);

        return;
    }

    string str1 = str;
    string str2 = str;

    for(int i=0; i<str.size(); i++){
        if(i == parentheses[index][0] || i == parentheses[index][1]){
            str1[i] = str[i];
            str2[i] = 'X';
        }
    }

    getExpressions(str1, ++index);
    getExpressions(str2, index);
}
