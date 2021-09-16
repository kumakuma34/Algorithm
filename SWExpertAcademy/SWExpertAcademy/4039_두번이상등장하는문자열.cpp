#include<iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
string s;

struct suffix {
	int idxex;
	int rank;
	int nextRank;
};
static bool comp(suffix a, suffix b) {
	if (a.rank < b.rank) return true;
	else if (a.rank == b.rank) {
		if (a.nextRank < b.nextRank) return true;
		else if (a.nextRank == b.nextRank) {
			if (a.idxex < b.idxex) return true;
		}
		return false;
	}
	return false;
}
vector<int> findSuffix(string s) {
	vector<suffix> v(N);
	
	for (int i = 0; i < N; i++) {
		int rank = (int)s[i] - (int)'a';
		v[i] = { i,rank };
	}

	for (int i = 0; i < N - 1; i++) {
		v[i].nextRank = v[i + 1].rank;
	}
	v[N - 1].nextRank = -1;

	sort(v.begin(), v.end(), comp);
	
	vector<int> tmp(N);
	for (int len = 4; len < 2 * N; len *= 2) {
		int rank = 0, prev = v[0].rank;
		v[0].rank = rank;
		tmp[v[0].idxex] = 0;

		for (int i = 1; i < N; i++) {
			if (v[i].rank == prev && v[i].nextRank == v[i - 1].nextRank) {
				prev = v[i].rank;
				v[i].rank = rank;
			}
			else {
				prev = v[i].rank;
				v[i].rank = ++rank;
			}
			tmp[v[i].idxex] = i;
		}

		for (int i = 0; i < N; i++) {
			int nextIdx = v[i].idxex + (len / 2);
			if (nextIdx >= N) {
				v[i].nextRank = -1;
				continue;
			}
			v[i].nextRank = v[tmp[nextIdx]].rank;
		}
		sort(v.begin(), v.end(), comp);
	}
	
	vector<int> suffixArr(N);
	for (int i = 0; i < N; i++) {
		suffixArr[i] = v[i].idxex;
	}
	return suffixArr;

}

vector<int> findLCP(string s, vector<int> suffixArr) {
	int len = suffixArr.size();
	vector<int> lcp(len);
	vector<int> invSuff(len);

	for (int i = 0; i < len; i++) {
		invSuff[suffixArr[i]] = i;
	}

	int k = 0;
	for (int i = 0; i < len; i++) {
		if (invSuff[i] == len - 1) {
			k = 0;
			continue;
		}

		int j = suffixArr[invSuff[i] + 1];
		
		while (i + k < len && j + k < len) {
			if (s[i + k] != s[j + k]) {
				break;
			}
			k++;
		}

		lcp[invSuff[i]] = k;

		if (k > 0) k--;
	}
	return lcp;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> s;
		vector<int> suffixArr = findSuffix(s);
		vector<int> lcp = findLCP(s, suffixArr);

		int ans = 0;
		for (int i = 0; i < N; i++) {
			if (ans < lcp[i]) ans = lcp[i];
		}
		cout << "#" << test_case << " " << ans << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}