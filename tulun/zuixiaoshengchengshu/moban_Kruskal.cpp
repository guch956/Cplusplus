#include<iostream>
#include<algorithm>
const int N=5002;const int M=200002;
int s[N];
int find_set(int x){
    if(s[x]!=x) s[x]=find_set(s[x]);
    return s[x];
}
bool hebing(int x,int y){
    int a=find_set(x),b=find_set(y);
    if(a==b){
        return 0;
    }
    s[a]=b;
    return 1;
}
struct bian{
    int v1;
    int v2;
    long long w;
};
bian g[M];
bool bijiao(bian b1,bian b2){
    return b1.w<b2.w;
}
int n,m;
int main(){
    using namespace std;
    int i,j,num=0;
    long long ans=0;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        s[i]=i;
    }
    for(i=0;i<m;i++){
        cin>>g[i].v1>>g[i].v2>>g[i].w;
    }
    sort(g,g+m,bijiao);
    for(i=0;i<m;i++){
        if(hebing(g[i].v1,g[i].v2)){
            num++;
            ans+=g[i].w;
            if(num==n-1){
                cout<<ans;
                return 0;
            }
        }
    }
    cout<<"orz";
    return 0;
}