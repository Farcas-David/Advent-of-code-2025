#include <fstream>
#include<iostream>
#include <unordered_set>
using namespace std;

ifstream fin("date.in");
unsigned long long a,b,sum=0;
char r,v;
int lengh(unsigned long long n){
    int ctr=0;
    while(n){
        ctr++;
        n/=10;
    }
    return ctr;
}
unsigned long long powten(int n){
    unsigned long long p=1;
    while(n){
        p*=10;
        n--;
    }
    return p;
}
bool ivd(unsigned long long n){
    int l=lengh(n);
    for(int i=2;i<=l;i++){
        if(l%i==0){
            int pl=l/i;
            unordered_set<int> s;
            for(int k=1;k<=i;k++)
                s.insert((n/powten((i-k)*pl))%powten(pl));
            if(s.size()==1) return true;
        }
    }
    return false;
}
int main(){
    while(fin>>a>>r>>b){
        for(unsigned long long i=a;i<=b;i++)
            if(ivd(i)) sum+=i;
        fin>>ws;
        if(fin.peek()==',') fin.get();
    }
    cout<<sum;
    return 0;
}
