#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=100003;
ll tree[N];
inline int lowbit(int x){return x&(-x);}
int n,k;
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
int weizhi[N],pinzhong[N];
int w[N],p[N];
int shanchu[N];
ll ans;
ll solve(int l,int r){
    if(l==r){return 0;}
    int i,j,t=0,s=0;
    int mid=(l+r)>>1;
    ll nixu=0;
    nixu+=solve(l,mid);
    nixu+=solve(mid+1,r);
    i = l;j = mid+1;
    while(i<=mid || j<=r){
        if(j==r+1 || (i<=mid && weizhi[i]<weizhi[j])){
            w[t]=weizhi[i];
            p[t]=pinzhong[i];
            ans+=chaxun(min(n,pinzhong[i]+k))-chaxun(max(0,pinzhong[i]-k-1));
            nixu+=j-mid-1;
            i++;
        }
        else{
            w[t]=weizhi[j];
            p[t]=pinzhong[j];
            update(pinzhong[j],1);
            shanchu[++s]=pinzhong[j];
            j++;
        }
        t++;
    }
    for(i=l;i<=r;i++){
        weizhi[i]=w[i-l];
        pinzhong[i]=p[i-l];
    }
    for(i=1;i<=s;i++){update(shanchu[i],-1);}
    return nixu;
}
int main(){
    int i,a;
    ll an;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        p[a]=i;
    }
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        weizhi[i]=p[a];
        pinzhong[i]=a;
    }
    an=solve(1,n);
    printf("%lld",an-ans);
    return 0;
}