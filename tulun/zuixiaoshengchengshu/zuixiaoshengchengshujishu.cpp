#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct e{
    int u1;
    int u2;
    int w;
}g[1003];
bool bijiao(e & g1,e & g2){
    return g1.w<g2.w;
}
struct {
    int to;
    int next;
}g1[203];
int head[103],ent=-1;
int P=31011;
int total=1,ans,n,huan,last;
int fa[103];
int fa1[103];
bool vis[103];
int find_set(int x){
    if(fa[x]!=x){
        fa[x] = find_set(fa[x]);
    }
    return fa[x];
}
void dfs(int s,int e){
    int v,i;
    vis[s]=1;
    for(i=head[s];i!=-1;i=g1[i].next){
        if(i==(e^1)){continue;}
        v = g1[i].to;
        if(!vis[v]){
            dfs(v,i);
        }
        else{
            huan = 0;
        }
    }
}
void adde(int u,int v){
    ent++;
    g1[ent].to=v;
    g1[ent].next=head[u];
    head[u] = ent;
}
int find_set1(int x){
    if(fa1[x]!=x){
        fa1[x] = find_set(fa1[x]);
    }
    return fa1[x];
}
void dfs1(int tnum,int num){
    if(num==0){
        huan = 1;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i,10000);
            }
        }
        ans+=huan;
    }
    else{
        if(tnum<num){
            dfs1(tnum,num-1);
        }
        if(tnum){
            int a = find_set1(g[last+num].u1),b=find_set1(g[last+num].u2);
            int last1=head[a],last2=head[b];
            adde(a,b);
            adde(b,a);
            dfs1(tnum-1,num-1);
            head[a] = last1;
            head[b] = last2;
            ent -= 2;
        }
    }
}
int main(){
    int i,m,a,b,num=0,tnum=0,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&g[i].u1,&g[i].u2,&g[i].w);
    }
    for(i=1;i<=n;i++){
        head[i]=-1;
        fa[i] = i;
        fa1[i]=i;
    }
    sort(g+1,g+m+1,bijiao);
    for(i=1;i<=m;i++){
        a = find_set(g[i].u1);
        b = find_set(g[i].u2);
        if(a!=b){
            tnum++;
            fa[a] = b;
        }
        num++;
        if(g[i].w!=g[i+1].w){
            ans=0;
            if(tnum>0){
                dfs1(tnum,num);
                total = (total*ans)%P;
            }
            last = i;
            for(j=1;j<=n;j++){
                fa1[j] = fa[j];
            }
            num = 0;
            tnum = 0;
        }
    }
    cout<<total;
    return 0;
}