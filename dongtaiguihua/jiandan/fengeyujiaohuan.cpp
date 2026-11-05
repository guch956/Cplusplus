#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=200003;
const ll P=1e9+7;
struct node{
    int zhi;
    int id;
}q[N];
bool bijiao(node n1,node n2){
    return n1.zhi==n2.zhi?n1.id<n2.id:n1.zhi<n2.zhi;
}
int p[N];
int n;
ll dp[N];
ll tree[N];
inline int lowbit(int x){return x&(-x);}
void update(int x,ll d){
    while(x<=n){
        tree[x]+=d;
        x+=lowbit(x);
    }
}
ll chaxun(int x){
    ll a=0;
    while(x){
        a+=tree[x];
        x-=lowbit(x);
    }
    return a;
}
int main(){
    int i,j;
    ll k,s=1,l=0;
    scanf("%d %lld",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&q[i].zhi);
        q[i].id=i;
    }
    sort(q+1,q+n+1,bijiao);
    for(i=1;i<=n;i++){
        p[q[i].id]=i;
    }
    j = 0;
    dp[j]=1;
    for(i=1;i<=n;i++){
        l+=i-j-1-chaxun(p[i]);
        update(p[i],1);
        while(l>k){
            s-=dp[j];
            j++;
            l-=chaxun(p[j]-1);
            update(p[j],-1);
        }
        s = (s%P+P)%P;
        dp[i]=s;
        s+=dp[i];
        s = s%P;
    }
    printf("%lld",dp[n]);
    return 0;
}