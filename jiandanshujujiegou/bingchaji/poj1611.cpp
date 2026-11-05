#include<cstdio>
#include<iostream>
int siz[30003];
int fa[30003];
int find(int x){
    if(fa[x]!=x){
        fa[x]=find(fa[x]);
    }
    return fa[x];
}
void hebing(int x,int y){
    int a=find(x),b=find(y);
    if(a!=b){
        fa[a]=b;
        siz[b]+=siz[a];
    }
}
int main(){
    int n,m,k,i,a,b;
    while(1){
        scanf("%d %d",&n,&m);
        if(n==0){break;}
        for(i=0;i<n;i++){
            fa[i]=i;siz[i]=1;
        }
        while(m--){
            scanf("%d",&k);
            if(k){scanf("%d",&a);}
            for(i=1;i<k;i++){scanf("%d",&b);hebing(a,b);}
        }
        printf("%d\n",siz[find(0)]);
    }
    return 0;
}