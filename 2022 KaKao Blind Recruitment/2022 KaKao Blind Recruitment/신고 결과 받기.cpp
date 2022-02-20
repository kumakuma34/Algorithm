#include <string>
#include <vector>
#include <map>
using namespace std;

pair<string, string> split(string s) {
    string from = "";
    string to = "";
    int i = 0;
    for (i = 0; i < s.size(); i++) {
        if (s[i] == ' ') break;
        from += s[i];
    }
    for (i++; i < s.size(); i++) {
        to += s[i];
    }
    return { from, to };
}
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, int> m; //key : userName, value : index
    int idx = 0;
    bool reportList[1001][1001] = { false, };
    int reportCnt[1001] = { 0, };
    bool reportedUser[1001] = { false, };
    //1. id_list를 돌면서 유저들을 index화 해줄겁니다.
    for (int i = 0; i < id_list.size(); i++) {
        m.insert({ id_list[i],idx++ });
    }
    //2. report 배열을 돌면서 from, to 관계로 어떤 유저가 어떤 유저를 신고했는지 확인
    for (int i = 0; i < report.size(); i++) {
        pair<string, string> p = split(report[i]);
        int fromIdx = m[p.first];
        int toIdx = m[p.second];
        reportList[fromIdx][toIdx] = true;
    }
    //3. 신고당한 횟수를 counting
    for (int i = 0; i < idx; i++) {
        for (int j = 0; j < idx; j++) {
            if (reportList[i][j]) reportCnt[j]++;
        }

    }
    //4. counting 결과를 바탕으로 정지된 유저가 누구인지를 확인
    for (int i = 0; i < idx; i++) {
        if (reportCnt[i] >= k) reportedUser[i] = true;
    }
    //5. 2번에서 만들 배열로 신고한 유저가 정지가 되었는지 확인.
    for (int i = 0; i < idx; i++) {
        int cnt = 0; //정지메일을 수신한 횟수
        for (int j = 0; j < idx; j++) {
            if (reportList[i][j] && reportedUser[j]) cnt++;
        }
        answer.push_back(cnt);
    }
    return answer;
}




