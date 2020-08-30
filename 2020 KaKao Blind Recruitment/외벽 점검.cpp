#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 987654321;
    int N = weak.size();
    vector<vector<int> > shift;//취약점 탐색 지점을 담을 배열
    vector<vector<int> > order;//친구들을 보낼 순서를 담을 배열

    //취약점을 한 칸 씩 shift하며 모든 방문 순서 탐색
    for (int i = 0; i < weak.size(); i++) {
        vector<int> v;
        for (int j = 0; j < weak.size(); j++) {
            int tmp = weak[(i + j) % weak.size()];
            v.push_back(weak[(i+j)%weak.size()]);
            if (j != 0 && v[j] < v[j - 1]) v[j] += n;
        }
        shift.push_back(v);
    }
    
    //(순열) 친구들을 보낼 모든 경우의 수 탐색
    vector<int> now;
    do {
        for (int j = 0; j < dist.size(); j++) {
            now.push_back(dist[j]);
        }
        order.push_back(now);
        now.clear();
    } while (next_permutation(dist.begin(), dist.end()));

    
    for (int k = 0; k < shift.size(); k++) {//모든 취약점 탐색 순서에 대해
        for (int i = 0; i < order.size(); i++) {//모든 친구들을 보낼 순서에 대해
            int start = shift[k][0], end = start;
            for (int j = 0; j < order[i].size(); j++) {
                int now = order[i][j];//현재 보낸 친구가 갈 수 있는 거리
                end = start + now;
                if (end >= shift[k][N - 1]) {//모든 취약점 탐색을 마친 경우
                    if (answer > j + 1) answer = j + 1;//현재 보낸 친구 수를 기준으로 ans 업데이트
                    break;
                }
                else {
                    for (int l = 0; l < shift[k].size(); l++) {//다음 취약점이 탐색 시작 지점
                        if (shift[k][l] > end) {
                            start = shift[k][l];
                            break;
                        }
                    }
                }
            }
        }
    }
    
    if (answer == 987654321) answer = -1; //탐색할 수 없는 경우 -1
    return answer;
}
