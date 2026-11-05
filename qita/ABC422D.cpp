#include<iostream>
#include<cstdio>
using namespace std;
int zhi[(1<<20)+4];
int main(){
    int n,k,m,ans,i,r,a,b;
    scanf("%d %d",&n,&k);
    m = 1<<n;
    ans = k/m;
    for(i=0;i<m;i++){zhi[i]=ans;}
    if(k%m==0){ans = 0;}
    else{
        r = k%m;
        for(i=0;i<r;i++){
            b = 0;
            for(a=0;a<n;a++){
                if((1<<a)&i){
                    b+=1<<(n-1-a);
                }
            }
            zhi[b]++;
        }
        ans=1;
    }
    printf("%d\n",ans);
    for(i=0;i<m;i++){printf("%d ",zhi[i]);}
    return 0;
}