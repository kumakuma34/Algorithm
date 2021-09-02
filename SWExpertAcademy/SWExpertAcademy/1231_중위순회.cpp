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

void inorder(node* pNode) {
	if (pNode->l != NULL) {
		inorder(pNode->l);
	}
	cout << pNode->data;
	if (pNode->r != NULL) {
		inorder(pNode->r);
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10, N;
	//freopen("input.txt", "r", stdin);
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		node nodes[101];

		cin >> N;
		cin.ignore();
		string s;
		for (int i = 1; i <= N; i++) {
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
			//cin.ignore();

			
		}
		cout << "#" << test_case << " ";
		inorder(&nodes[1]);
		cout << '\n';
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 이 부분에 여러분의 알고리즘 구현이 들어갑니다.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}