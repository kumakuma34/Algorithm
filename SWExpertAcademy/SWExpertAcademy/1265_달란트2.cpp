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
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
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
			 �� �κп� �������� �˰��� ������ ���ϴ�.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}