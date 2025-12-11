#include "libaoc.h"
using namespace std;
ifstream file("input.txt");
unordered_map<string,vector<string>> graf;
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
int main() {
    solve1();
    return 0;
}