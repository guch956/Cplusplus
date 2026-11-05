#include<iostream>
int main(){
    using namespace std;
    int e,f,n,**p,*q,i,j;
    cin>>e>>f;
    e = f-e;
    cin>>n;
    p = new int*[n];
    for(i=0;i<n;i++){
        p[i] = new int[2];
        cin>>p[i][0]>>p[i][1];
    }
    q = new int[e+1];
    
}