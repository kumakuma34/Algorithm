/*
BOJ 5086 [배수와 약수] 
2020.07.08
*/

#include <iostream>
using namespace std;

int n, m;
int main() {
	int ans = 0;// 0: neither, 1 : factor , 2 : multiple
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		if (n < m) {
			if (m % n == 0) 
				ans = 1;
		}
		else if(n > m) {
			if (n % m == 0) 
				ans = 2; 
		}

		if (ans == 0)
			cout << "neither\n";
		else if (ans == 1)
			cout << "factor\n";
		else if (ans == 2)
			cout << "multiple\n";
		
		ans = 0;
	}
}
