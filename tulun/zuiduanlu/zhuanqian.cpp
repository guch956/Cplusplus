#include<iostream>
using namespace std;
const int INF=100000000;
int g[302][302];
int dp[302][302];
int n;
int floyed(){
    int i,j,k;
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(dp[k][i]+g[i][j]+dp[j][k]<0){
                    return 1;
                }
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    return 0;
}
int main(){
    int d,p,f,i,j,a;
    cin>>d>>p>>n>>f;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            g[i][j]=INF;
        }
    }
    while(p--){
        cin>>i>>j;
        g[i][j]=min(g[i][j],-d);
    }
    while(f--){
        cin>>i>>j>>a;
        g[i][j]=min(g[i][j],a-d);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            dp[i][j]=g[i][j];
        }
    }
    if(floyed()){
        cout<<"orz";
    }
    else{
        a = INF;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                a = min(a,dp[i][j]);
            }
        }
        a = min(a,0);
        a = -a+d;
        cout<<a;
    }
    return 0;
}
