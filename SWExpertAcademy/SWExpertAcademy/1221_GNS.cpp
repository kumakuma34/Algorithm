#include<iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string words[10] = { "ZRO", "ONE", "TWO", "THR" , "FOR" , "FIV" , "SIX", "SVN", "EGT", "NIN" };

int main(int argc, char** argv)
{
	int test_case;
	int T, n;
	string test_num;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> test_num >> n;
		cout << test_num << " ";
		//("%s ", test_num);
		//숫자로 변환된 값을 넣을 벡터
		vector<int> v;
		string input;
		for (int i = 0; i < n; i++) {
			cin >> input;
			for (int j = 0; j < 10; j++) {
				if (input == words[j]) {
					v.push_back(j);
					break;
				}
			}
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < n; i++) {
			cout << words[v[i]] << " ";
			//printf("%s ", words[v[i]]);
		}
		printf("\n");
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}