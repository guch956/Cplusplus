#include<iostream>
int p[101][51][51];
int A[51][51];
int main(){
    using namespace std;
    int n,m,i,j,k;
    cin>>m>>n;
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            cin>>A[j][i];
        }
    }
    for(k=2;k<=m+n;k++){
        for(j=1;j<=n;j++){
            if(1<=k-j && k-j<=m){
                p[k][j][j]=max(p[k][j][j],p[k-1][j-1][j-1]);
                p[k][j][j]=max(p[k][j][j],p[k-1][j-1][j]);
                p[k][j][j]=max(p[k][j][j],p[k-1][j][j]);
                p[k][j][j]+=A[j][k-j];
                for(i=j+1;i<=n;i++){
                    if(1<=k-i && k-i<=m){
                        p[k][j][i]=max(p[k][j][i],p[k-1][j-1][i-1]);
                        p[k][j][i]=max(p[k][j][i],p[k-1][j-1][i]);
                        p[k][j][i]=max(p[k][j][i],p[k-1][j][i-1]);
                        p[k][j][i]=max(p[k][j][i],p[k-1][j][i]);
                        p[k][j][i]+=A[j][k-j];
                        p[k][j][i]+=A[i][k-i];

                    }
                }
            }
        }
    }
    cout<<p[m+n][n][n];
    return 0;
}