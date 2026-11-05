#include<iostream>
#include<algorithm>
const int N=500002;
inline int lowbit(int x){
    return x&(-x);
}
long long tree[N];
struct dian{
    int w;
    int id;
};
bool bijiao(dian d1,dian d2){
    return d1.w>d2.w;
}
dian p[N];
int q[N];
int n;
void update(int x,long long d){
    while(x<=n){
        tree[x]+=d;
        x+=lowbit(x);
    }
}
long long  chaxun(int x){
    long long ans=0;
    while(x!=0){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}
int main(){
    using namespace std;
    int i,d,b=-1;
    long long c=0;
    cin>>d;
    for(i=1;i<=d;i++){
        cin>>p[i].w;
        p[i].id=i;
    }
    sort(p+1,p+d+1,bijiao);
    for(i=1;i<=d;i++){
        if(p[i].w!=b){
            n++;
        }
        q[p[i].id]=n;
        b = p[i].w;
    }
    for(i=1;i<=d;i++){
        c+=chaxun(q[i]-1);
        update(q[i],1);
    }
    cout<<c;
    return 0;
}