#include<iostream>
#include<algorithm>
int main(){
    using namespace std;
    int w,n,*p,i,k,j,t=0,s;
    cin>>w;
    cin>>n;
    p = new int[n+1];
    for(i=0;i<n;i++){
        cin>>p[i];
    }
    p[n] = w+1;
    sort(p,p+n);
    i=0;j=n;
    while(i<j){
        s = w-p[i];
        k = j;
        while(p[k-1]>s && k>i+1){
            k--;
        }
        t+=j-k;
        j = k;
        j--;
        i++;
        t++;
    }
    cout<<t;
    return 0;
}