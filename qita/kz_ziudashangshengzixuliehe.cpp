#include<iostream>
int main(){
    using namespace std;
    int n,*p,*q,i,j,a;
    cin>>n;
    p = new int[n];
    q = new int[n];
    for(i=0;i<n;i++){
        cin>>p[i];
        q[i] = 0;
    }
    for(i=0;i<n;i++){
        for(j=0;j<i;j++){
            if(p[j]<p[i]){
                if (q[i]<q[j]){
                    q[i] = q[j];
                }
            }
        }
        q[i] = q[i]+p[i];
    }
    a = q[0];
    for(i=1;i<n;i++){
        a = q[i]>a?q[i]:a;
    }
    cout<<a;
    return 0;
}