/*
[1124] 언더프라임
*/

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
using namespace std;

vector<int> prime;
bool isPrime[100001];
int a, b;
void getPrime(int n) {
	memset(isPrime, 1, n+1);
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			for (int j = i*2; j <= n; j += i) {
				isPrime[j] = false;
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		if (isPrime[i])
			prime.push_back(i);
	}
}
int main() {
	cin >> a >> b;
	getPrime(b);
	int ans = 0;
	//a부터 b까지 소인수분해
	int cnt = 0;//소인수 분해 후 소수의 개수
	for (int i = a; i <= b; i++) {
		cnt = 0;
		int tmp = i;
		for (int j = 0; j < prime.size(); j++) {
			if (prime[j] > i) break;
			while (tmp % prime[j] == 0) {
				tmp /= prime[j];
				cnt++;
			}
		}
		if (isPrime[cnt]) ans++;
	}

	cout << ans << endl;

}