#include<iostream>
#include<algorithm>
int c,n;
bool check(int A[],int l){
    int i=0,j=1,s=1;
    while(1){
        j=i+1;
        while(A[j]-A[i]<l && j<=n-1){
            j++;
        }
        if(j==n){
            break;
        }
        else{
            i = j;
            s++;
        }
    }
    if(s>=c){
        return 1;
    }
    else{
        return 0;
    }
}
int erfen(int A[],int p,int q){
    if(p==q){
        return p;
    }
    int m=(p+q+1)/2;
    if(check(A,m)){
        return erfen(A,m,q);
    }
    else{
        return erfen(A,p,m-1);
    }
}
int main(){
    using namespace std;
    int *p,i;
    cin>>n>>c;
    p = new int[n];
    for(i=0;i<n;i++){
        cin>>p[i];

    }
    sort(p,p+n);
    cout<<erfen(p,1,p[n-1]);
    return 0;
}