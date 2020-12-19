#include <iostream>
#include <string>
using namespace std;

int t, h, w, n;
int main() {
	cin >> t;
	int a, b;
	while (t--) {
		cin >> h >> w >> n;
		if (n % h == 0) {
			a = h;
			b = n / h;
		}
		else {
			a = n % h;
			b = (n / h) + 1;
		}
		string x = to_string(a);
		string y = "";
		if (b < 10) y = '0';
		y += to_string(b);
		cout << x + y << endl;
	}
}