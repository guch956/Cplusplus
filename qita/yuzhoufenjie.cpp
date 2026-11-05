#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const ll P=998244353;
const int N=100003;
struct node{
    int val;
    int id;
}p[N];
bool bijiao(node & n1,node & n2){
    return n1.val<n2.val;
}
int q[N];
ll num[N];
int main(){
    int n,d=0,mi=0x3f3f3f3f,i,a;
    ll ans=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&p[i].val);
        p[i].id=i;
    }
    sort(p+1,p+n+1,bijiao);
    for(i=1;i<=n;i++){
        if(p[i].val!=p[i-1].val){d++;}
        q[p[i].id]=d;
    }
    for(i=1;i<=n;i++){
        if(q[i]>mi){num[q[i]]++;}
        mi = min(q[i],mi);
    }
    for(i=1;i<=d;i++){
        ans = ans*(num[i]+1)%P; 
    }
    printf("%lld",ans);
    return 0;
}