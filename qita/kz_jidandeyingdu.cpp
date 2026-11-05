#include<iostream>
int main(){
    using namespace std;
    int n,m,**p,i,j,k,l,s;
    while(cin>>n>>m && n!=EOF)
    {
    p = new int*[n+1];
    for(i=0;i<=n;i++){
        p[i] = new int[m+1];
        p[i][1] = i; 
    }
    for(i=1;i<=m-1;i++){
        s = 0;
        k = 1;
        l = 1;
        while(s+l<=n){
            for(j=s+1;j<=s+l-1;j++){
                p[j][i+1] = k;
            }
            p[s+l][i+1] = k+1;
            s = s+l;
            k++;
            l++;
            while(l<=n && p[l][i]==k){
                l++;
            }
            l--;
        }
        for(j=s+1;j<=n;j++){
            p[j][i+1] = k;
        }
    }
    cout<<p[n][m];
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cout<<p[i][j]<<' ';
        }
        cout<<endl;
    }
    for(i=0;i<=n;i++){
        delete p[i];
    }
    delete p;}
    return 0;
}