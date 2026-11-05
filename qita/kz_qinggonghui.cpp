#include<iostream>
int main(){
    using namespace std;
    int n,m,i,j,k,a,b,l,c,d,head=0,tail=0,**p,*q,*r1,*r2,s=0;
    cin>>n>>m;
    q = new int[m+1];
    p = new int*[n];
    for(i=0;i<n;i++){
        p[i] = new int[3];
        cin>>p[i][0]>>p[i][1]>>p[i][2];
        s = s>p[i][2]?s:p[i][2];
    }
    s +=4;
    r1 = new int[s];r2 = new int[s];
    for(i=0;i<=m;i++){
        q[i] = 0;
    }
    for(i=0;i<n;i++){
        for(j=0;j<p[i][0];j++){
            head=0;tail=0;
            for(k=0;k*p[i][0]+j<=m;k++){
                c = k*p[i][0]+j;
                a = q[c]-k*p[i][1];
                while(head!=tail){
                    if(tail==0){
                        b = s-1;
                    }
                    else{
                        b = tail-1;
                    }
                    if(a>=r2[b]){
                        tail = b;
                    }
                    else{
                        break;
                    }
                }
                r1[tail] = k;
                r2[tail] = a;
                tail = tail==s-1?0:tail+1;
                if(r1[head]<k-p[i][2]){
                    head = head==s-1?0:head+1;
                }
                l = r2[head]+p[i][1]*k;
                q[c] = q[c]>l?q[c]:l;
            }
        }
    }
    cout<<q[m];
    return 0;
}