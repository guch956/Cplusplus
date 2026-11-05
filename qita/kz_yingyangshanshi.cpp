#include<iostream>
#include<algorithm>
struct diet{
    int zhifang;
    int leibie;
};
bool bijiao(diet & d1,diet & d2){
    return d1.zhifang>d2.zhifang;
}
int main(){
    using namespace std;
    int n,m,k,*p,i,s=0;
    diet *d;
    cin>>n>>m>>k;
    p = new int[k+1];
    d = new diet[n];
    for(i=1;i<=k;i++){
        cin>>p[i];
    }
    for(i=0;i<n;i++){
        cin>>d[i].zhifang>>d[i].leibie;
    }
    sort(d,d+n,bijiao);
    i = 0;
    while(m>0){
        while(i<n && p[d[i].leibie]==0){
            i++;
        }
        if(i==n){
            break;
        }
        else{
            p[d[i].leibie]--;
            m--;
            s+=d[i].zhifang;
            i++;
        }
    }
    cout<<s;
    return 0;
}