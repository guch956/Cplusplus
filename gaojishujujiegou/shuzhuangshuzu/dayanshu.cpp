#include<iostream>
#define ll long long
const int N=5000;
ll tree[N][N];
inline int lowbit(int x){
    return x&(-x);
}
int n,m;
void update(int x,int y,ll d){
    int a;
    while(x<=n){
        a = y;
        while(a<=m){
            tree[x][a]+=d;
            a+=lowbit(a);
        }
        x+=lowbit(x);
    }
}
ll chaxun(int x,int y){
    int a;
    ll ans=0;
    while(x!=0){
        a = y;
        while(a!=0){
            ans+=tree[x][a];
            a-=lowbit(a);
        }
        x-=lowbit(x);
    }
    return ans;
}
int main(){
    using namespace std;
    int k,a,b,c,d;
    ll e;
    cin>>n;
    m = n;
    while(1){
        cin>>k;
        if(k==1){
            cin>>a>>b>>e;
            a++;b++;
            update(a,b,e);
        }
        else if(k==2){
            cin>>a>>b>>c>>d;
            a++;b++;c++;d++;
            e = chaxun(c,d)+chaxun(a-1,b-1)-chaxun(a-1,d)-chaxun(c,b-1);
            cout<<e<<endl;
        }
        else{
            break;
        }
    }
    return 0;
}
