#include<iostream>
#include<cstdio>
void dfs(int n){
    if(n<0){return ;}
    if(n==0){printf("1 0\n");return ;}
    if(n==1){printf("2 1 0\n");return ;}
    int i,k=1,m;
    while((k<<1)<=n){k = k<<1;}
    m = (k<<1)-1;
    for(i=k;i<=n;i++){
        printf("2 %d %d\n",i,m-i);
    }
    dfs(m-n-1);
}
int main(){
    int T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        printf("%d\n",(n>>1)+1);
        dfs(n);
    }
    return 0;
}