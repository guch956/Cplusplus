#include<iostream>
#include<cstdio>
using namespace std;
bool ying[1000003];
void get(int n,int & mi,int & ma){
    mi=11;
    ma=-1;
    int i;
    while(n){
        i = n%10;
        if(i){mi=min(mi,i);}
        ma=max(ma,i);
        n = n/10;
    }
}
int main(){
    int i,t,a,b;
    ying[0]=0;
    for(i=1;i<=1e6;i++){
        get(i,a,b);
        if(!ying[i-a] || !ying[i-b]){ying[i]=1;}
        else{ying[i]=0;}
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d",&a);
        if(ying[a]){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}