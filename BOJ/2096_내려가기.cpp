#include <iostream>
#include <algorithm>
using namespace std;

int N;
int minDP[2][3], maxDP[2][3];
int main() {
	cin >> N;
	int a, b, c;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		if (i == 0) {
			minDP[0][0] = a;
			minDP[0][1] = b;
			minDP[0][2] = c;

			maxDP[0][0] = a;
			maxDP[0][1] = b;
			maxDP[0][2] = c;

			minDP[1][0] = a;
			minDP[1][1] = b;
			minDP[1][2] = c;

			maxDP[1][0] = a;
			maxDP[1][1] = b;
			maxDP[1][2] = c;
		}
		else {
			minDP[0][0] = minDP[1][0];
			minDP[0][1] = minDP[1][1];
			minDP[0][2] = minDP[1][2];

			maxDP[0][0] = maxDP[1][0];
			maxDP[0][1] = maxDP[1][1];
			maxDP[0][2] = maxDP[1][2];
			

			minDP[1][0] = min(minDP[0][0], minDP[0][1]) + a;
			minDP[1][1] = min(min(minDP[0][0], minDP[0][1]), minDP[0][2]) + b;
			minDP[1][2] = min(minDP[0][1], minDP[0][2]) + c;

			maxDP[1][0] = max(maxDP[0][0], maxDP[0][1]) + a;
			maxDP[1][1] = max(max(maxDP[0][0], maxDP[0][1]), maxDP[0][2]) + b;
			maxDP[1][2] = max(maxDP[0][1], maxDP[0][2]) + c;

			//cout << minDP[1][0] << " " << minDP[1][1] << " " << minDP[1][2] << endl;
		}
	}

	int min_ans = min(min(minDP[1][0], minDP[1][1]), minDP[1][2]);
	int max_ans = max(max(maxDP[1][0], maxDP[1][1]), maxDP[1][2]);
	cout << max_ans << " " << min_ans << endl;
}