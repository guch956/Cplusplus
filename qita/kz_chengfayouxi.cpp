#include<iostream>
int main(){
    using namespace std;
    int n,i,j,a,min,k,*p,**q;
    cin>>n;
    p = new int[n];
    q = new int*[n];
    for(i=0;i<n;i++){
        cin>>p[i];
        q[i] = new int[n-i];
        for(j=0;j<n-i;j++){
            q[i][j] = 0;
        }
    }
    for(i=2;i<=n-1;i++){
        for(j=0;j<n-i;j++){
            min = p[j]*p[j+1]*p[j+i]+q[j+1][i-1];
            for(k=2;k<i;k++){
                a = q[j][k]+p[j]*p[j+k]*p[j+i]+q[j+k][i-k];
                min = a<min?a:min;
            }
            q[j][i] = min;
        }
    }
    cout<<q[0][n-1];
    return 0;
}