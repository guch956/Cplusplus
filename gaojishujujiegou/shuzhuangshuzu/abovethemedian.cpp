#include<iostream>
#include<algorithm>
#define ll long long
const int N=100002;
inline int lowbit(int x){
    return x&(-x);
}
int tree[N];int n;
void update(int x,int d){
    while(x<=n){
        tree[x]+=d;
        x+=lowbit(x);
    }
}
int chaxun(int x){
    int ans=0;
    while(x!=0){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}
struct dian{
    int w;
    int id;
};
bool bijiao(dian d1,dian d2){
    return d1.w<d2.w;
}
int A[N],num[N];
dian p[N];
int main(){
    using namespace std;
    int d,x,i;
    ll ans=0;
    int b;
    cin>>d>>x;
    for(i=1;i<=d;i++){
        cin>>A[i];
        num[i]=num[i-1];
        if(A[i]>=x){
            num[i]++;
        }
    }
    for(i=1;i<=d;i++){
        num[i]= 2*num[i]-i;
        if(num[i]>=0){
            ans++;
        }
        p[i].w=num[i];
        p[i].id=i;
    }
    sort(p+1,p+d+1,bijiao);
    b = -2*N-2;
    for(i=1;i<=d;i++){
        if(p[i].w!=b){
            n++;
        }
        num[p[i].id]=n;
        b = p[i].w;
    }
    for(i=1;i<=d;i++){
        ans+=chaxun(num[i]);
        update(num[i],1);
    }
    cout<<ans;
    return 0;
}