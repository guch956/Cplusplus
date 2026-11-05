#include<iostream>
int p[11][11][11][11];
int B[11][11];
int main(){
    using namespace std;
    int n,x=1,y,z,k,i,j,i2,j2;
    cin>>n;
    while(x){
        cin>>x>>y>>z;
        B[x][y]=z;
    }
    p[1][1][1][1] = B[1][1];
    for(k=3;k<=n+1;k++){
        for(i=1;i<=k-1;i++){
            for(j=1;j<=k-1;j++){
                i2 = k-i;j2 = k-j;
                p[i][i2][j][j2]=max(p[i][i2][j][j2],p[i-1][i2][j-1][j2]);
                p[i][i2][j][j2]=max(p[i][i2][j][j2],p[i-1][i2][j][j2-1]);
                p[i][i2][j][j2]=max(p[i][i2][j][j2],p[i][i2-1][j-1][j2]);
                p[i][i2][j][j2]=max(p[i][i2][j][j2],p[i][i2-1][j][j2-1]);
                if(i==j){
                    p[i][i2][j][j2]+=B[i][i2];
                }
                else{
                    p[i][i2][j][j2]+=B[i][i2];
                    p[i][i2][j][j2]+=B[j][j2];
                }
            }
        }
    }
    for(k=n+2;k<=2*n;k++){
        for(i=k-n;i<=n;i++){
            for(j=n-k;j<=n;j++){
                i2 = k-i;j2 = k-j;
                p[i][i2][j][j2]=max(p[i][i2][j][j2],p[i-1][i2][j-1][j2]);
                p[i][i2][j][j2]=max(p[i][i2][j][j2],p[i-1][i2][j][j2-1]);
                p[i][i2][j][j2]=max(p[i][i2][j][j2],p[i][i2-1][j-1][j2]);
                p[i][i2][j][j2]=max(p[i][i2][j][j2],p[i][i2-1][j][j2-1]);
                if(i==j){
                    p[i][i2][j][j2]+=B[i][i2];
                }
                else{
                    p[i][i2][j][j2]+=B[i][i2];
                    p[i][i2][j][j2]+=B[j][j2];
                }
            }
        }
    }
    cout<<p[n][n][n][n];
    return 0;
}