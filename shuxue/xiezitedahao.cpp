#include<iostream>
#include<cstdio>
#define ull unsigned long long
using namespace std;
const int N=1000003;
int w[N];
int pri[N];
void init(){
    int i,j;
    int ent=0;
    for(i=2;i<N;i++){
        if(w[i]==0){
            pri[++ent]=i;
        }
        for(j=1;j<=ent;j++){
            if(i*pri[j]>=N){break;}
            w[i*pri[j]]=w[i]+1;
            if(i%pri[j]==0){
                break;
            }
        }
    }
} 
int main(){
    int q,i;
    ull b,a;
    init();
    cin>>q;
    while (q--){
        scanf("%d %lld",&i,&a);
        if(i==1){
            printf("%d\n",w[a]);
        }
        else{
            b = (ull)1<<(a+1);
            printf("%llu\n",b);
        }
    }
    return 0;
}
