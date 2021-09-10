#include<iostream>
#include <algorithm>
#include <vector>

#define MAX 100000
using namespace std;

int N;
typedef struct Point {
	int x;
	int y;
};//좌표
Point points[MAX + 1];
Point start;

int ccw(Point p1, Point p2, Point p3) {
	long long temp = (long long)(p2.x - p1.x) * (long long)(p3.y - p1.y)
		- (long long)(p3.x - p1.x) * (long long)(p2.y - p1.y);
	if (temp > 0) return 1;
	else if (temp < 0) return -1;
	else return 0;
}
long long dist(Point p1, Point p2) {
	long long d1 = (long long)(p1.x - p2.x);
	long long d2 = (long long)(p1.y - p2.y);
	return d1 * d1 + d2 * d2;
}
bool comp(const Point p1, const Point p2) {
	int temp = ccw(start, p1, p2);
	if (temp == 0) return dist(start,p1) <= dist(start, p2);
	else return temp == 1;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> points[i].x >> points[i].y;
		}
		start = points[0];
		for (int i = 1; i < N; i++) {
			if (points[i].y < start.y || (points[i].y == start.y && points[i].x < start.x)) {
				start = points[i];
			}
		}
		
		sort(points, points + N, comp);
		vector<Point> s;//convex hull을 담을 vector

		for(int i = 0; i < N; i++) {
			while (s.size() >= 2 && ccw(s[s.size() - 2], s[s.size() - 1], points[i]) <= 0) {
				s.pop_back();
			}
			s.push_back(points[i]);
		}
		cout <<"#"<<test_case<<" "<< s.size() << endl;


		

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}