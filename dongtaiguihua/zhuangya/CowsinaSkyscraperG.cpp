#include<iostream>
#include<cstdio>
using namespace std;
int w[20];
int n;
int shengxia[(1<<18)-1];
int geshu[(1<<18)-1];
int main(){
    int i,W,ma,a,t;
    scanf("%d %d",&n,&W);
    ma = (1<<n)-1;
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(i=1;i<=ma;i++){
        a = 1;
        t = 1;
        while(a<=i){
            if((a|i) == i){
                if(shengxia[i-a]>=w[t]){
                    geshu[i]=geshu[i-a];
                    shengxia[i]=max(shengxia[i],shengxia[i-a]-w[t]);
                }
                else{
                    geshu[i]=geshu[i-a]+1;
                    shengxia[i]=max(shengxia[i],max(shengxia[i-a],W-w[t]));
                }
            }
            a = a<<1;
            t++;
        }
    }
    printf("%d",geshu[(1<<n)-1]);
    return 0;
}