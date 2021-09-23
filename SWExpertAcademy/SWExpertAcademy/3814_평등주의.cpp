#include<iostream>
#include <algorithm>

using namespace std;
#define MAX 100000

int T, N, K;
int arr[MAX + 1], tmp[MAX + 1];

bool valid(int target) {
	int cnt = K;
	for (int i = 0; i < N; i++) {
		int diff = 0;
		if (i > 0) diff = arr[i] - tmp[i - 1];
		if (i < N - 1) {
			int tmp = arr[i] - arr[i + 1];
			if (tmp > diff) diff = tmp;
		}
		if (diff > target) {
			tmp[i] = arr[i] - diff + target;
			cnt -= diff - target;
		}
		else
			tmp[i] = arr[i];
		if (cnt < 0) return false;
	}

	for (int i = N - 1; i >= 0; i--) {
		int diff = 0;
		if (i > 0) diff = tmp[i] - tmp[i - 1];
		if (i < N - 1) {
			int temp = tmp[i] - tmp[i + 1];
			if (temp > diff) diff = temp;
		}
		if (diff > target) {
			tmp[i] = tmp[i] - diff + target;
			cnt -= diff - target;
		}
		if (cnt < 0) return false;
	}
	return true;
}

int main(int argc, char** argv)
{
	int test_case;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> K;
		int start = 0, end = 0, middle;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		
		int max = 0;
		for (int i = 0; i < N - 1; i++) {
			int diff = arr[i] - arr[i + 1];
			if (diff < 0) diff = -1 * diff;
			if (max < diff) max = diff;
		}

		start = 0;
		end = max;

		while (start < end) {
			middle = (start + end) / 2;
			if (valid(middle)) {
				end = middle;
			}
			else
				start = middle + 1;
		}

		cout << "#" << test_case << " " << start  << endl;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 이 부분에 여러분의 알고리즘 구현이 들어갑니다.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}