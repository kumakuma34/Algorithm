#include <string>
#include <vector>
#include <iostream>

using namespace std;

int key1[21][21][4], key2[21][21], key3[21][21], key4[21][21];//열쇠를 4방향 회전한 값

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int n = key.size();
    int m = lock.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            key1[i][j][0] = key[i][j];
    }
    //그대로
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            key1[i][j][1] = key1[n - 1 - j][i][0];
        }
    }//90도 회전

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            key1[i][j][2] = key1[n - 1 - j][i][1];
        }
    }//180도 회전

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            key1[i][j][3] = key1[n - 1 - j][i][2];
        }
    }//270도 회전

    for (int k = 0; k < 4; k++) {
        for (int x = -m; x <= m; x++) {
            for (int y = -m; y <= m; y++) {//4방향 회전, -m부터 m까지의 좌우 이동, 상하 이동 모든 경우의 수 탐색
                bool flag = true;//해당 경우의 가능여부 판단
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < m; j++) {
                        int nx = i + x;
                        int ny = j + y;//key가 이동된 위치
                        if (nx < 0 || nx >= m || ny < 0 || ny >= m) {
                            if (lock[i][j] == 0) {
                                flag = false;
                                break;
                            }//이동된 key의 위치가 lock위 위치를 벗어났는데 lock이 홈이라면 fail
                            else
                                continue;
                            //그 외 이동된 key의 위치가 lock위 위치를 벗어났으면 탐색 필요 X
                        };
                        if (lock[i][j] == 1 && key1[nx][ny][k] == 1) {
                            flag = false;
                            break;
                        }//lock이 돌기이고, 이동된 key도 돌기이면 fail
                        if (lock[i][j] == 0 && key1[nx][ny][k] == 0) {
                            flag = false;
                            break;
                        }//lock이 홈이고 이동된 key도 홈이면 fail
                    }
                }
                if (flag) {
                    answer = true;
                }
                if (answer) break;
            }
        }
    }
  

    return answer;
}

int main() {
    solution({ {0,0,0}, {1,0,0}, {0,1,1} }, { {1,1,1}, {1,1,0},{1,0,1} });
}