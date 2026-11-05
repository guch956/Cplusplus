#include<iostream>
#include<cstdio>
using namespace std;
const int N=200003;
int fa[N<<1];
int du[N];
int find_set(int x){
    if(fa[x]!=x){
        fa[x]=find_set(fa[x]);
    }
    return fa[x];
}
void hebing(int x,int y){
    int a=find_set(x),b=find_set(y);
    if(a!=b){
        fa[a]=b;
    }
}
int main(){
    int n,m,i,a,b,q,x;
    scanf("%d %d %d",&n,&m,&q);
    for(i=1;i<=2*n;i++){
        fa[i]=i;
    }
    for(i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        hebing(a,b+n);
        hebing(b,a+n);
        du[a]++;
        du[b]++;
    }
    while(q--){
        scanf("%d %d %d",&a,&b,&x);
        if(a==b && du[a]==0){
            if(x==0){
                printf("tribool\n");
            }
            else{
                printf("expand\n");
            }
            continue;
        }
        if(x&1){
            if(find_set(a)==find_set(b+n)){
                printf("tribool\n");
            }
            else{
                printf("expand\n");
            }
        }
        else{
            if(find_set(a)==find_set(b)){
                printf("tribool\n");
            }
            else{
                printf("expand\n");
            }
        }
    }
    return 0;
}