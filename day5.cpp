#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
ifstream file ("date.in");
vector<pair<long long,long long>> range;
void read(){
    string s;
    while(getline(file,s)){
        if(s.empty()) break;
        size_t pos=s.find('-');
        if(pos==string::npos) continue;
        long long a=stoll(s.substr(0,pos));
        long long b=stoll(s.substr(pos+1));
        range.push_back({a,b});
    }
}
bool check(long long num) {
    for (auto p: range) {
        if (num>=p.first&&num<=p.second) {
            return true;
        }
    }
    return false;
}
int solve1() {
    int count=0;
    long long num;
    while (file>>num) {
        if (check(num)) {
            count++;
        }
    }
    return count;
}
int main() {
    read();
    cout<<solve1();
    return 0;
}