#include<iostream>
const int MOD = 1000007;
int main(){
    using namespace std;
    int m,n,*p,*q,i,j,k,s;
    cin>>n>>m;
    p = new int[n];
    for(i=0;i<n;i++){
        cin>>p[i];
    }
    q = new int[m+1];
    for(i=0;i<=p[0];i++){
        q[i] = 1;
    }
    for(i=p[0]+1;i<=m;i++){
        q[i] = 0;
    }
    for(i=1;i<n;i++){
        for(j=m;j>=0;j--){
            s = 0;
            for(k=0;k<=p[i];k++){
                if(j>=k){
                    s+=q[j-k];
                }
            }
            q[j] = s%MOD;
        }
    }
    cout<<q[m];
    return 0;
}