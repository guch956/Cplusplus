#include<iostream>
#include<cstdio>
using namespace std;
const int N=10003;
int head[N],to[N<<1],nex[N<<1],ent;
int dp1[N],dp2[N],val[N];
int cha[N];
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
void dfs(int s,int f){
    int i,num=2,ma1,ma2,m1,m2,sum=0,d;
    ma1 = ma2 = 0x3f3f3f3f;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        dfs(to[i],s);
        num++;
        sum+=dp1[to[i]];
    }
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        cha[val[to[i]]]+=dp2[to[i]]-dp1[to[i]];
    }
    for(i=1;i<=num;i++){
        d = cha[i]+i;
        if(d<ma1){
            ma2 = ma1;
            m2 = m1;
            ma1 = d;
            m1 = i;
        }
        else if(d<ma2){
            ma2 = d;
            m2 = i;
        }
    }
    dp1[s]=ma1+sum;
    dp2[s]=ma2+sum;
    val[s]=m1;
    for(i=head[s];i;i=nex[i]){
        cha[val[to[i]]]=0;
    }
}
int main(){
    int n,i,a,b;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    dfs(1,0);
    printf("%d",dp1[1]);
    return 0;
}