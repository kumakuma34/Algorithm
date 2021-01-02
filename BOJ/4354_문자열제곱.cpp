#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
int pi[1000000];
int main() {
	while (1) {
		string s;
		cin >> s;
		if (s == ".") break;
		
		for (int i = 0; i < 1000000; i++) {
			pi[i] = 0;
		}

		int len = s.size();
		int j = 0;

		for (int i = 1; i < len; ++i) {
			while (j > 0 && s[i] != s[j])
				j = pi[j - 1];
			if (s[i] == s[j]) pi[i] = ++j;
		}
		/*for (int i = 1; i < len; i++) {
			cout << pi[i] << ' ';
		}
		cout << endl;*/

		int maxLength = pi[len - 1];//접두사, 접미가사 같은 최대 길이
		if (len % (len - maxLength)) cout << "1\n";
		else
			cout << len / (len - maxLength) << "\n";
		

	}
}