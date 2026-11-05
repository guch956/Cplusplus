#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=50003;
const int INF=0x3f3f3f3f;
int head[N],nex[N<<2],to[N<<2],w[N<<2];
int ent;
int dis[N];
struct node{
    int id;
    int di;
    node(int i,int d){id=i;di=d;}
    bool operator<(const node n1)const{
        return di>n1.di;
    }
};
void adde(int u,int v,int w1){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    w[ent]=w1;
    head[u]=ent;
}
int dij(int s,int n){
    int i,d,ans=INF,ma;
    node u(s,0);
    priority_queue<node> q;
    for(i=1;i<=n;i++){
        dis[i]=INF;
    }
    dis[s]=0;
    q.push(u);
    while(q.size()){
        u = q.top();
        q.pop();
        if(u.di>dis[u.id])continue;
        for(i=head[u.id];i;i=nex[i]){
            d = u.di+1;
            if(d<w[i]){
                if((w[i]-d)%2==0)d = w[i];
                else d = w[i]+1;
            }
            if(d<dis[to[i]]){
                dis[to[i]]=d;
                q.push(node(to[i],d));
            }
        }
    }
    ma = 0;
    for(i=1;i<=n/2;i++){
        ma = max(dis[i],ma);
    }
    ans = min(ans,ma);
    ma = 0;
    for(i=n/2+1;i<=n;i++){
        ma = max(dis[i],ma);
    }
    ans = min(ans,ma);
    if(ans==INF)return -1;
    return ans;
}
int main(){
    int T,n,m,i,a,b,o,c,ans;
    scanf("%d %d",&c,&T);
    while(T--){
        scanf("%d %d %d",&n,&m,&o);
        while(m--){
            scanf("%d %d %d",&a,&b,&c);
            adde(a,b+n,c);
            adde(b+n,a,c);
            adde(a+n,b,c);
            adde(b,a+n,c);
        }
        ans = 2;
        for(i=head[1];i;i=nex[i]){
            ans = min(ans,w[i]);
        }
        if(ans!=1)ans = -1;
        else ans = dij(1,2*n);
        for(i=1;i<=n;i++){head[i]=head[i+n]=0;}
        ent = 0;
        printf("%d\n",ans==-1?ans:ans*o);
    }
    return 0;
}