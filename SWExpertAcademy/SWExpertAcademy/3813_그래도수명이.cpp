#include<iostream>

using namespace std;

#define MAX 200000
int T, N, K;
int arr[MAX + 2], chunks[MAX + 2];

//목표로하는 정답이 가능한지 확인하는 함수
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
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
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

		//이분탐색으로 가능한 최대값의 최소값을 찾아나갈꺼임
		int start, end, middle;
		start = 1;
		end = MAX;
		while (start < end) {
			middle = (start + end) / 2;
			if (valid(middle)) { //가능할 경우 더 작은 값을 찾아본다.
				end = middle;
			}
			else {
				start = middle + 1;
			}
		}
		cout << "#" << test_case << " " << start << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}