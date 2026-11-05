#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100003;
int n,k;
int tree[N<<1];
int ans[N];
struct node{
    int a;
    int b;
    int c;
    int id;
}p[N];
bool bijiao1(node n1,node n2){
    return n1.a<n2.a;
}
bool bijiao2(node n1,node n2){
    return n1.b<n2.b;
}
void solve(int l,int r){
    if(l==r){return ;}
    int mid=(l+r)>>1,i;
    solve(l,mid);
    solve(mid+1,r);
    sort(p+l,p+r+1,bijiao2);
    
}
