#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
typedef long long ll;
ll p[250003];
class node{
public:
    ll A;
    int id;
    bool operator<(const node & n1)const{
        return A<n1.A;
    } 
    node(int a=0,int ID=0){
        A = a;id = ID;
    }
}jiage[250003];
bool exist[250003];
int main(){
    int n,i,ans=0;
    ll sum=0,now=0;
    priority_queue<node> q;
    node u;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&p[i]);
    }
    for(i=1;i<=n;i++){
        scanf("%lld",&jiage[i].A);
        jiage[i].id=i;
    }
    for(i=1;i<=n;i++){
        now+=p[i];
        q.push(jiage[i]);
        now-=jiage[i].A;
        if(now<0){
            u = q.top();
            now+=u.A;
            exist[u.id]=1;
            q.pop();
        }
        else ans++;
    }
    printf("%d\n",ans);
    for(i=1;i<=n;i++){
        if(!exist[i])printf("%d ",i);
    }
    return 0;
}