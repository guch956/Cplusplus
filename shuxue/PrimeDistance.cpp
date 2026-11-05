#include<iostream>
#include<cstdio>
const int N=1000004;
using namespace std;
int pri[N];
bool vis[N];
int ent=-1;
void init(){
    int i,j;
    for(i=2;i<N;i++){
        if(!vis[i]){
            pri[++ent]=i;
        }
        for(j=0;j<=ent;j++){
            if(i*pri[j]>=N){break;}
            vis[i*pri[j]]=1;
            if(i%pri[j]==0){break;}
        }
    }
}
int main(){
    int l,r;
    init();
    for(l=0;l<=ent;l++){
        cout<<pri[l]<<endl;
    }
    return 0;
}