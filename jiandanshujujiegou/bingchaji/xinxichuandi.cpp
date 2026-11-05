#include<iostream>
#include<queue>
using namespace std;
const int N=200002;
struct edge{
    int to;
    int next;
};
int s[N],fa[N],vis[N];
int n;
edge g[2*N];int ent=1;int head[N];
void adde(int a,int b){
    g[ent].next=head[a];
    g[ent].to=b;
    head[a]=ent;
    ent++;
}
int main(){
    int i;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>fa[i];
    }
}