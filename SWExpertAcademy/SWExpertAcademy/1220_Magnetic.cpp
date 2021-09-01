#include<iostream>
#include <stdio.h>
using namespace std;

int map[101][101];
int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	int N; // 테이블의 크기
	
	//freopen("input.txt", "r", stdin);

	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;

		int ans = 0;//교착상태의 개수 

		//input
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		for (int j = 0; j < N; j++) {
			bool downFlag = false;//아래로 내려가는게 막혀 있는 경우 
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
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}