#include<iostream>
#include<cstdio>
using namespace std;
const int N=(1<<20)+1;
int pri[N],top;
int ispri[N];
void init(){
    int i,j,k;
    for(i=2;i<=N;i++){
        if(!ispri[i]){
            pri[++top]=i;
            ispri[i]=i;
        }
        for(j=1;j<=top;j++){
            k = i*pri[j];
            if(k>N){break;}
            ispri[k]=pri[j];
            if(i%pri[j]==0){break;}
        }
    }
}
int sum,num;
int suyinzi[30];
int geshu[30];
int vp[9];
void get(int x){
    num=0;sum=0;
    int p;
    while(x!=1){
        p = ispri[x];
        suyinzi[++num]=p;
        geshu[num]=0;
        while(x%p==0){
            geshu[num]++;
            x = x/p;
        }
        sum+=geshu[num];
    }
}
int vpn(int n,int p){
    int a=0,q=p;
    for(int i=1;q<=n;i++){
        a+=n/q;
        q = q*p;
    }
    return a;
}
int main(){
    int x,i,j;
    long long ans;
    init();
    while(~scanf("%d",&x)){
        get(x);
        ans=1;
        for(i=1;i<=8;i++){
            vp[i]=vpn(sum,pri[i]);
        }
        for(i=1;i<=num;i++){
            for(j=1;j<=8;j++){
                vp[j]-=vpn(geshu[i],pri[j]);
            }
        }
        for(i=1;i<=8;i++){
            for(j=1;j<=vp[i];j++){
                ans = ans*pri[i];
            }
        }
        printf("%d %lld\n",sum,ans);
    }
    return 0;
}
