#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int M, N, L;
vector<int> shoot;
vector<pair<int, int > > animal;
int main(){
	cin>>M>>N>>L;
	for(int i = 0 ; i< M; i++){
		int tmp;
		cin>>tmp;
		shoot.push_back(tmp);
	}
	for(int i = 0 ; i <N ;i++){
		int a, b;
		cin>>a>>b;
		animal.push_back(make_pair(a,b));		
	}

	int ans = 0;
	sort(shoot.begin(), shoot.end());
	for(int i = 0 ; i<N; i++){
		int diff = L - animal[i].second;

		if(diff<0) continue;
		int min_x = animal[i].first - diff;
		int max_x = animal[i].first + diff;
		int idx1 = *lower_bound(shoot.begin(), shoot.end(), min_x);
		int idx2 = *lower_bound(shoot.begin(), shoot.end(), max_x);
	
		if(idx1 ==  idx2){
			if(idx1 <= max_x && idx1>=min_x) ans++;
			else continue;
		}
		else
			ans++;

            
		
	}
	cout<<ans<<endl;
}