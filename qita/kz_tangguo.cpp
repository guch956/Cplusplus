#include<iostream>
int main(){
    using namespace std;
    int n,k,i,j,*p,**q,s,a = 0,c;
    cin>>n>>k;
    p = new int[n];
    q = new int*[k];
    for(i=0;i<n;i++){
        cin>>p[i];
    }
    for(i=0;i<k;i++){
        q[i] = new int[2];
        q[i][0] = 0;
        q[i][1] = 0;
    }
    q[p[0]%k][0]=p[0];
    for(i=1;i<n;i++){
        c = p[i]%k;
        s = q[0][a]+p[i];
        q[c][1-a] = q[c][a]>s?q[c][a]:s;
        for(j=1;j<k;j++){
            s = 0;
            c = (j+p[i])%k;
            if(q[j][a]!=0){
                s = q[j][a]+p[i]; 
            }
            q[c][1-a] = q[c][a]>s?q[c][a]:s;
        }
        a = 1-a;
    }
    cout<<q[0][a];
    return 0;
}