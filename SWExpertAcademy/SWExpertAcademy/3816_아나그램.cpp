#include<iostream>
#include <string>
using namespace std;

int cmp[26], now[26];
void init() {
	for (int i = 0; i < 26; i++) {
		cmp[i] = 0;
		now[i] = 0;
	}
}
void countCmp(string s, int arr[]) {
	for (int i = 0; i < s.length(); i++) {
		arr[s[i] - 'a']++;
	}
}
bool cmpEach() {
	for (int i = 0; i < 26; i++) {
		if (cmp[i] != now[i]) return false;
	}
	return true;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		int ans = 0;
		string s1, s2;
		cin >> s1>> s2;

		countCmp(s1, cmp);
	
		for (int i = 0; i <= s2.length() - s1.length(); i++) {
			if (i == 0) {
				countCmp(s2.substr(0,s1.length()), now);
			}
			else {
				now[s2[i - 1] - 'a']--;
				now[s2[i + s1.length()-1] - 'a']++;
				/*for (int i = 0; i < 26; i++) {
					cout << now[i] << " ";
				}
				cout << endl;*/
			}
			if (cmpEach()) ans++;
		}
		cout <<"#"<<test_case<<" "<< ans << endl;


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}