#include<iostream>
int main(){
    using namespace std;
    int T,n,k,*m,*p,*A,i,j,a;
    cin>>T;
    while(T>0){
        cin>>n>>k;
        m = new int[n];
        p = new int[n];
        A = new int[n];
        for(i=0;i<n;i++){
            cin>>m[i];
        }
        for(i=0;i<n;i++){
            cin>>p[i];
        }
        A[0] = p[0];
        for(i=1;i<n;i++){
            j = i;
            while(m[i]-m[j]<=k && j>=0){
                j--;
            }
            if (j==-1){
                a = p[i];
            }
            else{
                a = A[j]+p[i];
            }
            A[i] = a>A[i-1]?a:A[i-1];
        }
        cout<<A[n-1]<<endl;
        T--;
    }
    return 0;
}