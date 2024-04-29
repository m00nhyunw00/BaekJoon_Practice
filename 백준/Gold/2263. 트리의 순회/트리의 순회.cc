#include <iostream>
#define MAX 100000

using namespace std;

int n;
int inorder[MAX];       // 중위 순회
int postorder[MAX];     // 후위 순회

void getPreorder(int inStart, int inEnd, int postStart, int postEnd);
int searchRootIndex(int target);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i=0; i<n; i++)
        cin >> inorder[i];

    for (int i=0; i<n; i++)
        cin >> postorder[i];

    getPreorder(0, n-1, 0, n-1);

    return 0;
}

void getPreorder(int inStart, int inEnd, int postStart, int postEnd) {
    if (postStart > postEnd)
        return;

    cout << postorder[postEnd] << " ";

    int inRoot = searchRootIndex(postorder[postEnd]);
    int leftTreeNum = inRoot - inStart;

    getPreorder(inStart, inRoot - 1, postStart, postStart + leftTreeNum - 1);   // 왼쪽 서브 트리 재귀
    getPreorder(inRoot + 1, inEnd, postStart + leftTreeNum, postEnd - 1);   // 오른쪽 서브 트리 재귀
}


int searchRootIndex(int target){
    for (int i=0; i<n; i++){
        if (inorder[i] == target)
            return i;
    }
    return -1;
}