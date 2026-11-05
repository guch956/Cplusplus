#include<iostream>
int main(){
    using namespace std;
    int n,m,i,j,k,*p,*q,a;
    cin>>n>>m;
    p = new int[n];
    q = new int[m+1];
    a = 0;
    j = 0;
    for(i=0;i<n;i++){
        cin>>a;
        j += a;
        p[i] = j;
        cout<<p[i]<<endl;
    }
    for(i=0;i<m;i++){
        q[i] = i;
    }
    q[m] = n;
    k = 1;
    while(k){
        for(i=m-1;i>0;i--){
            a = 999999999;
            while(p[q[i]-1]-p[q[i-1]]<p[q[i+1]-1]-p[q[i]]){
                a = p[q[i+1]-1]-p[q[i]];
                q[i]++;
            }
            if(a<=p[q[i]-1]-p[q[i-1]]){
                q[i]--;
            }
            if(a!=999999999){
                k = 0;
            }
            for(j=0;j<=m;j++){
                cout<<q[j]<<' ';
            }
            cout<<endl;
        }
        k = 1-k;
    }
    for(i=0;i<=m;i++){
        cout<<q[i]<<' '<<q[i+1]-1<<endl;
    }
    return 0;
}