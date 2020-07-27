/*
[1051] ���� ���簢��
*/
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n, m;
char map[51][51];//���簢�� ���� �Է�
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			map[i][j] = tmp[j];
		}
	}

	int len = min(n, m);//n,m�� ���� ���� Ž���ؾ��� ����
	int ans = -1;
	for (int i = len-1; i >= 0; i--) {
		if (ans != -1) break;
		for (int x = 0; x < n-i; x++) {
			if (ans != -1) break;
			for (int y = 0; y < m-i; y++) { 
				if (map[x][y] == map[x + i][y] && map[x+i][y] == map[x][y + i] && map[x][y+i]== map[x + i][y + i]) {
					ans = i;
					break;
				}
			}
		}
	}
	cout << (ans+1)*(ans+1) << endl;

}