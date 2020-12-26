#include <iostream>
#include <vector>
using namespace std;

int N, M, ans;
void solve(int n, vector<int> v) {
	if (n == 3) {
		int x = 1, y = 1, i = 0;
		for (i = 0; i < v.size(); i++) {
			int now = v[i];
			if (now == 1) {
				x += 2; y += 1;
			}
			else if (now == 2) {
				x += 1; y += 2;
			}
			else if (now == 3) {
				x -= 1; y += 2;
			}
			else if (now == 4) {
				x -= 2; y += 1;
			}
			if (x > N || x <1 || y > M || y < 1) break;
		}
		if (ans < i + 1) ans = i + 1;
		return;
	}
	else {
		v.push_back(-1);
		for (int k = 1; k <= 4; k++) {
			v[n] = k;
			solve(n + 1, v);
		}
	}
}
int main() {
	cin >> N >> M;
	if (N == 1) ans = 1;
	else if (N == 2) {
		vector<int> v;
		solve(0, v);
	}
	else {
		if (M >= 7) ans = M - 2; //움직임이 4번 넘게 가능한 경우
		else { //움직임이 4번 이하인 경우
			vector<int> v;
			solve(0, v);
		}
	}
	cout << ans << endl;
}