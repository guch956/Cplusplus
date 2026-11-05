#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
int fa[N];
int siz[N];
int find(int x){
    if(fa[x]!=x){fa[x]=find(fa[x]);}
    return fa[x];
}
void hebing(int x,int y){
    int a=find(x),b=find(y);
    siz[a]++;
    if(a!=b){
        fa[b]=a;
        siz[a]+=siz[b];
    }
}
int main(){
    int n,k,i,x,y,ans=0;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++){fa[i]=i;siz[i]=-1;}
    while(k--){
        scanf("%d %d",&x,&y);
        hebing(x,y);
    }
    for(i=1;i<=n;i++){
        if(fa[i]==i)ans+=siz[i]+1;
    }
    printf("%d",ans);
    return 0;
}