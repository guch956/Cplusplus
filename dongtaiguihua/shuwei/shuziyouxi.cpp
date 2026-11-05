#include<iostream>
#include<cstring>
using namespace std;
int dp[10][12];
int num[12];
int dfs(int pos,int last,bool lead,bool limit){
    if(!pos){return 1;}
    if(!lead && !limit && dp[last][pos]!=-1){return dp[last][pos];}
    int i,now=limit?num[pos]:9;
    int ans=0;
    for(i=0;i<=now;i++){
        if(i==0 && lead){ans+=dfs(pos-1,-1,true,limit && i==num[pos]);}
        else if(i>=last){ans+=dfs(pos-1,i,false,limit && i==num[pos]);}
    }
    if(!lead && !limit){dp[last][pos]=ans;}
    return ans;
}
int jisuan(int x){
    int len=0;
    while(x){
        len++;
        num[len]=x%10;
        x = x/10;
    }
    return dfs(len,-1,true,true);
}
int main(){
    int a,b;
    memset(dp,-1,sizeof(dp));
    while(cin>>a>>b){
        if(a==EOF){break;}
        cout<<jisuan(b)-jisuan(a-1)<<endl;
    }
    return 0;
}