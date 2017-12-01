#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXV=10010;
int dp[101][MAXV];
int w[101],v[101];
int main(){
    int N,W;
    while ( cin>>N>>W ){
        for (int i=0; i<N; i++) cin>>w[i]>>v[i];
        memset(dp, 0x3f, sizeof(dp) );
        dp[0][0]=0;
        for (int i=0; i<N; i++){
            for (int j=0; j<MAXV; j++){
                if (j<v[i]){
                    dp[i+1][j] = dp[i][j];
                }else{
                    dp[i+1][j] = min(dp[i][j], dp[i][j-v[i]]+w[i] );
                }
            }
        }
        int res=0;
        for (int i=0; i<MAXV; i++){
            if ( dp[N][i]<=W ) res=i;
        }
        cout<<res<<endl;
    }
}
