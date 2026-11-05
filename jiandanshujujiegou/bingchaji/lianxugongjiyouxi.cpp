#include<iostream>
#include<cstdio>
using namespace std;
const int N=10003;
int siz[N],fa[N],head[N];
int to[N*100],nex[N*100],ent;
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
int find(int x){
    if(fa[x]!=x){fa[x]=find(fa[x]);}
    return fa[x];
}
void hebing(int x,int y){
    int a=find(x),b=find(y);
    if(a!=b){
        fa[b]=a;
        siz[a]+=siz[b];
    }
}
int main(){
    int n,i,a,b;
    scanf("%d",&n);
    for(i=1;i<=10000;i++){
        fa[i]=i;
        siz[i]=-1;
    }
    for(i=1;i<=n;i++){
        scanf("%d %d",&a,&b);
        if(a>b){swap(a,b);}
        siz[a]++;
        adde(b,a);
    }
    for(i=1;i<=10000;i++){
        for(b=head[i];b;b=nex[b]){
            hebing(i,to[b]);
        }
        if(siz[i]<0){break;}
    }
    printf("%d",i-1);
    return 0;
}
