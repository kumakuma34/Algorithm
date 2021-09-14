#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	int n;

	//freopen("input.txt", "r", stdin);
	
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;

		int ans = 1;
		for (int i = 1; i <= n; i++) {
			char c;
			cin >> i >> c;

			if (i <= n / 2) {//자식이 있는 경우
				int l, r;
				if (i == n / 2 && n % 2 == 0) cin >> l;//왼쪽 노드만 존재
				else cin >> l >> r;

				if (c >= '0' && c <= '9') ans = 0;
			}
			else {//자식이 없는leaf 노드
				if (!(c >= '0' && c <= '9')) ans = 0;
			}
		}
		cout << "#" << test_case << ' ' << ans << '\n';

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 이 부분에 여러분의 알고리즘 구현이 들어갑니다.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}