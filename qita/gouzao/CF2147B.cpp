#include<iostream>
#include<cstdio>
using namespace std;
const int N=200003;
int A[N<<1];
int main(){
    int T,n,i;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        if(n==1){
            printf("1 1\n");
        }
        else{
            A[1]=A[n+1]=n;
            A[2]=A[2*n]=n-1;
            for(i=1;i<n-1;i++){
                A[n+1-i]=A[n+1+i]=i;
            }
            for(i=1;i<=2*n;i++){
                printf("%d ",A[i]);
            }
            printf("\n");
        }
    }
    return 0;
}