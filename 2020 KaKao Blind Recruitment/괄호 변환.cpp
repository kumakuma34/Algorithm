#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

//올바른 괄호 문자열 확인 함수
bool check(string p) {
    stack<char> s;
    for (int i = 0; i < p.length(); i++) {
        if (p[i] == '(')
            s.push('(');
        else {
            if (!s.empty()) s.pop();
            else return false;
        }
    }
    if (s.empty()) return true;
    else return false;
}

//문자열을 u, v로 분리하는 함수
pair<string, string> parse(string s) {
    int cntA = 0, cntB = 0;
    string u = "", v = "";
    int i = 0;
    for (i = 0; i < s.length(); i++) {
        if (s[i] == '(') cntA++;
        else cntB++;
        u += s[i];
        if (cntA == cntB) break;
    }
    for (int j = i + 1; j < s.length(); j++) {
        v += s[j];
    }
    return { u,v };
}
//올바른 괄호열로 변환시킬 문제 정의를 구현할 재귀함수
string func(string p) {
    string ans = "";
    if (p == "") return "";
    string u = "", v = "";
    pair<string, string> tmp = parse(p);
    u = tmp.first; v = tmp.second;

    if (check(u)) {
        return (u + func(v));
    }
    else {
        string tmp = "(";
        tmp += func(v);
        tmp += ')';
        u = u.substr(1, u.length() - 2);
        for (int i = 0; i < u.length(); i++) {
            if (u[i] == '(') tmp += ')';
            else tmp += '(';
        }
        return tmp;
    }
}
string solution(string p) {
    string answer = "";
    if (check(p)) answer = p;
    else answer = func(p);
    return answer;
}
