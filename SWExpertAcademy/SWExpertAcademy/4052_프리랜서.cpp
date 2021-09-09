#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 500

vector<pair<int, pair<int, int> > > v;//finish, start, pay
int dp[MAX_N + 2], before[MAX_N + 2];
int T, N, M;

void init() {
	v.clear();
	for (int i = 0; i < N; i++) {
		dp[i] = 0;
		before[i] = -1;
	}
}
void print() {
	for (int i = 0; i < N; i++) {
		cout << v[i].second.first << " , " << v[i].first << " : " << before[i] << endl;
		cout << "Dp : " << dp[i] << endl;
	}
}
int main(int argc, char** argv)
{
	int test_case;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		//input
		cin >> N >> M;
		init();

		int s, f, p;
		for (int i = 0; i < N; i++) {
			cin >> s >> f >> p;
			v.push_back(make_pair(f, make_pair(s, p)));
		}

		//끝나는 시간을 기준으로 정렬
		sort(v.begin(), v.end());

		//before 배열 구하기(before : 자신과 겹치지 않는 가장 큰 인덱스)
		for (int i = 0; i < N; i++) {
			int start = v[i].second.first;
			int finish = v[i].first;
			for (int j = i - 1; j >= 0; j--) {
				int start_cmp = v[j].second.first;
				int finish_cmp = v[j].first;
				if (finish_cmp < start) {
					before[i] = j;
					break;
				}
			}
		}

		//print();
		dp[0] = v[0].second.second;
		for (int i = 1; i < N; i++) {
			if (before[i] == -1)
				dp[i] = max(dp[i - 1], v[i].second.second);
			else
				dp[i] = max(dp[i - 1], dp[before[i]] + v[i].second.second);
		}
		//print();
		cout << "#" << test_case << " " << dp[N - 1] << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}