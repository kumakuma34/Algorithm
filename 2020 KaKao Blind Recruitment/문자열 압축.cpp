#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = s.length();//�������� �ʾ��� �� ���̷� �ʱ�ȭ
    for (int i = 1; i < s.length(); i++) {//1���� ���̱����� ������ �߶��� �� Ž��
        vector<string> v;
        string temp = "";
        for (int j = 0; j < s.length(); j++) {
            if (j % i == 0 && j != 0) {
                v.push_back(temp);
                temp = "";
            }
            temp += s[j];
        }
        v.push_back(temp);
        v.push_back("");
        //i������ ���ڸ� �߶� ����, ������ ""�� ���� ���� ���Ǹ� ���� ����
        string now = v[0];
        string next = "";
        int cnt = 1;//������ ���ڿ� ���� �ľ� ��
        string result = "";
        for (int j = 1; j < v.size(); j++) {
            next = v[j];
            if (now == next) cnt++;
            else {
                if (cnt == 1) {
                    result += now;
                }//��ġ�� ���ڿ��� ������ ��� ���ڿ��� �״�� �߰�
                else {
                    result += to_string(cnt);
                    result += now;
                }//��ġ�� ���ڿ��� ������ ��ġ�� �� + ���ڿ� �߰�

                cnt = 1;
            }
            now = next;
        }
        if (result.length() < answer)
            answer = result.length();//���� ���亸�� ���̰� ������ �������� ������Ʈ
    }
    return answer;
}
