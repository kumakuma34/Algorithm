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

			if (i <= n / 2) {//�ڽ��� �ִ� ���
				int l, r;
				if (i == n / 2 && n % 2 == 0) cin >> l;//���� ��常 ����
				else cin >> l >> r;

				if (c >= '0' && c <= '9') ans = 0;
			}
			else {//�ڽ��� ����leaf ���
				if (!(c >= '0' && c <= '9')) ans = 0;
			}
		}
		cout << "#" << test_case << ' ' << ans << '\n';

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 �� �κп� �������� �˰��� ������ ���ϴ�.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}