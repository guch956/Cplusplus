#include<iostream>
#include<cstdio>
#include<queue>
#define ll long long
using namespace std;
const int N=1000003;
const int LEN=32;
struct {
    int son[2];
    int siz;
}t[N*LEN];
int ent;
int p[50];
int root[N];
ll sum[N];
ll total=0;
int newnode(int s1){
    ent++;
    t[ent].siz=s1;
    return ent;
}
void getp(ll x){
    for(int i=LEN-1;i>=0;i--){
        p[i]=x&1;
        x = x>>1;
    }
}
void insert(int * s,int k){
    int i,now=root[k-1],r=root[k];
    for(i=0;i<LEN;i++){
        t[r].son[s[i]]=newnode(t[t[now].son[s[i]]].siz+1);
        t[r].son[s[i]^1]=t[now].son[s[i]^1];
        now = t[now].son[s[i]];
        r = t[r].son[s[i]];
    }
}
ll chaxun(int k,int ti,int * s){
    int i,now=root[k-1],a;
    ll ans=0;
    for(i=0;i<LEN;i++){
        a = t[now].son[s[i]^1];
        if(t[a].siz>=ti){
            ans += (ll)1<<(LEN-i-1);
            now = a;
        }
        else{
            ti -= t[a].siz;
            now = t[now].son[s[i]];
        }
    }
    return ans;
}
struct node{
    int k;
    int p;
    ll zhi;
    bool operator<(const node a)const{
        return zhi<a.zhi;
    }
    node(int a,int b,ll c){
        k=a;p=b;zhi=c;
    }
};
int main(){
    int n=0,i,kk;
    ll a;
    node x(0,0,0);
    priority_queue<node> q;
    root[0]=newnode(1);
    n = root[0];
    for(i=0;i<LEN;i++){
        t[n].son[0]=newnode(1);
        n = t[n].son[0];
    }
    scanf("%d %d",&n,&kk); 
    for(i=1;i<=n;i++){
        scanf("%lld",&a);
        sum[i]=sum[i-1]^a;
        getp(sum[i]);
        root[i]=newnode(t[root[i-1]].siz+1);
        insert(p,i);
        q.push(node(i,1,chaxun(i,1,p)));
    }
    while(kk--){
        x=q.top();
        q.pop();
        total+=x.zhi;
        if(x.p<x.k){
            getp(sum[x.k]);
            q.push(node(x.k,x.p+1,chaxun(x.k,x.p+1,p)));
        }
    }
    printf("%lld",total);
    return 0;
}

