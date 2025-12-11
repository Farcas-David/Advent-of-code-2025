#include "libaoc.h"
#define ull unsigned long long
using namespace std;
ifstream file("input.txt");
unordered_map<string,vector<string>> graf;
unordered_map<string,vector<vector<long long>>> dp;
void solve1() {
    string s;
    while (getline(file, s)) {
        stringstream ss(s);
        string d,x;
        ss>>d;
        d.pop_back();
        while (ss>>x) {
            graf[d].push_back(x);
        }
    }
    queue<string> q;
    unordered_map<string,int> distance;
    q.push("you");
    distance["you"]=1;
    while (!q.empty()) {
        string i=q.front();
        q.pop();
        for (auto vecin:graf[i]) {
            distance[vecin]++;
            q.push(vecin);
        }
    }
    cout<<distance["out"];
}///ans:758
ull totalroute=0;
ull dfs(string nod, bool seen_dac,bool seen_fft) {
    if (nod=="dac") {
        seen_dac=true;
    }
    if (nod=="fft") {
        seen_fft=true;
    }
    if (nod=="out") {
        if (seen_dac&&seen_fft) {
            return 1;
        }
        return 0;
    }
    long long &res=dp[nod][seen_dac][seen_fft];
    if (res!=-1)
        return (ull)res;
    res=0;
    for (const auto &p: graf[nod]) {
        res+=dfs(p,seen_dac,seen_fft);
    }
    return (ull)res;
}
void solve2() {
    string s;
    while (getline(file, s)) {
        stringstream ss(s);
        string d,x;
        ss>>d;
        d.pop_back();
        while (ss>>x) {
            graf[d].push_back(x);
        }
    }
    for (const auto p:graf) {
        dp[p.first]=vector<vector<long long>>(2,vector<long long>(2,-1));
    }
    cout<<dfs("svr",false,false);
}///ans: 490695961032000 finally I did it dp is goated
int main() {
    ///solve1();
    solve2();
    return 0;
}