#include<iostream>

using namespace std;
int map[101];
int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, P;
		cin >> N >> P;
		int standard = N / P;
		for (int i = 0; i < P; i++)
			map[i] = standard;
		for (int i = 0; i < N - (standard * P); i++) {
			map[i]++;
		}
		long long ans = 1;
		for (int i = 0; i < P; i++) {
			ans *= map[i];
		}
		cout <<"#"<<test_case<<" "<< ans << endl;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 이 부분에 여러분의 알고리즘 구현이 들어갑니다.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}