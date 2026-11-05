#include<iostream>
int p[10001];
int A[100][100];
int main(){
    using namespace std;
    int t,n,m,i,j,k,s;
    cin>>t>>n>>m;
    for(j=0;j<t;j++){
        for(i=0;i<n;i++){
            cin>>A[j][i];
        }
    }
    for(k=1;k<t;k++){
        for(i=0;i<=m;i++){
            p[i]=i;
        }
        for(j=0;j<n;j++){
            for(i=A[k-1][j];i<=m;i++){
                p[i]=max(p[i],p[i-A[k-1][j]]+A[k][j]);
            }
        }
        s = 0;
        for(i=0;i<=m;i++){
            s = max(s,p[i]);
        }
        m = s;
    }
    cout<<m;
    return 0;
}