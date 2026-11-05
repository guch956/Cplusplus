#include<iostream>
#include<cstdio>
using namespace std;
int A[53][53];
int main(){
    int n,T,i,j,ok;
    char c;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        ok=1;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                c = getchar();
                while(c!='0' && c!='1'){c = getchar();}
                A[i][j]=c-'0';
            }
        }
        for(i=1;i<n;i++){
            for(j=1;j<n;j++){
                if(A[i][j] && (!A[i+1][j]) && (!A[i][j+1])){ok=0;}
            }
        }
        if(ok){printf("YES\n");}
        else{printf("NO\n");}
    }
    return 0;
}