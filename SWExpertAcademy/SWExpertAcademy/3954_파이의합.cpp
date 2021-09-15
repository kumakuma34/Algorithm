#include<iostream>
#include <vector>
#include <math.h>
using namespace std;

#define MAX 1000000
bool prime[MAX + 1];
long long phiValue[MAX];
long long sum[MAX];
//�Ҽ� ���ϱ�
void makePrime() {
	//�����佺�׳׽���¼���� ü
	prime[1] = true;
	for (int i = 2; i * i <= MAX; i++) {
		if (!prime[i]) {
			// ������� ���� ó��.
			for (int j = 2; i * j <= MAX; j++) {
				prime[i * j] = true;
			}
		}
	}
}
long long euler_phi(int n) {
	//n�� ���μ�����
	vector<int> v, c;
	long long ans = 1;
	for (int i = 2; i <= MAX; i++) {
		if (prime[i] == false && n % i == 0) {
			v.push_back(i);
			int cnt = 0;
			while (n % i == 0) { 
				n /= i;
				cnt++;
			}
			c.push_back(cnt);
		}
	}

	for (int i = 0; i < v.size(); i++) {
		ans *= (int)(pow(v[i], c[i]) - (int)(pow(v[i], c[i] - 1)));
	}
	if (n == 1) return ans;
	else return ans * (n - 1);
}
int main(int argc, char** argv)
{
	int test_case;
	int T, a, b;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	makePrime();
	for (int i = 1; i <= MAX; i++) {
		phiValue[i] = euler_phi(i);
	}
	sum[0] = 0;
	sum[1] = 1;
	for (int i = 2; i <= MAX; i++) {
		sum[i] = sum[i - 1] + phiValue[i];
	}
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> a >> b;
		cout << sum[b] - sum[a] << endl;
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}