#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=200003;
struct node{
    int b;
    ll w;
}B[N],C[N];
int A[N];
int p1[N],p2[N];
bool bijiao1(node b1,node b2){
    return b1.b<b2.b;
}
bool bijiao2(node b1,node b2){
    return b1.w<b2.w;
}
int main(){
    int n,i,m,l=0,r=0,mid,j,k;
    int n1,n2;
    ll ans=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
        r = max(r,A[i]);
    }
    for(i=1;i<=m;i++){
        scanf("%d %lld",&B[i].b,&B[i].w);
    }
    sort(B+1,B+m+1,bijiao1);
    sort(A+1,A+n+1);
    while(l<r){
        mid=(l+r)>>1;
        j = 1;
        k = 1;
        n1=0;n2=0;
        for(i=1;i<=n;i++){
            if(A[i]<=mid){
                while(j<=m && B[j].b<=A[i]){
                    p1[++n1]=B[j].b;
                    j++;
                }
                p1[++n1]=A[i];
            }
            else{
                while(A[k]<=mid && A[k]+mid<=A[i]){
                    p2[++n2]=A[k];
                    k++;
                }
                p2[++n2]=A[i]-mid;
            }
        }
        while(j<=m){
            p1[++n1]=B[j].b;
            j++;
        }
        while(A[k]<=mid){
            p2[++n2]=A[k];
            k++;
        }
        j = 1;
        for(i=1;i<=n2;i++){
            if(p2[i]>mid){break;}
            while(j<=n1 && p1[j]<p2[i]){j++;}
            if(j<=n1){j++;}
            else{break;}
        }
        if(i==n2+1){r = mid;}
        else{l = mid+1;}
    }
    n1 = 0;n2 = 0;mid=l;
    for(i=1;i<=n;i++){
        if(A[i]<=mid){
            while(j<=m && B[j].b<=A[i]){
                C[++n1]=B[j];
                j++;
            }
            C[++n1].b=A[i];
            C[n1].w=0;
        }
        else{
            while(A[k]<=mid && A[k]+mid<=A[i]){
                p2[++n2]=A[k];
                k++;
            }
            p2[++n2]=A[i]-mid;
        }
    }
    while(j<=m){
        C[++n1]=B[j];
        j++;
    }
    while(A[k]<=mid){
        p2[++n2]=A[k];
        k++;
    }
    sort(C+1,C+n1+1,bijiao2);
    
    printf("%d",l);
    return 0;
}

