#include<iostream>
int main(){
    using namespace std;
    int n,m,**p,*q,s,i,j;
    s = 0;
    cin>>m>>n;
    p = new int*[n];
    for(i=0;i<n;i++){
        p[i] = new int[2];
        cin>>p[i][0]>>p[i][1];
    }
    q = new int[m+1];
    for(i=0;i<=m;i++){
        q[i] = 0;
    }
    for(i=0;i<n;i++){
        for(j=m;j>=0;j--){
            if (j>=p[i][0]){
                s = q[j-p[i][0]]+p[i][1];
                q[j] = s>q[j]?s:q[j];
            }
        }
    }
    cout<<q[m];
    return 0;
}