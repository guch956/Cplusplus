#include<iostream>
#include<string>
int main(){
    using namespace std;
    string s;
    int n,i,j,**p,d,c;
    cin>>n;
    cin>>s;
    p = new int*[n];
    for(i=0;i<n;i++){
        p[i] = new int[2];
    }
    for(i=0;i<n-1;i++){
        p[i][0] = 0;
        p[i][1] = 1-(s[i]==s[i+1]);
    }
    p[n-1][0] = 0;
    d = 0;
    for(j=2;j<n;j++){
        for(i=0;i<=n-1-j;i++){
            if(s[i]==s[i+j]){
                p[i][d] = p[i+1][d];
            }
            else{
                c = 1-d;
                p[i][d] = (p[i][c]>p[i+1][c]?p[i+1][c]:p[i][c])+1;
            }
            
        }
        d = 1-d;
    }
    cout<<p[0][1-d];
    return 0;
}