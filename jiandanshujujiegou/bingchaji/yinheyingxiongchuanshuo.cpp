#include<iostream>
#include<cmath>
using namespace std;
const int N=30001;
int s[N],dis[N],tail[N];
int find_set(int x){
    int y=s[x];
    if(s[x]!=x){
        s[x] = find_set(s[x]);
        dis[x]+=dis[y];
    }
    return s[x];
}
int find_tail(int x){
    if(tail[x]!=x) tail[x]=find_tail(tail[x]);
    return tail[x];
}
void hebing(int x,int y){
    int a=find_set(x),b=find_tail(y);
    s[a]=b;
    tail[b]=a;
    dis[a]++;
}
int main(){
    int t,a,b,c,d;
    char p;
    for(int i=1;i<N;i++){
        tail[i]=i;
        s[i]=i;
    }
    cin>>t;
    while(t>0){
        t--;
        cin>>p;
        if(p=='M'){
            cin>>a>>b;
            hebing(a,b);
        }
        else{
            cin>>a>>b;
            c = find_set(a);
            d = find_set(b);
            if(c!=d){
                cout<<-1<<endl;
            }
            else{
                cout<<abs(dis[a]-dis[b])-1<<endl;
            }
        }
    }
    return 0;
}