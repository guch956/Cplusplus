#include<iostream>
#include<cstdio>
#include<queue>
#define ll long long
using namespace std;
const int N=100003;
int head[N],to[N<<1],nex[N<<1],id[N<<1],ent;
ll yezishu[N];
void adde(int u,int v,int i){
    ent++;
    nex[ent]=head[u];
    id[ent]=i;
    to[ent]=v;
    head[u]=ent;
}
struct node{
    int id;
    ll s;
    node(int i,ll s1){id=i;s=s1;}
    bool operator<(const node & n1)const{
        return s<n1.s;
    }
};
ll huafei[N*30];
ll w[N],c[N];
ll dfs(int s,int f){
    int i;
    ll num=0;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        yezishu[id[i]]=dfs(to[i],s);
        num+=yezishu[id[i]];
    }
    if(num==0){num=1;}
    return num;
}
int main(){
    int T,n,i,a,b,ans,m;
    ll S,sum,jian;
    node u(0,0);
    scanf("%d",&T);
    while (T--){
        priority_queue<node> q;
        scanf("%d %lld",&n,&S);
        ans = 0x3f3f3f3f;sum = 0;m = 0;
        for(i=1;i<n;i++){
            scanf("%d %d %lld %d",&a,&b,&w[i],&c[i]);
            adde(a,b,i);
            adde(b,a,i);
        }
        dfs(1,0);
        for(i=1;i<n;i++){
            sum += yezishu[i]*w[i];
            if(c[i]==2){q.push(node(i,yezishu[i]*(w[i]-(w[i]>>1))));}
        }
        while(q.size() && sum-huafei[m]>S){
            u = q.top();
            q.pop();
            m++;
            huafei[m]=huafei[m-1]+u.s;
            w[u.id]=w[u.id]>>1;
            if(w[u.id])q.push(node(u.id,yezishu[u.id]*(w[u.id]-(w[u.id]>>1))));
        }
        i = m;
        q=priority_queue<node>();
        for(a=1;a<n;a++){
            if(c[a]==1){q.push(node(a,yezishu[a]*(w[a]-(w[a]>>1))));}
        }
        m = 0;jian = 0;
        if(huafei[i]+S>=sum)ans = min(ans,2*i);
        while(q.size() && sum-jian>S){
            u = q.top();
            m++;
            q.pop();
            jian+=u.s;
            while(i && huafei[i-1]+jian+S>=sum){i--;}
            if(huafei[i]+jian+S>=sum)ans = min(ans,2*i+m);
            w[u.id]=w[u.id]>>1;
            if(w[u.id])q.push(node(u.id,yezishu[u.id]*(w[u.id]-(w[u.id]>>1))));
        }
        for(i=1;i<=n;i++){
            head[i]=yezishu[i]=0;
        }
        printf("%d\n",ans);
    }
    return 0;
}