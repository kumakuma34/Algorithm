#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, M;
string map[11];
int dp[11][1025];
bool broke_check(int n, int bit) { //해당 자리가 앉을 수 있는 자리인지 확인
	for (int i = 0; i < map[n].length(); i++) {
		if (map[n][i] == 'x' && (bit & (1 << i))) return false;
	}
	return true;
}

bool cunningCheck(int bit, int bit2) {
	for (int i = 0; i < M; i++) {
		if ((1 << i) & bit2) {//앞자리에 사람이 있을 때
			if (i > 0 && ((1 << (i - 1) & bit))) return false;//왼쪽 뒤일 경우 fail
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

		vector<pair<int, int> > ways; //first : 비트, second : 앉힌 사람 수

		for (int i = 0; i < (1 << M); i++) { //0부터 2^m까지 모두 탐색, 즉 한줄에 앉힐 수 있는 모든 경우 만들기
			if (adj_check(i)) {//양옆 비트가 모두 켜진 상황(양옆으로 인접하여 붙어 앉지 않았을 때)
				int cnt = 0;
				for (int j = 0; j < M; j++) {
					if ((1 << j) & i) cnt++;//비트가 1인 경우 사람을 앉힌 경우임 (and연산으로 1확인)
				}
				ways.push_back({ i,cnt });
			}
		}
		
		for (int k = 1; k <= N; k++) {
			for (int i = 0; i < ways.size(); i++) {
				int bit = ways[i].first;
				int cnt = ways[i].second;
				if (!broke_check(k, bit)) continue; //앉을 수 있는 자리인지 확인
				for (int j = 0; j < ways.size(); j++) {//i-1번째 줄의 경우에 따라 확인
					int bit2 = ways[j].first;
					if (cunningCheck(bit, bit2)) { //컨닝에 걸리지 않게 앉을 수 있는 경우
						dp[k][bit] = max(dp[k][bit], dp[k - 1][bit2] + cnt);
						ans = max(ans, dp[k][bit]);
					}
					
				}


			}
		}
		cout << ans << endl;
	}
}