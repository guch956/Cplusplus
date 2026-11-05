#include<iostream>
#include<cstdio>
using namespace std;
int dp[40][80][2];
int num[40];
inline int ch(int x){return x+35;}
int get(int x){
    int l=0;
    while(x){
        l++;
        num[l]=x&1;
        x = x>>1;
    }
    return l;
}
int dfs(int l,int cha,bool limit,bool lead){
    int i,ans=0;
    if((!limit) || l==0){return dp[l][ch(cha)][lead];}
    for(i=0;i<=num[l];i++){
        ans+=dfs(l-1,cha-1+2*i+(lead&&i==0),limit&&(i==num[l]),lead&&(i==0));
    }
    return ans;
}
int solve(int x){
    int l=get(x);
    return dfs(l,0,1,1);
}
int main(){
    int l,r,i,j;
    cin>>l>>r;
    for(i=-35;i<=0;i++){
        dp[0][ch(i)][0]=dp[0][ch(i)][1]=1;
    }
    for(j=1;j<=35;j++){
        for(i=-35;i<=35;i++){
            dp[j][ch(i)][0]=dp[j-1][ch(i-1)][0]+dp[j-1][ch(i+1)][0];
            dp[j][ch(i)][1]=dp[j-1][ch(i)][1]+dp[j-1][ch(i+1)][0];
        }
    }
    printf("%d",solve(r)-solve(l-1));
    return 0;
}