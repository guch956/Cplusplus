#include<iostream>
#include<cstdio>
using namespace std;
const int N=10002;const int M=50003;
struct edge{
    int to;
    int next;
};
edge g[M];int head[N];int ent=1;
int numb;int liant[N];
int num[N];int low[N];int dfn;
int rudu[N];
int stack[N];int top;
int n;
void addedge(int u,int to){
    g[ent].to=to;
    g[ent].next=head[u];
    head[u]=ent;
    ent++;
}
void tarjan(int s){
    int i,v;
    dfn++;num[s]=dfn;low[s]=dfn;
    stack[top]=s;top++;
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(num[v]==0){
            tarjan(v);
            low[s] = min(low[s],low[v]);
        }
        else if(liant[v]==0){
            low[s] = min(low[s],num[v]);
        }
    }
    if(low[s]==num[s]){
        numb++;
        while(1){
            top--;
            liant[stack[top]]=numb;
            if(stack[top]==s){
                break;
            }
        }
    }
}
void jisuan(){
    int ans=0,x;int i,j,v;
    for(i=1;i<=n;i++){
        if(num[i]==0){
            tarjan(i);
        }
    }
    for(i=1;i<=n;i++){
        for(j=head[i];j!=0;j=g[j].next){
            v=g[j].to;
            if(liant[i]!=liant[v]){
                rudu[liant[i]]++;
            }
        }
    }
    for(i=1;i<=numb;i++){
        if(rudu[i]==0){
            if(ans==1){
                cout<<0;
                return ;
            }
            ans++;
            x=i;
        }
    }
    ans=0;
    for(i=1;i<=n;i++){
        if(liant[i]==x){
            ans++;
        }
    }
    cout<<ans;
}
int main(){
    int m,i,a,b;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        addedge(a,b);
    }
    jisuan();
    return 0;
}