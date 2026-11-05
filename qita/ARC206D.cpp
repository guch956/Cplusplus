#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int T,i,n,k;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&k);
        if(n==1){
            if(k==0)printf("-1");
            else printf("1");
        }
        else{
            if(k>=2){
                for(i=1;i<=n-k;i++)printf("%d ",n+1-i);
                for(i=1;i<=k;i++)printf("%d ",i);
            }
            else printf("-1");
        }
        printf("\n");
    }
    return 0;
}