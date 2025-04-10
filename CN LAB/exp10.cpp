#include<iostream>
using namespace std;

int main(){
    int p;
    int g;
    cout<<"Enter Prime No(p) & Primitive Root No(g) :";
    cin>>p>>g;
    int a,b;
    cout<<endl<<"Enter A's private key : ";
    cin>>a;
    cout<<endl<<"Enter B's private key  : ";
    cin>>b;
    long long a_public = pow(g,a);
    long long b_public = pow(g,b);
    cout<<endl<<"Data shared by A publicaly : "<<a_public%p;
    cout<<endl<<"Data shared by B publicaly : "<<b_public%p;
    cout<<endl<<"Data Interpreted by A: "<<int(pow(b_public%p,a))%p;
    cout<<endl<<"Data Interpreted by B: "<<int(pow(a_public%p,b))%p<<endl;
   

}