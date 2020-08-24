#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = s.length();//압축하지 않았을 때 길이로 초기화
    for (int i = 1; i < s.length(); i++) {//1부터 길이까지의 단위로 잘랐을 때 탐색
        vector<string> v;
        string temp = "";
        for (int j = 0; j < s.length(); j++) {
            if (j % i == 0 && j != 0) {
                v.push_back(temp);
                temp = "";
            }
            temp += s[j];
        }
        v.push_back(temp);
        v.push_back("");
        //i단위로 문자를 잘라서 저장, 마지막 ""는 로직 구현 편의를 위해 대입
        string now = v[0];
        string next = "";
        int cnt = 1;//동일한 문자열 개수 파악 용
        string result = "";
        for (int j = 1; j < v.size(); j++) {
            next = v[j];
            if (now == next) cnt++;
            else {
                if (cnt == 1) {
                    result += now;
                }//겹치는 문자열이 없으면 결과 문자열에 그대로 추가
                else {
                    result += to_string(cnt);
                    result += now;
                }//겹치는 문자열이 있으면 겹치는 수 + 문자열 추가

                cnt = 1;
            }
            now = next;
        }
        if (result.length() < answer)
            answer = result.length();//현재 정답보다 길이가 작으면 정답으로 업데이트
    }
    return answer;
}
