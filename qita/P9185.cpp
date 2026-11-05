#include<iostream>
#include<cstdio>
using namespace std;
int A[200003];
int ans[200003];
int main(){
    int n,k,t,i,a,add,b;
    scanf("%d %d %d",&n,&k,&t);
    for(i=1;i<=k;i++){
        scanf("%d",&A[i]);
    }
    A[k+1] = n;
    k = 0;
    for(i=0;i<n;i++){
        if(i>=A[k+1]){
            k++;
            a = A[k+1]-A[k];
        }
        add=0;
        if(i-A[k]<t){
            b = (t-1-i+A[k])/a+1;
            add = b*a;
        }
        ans[(i+add)%n] = i;
    }
    for(i=0;i<n;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}