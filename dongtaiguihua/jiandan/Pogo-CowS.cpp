#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1003;
struct node{
    int x;
    int val;
}p[N];
bool bijiao(node & n1,node & n2){return n1.x<n2.x;}
int dp[N][N],zhiz[N];
int n,ans;
void jisuan(){
    int i,j;
    sort(p+1,p+n+1,bijiao);
    for(i=1;i<=n;i++){
        zhiz[i]=i;
        dp[i][i]=0;
        for(j=1;j<i;j++){
            while(zhiz[j]>1 && (p[j].x-p[zhiz[j]-1].x)<=(p[i].x-p[j].x)){
                zhiz[j]--;
            }
            dp[i][j]=dp[j][zhiz[j]];
        }
        for(j=i;j>=1;j--){
            dp[i][j]+=p[i].val;
            dp[i][j]=max(dp[i][j],dp[i][j+1]);
            ans = max(ans,dp[i][j]);
        }
    }
}
int main(){
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d",&p[i].x,&p[i].val);
    }
    jisuan();
    for(i=1;i<=n;i++){p[i].x=-p[i].x;}
    jisuan();
    cout<<ans;
    return 0;
}
