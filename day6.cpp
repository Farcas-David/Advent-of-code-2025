#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <stack>
using namespace std;
ifstream file("date.in");
string line, ops;
vector<vector<int>> num;
vector<string> tok;
int lc=0;
long long tot=0;
void read() {
    while (getline(file,line)) {
        if (line.find_first_not_of("*+ ") == string::npos) {
            for (char c: line) {
                if (c=='+'||c=='*') {
                    ops.push_back(c);
                }
            }
            continue;
        }
        stringstream ss(line);
        int x;
        vector<int> row;
        while (ss>>x)
            row.push_back(x);
        num.push_back(row);
    }
}

void solve1() {
    for (int i=0; i<num[0].size(); i++) {
        queue<int> q;
        for (int j=0; j<num.size(); j++)
            q.push(num[j][i]);
        long long ans=q.front();
        q.pop();
        cout<<ans<<" ";
        if (ops[i]=='+') {
            while (!q.empty()) {
                ans+=q.front();
                cout<<q.front()<<" ";
                q.pop();
            }
        } else {
            while (!q.empty()) {
                ans*=q.front();
                cout<<q.front()<<" ";
                q.pop();
            }
        }
        cout<<ans<<endl<<endl;
        tot+=ans;
    }
}
void read2() {
    string line;
    while (getline(file,line)) {
        if (line.find_first_not_of("*+ ") == string::npos) {
            for (char c: line) {
                if (c=='+'||c=='*') {
                    ops.push_back(c);
                }
            }
            continue;
        }
        tok.push_back(line);
        lc++;
    }
}
void solve2() {
    int p=ops.size()-1;
    queue<int> q;
    for (int i=tok[1].size()-1; i>=0; i--) {
        string nr;

        for (int j=0; j<lc; j++) {
            if (tok[j][i]!=' ') {
                nr.push_back(tok[j][i]);
            }
        }
        if (nr.empty()) {
            long long ans=q.front();
            q.pop();
            if (ops[p]=='+') {
                while (!q.empty()) {
                    ans+=q.front();
                    q.pop();
                }
            } else {
                while (!q.empty()) {
                    ans*=q.front();
                    q.pop();
                }
            }
            p--;
            tot+=ans;
            q=queue<int>();
            continue;
        }
        else {
            q.push(stoi(nr));
        }
    }
    long long ans=q.front();
    q.pop();
    if (ops[p]=='+') {
        while (!q.empty()) {
            ans+=q.front();
            q.pop();
        }
    } else {
        while (!q.empty()) {
            ans*=q.front();
            q.pop();
        }
    }
    p--;
    tot+=ans;
}///finally got around to doing it
int main() {
    ///read();
    ///solve1();
    read2();
    solve2();
    cout<<tot;
    return 0;
}
