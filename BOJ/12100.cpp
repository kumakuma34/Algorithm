#include <iostream>
#include <vector>
using namespace std;

int N;
int map[21][21];
int origin[21][21];
int ans = -1;
void print(){
    cout<<endl;
    for(int i = 0 ; i < N; i ++){
        for(int j = 0 ;j < N; j++){
            cout<<map[i][j]<< ' ';
        }
        cout<<endl;
    }
}
void moveLeft(){
    for(int i = 0 ; i <N; i ++){
        vector<int> v;
        for(int j= 0 ;j < N; j++){
            if(map[i][j] != 0) v.push_back(map[i][j]);
            map[i][j] = 0;
        }
        int idx = 0;
        if(v.empty()) continue;
        for(int j = 0 ;j < v.size(); j++){
            if(j == v.size()-1) map[i][idx] = v[j];
            else if(v[j] != v[j+1]){
                map[i][idx] = v[j];
                //if(j == v.size()-2) map[i][++idx] = v[j+1];
            }
            else{
                map[i][idx] = v[j] + v[j+1];
                j++;
                // if(j == v.size()-1){
                //     map[i][++idx] = v[j];
                // }
            }
            idx++;
        }
        // for(int j = idx+1; j< N; j++){
        //     map[i][j] = 0;
        // }
    }
}
void moveRight(){
    for(int i = 0 ; i <N; i ++){
        vector<int> v;
        for(int j= N-1 ;j >=0; j--){
            if(map[i][j] != 0) v.push_back(map[i][j]);
            map[i][j] = 0;
        }
        int idx = N-1;
        if(v.empty()) continue;

        for(int j = 0 ;j < v.size(); j++){
            if(j == v.size()-1) map[i][idx] = v[j];
            else if(v[j] != v[j+1]){
                map[i][idx] = v[j];
                //if(j == v.size()-2) map[i][--idx] = v[j+1];
            }
            else{
                map[i][idx] = v[j] + v[j+1];
                j++;
                // if(j == v.size()-1){
                //     map[i][--idx] = v[j];
                // }
            }
            idx--;
        }
        // for(int j = idx-1; j>=0 ;j--){
        //     map[i][j] = 0;
        // }
    }
}
void moveUp(){
    for(int j = 0 ; j < N; j++){
        vector<int> v;
        for(int i = 0 ; i < N; i++){
            if(map[i][j] != 0) v.push_back(map[i][j]);
            map[i][j] = 0;
        }
        int idx = 0;
        if(v.empty()) continue;
        for(int i = 0 ; i < v.size(); i++){
            if(i == v.size()-1) map[idx][j] = v[i];
            else if(v[i] != v[i+1]){
                map[idx][j] = v[i];
                // if(i == v.size()-2){
                //     map[++idx][j] = v[i+1];
                // }
            }
            else{
                map[idx][j] = v[i] + v[i+1];
                i++;
            }
            idx++;
            
        }
        // for(int i = idx+1 ; i<N ;i++){
        //     map[i][j] = 0;
        // }
    }
   
}

void moveDown(){
    for(int j = 0 ; j < N; j++){
        vector<int> v;
        for(int i = N-1 ; i >=0; i--){
            if(map[i][j] != 0) v.push_back(map[i][j]);
            map[i][j] = 0;
        }
        int idx = N-1;
        if(v.empty()) continue;

        for(int i = 0 ; i < v.size(); i++){
            if(i == v.size()-1) map[idx][j] = v[i];
            else if(v[i] != v[i+1]){
                map[idx][j] = v[i];
                // if(i == v.size()-2){
                //     map[--idx][j] = v[i+1];
                // }
            }
            else{
                map[idx][j] = v[i] + v[i+1];
                i++;
            }
            idx--;
            
        }
        // for(int i = idx-1 ; i>=0 ;i--){
        //     map[i][j] = 0;
        // }
    }
   
}
int getMax(vector<int> v){
    for(int i = 0 ; i< v.size(); i++){
        if(v[i] == 0) moveLeft();
        else if(v[i] ==1) moveRight();
        else if(v[i] == 2) moveUp();
        else if(v[i] == 3) moveDown();
        //print();

    }
    int tmp = -1;
    for(int i = 0 ; i <N ;i++){
        for(int j = 0 ; j < N; j++){
            if(tmp < map[i][j]) tmp = map[i][j];
        }
    }
    return tmp;
}
void solve(vector<int> v, int n){
    if(v.size() != 5){
        v.push_back(-1);
        for(int i = 0 ; i < 4; i++){
            v[v.size()-1] = i;
            solve(v, n+1);        
        }
    }
    else{
        for(int i = 0 ; i <N ;i ++){
            for(int j = 0 ;j < N ;j++){
                map[i][j] = origin[i][j];
            }
        }
        // for(int i = 0 ; i < v.size(); i++){
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;
        // cout<< getMax(v)<<endl;
        int now = getMax(v);
        if(ans < now) ans = now;
        return;
    }
}
int main(){
    cin>>N;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ;j < N ; j++){
            cin>>map[i][j];
            origin[i][j] = map[i][j];
        }
    }
    vector<int> v;
    solve(v, 0);
    cout<<ans<<endl;

}