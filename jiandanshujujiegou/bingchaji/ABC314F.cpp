#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
class inverse{
    private:
        int n;
        ll P;
        ll* ans;
        ll* ni;
    public:
        inverse(int ,ll);
        void add(int ,int ,int ,int );
        void show(int );
};
inverse::inverse(int n0,ll P0=998244353){
    n = n0;P = P0;
    ans = new ll[n+1];
    ni = new ll[n+1];
    ni[1] = 1;ans[1] = 0;
    ll i,k,r;
    for(i=2;i<=n;i++){
        k = P/i;
        r = P%i;
        ni[i] = (P-k)*ni[r]%P;
        ans[i] = 0;
    }
}
void inverse::add(int a1,int a2,int s1,int s2){
    ans[a2]+=ans[a1];
    ans[a1] = (ans[a1]+s1*ni[s1+s2]%P)%P;
    ans[a2] = (ans[a2]+s2*ni[s1+s2]%P)%P;
}
void inverse::show(int m){
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
class Rollback_DSU{
    private:
        int n;
        int* fa;
        int* son;
        int* f;
        int* siz;
        int top;
        inverse inv;
    public:
        Rollback_DSU(int );
        int find(int );
        void hebing(int ,int );
        void rollback();
        void show(int );
        ~Rollback_DSU();
};
Rollback_DSU::Rollback_DSU(int n0):inv(n0){
    n = n0;
    top = 0;
    fa = new int [n+1];
    son = new int [n+1];
    f = new int [n+1];
    siz = new int [n+1];
    for(int i=1;i<=n;i++){
        f[i] = i;
        siz[i] = 1;
    }
}
int Rollback_DSU::find(int x){
    while(f[x]!=x){x = f[x];}
    return x;
}
void Rollback_DSU::hebing(int x,int y){
    int a = find(x),b = find(y);
    if(a!=b){
        if(siz[a]<siz[b]){swap(a,b);}
        f[b] = a;
        siz[a]+=siz[b];
        fa[++top] = a;
        son[top] = b;
    }
}
void Rollback_DSU::rollback(){
    siz[fa[top]]-=siz[son[top]];
    f[son[top]] = son[top];
    inv.add(fa[top],son[top],siz[fa[top]],siz[son[top]]);
    top--;
}
void Rollback_DSU::show(int m){
    inv.show(m);
}
Rollback_DSU::~Rollback_DSU(){
    delete []f;
    delete []fa;
    delete []son;
    delete []siz;
}
int main(){
    int n,i,a,b;
    scanf("%d",&n);
    Rollback_DSU r = Rollback_DSU(n);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        r.hebing(a,b);
    }
    for(i=1;i<n;i++){
        r.rollback();
    }
    r.show(n);
    return 0;
}