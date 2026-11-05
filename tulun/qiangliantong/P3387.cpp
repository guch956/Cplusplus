#include<iostream>
using namespace std;
const int N=10002;const int M=200003;
struct edge{
    int to;
    int next;
};
edge g[M];int head[N];int ent=1;
int dfn;int num[N];int low[N];
int liant[N];int numb;
int stack[N];int top;
int n;
int dian[N];int liant_dian[N];
int liant_head[N];
int rudu[N];
void addedge(int a,int b){
    g[ent].to=b;
    g[ent].next=head[a];
    head[a]=ent;
    ent++;
}
void liant_addedge(int a,int b){
    g[ent].to=b;
    g[ent].next=liant_head[a];
    liant_head[a]=ent;
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
            liant_dian[numb]+= dian[stack[top]];
            if(stack[top]==s){
                break;
            }
        }
    }
}
void dfs(int s){
    int i,v;
    num[s]=1;
    stack[top]=s;
    top++;
    for(i=liant_head[s];i!=0;i=g[i].next){
        v=g[i].to;
        rudu[v]--;
        if(rudu[v]==0 && num[v]==0){
            dfs(v);
        }
    }
}
void jisuan(){
    int i,j,v,ans=0;
    for(i=1;i<=n;i++){
        if(num[i]==0){
            tarjan(i);
        }
    }
    for(i=1;i<=n;i++){
        for(j=head[i];j!=0;j=g[j].next){
            v=g[j].to;
            if(liant[i]!=liant[v]){
                liant_addedge(liant[i],liant[v]);
                rudu[liant[v]]++;
            }
        }
    }
    top=0;
    for(i=1;i<=numb;i++){
        num[i]=0;
    }
    for(i=1;i<=numb;i++){
        if(rudu[i]==0){
            dfs(i);
        }
    }
    for(i=top-1;i>=0;i--){
        for(j=liant_head[stack[i]];j!=0;j=g[j].next){
            v = g[j].to;
            rudu[stack[i]]=max(rudu[stack[i]],rudu[v]);
        }
        rudu[stack[i]]+=liant_dian[stack[i]];
    }
    for(i=1;i<=n;i++){
        ans = max(ans,rudu[i]);
    }
    cout<<ans;
}
int main(){
    int m,i,a,b;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>dian[i];
    }
    for(i=1;i<=m;i++){
        cin>>a>>b;
        addedge(a,b);
    }
    jisuan();
    return 0;
}