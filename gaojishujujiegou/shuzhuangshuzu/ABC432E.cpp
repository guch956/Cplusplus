#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=500003;
ll A[N];
class t{
private:
    ll* tree;
    ll* sum;
    inline int lowbit(int x){return x&(-x);}
    ll get_s(int x);
    ll get_n(int x);
public:
    t(){
        tree = new ll[N];
        sum = new ll[N];
        memset(tree,0,sizeof(tree));
        memset(sum,0,sizeof(sum));
    }
    void update(int x,ll d);
    void chaxun(ll l,ll r);
};
ll t::get_s(int x){
    ll ans=0;
    x++;
    while(x){
        ans+=sum[x];
        x-=lowbit(x);
    }
    return ans;
}
ll t::get_n(int x){
    ll ans=0;
    x++;
    while(x){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}
void t::update(int x,ll d){
    ll y = x;
    x++;
    while(x<N){
        tree[x]+=d;
        sum[x]+=d*y;
        x+=lowbit(x);
    }
}
void t::chaxun(ll l,ll r){
    ll ans=0;
    ans = max(l,r)*(get_n(N-2)-get_n(r-1));
    if(l>=r){
        ans+=l*(get_n(r-1));
    }
    else{
        ans+=l*(get_n(l-1));
        ans+=get_s(r-1)-get_s(l-1);
    }
    printf("%lld\n",ans);
}
int main(){
    int n,q,i,a,x,y;
    t tt = t();
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        A[i]=a;
        tt.update(a,1);
    }
    while(q--){
        scanf("%d %d %d",&i,&x,&y);
        if(i==1){
            tt.update(A[x],-1);
            tt.update(y,1);
            A[x]=y;
        }
        else{
            tt.chaxun(x,y);
        }
    }
    return 0;
}