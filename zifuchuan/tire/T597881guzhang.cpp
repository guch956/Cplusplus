#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=300003;
int n;
ll siz[N*60],son[N*60][2];
bool del[N*60];
int ent;
int p[65];
ll fa[65];
int newnode(ll s){
    siz[++ent]=s;
    return ent;
}
int get(ll u){
    int l=0;
    while(u!=1){
        p[++l]=u&1;
        u = u>>1;
    }
    return l;
}
void change(int l){
    int i,j=0,now=1;
    ll si;
    fa[j]=now;
    for(i=l;i>=1;i--){
        if(!son[now][p[i]]){son[now][p[i]]=newnode(((ll)1<<(n-l+i-1))-1);}
        now = son[now][p[i]];
        fa[++j]=now;
    }
    if(del[now]){return ;}
    del[now]=1;
    si = siz[now];
    for(i=l-1;i>=0;i--){
        siz[fa[i]]-=si;
        if(del[fa[i]]){break;}
    }
}
ll chaxun(int l){
    int i,now=1,f=1;
    for(i=l;i>=1;i--){
        if(!son[now][p[i]]){return siz[f];}
        now = son[now][p[i]];
        if(del[now]){f = now;}
    }
    return siz[f];
}
int main(){
    int i,q,l;
    ll u,t,ans=0;
    scanf("%d %d",&n,&q);
    newnode(((ll)1<<n)-1);
    while(q--){
        scanf("%d %lld",&i,&u);
        l = get(u);
        if(i==1){
            if(l){change(l);}
        }
        else{
            t = chaxun(l);
            ans = ans^t;
        }
    }
    std::cout<<ans;
    return 0;
}