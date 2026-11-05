#include<iostream>
#include<cstring>
using namespace std;
int dp[10][10];
int num[10];
int dfs(int pos,int last,bool limit){
    if(last==4){return 0;}
    if(!pos){return 1;}
    if(!limit && dp[pos][last]!=-1){return dp[pos][last];}
    int ans=0,i,now=limit?num[pos]:9;
    for(i=0;i<=now;i++){
        if(last==6 && i==2){continue;}
        ans+=dfs(pos-1,i,limit && i==num[pos]);
    }
    if(!limit){dp[pos][last]=ans;}
    return ans;
}
int jisuan(int x){
    int len=0;
    while(x){
        len++;
        num[len]=x%10;
        x = x/10;
    }
    return dfs(len,0,true);
}
int main(){
    int a,b;
    memset(dp,-1,sizeof(dp));
    while(cin>>a>>b){
        if(a==0 && b==0){break;}
        cout<<jisuan(b)-jisuan(a-1)<<endl;
    }
    return 0;
}