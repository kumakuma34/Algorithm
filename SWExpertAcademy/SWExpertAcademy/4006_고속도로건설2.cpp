#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define MAX 50000

int N, M;
int set[MAX + 1];
vector < pair<int, pair<int, int> > > v;

void init() {
	v.clear();
	for (int i = 0; i < MAX + 1; i++)
		set[i] = i;
}

//�θ� ��� Ȯ��
int getPar(int x) {
	if (set[x] == x) return x;
	return set[x] = getPar(set[x]);
}

//�θ� ��带 ����
void unionPar(int a, int b) {
	a = getPar(a);
	b = getPar(b);

	if (a < b) set[b] = a;
	else set[a] = b;
}

//���� �θ����� Ȯ��
int find(int a, int b) {
	a = getPar(a);
	b = getPar(b);
	if (a == b) return 1;
	else return 0;
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		cin >> N >> M;
		int from, to, cost;
		while (M--) {
			cin >> from >> to >> cost;
			v.push_back({ cost, {from, to} } );
		}

		sort(v.begin(), v.end());
		
		int sum = 0;
		for (int i = 0; i < v.size(); i++) {
			if (!find(v[i].second.first, v[i].second.second)) {
				sum += v[i].first;
				unionPar(v[i].second.first, v[i].second.second);
			}
		}

		cout << "#" << test_case << " " << sum << '\n';

	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}