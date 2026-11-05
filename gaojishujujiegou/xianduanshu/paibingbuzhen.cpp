#include<iostream>
#include<algorithm>
using namespace std;
const int N=202;
int dp[N*100];
int celue[N][N];
int main(){
    int n,m,i,j,s,k,a;
    cin>>s>>n>>m;
    for(i=0;i<s;i++){
        for(j=1;j<=n;j++){
            cin>>celue[j][i];
        }
    }
    for(i=1;i<=n;i++){
        sort(celue[i],celue[i]+s);
    }
    for(i=1;i<=n;i++){
        for(j=m;j>=1;j--){
            for(k=0;k<s;k++){
                if(j>2*celue[i][k]){
                    a = 2*celue[i][k]+1;
                    dp[j]=max(dp[j],dp[j-a]+i*(k+1));
                }
            }
        }
    }
    cout<<dp[m];
    return 0;
}