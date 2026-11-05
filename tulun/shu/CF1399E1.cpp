#include<iostream>
#include<cstdio>
#include<queue>
#define ll long long
using namespace std;
const int N=100005;
int nex[N<<1],id[N<<1],to[N<<1],head[N],ent;
ll yezishu[N];
ll num[N];
ll w[N];
class node
{
public:
    int i;
    ll jianshao;
    node(int i1,ll j1){i=i1;jianshao=j1;}
    bool operator< (const node & n1)const{return jianshao<n1.jianshao;}
};
void adde(int u,int v,int i){
    ent++;
    id[ent]=i;
    nex[ent]=head[u];
    to[ent]=v;
    head[u]=ent;
}
void dfs(int s,int f){
    int i;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        dfs(to[i],s);
        yezishu[id[i]]=num[to[i]];
        num[s]+=num[to[i]];
    }
    if(num[s]==0){num[s]=1;}
}
int main(){
    int T,n,i,a,b,ans;
    ll s,sum,d;
    node u(0,0);
    scanf("%d",&T);
    while(T--){
        priority_queue<node> q;
        scanf("%d %lld",&n,&s);
        sum=0;ans=0;
        for(i=1;i<n;i++){
            scanf("%d %d %lld",&a,&b,&w[i]);
            adde(a,b,i);
            adde(b,a,i);
        }
        dfs(1,1);
        for(i=1;i<n;i++){
            sum+=yezishu[i]*w[i];
            d = w[i]/2;
            q.push(node(i,yezishu[i]*(w[i]-d)));
        }
        while(sum>s){
            u = q.top();
            q.pop();
            sum-=u.jianshao;
            w[u.i]=w[u.i]/2;
            u.jianshao=yezishu[u.i]*(w[u.i]-(w[u.i]/2));
            q.push(u);
            ans++;
        }
        printf("%d\n",ans);
        for(i=1;i<=n;i++){
            yezishu[i]=head[i]=num[i]=0;
        }
    }
    return 0;
} 