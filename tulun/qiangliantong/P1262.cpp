#include<iostream>
#include<vector>
using namespace std;
const int N=3002;
vector<int> g[N];
int dfn;int numb;int ans;
const int INF = 0x3f3f3f3f;
bool kongz[N];bool lt_kongz[N];
int stack[N];int top=1;int n;
int lt_jiage[N];int rudu[N];
int jiage[N];int low[N];int num[N];int liant[N];
void tarjan(int s){
    int i,v;
    dfn++;
    num[s] = dfn;low[s]=dfn;
    stack[top]=s;top++;
    for(i=0;i<g[s].size();i++){
        v = g[s][i];
        if(num[v]==0){
            tarjan(v);
            low[s] = min(low[s],low[v]);
        }
        else if(!liant[v]){
            low[s] = min(low[s],num[v]);
        }
    }
    if(low[s]==num[s]){
        numb++;
        while(1){
            top--;
            v = stack[top];
            liant[v]=numb;
            lt_jiage[numb]= min(jiage[v],lt_jiage[numb]);
            if(kongz[v]){
                lt_kongz[numb]=1;
            }
            if(v==s){
                break;
            }
        }
    }
}
void jisuan(){
    int i,j,v;
    for(i=1;i<=n;i++){
        if(num[i]==0 && kongz[i]){
            tarjan(i);
        }
    }
    for(i=1;i<=n;i++){
        if(num[i]==0){
            cout<<"NO"<<endl;
            cout<<i;
            return ;
        }
    }
    for(i=1;i<=n;i++){
        for(j=0;j<g[i].size();j++){
            v = g[i][j];
            if(liant[i]!=liant[v]){
                rudu[liant[v]]++;
            }
        }
    }
    for(i=1;i<=numb;i++){
        if(rudu[i]==0){
            ans+=lt_jiage[i];
        }
    }
    cout<<"YES"<<endl;
    cout<<ans;
}
int main(){
    int i,p,a,b,m;
    cin>>n;
    cin>>p;
    for(i=1;i<=n;i++){
        jiage[i] = INF;
        lt_jiage[i]=INF;
    }
    for(i=1;i<=p;i++){
        cin>>a;
        kongz[a]=1;
        cin>>jiage[a];
    }
    cin>>m;
    for(i=1;i<=m;i++){
        cin>>a>>b;
        g[a].push_back(b);
    }
    jisuan();
    return 0;
}