#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=100003;
int d[N],c[N];
int main(){
    int n,l,i,r,mid,s;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&c[i]);
        c[i]++;
    }
    l = 1;r = n;
    while(l<r){
        mid=(l+r)>>1;
        memset(d,0,sizeof(d));
        for(i=1;i<=mid;i++){
            d[c[i]]--;
        }
        d[0]=mid;
        s = 0;
        for(i=0;i<=n-1;i++){
            s+=d[i];
            if(s+i>=n){break;}
        }
        if(i<n){r=mid;}
        else{l=mid+1;}
    }
    printf("%d",n-l);
    return 0;
}