#include<iostream>
#include<cstdio>
using namespace std;
const int N=50003;
int fa[N];
int find(int x){
    if(x!=fa[x]){
        fa[x]=find(fa[x]);
    }
    return fa[x];
}
int main(){
    int i,n,m,a,b,t=0,ans;
    while(1){
        scanf("%d %d",&n,&m);
        t++;
        ans=n;
        if(n==0){break;}
        for(i=1;i<=n;i++){fa[i]=i;}
        for(i=1;i<=m;i++){
            scanf("%d %d",&a,&b);
            if(find(a)!=find(b)){
                fa[find(a)]=find(b);
                ans--;
            }
        }
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}