/*
	[1052]¹°º´
*/

#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
int n, k;

int getCount(int n) {
	int cnt = 0;
	while (n > 0) {
		if (n % 2 == 1) cnt++;
		n /= 2;
	}
	return cnt;
}

int main() {
	cin >> n >> k;
	int ans = n;
	while (1) {
		if (getCount(ans) <= k) break;
		else
			ans++;
	}
	cout << ans - n << endl;
}