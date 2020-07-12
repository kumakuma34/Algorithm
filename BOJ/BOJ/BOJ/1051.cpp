/*
[1051] 숫자 정사각형
*/
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n, m;
char map[51][51];//정사각형 정보 입력
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			map[i][j] = tmp[j];
		}
	}

	int len = min(n, m);//n,m중 작은 값이 탐색해야할 길이
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