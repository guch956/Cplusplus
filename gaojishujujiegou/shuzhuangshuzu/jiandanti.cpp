#include<iostream>
#include<cstdio>
inline int lowbit(int x){
    return x&(-x);
}
const int N=100003;
int tree[N];
int n;
void update(int x){
    while(x<=n){
        tree[x]= (tree[x]+1)&1;
        x +=lowbit(x);
    }
}
int chaxun(int x){
    int ans=0;
    while(x!=0){
        ans+=tree[x];
        x -=lowbit(x);
    }
    ans = ans&1;
    return ans;
}
int main(){
    using namespace std;
    int m,i,a,b,c;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d",&a);
        if(a==1){
            scanf("%d %d",&b,&c);
            update(b);
            update(c+1);
        }
        else{
            scanf("%d",&b);
            printf("%d\n",chaxun(b));
        }
    }
    return 0;
}