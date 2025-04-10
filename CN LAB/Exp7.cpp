#include<iostream>
using namespace std;

void print(string ip) {
    if (ip.length() != 32) {
        cout << "Invalid IP length. Must be 32 bits." << endl;
        return;
    }

    cout << "IP Address (Binary) : ";
    for (int i = 0; i < 32; i++) {
        cout << ip[i];
        if ((i + 1) % 8 == 0 && i != 31)
            cout << ".";
    }
    cout << endl;

    cout << "IP Address in Decimal : ";
    for (int i = 0; i < 32; i += 8) {
        string part = ip.substr(i, 8);
        int val = stoi(part, nullptr, 2);
        cout << val;
        if (i != 24)
            cout << ".";
    }
    cout << endl;
}

int main(){
    string ip;
    cout<<"Enter IP Address (Binary Sequence without dots) : ";
    cin>>ip;
    cout<<endl<<"Processing......"<<endl;
    //class A
    if(ip.substr(0,1)=="0"){
        print(ip);
        cout<<"Class : A"<<endl;
        cout<<"Network_ID : "<<ip.substr(0,4)<<endl;
        cout<<"Network_ID (INT) : "<<stoi(ip.substr(0,4),0,2)<<endl;
        cout<<"Host_ID : "<<ip.substr(4)<<endl;
        cout<<"Host_ID  (INT)  : "<<stoll(ip.substr(4),0,2)<<endl;
    }
    //class B
    else if(ip.substr(0,2)=="10"){
        print(ip);
        cout<<"Class : B"<<endl;
        cout<<"Network_ID : "<<ip.substr(0,16)<<endl;
        cout<<"Network_ID (INT) : "<<stoi(ip.substr(0,16),0,2)<<endl;
        cout<<"Host_ID : "<<ip.substr(16)<<endl;
        cout<<"Host_ID  (INT)  : "<<stoll(ip.substr(16),0,2)<<endl;

    }
    //class C
    else if(ip.substr(0,3)=="110"){
        print(ip);
        cout<<"Class : C"<<endl;
        cout<<"Network_ID : "<<ip.substr(0,24)<<endl;
        cout<<"Network_ID (INT) : "<<stoi(ip.substr(0,24),0,2)<<endl;
        cout<<"Host_ID : "<<ip.substr(24)<<endl;
        cout<<"Host_ID  (INT)  : "<<stoll(ip.substr(24),0,2)<<endl;

    }
    //class D
    else if(ip.substr(0,4)=="1110"){
        print(ip);
        cout<<"Class : D"<<endl;
        cout<<"Network_ID : "<<ip.substr(0,32)<<endl;
        cout<<"Network_ID (INT) : "<<stoll(ip.substr(0,32),0,2)<<endl;
        cout<<"Host_ID : "<<"Not Applicable"<<endl;
        cout<<"Host_ID  (INT)  : "<<"Not Applicable"<<endl;
    }
    //class E
    else if(ip.substr(0,4)=="1111"){
        cout<<"Class : E"<<endl;
        cout<<"Network_ID : "<<ip.substr(0,32)<<endl;
        cout<<"Network_ID (INT) : "<<stoll(ip.substr(0,32),0,2)<<endl;
        cout<<"Host_ID : "<<"Not Applicable"<<endl;
        cout<<"Host_ID  (INT)  : "<<"Not Applicable"<<endl;

    }
    else{
        cout<<"Error in IP Sequence..."<<endl;
    }
}
