#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100003;
struct node{
    int w;
    int e[4];
    int v;
}g[N];
bool bijiao(node & n1,node & n2){
    return n1.w<n2.w;
}
int edge[N<<1][2];
int s[N<<2];
int find(int x){
    if(s[x]!=x){
        s[x] = find(s[x]);
    }
    return s[x];
}
void hebing(int x,int y){
    int a = find(x),b=find(y);
    s[b]=a;
}
void adde(int v,int e){
    if(edge[e][0]){
        edge[e][1]=v;
    }
    else{
        edge[e][0]=v;
    }
}
int main(){
    int n,i,j,a,b;
    scanf("%d",&n);
    for(i=1;i<=(n<<2);i++){
        s[i]=i;
    }
    for(i=1;i<=n;i++){
        scanf("%d %d %d %d %d",&g[i].w,&g[i].e[0],&g[i].e[1],&g[i].e[2],&g[i].e[3]);
        hebing(i,i+n);
        hebing(i+2*n,i+3*n);
        g[i].v=i;
        for(j=0;j<=3;j++){
            adde(i+j*n,g[i].e[j]);
        }
    }
    for(i=1;i<=(n<<1);i++){
        hebing(edge[i][0],edge[i][1]);
    }
    sort(g+1,g+n+1,bijiao);
    j = 0;
    for(i=1;i<=n;i++){
        a = find(g[i].v);b = find(g[i].v+2*n);
        if(a!=b){
            j+=g[i].w;
            hebing(a,b);
        }
    }
    printf("%d",j);
    return 0;
}
