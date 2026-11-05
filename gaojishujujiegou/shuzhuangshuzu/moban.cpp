#include<iostream>
const int N=500003;
inline int lowbit(int x){
    return x&(-x);
}
int tree[N];
int n;
void update(int x,int d){
    while(x<=n){
        tree[x]+=d;
        x += lowbit(x);
    }
}
int chaxun(int x){
    int ans=0;
    while(x!=0){
        ans+=tree[x];
        x -= lowbit(x);
    }
    return ans;
}
int main(){
    using namespace std;
    int m,i,a,k,b;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>a;
        update(i,a);
    }
    for(i=1;i<=m;i++){
        cin>>a>>b>>k;
        if(a==1){
            update(b,k);
        }
        else{
            cout<<chaxun(k)-chaxun(b-1)<<endl;
        }
    }
    return 0;
}