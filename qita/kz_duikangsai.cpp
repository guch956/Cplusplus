#include<iostream>
int main(){
    using namespace std;
    int n,*p,*q,i,j,s=0;
    cin>>n;
    p = new int[n];
    for(i=0;i<n;i++){
        cin>>p[i];
        s +=p[i];
    }
    if (s%2==0){
        s = s/2;
        q = new int[s+1];
        q[0] = 1;
        for(i=1;i<=s;i++){
            q[i] = 0;
        }
        for(i=0;i<n;i++){
            for(j=s;j>=p[i];j--){
                q[j]+=q[j-p[i]];
            }
        }
        cout<<q[s]/2;
    }
    else{
        cout<<0;
    }
    return 0;
}