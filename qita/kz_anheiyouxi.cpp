#include<iostream>
int main(){
    using namespace std;
    int n,m1,m2,i,j,j1,k,k1,a,b,l,c1,c2,head=0,tail=0,**p,**q,*r1,*r2,s=0;
    cin>>n>>m1>>m2;
    q = new int*[m1+1];
    p = new int*[n];
    for(i=0;i<n;i++){
        p[i] = new int[4];
        cin>>p[i][0]>>p[i][1]>>p[i][2]>>p[i][3];
        if(p[i][2]==0){
            p[i][2] = m1/p[i][0]+1;
            
        }
        s = s>p[i][2]?s:p[i][2];
    }
    s +=4;
    r1 = new int[s];r2 = new int[s];
    for(i=0;i<=m1;i++){
        q[i] = new int[m2+1];
        for(j=0;j<=m2;j++){
            q[i][j] = 0;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<p[i][0];j++){
            for(j1=0;j1<p[i][1];j1++){
                for(k=0;k*p[i][0]+j<=m1;k++){
                    c1 = k*p[i][0]+j;
                    head=0;tail=0;
                    for(k1=0;k1*p[i][1]+j1<=m1;k1++){
                        c2 = k1*p[i][1]+j1;
                        a = q[c1][c2]-k1*p[i][3];
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
                        r1[tail] = k1;
                        r2[tail] = a;
                        tail = tail==s-1?0:tail+1;
                        while(r1[head]<k1-p[i][2] || r1[head]<k1-k){
                            head = head==s-1?0:head+1;
                        }
                        l = r2[head]+p[i][3]*k1;
                        q[c1][c2] = q[c1][c2]>l?q[c1][c2]:l;
                    }
                }
            }
        }
    }
    cout<<q[m1][m2];
    return 0;
}