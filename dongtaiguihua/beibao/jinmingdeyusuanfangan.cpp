#include<iostream>
#include<cstdio>
using namespace std;
const int N=32003;
int dp[N];
int daij[63];
int jiaz[63];
int son[63][2];
int fa[63];
int main(){
    int n,m,i,j,a;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&daij[i],&jiaz[i],&fa[i]);
        jiaz[i]=jiaz[i]*daij[i];
        if(fa[i]){
            if(son[fa[i]][0]){
                son[fa[i]][1]=i;
            }
            else{
                son[fa[i]][0]=i;
            }
        }
    }
    for(i=1;i<=m;i++){
        if(fa[i]){continue;}
        for(j=n;j>=daij[i];j--){
            if(son[i][1]){
                a = daij[i]+daij[son[i][1]];
                if(a<=j){
                    dp[j]=max(dp[j],dp[j-a]+jiaz[i]+jiaz[son[i][1]]);
                }
                a = daij[i]+daij[son[i][0]]+daij[son[i][1]];
                if(a<=j){
                    dp[j]=max(dp[j],dp[j-a]+jiaz[i]+jiaz[son[i][1]]+jiaz[son[i][0]]);
                }
            }
            if(son[i][0]){
                a = daij[i]+daij[son[i][0]];
                if(a<=j){
                    dp[j]=max(dp[j],dp[j-a]+jiaz[i]+jiaz[son[i][0]]);
                }
            }
            dp[j]=max(dp[j],dp[j-daij[i]]+jiaz[i]);
        }
    }
    cout<<dp[n];
    return 0;
}