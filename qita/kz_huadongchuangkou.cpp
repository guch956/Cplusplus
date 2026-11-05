#include<iostream>
int head,tail,k,n,p[1000001],q[1000000];
void push_min(int i){
    while(head<tail && q[p[tail-1]]>=q[i]){
        tail--;
    }
    p[tail]=i;
    tail++;
    if(p[head]<=i-k){
        head++;
    }
}
void push_max(int i){
    while(head<tail && q[p[tail-1]]<=q[i]){
        tail--;
    }
    p[tail]=i;
    tail++;
    if(p[head]<=i-k){
        head++;
    }
}
int main(){
    using namespace std;
    int i;
    cin>>n>>k;
    head=0;tail=0;
    for(i=0;i<n;i++){
        cin>>q[i];
    }
    for(i=0;i<k-1;i++){
        push_min(i);
    }
    for(i=k-1;i<n;i++){
        push_min(i);
        cout<<q[p[head]]<<' ';
    }
    cout<<endl;
    head=0;tail=0;
    for(i=0;i<k-1;i++){
        push_max(i);
    }
    for(i=k-1;i<n;i++){
        push_max(i);
        cout<<q[p[head]]<<' ';
    }
    return 0;
}