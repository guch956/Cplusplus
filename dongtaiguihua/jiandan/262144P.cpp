#include<iostream>
#include<cstdio>
using namespace std;
const int N=262000;
int dp[N][61];
int p[N];
int main(){
    int n,i,j,ans=0,a;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&p[i]);
    }
    for(i=1;i<=n;i++){
        j = i-1;
        a = p[i];
        dp[i][a]=j;
        while(j && p[j]<=a && a<=dp[j][0]){
            j = dp[j][a];
            a++;
            dp[i][a]=j;
        }
        dp[i][0]=a;
        ans=max(ans,a);
    }
    printf("%d",ans);
    return 0;
}