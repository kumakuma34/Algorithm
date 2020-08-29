#include <string>
#include <vector>
#include <iostream>

using namespace std;

int key1[21][21][4], key2[21][21], key3[21][21], key4[21][21];//���踦 4���� ȸ���� ��

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int n = key.size();
    int m = lock.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            key1[i][j][0] = key[i][j];
    }
    //�״��
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            key1[i][j][1] = key1[n - 1 - j][i][0];
        }
    }//90�� ȸ��

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            key1[i][j][2] = key1[n - 1 - j][i][1];
        }
    }//180�� ȸ��

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            key1[i][j][3] = key1[n - 1 - j][i][2];
        }
    }//270�� ȸ��

    for (int k = 0; k < 4; k++) {
        for (int x = -m; x <= m; x++) {
            for (int y = -m; y <= m; y++) {//4���� ȸ��, -m���� m������ �¿� �̵�, ���� �̵� ��� ����� �� Ž��
                bool flag = true;//�ش� ����� ���ɿ��� �Ǵ�
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < m; j++) {
                        int nx = i + x;
                        int ny = j + y;//key�� �̵��� ��ġ
                        if (nx < 0 || nx >= m || ny < 0 || ny >= m) {
                            if (lock[i][j] == 0) {
                                flag = false;
                                break;
                            }//�̵��� key�� ��ġ�� lock�� ��ġ�� ����µ� lock�� Ȩ�̶�� fail
                            else
                                continue;
                            //�� �� �̵��� key�� ��ġ�� lock�� ��ġ�� ������� Ž�� �ʿ� X
                        };
                        if (lock[i][j] == 1 && key1[nx][ny][k] == 1) {
                            flag = false;
                            break;
                        }//lock�� �����̰�, �̵��� key�� �����̸� fail
                        if (lock[i][j] == 0 && key1[nx][ny][k] == 0) {
                            flag = false;
                            break;
                        }//lock�� Ȩ�̰� �̵��� key�� Ȩ�̸� fail
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