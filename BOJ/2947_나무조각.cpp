#include <iostream>
using namespace std;

int arr[5];
int main() {
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}
	int cnt = 0;
	while (1) {
		for (int cnt = 0; cnt <= 3; cnt++) {
			if (arr[cnt % 5] > arr[(cnt + 1) % 5]) {
				swap(arr[cnt % 5], arr[(cnt + 1) % 5]);

				for (int i = 0; i < 5; i++) {
					cout << arr[i] << ' ';
				}
				cout << '\n';
			}
		}
		if (arr[0] == 1 && arr[1] == 2 && arr[2] == 3 && arr[3] == 4 && arr[4] == 5) break;
		
		
	}
}