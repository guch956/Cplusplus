#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
const int N=200003;
const ll INF=0x3f3f3f3f3f3f3f3f;
struct {
    int ls;
    int rs;
    ll y;
    ll val;
    ll mi;
    int pri; 
}t[N];
int ent;
ll point[N][2];
int zhi[N];
ll ans[N];
int entp;
int paixu[N];
void push_up(int x){t[x].mi=min(min(t[t[x].ls].mi,t[t[x].rs].mi),t[x].val);}
void fenlie(int u,ll y1,int & L,int & R){
    if(u==0){L=R=0;return ;}
    if(t[u].y<y1){
        L = u;
        fenlie(t[u].rs,y1,t[L].rs,R);
    }
    else{
        R = u;
        fenlie(t[u].ls,y1,L,t[R].ls);
    }
    push_up(u);
}
int hebing(int L,int R){
    if(L==0 || R==0){return L+R;}
    if(t[L].pri>t[R].pri){
        t[L].rs=hebing(t[L].rs,R);
        push_up(L);
        return L;
    }
    else{
        t[R].ls=hebing(L,t[R].ls);
        push_up(R);
        return R;
    }
}
int addnode(ll y1,ll v){
    ent++;
    t[ent].ls=t[ent].rs=0;
    t[ent].mi=t[ent].val=v;
    t[ent].y=y1;
    t[ent].pri=rand();
    return ent;
}
void addp(ll x,ll y){
    point[entp][0]=x;
    point[entp][1]=y;
    paixu[entp]=entp;
    entp++;
}
bool bijiao(int a,int b){
    return point[a][0]==point[b][0]?point[a][1]>point[b][1]:point[a][0]>point[b][0];
}
int main(){
    int n,root,i,L,R;
    ll N,x1,x2,y1,y2;
    t[0].mi=INF;
    scanf("%lld %d",&N,&n);
    addp(0,0);
    for(i=1;i<=n;i++){
        scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
        addp(x1,y1);
        zhi[entp-1]=entp;
        addp(x2,y2);
    }
    sort(paixu,paixu+entp,bijiao);
    root=addnode(N,2*N);
    for(i=0;i<entp;i++){
        fenlie(root,point[paixu[i]][1],L,R);
        ans[paixu[i]]=t[R].mi-point[paixu[i]][0]-point[paixu[i]][1];
        if(zhi[paixu[i]]){
            ans[paixu[i]]=min(ans[paixu[i]],ans[zhi[paixu[i]]]);
        }
        root=addnode(point[paixu[i]][1],ans[paixu[i]]+point[paixu[i]][0]+point[paixu[i]][1]);
        root=hebing(L,hebing(root,R));
    }
    printf("%lld",ans[0]);
    return 0;
}