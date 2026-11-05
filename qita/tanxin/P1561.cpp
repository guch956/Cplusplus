#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
typedef long long ll;
const int N=50003;
class cow{
    public:
    ll fir,sec;
    cow(ll f,ll s){
        fir = f;sec = s;
    }
    cow(){
        fir = 0;sec = 0;
    }
    bool operator<(const cow & c1)const{
        return min(fir,sec)>min(c1.fir,c1.sec);
    }
};
cow pailie[N];
int main(){
    int n,i,j;
    ll f,s,ans=0;
    cow c(0,0);
    priority_queue<cow> q;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lld %lld",&f,&s);
        q.push(cow(f,s));
    }
    i = 1;j = n;
    while(!q.empty()){
        c = q.top();
        q.pop();
        if(c.fir<=c.sec){
            pailie[i] = c;i++;
        }
        else{
            pailie[j] = c;j--;
        }
    }
    f = 0;
    for(i=1;i<=n;i++){
        f = f-pailie[i].fir;
        ans+=max((ll)0,-f);
        ans+=pailie[i].sec;
        f = max((ll)0,f)+pailie[i].sec;
    }
    cout<<ans<<endl;
    return 0;
}