#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100003;
int fa[N],siz[N];
struct edge{
    int u;
    int v;
    int r;
}g[N];
bool bijiaoe(edge & e1,edge & e2){
    return e1.r>e2.r;
}
struct query{
    int v;
    int k;
    int bianhao;
}q[N];
int ans[N];
bool bijiaoq(query & q1,query & q2){
    return q1.k>q2.k;
}
int find(int x){
    if(fa[x]!=x){
        fa[x]=find(fa[x]);
    }
    return fa[x];
}
void hebing(int x,int y){
    int a=find(x),b=find(y);
    fa[a]=b;
    siz[b]+=siz[a];
}
int main(){
    int n,m,i,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<n;i++){
        fa[i]=i;
        siz[i]=1;
        scanf("%d %d %d",&g[i].u,&g[i].v,&g[i].r);
    }
    fa[n]=n;
    siz[n]=1;
    for(i=0;i<m;i++){
        scanf("%d %d",&q[i].k,&q[i].v);
        q[i].bianhao=i;
    }
    sort(g+1,g+n,bijiaoe);
    sort(q,q+m,bijiaoq);
    j=1;
    for(i=0;i<m;i++){
        while(j<n && g[j].r>=q[i].k){
            hebing(g[j].u,g[j].v);
            j++;
        }
        ans[q[i].bianhao]=siz[find(q[i].v)]-1;
    }
    for(i=0;i<m;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}