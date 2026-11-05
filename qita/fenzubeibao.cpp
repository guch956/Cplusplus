#include<iostream>
#include<algorithm>
bool bijiao(int *p1,int *p2){
    return p1[2]<p2[2];
}
int main(){
    using namespace std;
    int m,n,t=0,**p,*q,i,j,k,s,c;
    cin>>m>>n>>t;
    p = new int*[n+1];
    q = new int[m+1];
    for(i=0;i<n;i++){
        p[i] = new int[3];
        cin>>p[i][0]>>p[i][1]>>p[i][2];
    }
    p[n] = new int[3];
    sort(p,p+n,bijiao);
    p[n][2] = p[n-1][2]+1;
    for(i=0;i<=m;i++){
      q[i] = 0;  
    }
    c = n;
    n = 0;
    for(j=p[0][2];j<=p[c-1][2];j++){
        for(i=m;i>=0;i--){
            for(k=n;p[k][2]==j;k++){
                if (p[k][0]<=i){
                    s = q[i-p[k][0]]+p[k][1];
                    q[i] = s>q[i]?s:q[i];
                }
            }
        }
        n = k;
    }
    cout<<q[m];
    return 0;
}