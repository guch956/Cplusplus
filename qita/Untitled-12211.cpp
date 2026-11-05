#include<iostream>
#include<cstdio>
int A[103];
int main(){
    int x,c,n,i,j=1,k;
    scanf("%d",&n);
    k = n-1;
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
    }
    while(j<=n && A[j]==0){j++;}
    while(k>=0 && A[k+1]==0){k--;}
    if(k<j){printf("0");}
    else{printf("%d",k-j+1);}
    return 0;
}