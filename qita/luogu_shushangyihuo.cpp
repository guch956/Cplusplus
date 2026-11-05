#include<iostream>
int main(){
    using namespace std;
    int a,b,c,s;
    cin>>a>>b>>c;
    cout<<a*(b^c)<<endl;
    s = (a*b)^(a*c);
    cout<<s;
    return 0;
}