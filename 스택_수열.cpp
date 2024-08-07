#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    int result[100000];
    stack<int> s;
    int num = 1; // 현재 스택에 넣을 숫자
    string output[200000]; // 충분히 큰 배열 크기
    int index = 0;

    for (int i = 0; i < n; i++) {
        cin >> result[i];
    }

    for (int i = 0; i < n; i++) {
        int target = result[i];

        // 목표 숫자에 도달할 때까지 숫자를 스택에 푸시
        while (num <= target) {
            s.push(num++);
            output[index++] = '+';
        }

        // 스택이 비어있지 않고 최상단 숫자가 목표 숫자와 일치하면 팝
        if (!s.empty() && s.top() == target) {
            s.pop();
            output[index++] = '-';
        } else {
            cout << "NO\n";
            return 0;
        }
    }

    for (int i = 0; i < index; i++) {
        cout << output[i] << '\n';
    }

    return 0;
}
