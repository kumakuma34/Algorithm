#include <iostream>
#include <algorithm>
using namespace std;
int H, W, N;
pair<int, int> arr[101];//스티커 정보

int searchMaxArea(int w1, int h1, int w2, int h2) {
	int res = -1;
	if (max(h1, h2) <= H && w1 + w2 <= W) {
		int now = w1 * h1 + w2 * h2;
		res = max(res, now);
	}
	if (max(w1,w2) <=W && h1+h2 <= H) {//둘다 붙일 수 있는 경우
		int now = w1 * h1 + w2 * h2;
		res = max(res, now);
	}
	/*if (w1 <= W && h1 <= H) res = max(res, w1 * h1);
	if (w2 <= W && h2 <= H) res = max(res, w2 * h2);*/
	
	return res;
}
int main() {
	cin >> H >> W >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		arr[i] = { a,b };
	}
	int ans = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			int w1 = arr[i].first;
			int h1 = arr[i].second;
			int w2 = arr[j].first;
			int h2 = arr[j].second;
			ans = max(ans, searchMaxArea(w1, h1, w2, h2));
			ans = max(ans, searchMaxArea(h1, w1, w2, h2));
			ans = max(ans, searchMaxArea(w1, h1, h2, w2));
			ans = max(ans, searchMaxArea(h1, w1, h2, w2));
		}
	}
	if (ans == -1) cout << "0\n";
	else cout << ans << "\n";
}