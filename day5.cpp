#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
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
bool canunite(pair<long long,long long> a,pair<long long,long long> b) {
    return b.first<=a.second;
}
long long solve2() {
    long long count=0;
    read();
    sort(range.begin(),range.end(),[](pair<long long,long long> a,pair<long long,long long> b) {
        if (a.first!=b.first)
            return a.first>b.first;
        return a.second>b.second;
    });
    while(range.size()>1) {
        auto e1=range.back();
        range.pop_back();
        if(canunite(e1,range.back())){
            auto e2=range.back();
            range.pop_back();
            range.push_back(make_pair(e1.first,max(e1.second,e2.second)));
        }
        else {
            count+=e1.second-e1.first+1;
        }
    }
    count+=range.back().second-range.back().first+1;///forgot this
    return count;
}///ans:525
int main() {
    ///read();
    ///cout<<solve1()<<endl; answer is 525 for part 1
    cout<<solve2()<<endl;///answer is 333892124923577
    return 0;
}
