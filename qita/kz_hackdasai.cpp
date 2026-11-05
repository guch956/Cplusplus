#include<iostream>
int main(){
    using namespace std;
    int n,C,L,R,*p,i,j,s,d;
    cin>>n>>C>>L>>R;
    if(C>R){
        cout<<0;
    }
    else{
    p = new int[R+1];
    for(i=0;i<=R;i++){
        p[i] = 0;
    }
    p[C] = 1;
    for(i=1;i<=n;i++){
        for(j=R-i;j>=C;j--){
            if(j+i<=R){
                p[j+i]+=p[j];
                p[j+i] = p[j+i]%998244353;
            }
        }
    }
    s = 0;
    L = L>C?L:C;
    for(i=L;i<=R;i++){
        s+=p[i];
        s = s%998244353;
    }
    cout<<s;
    }
    return 0;
}