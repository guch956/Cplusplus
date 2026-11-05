#include<iostream>
#include<vector>
using namespace std;
const int N=1002;
vector<int > g[N];
int s[N],size1[N];
int n;
int find_set(int x){
    if(s[x]!=x){
        s[x] = find_set(s[x]);
    }
    return s[x];
}
void hebing(int x,int y){
    int a=find_set(x),b=find_set(y);
    if(a!=b){
        s[a] = b;
        size1[b]+=size1[a];
    }
}
int jisuan(){
    int i,j,v,ans=0;
    for(i=1;i<=n;i++){
        s[i]=i;
        size1[i]=1;
    }
    for(i=n;i>=1;i--){
        ans=0;
        for(j=0;j<g[i].size();j++){
            v=g[i][j];
            hebing(v,i);
        }
        if(size1[s[i]]*2>n){
            break;
        }
    }
    return i;
}
int main(){
    int i,j,k,c;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>k;
        for(j=1;j<=k;j++){
            cin>>c;
            if(c>=i){
                g[i].push_back(c);
            }
        }
    }
    cout<<jisuan();
    return 0;
}