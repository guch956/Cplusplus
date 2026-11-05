#include<iostream>
int main(){
    using namespace std;
    int n,t,*p,*q,i,j=0;
    cin>>n>>t;
    p = new int[n];
    q = new int[t+1];
    for(i=0;i<n;i++){
        cin>>p[i];
    }
    for(i=0;i<=t;i++){
        q[i] = 0;
    }
    q[0] = 1;
    for(i=0;i<n;i++){
        for(j=t;j>=0;j--){
            if (j>=p[i]){
                q[j]+=q[j-p[i]];
            }
        }
    }
    cout<<q[t];
    return 0;
}