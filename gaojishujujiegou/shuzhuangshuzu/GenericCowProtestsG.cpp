#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const ll P=1000000009;
const int N=100003;
struct node{
    ll sum;
    int id;
}p[N];
int lisan[N];
int num=1;
ll tree[N];
inline int lowbit(int x){return x&(-x);}
void update(int x,ll d){
    while(x<=num){
        tree[x]+=d;
        tree[x]%=P;
        x = x+lowbit(x);
    }
}
ll chaxun(int x){
    ll ans=0;
    while(x){
        ans+=tree[x];
        x -= lowbit(x);
    }
    return ans%P;
}
bool bijiao(node a,node b){
    return a.sum<b.sum;
}
int main(){
    int n,i;
    ll dp;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&dp);
        p[i].sum=p[i-1].sum+dp;
        p[i].id=i;
    }
    sort(p,p+n+1,bijiao);
    lisan[p[0].id]=1;
    for(i=1;i<=n;i++){
        if(p[i].sum!=p[i-1].sum){
            num++;
        }
        lisan[p[i].id]=num;
    }
    update(lisan[0],1);
    for(i=1;i<=n;i++){
        dp = chaxun(lisan[i]);
        update(lisan[i],dp);
    }
    printf("%lld",dp);
    return 0;
}