#include <iostream>
#include <stdio.h>
using namespace std;
int map[256][1005];
int ans;
void init() {
	ans = 0;
	for (int i =0; i < 256; i++) {
		for (int j = 0; j < 1005; j++) {
			map[i][j] = 0;
		}
	}
}
int main(int argc, char** argv)
{
	int test_case;
	int T, len;
	
	T = 10; //테스트케이스는 10개
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		scanf("%d", &len);

		int height; //각 건물의 높이 

		//지도에 건물 높이 표시
		for (int j = 0; j < len; j++) {
			scanf("%d", &height);
			for (int i = 0; i < height; i++) {
				map[i][j] = 1;
			}
		}
		
		for (int i = 0; i < 256; i++) {
			for (int j = 2; j < len-2; j++) {
				if (map[i][j] == 0) continue;
				if (map[i][j - 1] == 0 && map[i][j - 2] == 0 && map[i][j + 1] == 0 && map[i][j + 2] == 0)
					ans++;
			}
		}
		
		//정답 출력
		printf("\#%d %d\n", test_case, ans);


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}