#include<iostream>
int main(){
    using namespace std;
    int m,n,*p,*q,i,j,a,s;
    cin>>m>>n;
    p = new int[n];
    q = new int[n];
    for(i=0;i<n;i++){
        cin>>p[i];
    }
    for(j=1;j<m;j++){
        for(i=0;i<n;i++){
        cin>>a;
        if(a>=p[i]){
            p[i] = a;
        }
    }
    }
    a = 0;
    for(i=0;i<n;i++){
        a+=p[i];
        q[i] = a;
    }
    s = q[0];
    a = 0;
    for(i=1;i<n;i++){
        if(q[i-1]<a){
            a = q[i-1];
        }
        j = q[i]-a;
        s = j>s?j:s;
    }
    cout<<s;
    return 0;
}