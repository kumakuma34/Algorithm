#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool gi[102][102] = {};
bool bo[102][102] = {};

bool check_gi(int x, int y, int n) {
    if (y == 0) return 1;
    if (gi[x][y - 1]) return 1;
    if (x > 0 && bo[x - 1][y]) return 1;
    if (x < n && bo[x][y]) return 1;

    return 0;
}
bool check_bo(int x, int y, int n) {
    if (gi[x][y - 1]) return 1;
    if (x < n && gi[x + 1][y - 1]) return 1;
    if (x > 0 && x < n && bo[x + 1][y] && bo[x - 1][y]) return 1;

    return 0;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    for (int i = 0; i < build_frame.size(); i++) {
        int x, y, a, b;

        x = build_frame[i][0];
        y = build_frame[i][1];
        a = build_frame[i][2];
        b = build_frame[i][3];

        if (a == 0 && b == 1) {
            if (check_gi(x, y, n)) {
                gi[x][y] = 1;
            }
        }
        // 보 설치
        else if (a == 1 && b == 1) {
            if (check_bo(x, y, n)) {
                bo[x][y] = 1;
            }
        }
        else if (a == 0 && b == 0) {
            bool flag = 1;
            gi[x][y] = 0;

            if (y < n && gi[x][y + 1] && !check_gi(x, y + 1, n)) flag = false;
            else if (y < n && bo[x][y + 1] && !check_bo(x, y + 1, n)) flag = false;
            else if (x > 0 && bo[x - 1][y + 1] && y < n && !check_bo(x - 1, y + 1, n)) flag = false;

            if (!flag) gi[x][y] = 1;//한가지라도 문제가 생기면 명령어 무시, 원복
        }
        else if (a == 1 && b == 0) {
            bool flag = true;/////////진짜 나새끼야,,,
            bo[x][y] = 0;

            if (gi[x][y] && !check_gi(x, y, n)) flag = 0;
            else if (x < n && gi[x + 1][y] && !check_gi(x + 1, y, n)) flag = 0;
            else if (x > 0 && bo[x - 1][y] && !check_bo(x - 1, y, n)) flag = 0;
            else if (x < n && bo[x + 1][y] && !check_bo(x + 1, y, n)) flag = 0;

            if (!flag) bo[x][y] = 1;//한가지라도 문제가 생기면 명령어 무시, 원복

        }
      
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (gi[i][j]) answer.push_back({ i,j,0 });
            if (bo[i][j]) answer.push_back({ i,j,1 });
        }
    }

    return answer;
}
