#include<iostream>
#include <string>
using namespace std;

string codes[10] = { "0001101", "0011001" , "0010011", "0111101", "0100011" ,
"0110001", "0101111", "0111011" , "0110111" , "0001011" };

//�ùٸ� ��ȣ �ڵ����� Ȯ��, �ùٸ��� ���� ��� 0���� return 
int checkValid(string code) {
	int idx = 0;
	int data[8];
	for (int i = 0; i < code.length(); i+=7) {
		string now = code.substr(i, 7);
		for (int j = 0; j < 10; j++) {
			if (now == codes[j]) {
				data[idx] = j;
				break;
			}
		}
		idx++;
	}
	
	int result = (data[0] + data[2] + data[4] + data[6]) * 3 + data[1] + data[3] + data[5] + data[7];
	if (result % 10 == 0) {
		int sum = 0;
		for (int i = 0; i < 8; i++) {
			sum += data[i];
		}
		return sum;
	}
	else 
		return 0;
}

int main(int argc, char** argv)
{
	int test_case;
	int T, N, M;
	string input[51];
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int ans = 0;
		cin >> N >> M;
		bool startWithZero = false;
		
		for (int i = 0; i < N; i++) {
			cin >> input[i];
		}

		for (int i = 0; i< N; i++) {
			for (int j = M; j >0; j--) {
				if (j - 55 <= 0) continue;
				if (input[i][j] == '1' && input[i][j - 55] == '0') {
					ans = checkValid(input[i].substr(j - 55, 56));
					if (ans) break;
				}
			}
		}
		cout << "#" <<test_case<<" " << ans << endl;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 �� �κп� �������� �˰��� ������ ���ϴ�.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}