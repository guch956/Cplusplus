#include<iostream>
void qiujie(int n,int *p){
    int a[2],c=1,s,i;
    a[0] = p[0];
    a[1] = 0;
    for(i=1;i<n;i++){
        s = a[c]+p[i];
        a[c] = s>a[1-c]?s:a[1-c];
        c = 1-c;
    }
    std::cout<<a[1-c]<<std::endl;;
}
int main(){
    using namespace std;
    int t,n,*p,i;
    cin>>t;
    while(t-->0){
        cin>>n;
        p = new int[n];
        for(i=0;i<n;i++){
            cin>>p[i];
        }
        qiujie(n,p);
        delete p;
    }
    return 0;
}