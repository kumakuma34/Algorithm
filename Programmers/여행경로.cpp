#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
bool dfs(string from, vector<vector<string> > tickets, vector<bool> visit, vector<string> temp,
    vector<string> answer, int cnt) {
    temp.push_back(from);

    if (cnt == tickets.size()) {
        answer = temp;
        return true;
    }

    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == from && !visit[i]) {
            visit[i] = true;
            bool success = dfs(tickets[i][1], tickets, visit, temp, answer, cnt + 1);
            if (success)
                return true;
            visit[i] = false;
        }
    }
    temp.pop_back();
    return false;
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(), tickets.end());
    vector<pair<string, int> > v;
    queue<pair<string, int> > q;
    bool used[10001];
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == "ICN") {
            v.push_back({ tickets[i][0] , i });
        }
    }
    int cnt = 0;
    string now;
    string dest;
    int idx;
    for (int i = 0; i < v.size(); i++) {
        cnt = 1;
        q.push(v[i]);
        for (int j = 0; j < tickets.size(); j++)
            used[j] = false;
        while (!q.empty()) {
            vector<pair<string, int> > v;
            now = q.front().first;
            idx = q.front().second;
            dest = tickets[idx][1];
            used[idx] = true;
            answer.push_back(now);
            q.pop();
            for (int i = 0; i < tickets.size(); i++) {
                if (tickets[i][0] == dest && !used[i]) {
                    v.push_back({ tickets[i][0] , i });
                }
            }
            if (v.size() > 0) {
                q.push(v[0]);
                cnt++;
            }
        }
        if (cnt != tickets.size()) answer.clear();
        if (!answer.empty()) break;
    }
    answer.push_back(tickets[idx][1]);
    return answer;
}
