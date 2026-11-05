#include<iostream>
#include<cstdio>
using namespace std;
int sumB[10002];
int jieshu[503][10002];
int linshi[1003];
int P[10002],A[10002],B[10002];
int n;
void solve(int k){
    int i,a;
    for(i=0;i<=500;i++){
        if(P[k]<i){jieshu[i][k]=linshi[max(0,i-B[k])];}
        else{jieshu[i][k]=linshi[i+A[k]];}
    }
    for(i=1000;i>500;i--){
        linshi[i]=linshi[i-B[k]];
    }
    for(i=0;i<=500;i++){
        linshi[i]=jieshu[i][k];
    }
}
int main(){
    int q,i,l,r,mid,x;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d %d",&P[i],&A[i],&B[i]);
        sumB[i]=sumB[i-1]+B[i];
    }
    for(i=0;i<=500;i++){
        jieshu[i][n+1]=i;
    }
    for(i=0;i<=1000;i++){linshi[i]=i;}
    for(i=n;i>=1;i--){solve(i);}
    scanf("%d",&q);
    while(q--){
        scanf("%d",&x);
        l = 0;r = n+1;
        while(l<r){
            mid = (l+r)>>1;
            if(x<=sumB[mid]+500){r = mid;}
            else{l = mid+1;}
        }
        if(l==n+1){printf("%d\n",x-sumB[n]);}
        else{printf("%d\n",jieshu[x-sumB[l]][l+1]);}
    }
    return 0;
}