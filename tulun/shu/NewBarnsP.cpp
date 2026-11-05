#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
int fa[N][17];
int zhijing[N][2];
int deep[N];
int liant[N];
int n,k;
int lca(int x,int y){
    int i;
    if(deep[x]<deep[y]){swap(x,y);}
    for(i=16;i>=0;i--){
        if(deep[fa[x][i]]>=deep[y]){
            x = fa[x][i];
        }
    }
    for(i=16;i>=0;i--){
        if(fa[x][i]!=fa[y][i]){
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    if(x==y){return x;}
    else{return fa[x][0];}
}
int dis(int x,int y){
    int z=lca(x,y);
    return deep[x]+deep[y]-2*deep[z];
}
void build(int p){
    int i;
    n++;
    if(p==-1){
        fa[n][0]=n;
        k++;
        liant[n]=k;
        zhijing[k][0]=zhijing[k][1]=n;
    }
    else{
        fa[n][0]=p;
        deep[n]=deep[p]+1;
        liant[n]=liant[p];
    }
    for(i=1;i<=16;i++){
        fa[n][i]=fa[fa[n][i-1]][i-1];
    }
    if(p!=-1){
        int l=dis(zhijing[liant[p]][0],zhijing[liant[p]][1]);
        if(dis(n,zhijing[liant[p]][0])>l){
            zhijing[liant[p]][1]=n;
        }
        else if(dis(n,zhijing[liant[p]][1])>l){
            zhijing[liant[p]][0]=n;
        }
    }
}
int main(){
    int q,a;
    char c;
    scanf("%d",&q);
    while(q--){
        cin>>c;
        scanf("%d",&a);
        if(c=='B'){build(a);}
        else{
            printf("%d\n",max(dis(a,zhijing[liant[a]][0]),dis(a,zhijing[liant[a]][1])));
        }
    }
    return 0;
}