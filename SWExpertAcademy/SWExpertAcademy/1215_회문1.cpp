#include<iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
vector<string> pelindrome[10];
char map[8][8];

string makePelin(int len, string s) {
	//���� ���߱�
	while (s.length() < len) {
		s += 'D';
	}
	if (len % 2 == 0) {	
		for (int i = 0; i < len/2; i++) {
			s[len - 1 - i] = s[i];
		}
		return s;
	}
	else {
		for (int i = 0; i < len / 2; i++) {
			s[len - 1 - i] = s[i];
		}
		return s;
	}
}
void makeString(int len) {
	queue<string> q;
	q.push("A");
	q.push("B");
	q.push("C");

	while (!q.empty()) {
		string now = q.front();
		q.pop();
		if (now.length() < len / 2) {
			//A, B, C �ٿ��� q�� �ֱ�
			q.push(now + "A");
			q.push(now + "B");
			q.push(now + "C");
		}
		else {
			if (len % 2 == 0)
				pelindrome[len].push_back(makePelin(len, now));
			else{
				pelindrome[len].push_back(makePelin(len, now + 'A'));
				pelindrome[len].push_back(makePelin(len, now + 'B'));
				pelindrome[len].push_back(makePelin(len, now + 'C'));
			}
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	int N; //ã�ƾ� �ϴ� ȸ���� ����
	
	//freopen("input.txt", "r", stdin);

	//Ž�� ���� �� pelindrome �����
	for (int i = 1; i <= 8; i++) {
		makeString(i);
		/*cout << i << " =======================" << endl;
		for (int j = 0; j < pelindrome[i].size(); j++) {
			cout << pelindrome[i][j] << " ";
		}
		cout << endl;
	*/
	}

	for (test_case = 1; test_case <= T; ++test_case)
	{
		//input
		cin >> N;
		int ans = 0;
		for (int i = 0; i < 8; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < 8; j++) {
				map[i][j] = s[j];
			}
		}

		//���ι��� Ž��
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j <= 8 - N; j++) {
				string cmp = "";
				for (int k = 0; k < N; k++) {
					cmp += map[i][j + k];
					for (int l = 0; l < pelindrome[N].size(); l++) {
						if (pelindrome[N][l] == cmp) {
							ans++;
							break;
						}
					}
				}
			}
		}

		//���ι��� Ž��
		for (int j = 0; j < 8; j++) {
			for (int i = 0; i <= 8 - N; i++) {
				string cmp = "";
				for (int k = 0; k < N; k++) {
					cmp += map[i + k][j];
					for (int l = 0; l < pelindrome[N].size(); l++) {
						if (pelindrome[N][l] == cmp) {
							ans++;
							break;
						}
					}
				}
			}
		}
		
		cout << "#"<<test_case<<" " <<ans << endl;

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 �� �κп� �������� �˰��� ������ ���ϴ�.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}