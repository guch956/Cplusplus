#include<iostream>
#include<vector>
#include<queue>
int main(){
    using namespace std;
    int n,i,j,m,q,x,y,*t;
    cin>>n>>m>>q;
    t = new int[n];
    vector<vector<int>> tu(n);
    queue<int> p;
    for(i=0;i<m;i++){
        cin>>x>>y;
        tu[x-1].push_back(y-1);
        tu[y-1].push_back(x-1);
    }
    for(i=0;i<n;i++){
        t[i] = -1;
    }
    t[0] = 0;
    p.push(0);
    while(p.size()){
        x = p.front();
        p.pop();
        for(int i : tu[x]){
            if(t[i]==-1){
                t[i]=t[x]+1;
                p.push(i);
            }
        }
    }
    for(i=0;i<q;i++){
        cin>>x>>y;
        if(t[x-1]<=y){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}