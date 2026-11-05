#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
int fa[N],p[N];
int find(int x){
    if(fa[x]!=x){
        fa[x] = find(fa[x]);
    }
    return fa[x];
}
int u[N],v[N],w[N];
int main(){
    int n,l=1,r=0,mid,a,m,i,b,c;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&p[i]);
    }
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&u[i],&v[i],&w[i]);
        r = max(r,w[i]);
    }
    r++;c = r;
    while(l<r){
        mid=(l+r+1)>>1;
        for(i=1;i<=n;i++){fa[i]=i;}
        for(i=1;i<=m;i++){
            if(w[i]>=mid){
                a = find(u[i]);
                b = find(v[i]);
                if(a!=b){
                    fa[a]=b;
                }
            }
        }
        for(i=1;i<=n;i++){
            if(find(i)!=find(p[i])){
                r = mid-1;
                break;
            }
        }
        if(r>=mid){
            l = mid;
        }
    }
    if(r==c){cout<<-1;}
    else{cout<<l;}
    return 0;
}