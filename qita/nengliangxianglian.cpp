#include<iostream>
int main(){
    using namespace std;
    int n,i,k,j,s,**p,*q;
    cin>>n;
    p = new int*[2*n];
    q = new int[2*n];
    for(i=0;i<n;i++){
        cin>>q[i];
        q[i+n] = q[i];
    }
    for(i=0;i<2*n;i++){
        p[i] = new int[n];
    }
    for(i=0;i<2*n;i++){
        p[i][0] = 0;
    }
    for(j=1;j<n;j++){
        for(i=0;i<2*n-j-1;i++){
            p[i][j] = 0;
            for(k=1;k<=j;k++){
                p[i][j] = max(p[i][j],p[i][k-1]+p[i+k][j-k]+q[i]*q[i+j+1]*q[i+k]);
            }
        }
    }
    s = 0;
    for(i=0;i<n;i++){
        s = max(s,p[i][n-1]);
    }
    cout<<s;
    return 0;
}