#include<iostream>
int main(){
    using namespace std;
    int n,i,j,k,s,**p,*q;
    cin>>n;
    p = new int*[2*n];
    q = new int[2*n];
    for(i=0;i<n;i++){
        cin>>q[i];
        q[i+n] = q[i];
    }
    for(i=0;i<2*n;i++){
        p[i] = new int[n];
        p[i][0] = 0;
    }
    for(j=1;j<n;j++){
        for(i=0;i<2*n-j-1;i++){
            p[i][j] = 2147483647;
            s = q[i];
            for(k=1;k<=j;k++){
                p[i][j] = min(p[i][j],p[i][k-1]+p[i+k][j-k]);
                s+=q[i+k];
            }
            p[i][j]+=s;
        }
    }
    s = 2147483647;
    for(i=0;i<n;i++){
        s = min(s,p[i][n-1]);
    }
    cout<<s<<endl;
    for(j=1;j<n;j++){
        for(i=0;i<2*n-j-1;i++){
            p[i][j] = 0;
            s = q[i];
            for(k=1;k<=j;k++){
                p[i][j] = max(p[i][j],p[i][k-1]+p[i+k][j-k]);
                s+=q[i+k];
            }
            p[i][j]+=s;
        }
    }
    s = 0;
    for(i=0;i<n;i++){
        s = max(s,p[i][n-1]);
    }
    cout<<s<<endl;
    return 0;
}