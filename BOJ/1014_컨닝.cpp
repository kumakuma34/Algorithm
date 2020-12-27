#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, M;
string map[11];
int dp[11][1025];
bool broke_check(int n, int bit) { //�ش� �ڸ��� ���� �� �ִ� �ڸ����� Ȯ��
	for (int i = 0; i < map[n].length(); i++) {
		if (map[n][i] == 'x' && (bit & (1 << i))) return false;
	}
	return true;
}

bool cunningCheck(int bit, int bit2) {
	for (int i = 0; i < M; i++) {
		if ((1 << i) & bit2) {//���ڸ��� ����� ���� ��
			if (i > 0 && ((1 << (i - 1) & bit))) return false;//���� ���� ��� fail
			if ((1 << (i + 1) & bit)) return false;
		}
	}	return true;
}

bool adj_check(int bit) {
	for (int i = 0; i < M - 1; i++) {
		int val = (3 << i); //101
		if ((bit & val) == val) return false;
	}
	return true;
}
int main() {
	cin >> T;
	while (T--) {
		int ans = 0;
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= (1 << M); j++) {
				dp[i][j] = 0;
			}
		}

		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			cin >> map[i];
		}

		vector<pair<int, int> > ways; //first : ��Ʈ, second : ���� ��� ��

		for (int i = 0; i < (1 << M); i++) { //0���� 2^m���� ��� Ž��, �� ���ٿ� ���� �� �ִ� ��� ��� �����
			if (adj_check(i)) {//�翷 ��Ʈ�� ��� ���� ��Ȳ(�翷���� �����Ͽ� �پ� ���� �ʾ��� ��)
				int cnt = 0;
				for (int j = 0; j < M; j++) {
					if ((1 << j) & i) cnt++;//��Ʈ�� 1�� ��� ����� ���� ����� (and�������� 1Ȯ��)
				}
				ways.push_back({ i,cnt });
			}
		}
		
		for (int k = 1; k <= N; k++) {
			for (int i = 0; i < ways.size(); i++) {
				int bit = ways[i].first;
				int cnt = ways[i].second;
				if (!broke_check(k, bit)) continue; //���� �� �ִ� �ڸ����� Ȯ��
				for (int j = 0; j < ways.size(); j++) {//i-1��° ���� ��쿡 ���� Ȯ��
					int bit2 = ways[j].first;
					if (cunningCheck(bit, bit2)) { //���׿� �ɸ��� �ʰ� ���� �� �ִ� ���
						dp[k][bit] = max(dp[k][bit], dp[k - 1][bit2] + cnt);
						ans = max(ans, dp[k][bit]);
					}
					
				}


			}
		}
		cout << ans << endl;
	}
}