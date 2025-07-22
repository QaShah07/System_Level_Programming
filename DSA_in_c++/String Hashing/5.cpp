#include<bits/stdc++.h>
using namespace std;
int result=0;
int N ,M;
vector<vector<int>>dp;
int rec(int row, int col){
    if(row==0){
        return dp[row][col];
        
    }
    if(col<0 ||col+1>M){
        return 0;
    }
    int ans = dp[row][col]+dp[row-1][col]+max(rec(row-1,col-1),rec(row-1,col+1));
    return ans;
}
int main(){
    cin >> N >> M;
    dp.resize(N, vector<int>(M));
    for(int i=0; i<N ; i++){
        for(int j=0; j<M; j++){
             cin>>dp[i][j];
        }
        cout<<endl;
    }
    for(int i=0; i<M; i++){
         result=max(result , rec(N-1, i));
         
    }
        cout << result << endl;
    return 0;

}