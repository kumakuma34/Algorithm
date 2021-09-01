#include<iostream>
#include <vector>
using namespace std;

//�η� ���ϱ�
double calcPower(double m, double dist) {
	return m / (dist * dist);
}
int main(int argc, char** argv)
{
	int test_case;
	int T, N; // N: �ڼ�ü�� ���� 
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		vector<int> locate, weight;
		
		//input
		int tmp;
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			locate.push_back(tmp);
		}
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			weight.push_back(tmp);
		}

		cout << "#" << test_case << " ";
		//N-1���� ���� �̺�Ž�� ����
		for (int i = 0; i < N - 1; i++) {
			int maxCnt = 100;

			double left = (double)locate[i];
			double right = (double)locate[i + 1];
			double mid = (double)(left + right) / 2.0;

			while (maxCnt--) {
				double pLeft = 0.0; // ���� �ڼ�ü������ �޴� ���� ��
				double pRight = 0.0; // ������ �ڼ�ü������ �޴� ���� ��

				for (int j = 0; j <= i; j++) {
					pLeft += calcPower(weight[j], (mid - locate[j]));
				}
				for (int j = i + 1; j < N; j++) {
					pRight += calcPower(weight[j], (locate[j] - mid));
				}
				
				if (pLeft - pRight == 0) {
					break;
				}
				else if (pLeft > pRight) {//�������� �� Ŭ ��� ������ ����
					 left = mid;
					 mid = (double)(left + right) / 2.0;
				}
				else if (pRight > pLeft) {
					 right = mid;
					 mid = (double)(left + right) / 2.0;
				}
			}
			printf("%.10f ", mid);
		}
		cout << endl;
		
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}