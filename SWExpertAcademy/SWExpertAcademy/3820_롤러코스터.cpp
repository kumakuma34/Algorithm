#include<iostream>
#include <queue>
#include <vector>

using namespace std;
#define MOD 1000000007
vector<pair<int, int> > v;
priority_queue<pair<double, int> > pq;
int N;

void init() {
	v.clear();
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		cin >> N;
		int a, b;
		for (int i = 0; i < N; i++) {
			cin >> a >> b;
			v.push_back({ a,b });
			double f = (double)(a - 1.0) / (double)b;
			pq.push({f, i });
		}
		long long ans = 1;
		while (!pq.empty()) {
			int idx = pq.top().second;
			pq.pop();
			ans = (((ans * (long long)v[idx].first) % MOD) + v[idx].second) % MOD;
			//cout << idx << endl;
		}

		cout << "#" << test_case << " "<<ans<< endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}