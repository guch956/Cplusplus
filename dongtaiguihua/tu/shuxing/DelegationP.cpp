#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100003;
int m;
int head[N],ent,to[N],nex[N];
int dp[N];
bool xing[N];
int A[N];
int B[N];
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
void dfs(int s,int f){
    int i,num=1,num2=0,num1=0;
    xing[s]=1;dp[s]=0;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        dfs(to[i],s);
        if(!xing[to[i]]){xing[s]=0;return ;}
    }
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        A[num++]=dp[to[i]]+1;
    }
    sort(A+1,A+num);
    for(i=1;i<num;i++){
        if(2*A[i]<m){num2++;}
        if(A[i]<m){num1++;}
    }
}
int main(){
    int n,i,l,r;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d %d",&l,&r);
        adde(l,r);
        adde(r,l);
    }
    l = 1;r = n-1;
    while(l<r){
        m=(l+r+1)>>1;
        dfs(1,1);
        if(xing[1]){l = m;}
        else{r = m-1;}
    }
    printf("%d",l);
    return 0;
}