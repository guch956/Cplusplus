#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=100003;
int n;
struct node{
    int id;
    int zhi;
}q[N];
bool bijiao(node q1,node q2){
    return q1.zhi==q2.zhi?q1.id<q2.id:q1.zhi<q2.zhi;
}
inline int lowbit(int x){return x&(-x);}
ll tree1[N];
ll tree2[N];
int p[N];
void update1(int x,ll d){
    while(x<=n){
        tree1[x]+=d;
        x+=lowbit(x);
    }
}
void update2(int x,ll d){
    while(x<=n){
        tree2[x]=max(tree2[x],d);
        x+=lowbit(x);
    }
}
ll chaxun1(int x){
    ll an=0;
    while(x){
        an+=tree1[x];
        x-=lowbit(x);
    }
    return an;
}
ll chaxun2(int x){
    ll an=0;
    while(x){
        an=max(an,tree2[x]);
        x-=lowbit(x);
    }
    return an;
}
int main(){
    int i,u;
    ll ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&q[i].zhi);
        q[i].id=i;
    }
    sort(q+1,q+n+1,bijiao);
    for(i=1;i<=n;i++){
        p[q[i].id]=i;
    }
    for(i=n;i>=1;i--){
        u = chaxun2(p[i]-1);
        if(u!=0){
            ans+=1+u-p[i];
        }
        else{
            u = chaxun1(p[i]-1);
            ans+=max(1,i+u-p[i]);
        }
        update1(p[i],1);
        update2(p[i],i);
    }
    printf("%lld",ans);
    return 0;
}
