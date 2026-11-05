#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=200003;
struct node{
    ll a;
    int id;
}pa[N];
ll pb[N],m;
int weizhi[N];
bool bijiao1(ll n1,ll n2){
    return (n1%m)<(n2%m);
}
bool bijiao2(node p1,node p2){
    return p1.a>p2.a;
}
void solve(){
    int n,i,k;
    ll ans=0,ma=0,d;
    scanf("%d %lld",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%lld",&pa[i].a);
        pa[i].id=i;
        pa[i].a=pa[i].a%m;
        ans+=pa[i].a;
    }
    for(i=1;i<=n;i++){
        scanf("%lld",&pb[i]);
        ans+=pb[i]%m;
    }
    sort(pa+1,pa+n+1,bijiao2);
    sort(pb+1,pb+n+1,bijiao1);
    k = 1;
    for(i=1;i<=n;i++){
        while(k<=n && pb[k]%m+pa[i].a<m){k++;}
        ma = max(ma,(ll)i-k+1);
    }
    ans = ans-ma*m;
    for(i=1+ma;i<=n;i++){
        weizhi[pa[i].id]=i-ma;
    }
    for(i=1;i<=ma;i++){
        weizhi[pa[i].id]=i+n-ma;
    }
    printf("%lld\n",ans);
    for(i=1;i<=n;i++){
        printf("%lld ",pb[weizhi[i]]);
    }
    printf("\n");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){solve();}
    return 0;
}