#include<iostream>
#include<cstdio>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int N=1000003; 
ull P[N];
ull hasha[N],hashb[N];
char A[N],B[N];
ull gethash(int l,int r,ull * hash){
    return hash[r]-P[r-l+1]*hash[l-1];
}
bool check(int l1,int l2,int r){
    return gethash(l1,l1+r-1,hasha)==gethash(l2,l2+r-1,hashb);
}
int main(){
    int T,n,i;
    ull p=131;
    scanf("%d",&T);
    P[0]=1;
    for(i=1;i<N;i++){
        P[i]=P[i-1]*p;
    }
    while(T--){
        scanf("%s",A+1);
        scanf("%s",B+1);
        for(i=1;A[i];i++){
            hasha[i]=hasha[i-1]*p+A[i];
            hashb[i]=hashb[i-1]*p+B[i];
        }
        n = i-1;
        for(i=0;i<n;i++){
            if(check(i+1,1,n-i) && check(1,n+1-i,i))break;
        }
        if(i==n)printf("-1\n");
        else printf("%d\n",i);
    }
    return 0;
} 