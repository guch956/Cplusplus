#include<iostream>
#include<algorithm>
const int N=100002;
inline int lowbit(int x){
    return x&(-x);
}
int tree[N];
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
int main(){
    using namespace std;
    int i,d,b=-1;
    int c=0,e=0,ans=0;
    cin>>d;
    for(i=1;i<=d;i++){
        cin>>p[i].w;
        p[i].id=i;
    }
    sort(p+1,p+d+1,bijiao);
    for(i=1;i<=d;i++){
        n++;
        q[p[i].id]=n;
    }
    for(i=1;i<=d;i++){
        c=chaxun(q[i]-1);
        e = q[i]-1-c;
        if(c<e){
            if(e>2*c){
                ans++;
            }
        }
        else{
            if(c>2*e){
                ans++;
            }
        }
        update(q[i],1);
    }
    cout<<ans;
    return 0;
}