#include<iostream>
#include <stdio.h>
using namespace std;

int map[101][101];
int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	int N; // ���̺��� ũ��
	
	//freopen("input.txt", "r", stdin);

	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;

		int ans = 0;//���������� ���� 

		//input
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		for (int j = 0; j < N; j++) {
			bool downFlag = false;//�Ʒ��� �������°� ���� �ִ� ��� 
			for (int i = 0; i < N; i++) {
				if (map[i][j] == 1) {
					if (!downFlag) downFlag = true;
				}
				else if (map[i][j] == 2) {
					if (downFlag) {
						ans++;
						downFlag = false;
					}
				}
			}
		}

		cout << "#" << test_case << " " << ans << endl;
	

	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}