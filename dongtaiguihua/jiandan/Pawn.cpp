#include<iostream>
#include<string>
const int N=105;
const int INF=0x3f3f3f3f;int k;
using namespace std;
string c;
int p[N][N],dp[N][N][13],fx[N][N][13];
void dfs(int hang,int lie,int geshu){
    if(hang==1){
        cout<<lie<<endl;
        return ;
    }
    if(fx[hang][lie][geshu]==1){
        dfs(hang-1,lie-1,(geshu+(k-1)*p[hang][lie])%k);
        cout<<'R';
    }
    else{
        dfs(hang-1,lie+1,(geshu+(k-1)*p[hang][lie])%k);
        cout<<'L';
    }
}
int main(){
    int n,m,i,j,l,a,ans;
    cin>>n>>m>>k;
    k++;
    for(i=1;i<=n;i++){
        cin>>c;
        for(j=0;j<m;j++){
            p[i][j+1]=c[j]-'0';
        }
    }
    for(i=1;i<=m;i++){
        for(j=0;j<k;j++){
            dp[1][i][j]=-INF;
        }
        dp[1][i][p[1][i]%k]=p[1][i];
    }
    for(i=2;i<=n;i++){
        for(j=1;j<=m;j++){
            for(l=0;l<k;l++){
                dp[i][j][l]=-INF;
                if(j!=1){
                    a = dp[i-1][j-1][((k-1)*p[i][j]+l)%k];
                    if(a>=0 && a>dp[i][j][l]){
                        dp[i][j][l]=a;
                        fx[i][j][l]=1;
                    }
                    
                }
                if(j!=m){
                    a=dp[i-1][j+1][((k-1)*p[i][j]+l)%k];
                    if(a>=0 && a>dp[i][j][l]){
                        dp[i][j][l]=a;
                        fx[i][j][l]=0;
                    }
                }
                dp[i][j][l]+=p[i][j];
            }
        }
    }
    a = 0;ans=-INF;
    for(i=1;i<=m;i++){
        if(dp[n][i][0]>ans){
            ans=dp[n][i][0];
            a = i;
        }
    }
    if(ans>=0){
        cout<<ans<<endl;
        dfs(n,a,0);
    }
    else{
        cout<<-1;
    }
    return 0;
}