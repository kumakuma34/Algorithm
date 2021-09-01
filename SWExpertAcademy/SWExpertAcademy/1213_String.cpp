#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	string cmp, input;
	//freopen("input.txt", "r", stdin);
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		//input
		int ans = 0;
		int test_num;
		cin >> test_num;
		cin >> cmp >> input;
		
		//kmp 안쓰고 그냥 naive하게 비교
		for (int i = 0; i <= input.length() - cmp.length(); i++) {
			bool flag = true;
			for (int j = 0; j < cmp.length(); j++) {
				if (input[i+j] != cmp[j]) {
					flag = false;
					break;
				}
			}
			if (flag) ans++;
		}

		cout << "#" << test_case << " " << ans << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}