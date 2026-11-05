#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int dp[12][10];
int num[12];
int dfs(int pos,int last,bool limit,bool lead){
    if(!pos){return 1;}
    if(!limit && !lead && dp[pos][last]!=-1){return dp[pos][last];}
    int i,ans=0,now=limit?num[pos]:9;
    for(i=0;i<=now;i++){
        if(i==0 && lead){ans+=dfs(pos-1,-2,limit && i==num[pos],true);}
        else if(abs(i-last)>=2){ans+=dfs(pos-1,i,limit && i==num[pos],false);}
    }
    if(!limit && !lead){dp[pos][last]=ans;}
    return ans;
}
int jisuan(int x){
    int len=0;
    while(x){
        len++;
        num[len]=x%10;
        x = x/10;
    }
    return dfs(len,-2,true,true);
}
int main(){
    int a,b;
    memset(dp,-1,sizeof(dp));
    cin>>a>>b;
    cout<<jisuan(b)-jisuan(a-1);
    return 0;
}