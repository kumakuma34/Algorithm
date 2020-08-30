
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
#include <string>
#include <vector>

using namespace std;
int len2[12] = { 3,1,0,1,2,1,2,3,2,3,4,4 };//2까지의 거리 하드코딩
int len5[12] = { 2,2,1,2,1,0,1,2,1,2,3,3 };//5까지의 거리 하드코딩
int len8[12] = { 1,3,2,3,2,1,2,1,0,1,2,2 };//8까지의 거리 하드코딩
int len0[12] = { 0,4,3,4,3,2,3,2,1,2,1,1 };//10까지의 거리 하드코딩

int getLength(int from, int to) {
    if (to == 2) return len2[from];
    if (to == 5) return len5[from];
    if (to == 8) return len8[from];
    if (to == 0) return len0[from];
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int lPos = 10;//'*'
    int rPos = 11;//'#'
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += 'L';
            lPos = numbers[i];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += 'R';
            rPos = numbers[i];
        }
        else {
            int lLen = getLength(lPos, numbers[i]);
            int rLen = getLength(rPos, numbers[i]);
            if (lLen < rLen) {
                answer += 'L';
                lPos = numbers[i];
            }
            else if (lLen > rLen) {
                answer += 'R';
                rPos = numbers[i];
            }
            else {
                if (hand == "right") {
                    answer += 'R';
                    rPos = numbers[i];
                }
                else if (hand == "left") {
                    answer += 'L';
                    lPos = numbers[i];
                }
            }
        }
    }
    return answer;
}