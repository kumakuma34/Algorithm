#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 1001;//�ִ����� �ʱ�ȭ
    
    string prev = "";
    string next = "";
    for (int i = 1; i < s.length(); i++) {
        int idx = 0;
        prev = "";
        for (int j = 0; j < i; j++) {
            next += s[idx];
            idx++;
        }
        cout << prev << " ";
        prev = next;
        cout << next << endl;
        next = "";
        
    }//���ڿ��� �ڸ��� ������ 1���� ���� ���̱��� ����Ž��

    return answer;
}

int main() {
    solution("aaBB");
}