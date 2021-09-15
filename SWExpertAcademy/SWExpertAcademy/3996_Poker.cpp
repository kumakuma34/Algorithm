#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int pattern[4];
int numbers[15];
bool ans[9];
string pairs[9] = { "Top" ,"1 Pair" ,"2 Pair" ,"Triple" ,
			"Straight" ,"Flush" ,"Full House" ,"4 Card" ,"Straight Flush" };
vector<pair<char, int> > cards;

void init() {
	for (int i = 0; i < 4; i++)
		pattern[i] = 0;
	for (int i = 0; i < 15; i++) {
		numbers[i] = 0;
	}
	for (int i = 0; i < 9; i++)
		ans[i] = false;
	ans[0] = true;
	cards.clear();
}
void printcard(vector<pair<char, int> > card) {
	for (int i = 0; i < card.size(); i++) {
		cout << card[i].first << "-" << card[i].second << "  ";
	}
	cout << endl;
}
void solve(vector<pair<char, int> > card) {
	//counting
	printcard(card);
	for (int i = 0; i < card.size(); i++) {
		numbers[card[i].second]++;
		if (card[i].second == 1) numbers[14]++;
		char c = card[i].first;
		if (c == 'S') pattern[0]++;
		else if (c == 'D') pattern[1]++;
		else if (c == 'C') pattern[2]++;
		else if (c == 'H') pattern[3]++;
	}

	//(4) Straight -> ���ӵ� ���� 5��
	bool flag4 = false;
	for (int i = 1; i <= 10; i++) {
		int tmp = 0;
		for (int j = 1; j < i + 5; j++) {
			if (numbers[j] != 1) break;
			tmp++;
		}
		if (tmp == 5) flag4 = true;
	}
	if (flag4) ans[4] = true;

	//(5) Flush -> ���� ���� 5�� ����
	bool flag5 = false;
	for (int i = 0; i < 4; i++) {
		if (pattern[i] == 5) flag5 = true;
	}
	if (flag5) ans[5] = true;

	//(8) Straight Flush -> ���� ������ ���ӵ� ���� 5�� ����
	if (flag4 && flag5) ans[8] = true;

	int pairCnt = 0;
	int tripleCnt = 0;

	for (int i = 1; i < 14; i++) {
		if (numbers[i] == 4) ans[7] = true;

		//���� ���� 2�� Ȯ��
		if (numbers[i] == 2) pairCnt++;
		//���� ���� 3�� Ȯ��
		if (numbers[i] == 3) tripleCnt++;
	}

	//(1) Pair -> ���� ���ڰ� �ѽ� ����
	if (pairCnt == 1) ans[1] = true;
	//(2) -> ���� ���ڰ� �ν� ����
	if (pairCnt == 2) ans[2] = true;
	//(3) Triple -> �� ���� ���� ���ڰ� ����
	if (tripleCnt == 1) ans[3] = true;
	//(6) Triple�� Pair�� �Բ� ����
	if (tripleCnt == 1 && pairCnt == 1) ans[6] = true;
}

void makeCombination() {
	vector<int> tmp = { 0,0,1,1,1,1,1 };
	vector<pair<char, int> > card;
	//���� �����
	do {
		for (int i = 0; i < tmp.size(); i++) {
			if (tmp[i]) {
				card.push_back(cards[i]);
			}
		}
		solve(card);
		card.clear();
	} while (next_permutation(card.begin(), card.end()));

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
		char c;
		int num;
		for (int i = 0; i < 7; i++) {
			cin >> c >> num;
			cards.push_back({ c, num });
		}
		makeCombination();
		
		for (int i = 8; i >=0; i--) {
			//cout << ans[i] << " ";
			if (ans[i]) {
				cout << "#" << test_case << " " << pairs[i] << endl;
				break;
			}
		}
		



	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}