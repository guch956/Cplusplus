#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define ll long long
using namespace std;
const ll P=1000000007;
const int N=1503;
struct {
    int son[10];
    int fail;
    bool isend;
}t[N];
ll dp[N][N];
int ent=0;
char p1[N];
int num[N];
void insert(char * s,int slen){
    int i,now=0,ch;
    for(i=0;i<slen;i++){
        ch = s[i]-'0';
        if(!t[now].son[ch]){t[now].son[ch]=++ent;}
        now = t[now].son[ch];
    }
    t[now].isend=1;
}
void getfail(){
    int i,now;
    queue<int> q;
    for(i=0;i<10;i++){
        if(t[0].son[i]){
            q.push(t[0].son[i]);
        }
    }
    while(q.size()){
        now = q.front();
        q.pop();
        if(t[t[now].fail].isend){
            t[now].isend=1;
        }
        for(i=0;i<10;i++){
            if(t[now].son[i]){
                t[t[now].son[i]].fail=t[t[now].fail].son[i];
                q.push(t[now].son[i]);
            }
            else{
                t[now].son[i]=t[t[now].fail].son[i];
            }
        }
    }
}
ll dfs(int pos,int now,bool lead,bool limit){
    if(t[now].isend){return 0;}
    if(!pos){return 1;}
    if((!lead) && (!limit) && dp[pos][now]!=-1){return dp[pos][now];}
    ll ans=0;
    int i,up;
    up = limit?num[pos]:9;
    for(i=0;i<=up;i++){
        if((i==0) && lead){
            ans+=dfs(pos-1,now,1,(i==num[pos])&&limit);
        }
        else{
            ans+=dfs(pos-1,t[now].son[i],0,(i==num[pos])&&limit);
        }
    }
    ans=ans%P;
    if((!lead) && (!limit)){
        dp[pos][now]=ans;
    }
    return ans;
}
int main(){
    int i,n,m;
    memset(dp,-1,sizeof(dp));
    scanf("%s",p1);
    n = strlen(p1);
    for(i=0;i<n;i++){
        num[n-i]=p1[i]-'0';
    }
    scanf("%d",&m);
    while(m--){
        scanf("%s",p1);
        insert(p1,strlen(p1));
    }
    getfail();
    printf("%lld",(dfs(n,0,1,1)+P-1)%P);
    return 0;
}