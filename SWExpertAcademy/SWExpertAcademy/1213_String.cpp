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
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		//input
		int ans = 0;
		int test_num;
		cin >> test_num;
		cin >> cmp >> input;
		
		//kmp �Ⱦ��� �׳� naive�ϰ� ��
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
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}