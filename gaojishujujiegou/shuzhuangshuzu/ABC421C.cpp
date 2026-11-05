#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int N=500003;
inline int lowbit(int x){return x&(-x);}
ll tree[N<<1];
int n;
int weizhi[N<<1];
char s[N<<1];
void add(int x,ll d){
    while(x<=n){
        tree[x]+=d;
        x+=lowbit(x);
    }
}
ll query(int x){
    ll a=0;
    while(x){
        a+=tree[x];
        x = x-lowbit(x);
    }
    return a;
}
ll jisuan(){
    int i;
    ll an=0;
    for(i=n;i>=1;i--){
        an += query(weizhi[i]);
        add(weizhi[i],1);
    }
    return an;
}
void get(int k0,int k1){
    int i;
    for(i=0;i<n;i++){
        if(s[i]=='A'){
            weizhi[k0]=i+1;
            k0+=2;
        }
        else{
            weizhi[k1]=i+1;
            k1+=2;
        }
    }
}
int main(){
    ll ans;
    int i;
    scanf("%d",&n);
    n = n<<1;
    scanf("%s",s);
    get(1,2);
    ans = jisuan();
    memset(tree,0,sizeof(tree));
    get(2,1);
    ans = min(ans,jisuan());
    printf("%lld",ans);
    return 0;
}