#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//문자열을 거꾸로 뒤집어서 반환해주는 함수
string swap(string s) {
    string tmp;
    for (int i = s.length() - 1; i >= 0; i--)
        tmp += s[i];
    return tmp;
}
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    vector<vector<string> > order , reverse;
    order.resize(10001);
    reverse.resize(10001);//단어의 길이별로 정렬해서 저장할 배열
    
    for (int i = 0; i < words.size(); i++) {
        order[words[i].length()].push_back(words[i]);
        string re = swap(words[i]);
        reverse[re.length()].push_back(re);
    }//단어의 길이별로 저장
    for (int i = 0; i < order.size(); i++) {
        sort(order[i].begin(), order[i].end());
    }
    for (int i = 0; i < reverse.size(); i++) {
        sort(reverse[i].begin(), reverse[i].end());
    }

    for (int i = 0; i < queries.size(); i++) {
        if (queries[i][0] != '?') {//접두사
            int len = queries[i].length();
            string start = "", end = "";
            for (int j = 0; j < len; j++) {
                if (queries[i][j] != '?') {
                    start += queries[i][j];
                    end += queries[i][j];
                }
                else {
                    start += 'a';
                    end += 'z';
                }
            }
            int cnt = upper_bound(order[len].begin(), order[len].end(), end) - lower_bound(order[len].begin(), order[len].end(), start);
            answer.push_back(cnt);
        }
        else {//접미사
            string now = swap(queries[i]);
            int len = now.length();
            string start = "", end = "";
            for (int j = 0; j < len; j++) {
                if (now[j] != '?') {
                    start += now[j];
                    end += now[j];
                }
                else {
                    start += 'a';
                    end += 'z';
                }
            }
            int cnt = upper_bound(reverse[len].begin(), reverse[len].end(), end) - lower_bound(reverse[len].begin(), reverse[len].end(), start);
            answer.push_back(cnt);
        }
    }
    return answer;
}
