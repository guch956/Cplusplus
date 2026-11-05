#include<iostream>
const int N=1002;
int dp[N];
int q[N];int p[N];
int main(){
    using namespace std;
    int n,m,i,j;
    cin>>m>>n;
    for(i=1;i<=n;i++){
        cin>>q[i]>>p[i];
    }
    for(i=1;i<=n;i++){
        for(j=m;j>=q[i];j--){
            dp[j]=max(dp[j],dp[j-q[i]]+p[i]);
        }
    }
    cout<<dp[m];
    return 0;
}