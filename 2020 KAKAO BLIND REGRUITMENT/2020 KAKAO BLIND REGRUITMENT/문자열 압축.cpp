#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 1001;//최댓값으로 초기화
    
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
        
    }//문자열을 자르는 단위를 1부터 문자 길이까지 완전탐색

    return answer;
}

int main() {
    solution("aaBB");
}