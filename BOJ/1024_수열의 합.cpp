/*
BOJ 1024[수열의 합]
*/
#include <iostream>
using namespace std;

int n, l;
int main() {
	cin >> n >> l;
	int ans = -1;
	int x = l;
	for (; x <= 100; x++) {
		if( (2 * n - x * x + x) % (2 * x) ==0 && (2 * n - x * x + x) >=0)
			ans = (2 * n - x * x + x) / (2 * x);
		if (ans != -1) break;
	}
	if (ans != -1) {
		for (int i = 0; i < x; i++) {
			cout << ans << " ";
			ans++;
		}
	}
	else
		cout << ans << endl;

}