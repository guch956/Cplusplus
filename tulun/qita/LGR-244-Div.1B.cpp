#include<iostream>
#include<cstdio>
#include<queue>
#include<utility>
using namespace std;
const int N=100003;
const int INF=0x3f3f3f3f;
int dis[N][22];
int tim[N];
int head[22],typ[22],to[22],nex[22],ent;
int xianz[22];
int beg[22];
struct {
    int type;
    int xi;
}p[22];
void add(int u,int v,int t){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    typ[ent]=t;
    head[u]=ent;
}
int main(){
    int n,m,i,t,d,x,j,k;
    queue<pair<int,int>> q;
    pair<int,int> u;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){tim[i]=INF;dis[i][0]=INF;}
    for(i=1;i<=n;i++)scanf("%d",&xianz[i]);
    for(i=1;i<=n;i++){
        scanf("%d %d %d",&t,&x,&d);
        add(d,x,t);
        for(j=1;j<=m;j++){dis[j][i]=INF;}
    }
    t = 1;
    for(i=1;i<=n;i++){
        beg[i]=t;
        for(j=head[i];j;j=nex[j]){
            p[t].type=typ[j];
            p[t].xi=to[j];
            t++;
        }
    }
    beg[n+1]=t;
    for(j=1;j<=n;j++){
        for(i=beg[j];i<=n;i++){
            if(p[i].type==1)continue;
            for(k=0;k<p[i].xi;k++){
                if(dis[k][i]<INF){
                    q.push(make_pair(k,i));
                    dis[k][i]=0;
                }
            }
        }
        for(k=0;k<m;k++){
            if(dis[k][0]<INF){
                q.push(make_pair(k,0));
                dis[k][0]=0;
            }
        }
        while(q.size()){
            u = q.front();
            q.pop();
            if(dis[u.first][u.second]==xianz[j]){continue;}
            for(i=beg[j];i<beg[j+1];i++){
                if(p[i].type==1){
                    x = u.second==0?u.first+p[i].xi:(u.first+p[i].xi)%p[u.second].xi;
                    if(u.second==0 && x>m)continue;
                    if(dis[x][u.second]>dis[u.first][u.second]+1){
                        dis[x][u.second]=dis[u.first][u.second]+1;
                        q.push(make_pair(x,u.second));
                    }
                }
            }
            if(u.second && u.second<beg[j+1]){
                x = 2*u.first%p[u.second].xi;
                if(dis[x][u.second]>dis[u.first][u.second]+1){
                    dis[x][u.second]=dis[u.first][u.second]+1;
                    q.push(make_pair(x,u.second));
                }
                if(dis[x][0]>dis[u.first][u.second]+1){
                    dis[x][0]=dis[u.first][u.second]+1;
                    q.push(make_pair(x,0));
                    for(i=beg[j];i<=n;i++){
                        if(p[i].type==1)continue;
                        if(dis[x%p[i].xi][i]>dis[x][0]){
                            dis[x%p[i].xi][i]=dis[x][0];
                            q.push(make_pair(x%p[i].xi,i));
                        }
                    }
                }
            }
        }
        for(i=1;i<=m;i++){
            if(dis[i][0]<INF){tim[i]=min(tim[i],j);}
        }
    }
    for(i=1;i<=m;i++){
        if(tim[i]<INF)printf("%d",tim[i]);
        else printf("-1");
        printf("\n");
    }
    return 0;
}