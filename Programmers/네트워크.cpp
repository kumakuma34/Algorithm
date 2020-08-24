#include <string>
#include <vector>

using namespace std;

bool visited[201];
vector<vector<int> > v;
int N;
void dfs(int x) {
    for (int i = 0; i < N; i++) {
        if (v[x][i] && !visited[i]){
            visited[i] = true;
            dfs(i);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    N = n;
    v = computers;//전역변수로 뺌
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            answer++;
            visited[i] = true;
            dfs(i);
        }
    }
    return answer;
}