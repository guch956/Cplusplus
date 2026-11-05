#include<iostream>
#include<cstdio>
using namespace std;
int num[1000003];
int main(){
    int n,q,i,up=0,x,y,geshu;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){num[i]=1;}
    while(q--){
        scanf("%d %d",&x,&y);
        geshu=0;
        for(i=up+1;i<=x;i++){
            geshu+=num[i];
            num[i]=0;
        }
        up = max(up,x);
        num[y]+=geshu;
        printf("%d\n",geshu);
    }
    return 0;
}