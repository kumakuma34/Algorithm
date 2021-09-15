#include<iostream>

using namespace std;

int arrB[11], arrN[11];
int N;

long long getInverse(long long a, long long b) {
	long long m = b, t, q;
	long long x = 0, y = 1;

	if (b == 1) return 0;

	//유클리드
	while (a > 1) {
		q = a / b;
		t = b;
		b = (int)(a % b);
		a = t;

		t = x;
		x = y - q * x;
		y = t;
	}

	if (y < 0) y += m;

	return y;
}
long long solve() {
	long long product = 1;
	for (int i = 0; i < N; i++) {
		product *= arrN[i];
	}

	long long result = 0;
	for (int i = 0; i < N; i++) {
		long long partialProduct = product / arrN[i];
		result += arrB[i] * getInverse(partialProduct, arrN[i]) * partialProduct;
	}
	
	return result % product;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		int a, b;
		for (int i = 0; i < N; i++) {
			cin >> a >> b;
			arrB[i] = a;
			arrN[i] = b;
		}
		cout << "#" << test_case << " "<<solve() << endl;
		
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 이 부분에 여러분의 알고리즘 구현이 들어갑니다.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}