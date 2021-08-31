#include<iostream>

using namespace std;
double possibleA[19], possibleB[19];
double cnt[19];//이항계수

int combination(int n, int r) {
	if (n == r | r == 0)
		return 1;
	else
		return combination(n - 1, r - 1) + combination(n - 1, r);
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	double a, b;
	scanf("%d" , &T);
	for (int i = 0; i < 19; i++) {
		cnt[i] = combination(18, i);
	}

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> a >> b;
		a /= 100.0;
		b /= 100.0;
		
		for (int i = 1; i <=18; i++) {
			possibleA[i] = cnt[i];
			possibleB[i] = cnt[i];

			for (int j = 0; j < i; j++) {
				possibleA[i] *= a;
				possibleB[i] *= b;

			}
			for (int j = 0; j < 18 - i; j++) {
				possibleA[i] *= (1.0 - a);
				possibleB[i] *= (1.0 - b);

			}
		}
		
		//둘다 소수가 아닐 확률을 구해서 1에서 빼기
		double primeA = 0.0;
		double primeB = 0.0;
		primeA = possibleA[2] + possibleA[3] + possibleA[5] + possibleA[7] + possibleA[11] + possibleA[13] + possibleA[17];
		primeB = possibleB[2] + possibleB[3] + possibleB[5] + possibleB[7] + possibleB[11] + possibleB[13] + possibleB[17];

		double ans = 1.0 - (1.0 - primeA) * (1.0 - primeB);
		printf("#%d %.6f\n", test_case, ans);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}