#include<iostream>
#include<cstdio>
using namespace std;
const int N=100002;
int n;
int tree[2][N];int p[N<<1];
inline int lowbit(int x){return x&(-x);}
int jisuan(int x,int k){
    int ans=0;
    while(x!=0){
        ans=ans^tree[k][x];
        x = x-lowbit(x);
    }
    return ans;
}
void update(int x,int c,int k){
    while(2*x<=n+k){
        tree[k][x]=tree[k][x]^c;
        x = x+lowbit(x);
    }
}
int main(){
    int m,i,a,b,k;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        p[i]=a;
    }
    for(i=1;2*i-1<=n;i++){
        update(i,p[2*i-1],1);
    }
    for(i=1;2*i<=n;i++){
        update(i,p[2*i],0);
    }
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&k,&a,&b);
        if(k==1){
            if(a%2==0){
                update(a/2,p[a]^b,0);
                p[a]=b;
            }
            else{
                update((a+1)/2,p[a]^b,1);
                p[a]=b;
            }
        }
        else{
            if((b-a)%2==1){
                printf("0\n");
            }
            else{
                if(a%2==0){
                    printf("%d\n",jisuan((a/2)-1,0)^jisuan(b/2,0));
                }
                else{
                    printf("%d\n",jisuan((a-1)/2,1)^jisuan((b+1)/2,1));
                }
            }
        }
    }
    return 0;
}