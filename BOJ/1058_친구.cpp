#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;
int isFriend[51][51];
int main() {
	cin >> n;
	vector<vector<int> > graph;
	string tmp = "";
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		vector<int> v;
		for (int j = 0; j < n; j++) {
			if (tmp[j] == 'N') v.push_back(0);
			else if (tmp[j] == 'Y') v.push_back(1);
		}
		graph.push_back(v);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] == 1) {
				isFriend[i][j] = 1;//Ž�� ���� ����� ģ�� ����
				int now = j;
				for (int k = 0; k < n; k++) {//ģ�������� ������� ģ���� 2-ģ��
					if (graph[now][k] == 1)
						isFriend[i][k] = 1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (isFriend[i][j] == 1 && i != j ) cnt++;
			//cout << isFriend[i][j] << ' ';
		}
		//cout << endl;
		ans = max(ans, cnt);
		
	}
	cout << ans << endl;
}