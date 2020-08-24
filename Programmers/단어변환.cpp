#include <string>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#include <iostream>

using namespace std;

int map[51][51];
int dist[51];
bool check(string from, string to) {
    int diff = 0;
    for (int i = 0; i < from.length(); i++) {
        if (from[i] != to[i])
            diff++;
    }
    if (diff == 1) return true;
    else return false;
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int end = -1;
    for (int i = 0; i < words.size(); i++)
        dist[i] = 987654321;

    queue<int> q;
    for (int i = 0; i < words.size(); i++) {
        if (check(begin, words[i])) {
            dist[i] = 1;
            q.push(i);
        } 
        if (words[i] == target) end = i;
    }
    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < words.size(); j++) {
            if (check(words[i], words[j])) map[i][j] = 1;
        }
    }

    while (!q.empty()) {
        int x = q.front();
        int cost = dist[x];
        q.pop();
        for (int i = 0; i < words.size(); i++) {
            if (map[x][i] && (dist[i] > cost + 1)) {
                q.push(i);
                dist[i] = cost + 1;
            }
        }
        /*cout << x << ": ";
        for (int i = 0; i < words.size(); i++)
            cout << dist[i] << " ";
        cout << endl;*/
    }
    if (end == -1 || dist[end] == 987654321) answer = 0;
    else answer = dist[end];
    return answer;
}

int main() {
    cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });
}