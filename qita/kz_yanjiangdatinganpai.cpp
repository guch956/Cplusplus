#include<iostream>
#include<algorithm>
struct qujian{
    int begin;
    int end;
};
bool bijiao(qujian & q1,qujian & q2){
    return q1.end<q2.end;
}
int main(){
    using namespace std;
    int n,i,k,*p,c;
    qujian *q;
    cin>>n;
    p = new int[n];
    q = new qujian[n];
    for(i=0;i<n;i++){
        cin>>q[i].begin>>q[i].end;
    }
    sort(q,q+n,bijiao);
    p[0] = q[0].end-q[0].begin;
    for(i=1;i<n;i++){
        k = i-1;
        while(q[k].end>q[i].begin && k>=0){
            k--;
        }
        if(k==-1){
            c = q[i].end-q[i].begin;
        }
        else{
            c = q[i].end-q[i].begin+p[k];
        }
        p[i] = c>p[i-1]?c:p[i-1];
    }
    cout<<p[n-1];
    return 0;
}