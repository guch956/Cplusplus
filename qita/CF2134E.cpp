#include<iostream>
#include<cstdio>
using namespace std;
const int N=1003;
int num[N];
int power[N];
void get(int n,int nu,int k){
    int a;
    printf("throw %d\n",n);
    fflush(stdout);
    scanf("%d",&a);
    if(a==nu){power[k]=2;}
    else{power[k]=1;}
}
void update(int n,int p){
    num[n]=num[n+p]+1;
}
void solve(int n){
    int i;
    if(n==0){return ;}
    else if(n==1){
        if(num[2]==num[3]){
            printf("swap 1\n");
            fflush(stdout);
            get(2,num[4]+1,1);
        }
        else{
            get(1,num[3]+1,1);
        }
        return ;
    }
    else{
        if(num[n+1]==num[n+2]){
            get(n-1,num[n+1]+1,n-1);
            printf("swap %d\n",n-1);
            fflush(stdout);
            get(n-1,num[n+1]+1,n);
        }
        else{
            get(n,num[n+2]+1,n);
            printf("swap %d\n",n-1);
            fflush(stdout);
            get(n,num[n+2]+1,n-1);
        }
        update(n,power[n-1]);
        update(n-1,power[n]);
        solve(n-2);
    }
}
int main(){
    int T,n,i;
    scanf("%d",&T);
    while (T--){
        scanf("%d",&n);
        solve(n);
        printf("!");
        for(i=1;i<=n;i++){
            printf(" %d",power[i]);
            num[i]=0;
        }
        printf("\n");
        fflush(stdout);
    }
    return 0;
}