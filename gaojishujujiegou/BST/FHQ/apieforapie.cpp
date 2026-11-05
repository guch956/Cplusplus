#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
using namespace std;
const int N=100003;
const int INF=0x3f3f3f3f;
struct {
    int ls;
    int rs;
    int val;
    int other;
    int pri;
}t[N<<1];
int dis[N<<1];
queue<int> q;
void fenlie(int x,int u,int & L,int & R){
    if(u==0){L=R=0;return ;}
    if(t[u].val<=x){
        L = u;
        fenlie(x,t[u].rs,t[L].rs,R);
    }
    else{
        R = u;
        fenlie(x,t[u].ls,L,t[R].ls);
    }
}
int hebing(int L,int R){
    if(L==0 || R==0){return L+R;}
    if(t[L].pri>t[R].pri){
        t[L].rs=hebing(t[L].rs,R);
        return L;
    }
    else{
        t[R].ls=hebing(L,t[R].ls);
        return R;
    }
}
void add(int & r,int i){
    int L,R;
    fenlie(t[i].val,r,L,R);
    r = hebing(hebing(L,i),R);
}
void dfs(int s,int di){
    if(s==0){return ;}
    if(dis[s]>di){dis[s]=di;q.push(s);}
    dfs(t[s].ls,di);
    dfs(t[s].rs,di);
}
int main(){
    int n,i,root[2],d,L,R,u,K,a;
    root[0]=root[1]=0;
    scanf("%d %d",&n,&d);
    for(i=1;i<=n;i++){
        scanf("%d %d",&t[i].other,&t[i].val);
        if(t[i].val==0){
            q.push(i);
            dis[i]=1;
        }
        else{
            t[i].pri=rand();
            add(root[0],i);
            dis[i]=INF;
        }
    }
    for(i=n+1;i<=2*n;i++){
        scanf("%d %d",&t[i].val,&t[i].other);
        if(t[i].val==0){
            q.push(i);
            dis[i]=1;
        }
        else{
            t[i].pri=rand();
            add(root[1],i);
            dis[i]=INF;
        }
    }
    while(q.size()){
        u = q.front();
        q.pop();
        if(u<=n){a=1;}
        else{a=0;}
        fenlie(t[u].other-d-1,root[a],L,R);
        fenlie(t[u].other,R,K,R);
        root[a]=hebing(L,R);
        dfs(K,dis[u]+1);
    }
    for(i=1;i<=n;i++){
        if(dis[i]<INF){
            printf("%d\n",dis[i]);
        }
        else{
            printf("-1\n");
        }
    }
    return 0;
}