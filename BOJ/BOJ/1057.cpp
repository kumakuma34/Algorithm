/*
[1057] 토너먼트
*/

#include <iostream>
using namespace std;
int n, a, b;
int main() {
	cin >> n >> a >> b;
	int ans = 0;
	while (a != b) {
		a = a / 2 + a % 2;
		b = b / 2 + b % 2;
		ans++;
	}
	cout << ans << endl;

}