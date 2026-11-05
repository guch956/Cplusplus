#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000003;
int A[N];
int n;
void dui(int m){
    int j=m>>1;
    if(!j){return;}
    if(A[j]>A[m]){
        swap(A[j],A[m]);
        dui(j);
    }
}
void insert(int x){
    A[++n]=x;
    dui(n);
}
void pop(int m){
    int l=m<<1,r=m<<1|1,t=m;
    if(l<=n && A[l]<A[t]){t=l;}
    if(r<=n && A[r]<A[t]){t=r;}
    if(t!=m){
        swap(A[m],A[t]);
        pop(t);
    }
}
int main(){
    int q,opt,x;
    cin>>q;
    while(q--){
        scanf("%d",&opt);
        if(opt==1){
            scanf("%d",&x);
            insert(x);
        }
        else if(opt==2){
            printf("%d\n",A[1]);
        }
        else{
            swap(A[1],A[n]);
            n--;
            pop(1);
        }
    }
    return 0;
}