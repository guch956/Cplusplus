#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=200003;
const int L=30;
int son[N*L][2],ent;
ll num[N*L];
ll dp[N*L];
int shu[L];
void get(int x){
    for(int i=0;i<L;i++){
        if(x&1){shu[i]=1;}
        else{shu[i]=0;}
        x = x>>1;
    }
}
void insert(int now){
    int i;
    for(i=L-1;i>=0;i--){
        if(!son[now][shu[i]]){son[now][shu[i]]=++ent;}
        now = son[now][shu[i]];
    }
    num[now]++;
}
void dfs0(int now,int l){
    if(l==-1){return ;}
    if(son[now][1]&&son[now][0]){
        dfs0(son[now][1],l-1);
        dfs0(son[now][0],l-1);
        dp[now]=dp[son[now][0]]+dp[son[now][1]];
    }
    else if(son[now][0]){
        dfs0(son[now][0],l-1);
        dp[now]=2*dp[son[now][0]]+((ll)1<<(2*l));
    }
    else{
        dfs0(son[now][1],l-1);
        dp[now]=2*dp[son[now][1]]+((ll)1<<(2*l));
    }
}
ll dfs(int now,int l,ll xianzhi){
    if(l==-1){
        return 0;
    }
    int k=1<<l;
    if(xianzhi>k){
        if(son[now][1] && son[now][0]){
            return dfs(son[now][1],l-1,xianzhi-k)+dp[son[now][0]];
        }
        else if(son[now][1]){
            return dp[son[now][1]]+dfs(son[now][1],l-1,xianzhi-k)+((ll)1<<(2*l));
        }
        else{
            return dp[son[now][0]]+dfs(son[now][0],l-1,xianzhi-k)+((ll)1<<l)*(xianzhi-k);
        }
    }
    else{
        if(son[now][0]){
            return dfs(son[now][0],l-1,xianzhi);
        }
        else{
            return dfs(son[now][1],l-1,xianzhi)+((ll)1<<l)*xianzhi;
        }
    }
}
int main(){
    int n,i,x;
    ll m;
    scanf("%d %lld",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&x);
        get(x);
        insert(0);
    }
    dfs0(0,L-1);
    printf("%lld",dfs(0,L-1,m));
    return 0;
}