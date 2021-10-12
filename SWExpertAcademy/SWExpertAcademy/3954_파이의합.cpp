#include<iostream>
#include <vector>
#include <math.h>
using namespace std;

#define MAX 1000000
bool prime[MAX + 1];
vector<int> arr(MAX + 1, 0);
vector<long long> sum(MAX + 1, 0);

//소수 구하기
void solve() {
	//에라토스테네스어쩌구의 체
	prime[1] = true;
	for (int i = 2; i * i <= MAX; i++) {
		if (!prime[i]) {
			// 배수들을 제외 처리.
			for (int j = 2; i * j <= MAX; j++) {
				prime[i * j] = true;
			}
		}
	}
	for (int i = 1; i <= MAX; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= MAX; i++) {
		if (!prime[i]) {
			for (int j = 1; i * j <= MAX; j++) {
				arr[i * j] = (i - 1) * (arr[i * j] / i);
			}
		}
	}

	sum[0] = 0;
	sum[1] = 1;
	for (int i = 2; i <= MAX; i++) {
		sum[i] = sum[i - 1] + arr[i];
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T, a, b;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	solve();

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> a >> b;
		cout << "#"<<test_case<<" "<<sum[b] - sum[a-1] << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}