#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 987654321;
    int N = weak.size();
    vector<vector<int> > shift;//����� Ž�� ������ ���� �迭
    vector<vector<int> > order;//ģ������ ���� ������ ���� �迭

    //������� �� ĭ �� shift�ϸ� ��� �湮 ���� Ž��
    for (int i = 0; i < weak.size(); i++) {
        vector<int> v;
        for (int j = 0; j < weak.size(); j++) {
            int tmp = weak[(i + j) % weak.size()];
            v.push_back(weak[(i+j)%weak.size()]);
            if (j != 0 && v[j] < v[j - 1]) v[j] += n;
        }
        shift.push_back(v);
    }
    
    //(����) ģ������ ���� ��� ����� �� Ž��
    vector<int> now;
    do {
        for (int j = 0; j < dist.size(); j++) {
            now.push_back(dist[j]);
        }
        order.push_back(now);
        now.clear();
    } while (next_permutation(dist.begin(), dist.end()));

    
    for (int k = 0; k < shift.size(); k++) {//��� ����� Ž�� ������ ����
        for (int i = 0; i < order.size(); i++) {//��� ģ������ ���� ������ ����
            int start = shift[k][0], end = start;
            for (int j = 0; j < order[i].size(); j++) {
                int now = order[i][j];//���� ���� ģ���� �� �� �ִ� �Ÿ�
                end = start + now;
                if (end >= shift[k][N - 1]) {//��� ����� Ž���� ��ģ ���
                    if (answer > j + 1) answer = j + 1;//���� ���� ģ�� ���� �������� ans ������Ʈ
                    break;
                }
                else {
                    for (int l = 0; l < shift[k].size(); l++) {//���� ������� Ž�� ���� ����
                        if (shift[k][l] > end) {
                            start = shift[k][l];
                            break;
                        }
                    }
                }
            }
        }
    }
    
    if (answer == 987654321) answer = -1; //Ž���� �� ���� ��� -1
    return answer;
}
