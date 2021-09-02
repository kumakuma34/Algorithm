#include<iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct node {
	string data;
	node* l;
	node* r;
} node;

//C++에 string split함수가 없어서 만듬
vector<string> split(string str, char delimiter) {
	vector<string> vs;
	string tmp;

	for (int i = 0; !(str[i] == 13 || str[i] == '\n' || str[i] == 0); i++) {
		if (str[i] == delimiter) {
			vs.push_back(tmp);
			tmp.clear();

			continue;
		}

		tmp.push_back(str[i]);
	}
	vs.push_back(tmp);

	return vs;
}

double postorder(node* pNode) {
	if (pNode->data == "+")
		return postorder(pNode->l) + postorder(pNode->r);
	else if (pNode->data == "-")
		return postorder(pNode->l) - postorder(pNode->r);
	else if (pNode->data == "*")
		return postorder(pNode->l) * postorder(pNode->r);
	else if (pNode->data == "/")
		return postorder(pNode->l) / postorder(pNode->r);
	else
		return (double)stoi(pNode->data);
}
int main(int argc, char** argv)
{
	int test_case;
	int T = 10, N;
	//freopen("input.txt", "r", stdin);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		node nodes[1001];

		cin >> N;
		cin.ignore();
		string s;
		for (int i = 1; i <= N; i++) {
			//input
			getline(cin, s);

			vector<string> v = split(s, ' ');

			nodes[i].data = v[1];

			if (v.size() >= 3)
				nodes[i].l = &nodes[stoi(v[2])];
			else
				nodes[i].l = NULL;
			if (v.size() >= 4)
				nodes[i].r = &nodes[stoi(v[3])];
			else
				nodes[i].r = NULL;
		}
		cout << "#" << test_case << " ";
		cout << postorder(&nodes[1]);
		cout << '\n';
	

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}