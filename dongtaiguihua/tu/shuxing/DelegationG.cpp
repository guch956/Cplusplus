#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
int k;
int head[N],to[N<<1],nex[N<<1],ent;
int dp[N];
int siz[N];
int tong[N];
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
void dfs1(int s,int f){
    int i;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        dfs1(to[i],s);
        siz[s]+=siz[to[i]];
    }
    siz[s]++;
}
void dfs(int s,int f){
    int i,a,b;
    dp[s]=1;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        dfs(to[i],s);
        if(!dp[to[i]]){dp[s]=0;return ;}
    }
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        a = siz[to[i]]%k;
        if(tong[a]){tong[a]--;}
        else if(a){a = k-a;tong[a]++;}
    }
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        a = k-(siz[to[i]]%k);
        if(tong[a]){dp[s]+=tong[a];tong[a]=0;}
    }
    if(dp[s]>=3){dp[s]=0;}
    else{dp[s]=1;}
}
int main(){
    int n,i,a,b;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    printf("1");
    dfs1(1,1);
    for(k=2;k<n;k++){
        if((n-1)%k==0){
            dfs(1,1);
            if(dp[1]){printf("1");}
            else{printf("0");}
        }
        else{printf("0");}
    }
    return 0;
}