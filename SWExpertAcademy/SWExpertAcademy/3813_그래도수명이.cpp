#include<iostream>

using namespace std;

#define MAX 200000
int T, N, K;
int arr[MAX + 2], chunks[MAX + 2];

//��ǥ���ϴ� ������ �������� Ȯ���ϴ� �Լ�
bool valid(int target) {
	int cnt = 0, arrCnt = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] <= target) {
			cnt++;
		}
		else {
			cnt = 0;
		}

		if (cnt == chunks[arrCnt]) {
			cnt = 0;
			arrCnt++;
			if (arrCnt == K) break;
		}
	}
	return arrCnt == K;
}

int main(int argc, char** argv)
{
	int test_case;

	freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		//input
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < K; i++) {
			cin >> chunks[i];
		}

		//�̺�Ž������ ������ �ִ밪�� �ּҰ��� ã�Ƴ�������
		int start, end, middle;
		start = 1;
		end = MAX;
		while (start < end) {
			middle = (start + end) / 2;
			if (valid(middle)) { //������ ��� �� ���� ���� ã�ƺ���.
				end = middle;
			}
			else {
				start = middle + 1;
			}
		}
		cout << "#" << test_case << " " << start << endl;
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}