#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;
ifstream file ("input.txt");
vector<string> m;
string line;
vector<bitset<150>> visited;
int nrs=0;
void read() {
    while (getline(file, line)) {
        m.push_back(line);
        visited.push_back(0);
    }
}
void solve1() {
    queue<pair<int,int>>q;
    q.push({0,m[0].size()/2});
    visited[0][m[0].size()/2]=1;
    while (!q.empty()) {
        int i = q.front().first, j = q.front().second;
        q.pop();
        if (i+1>=m.size()) {
            continue;
        }
        bool found=false;
        for (int k=i+1; k<m.size()&&found==false; k++) {
            if (m[k][j]=='^') {
                found=true;
                nrs++;
                if (j+1<m[0].size()&&visited[k+1][j+1]==0) {
                    q.push({k+1,j+1});
                    visited[k+1][j+1]=1;
                }
                if (j-1>=0&&visited[k+1][j-1]==0) {
                    q.push({k+1,j-1});
                    visited[k+1][j-1]=1;
                }
            }
            else if (visited[k][j]==1) {
                found=true;
            }
            else {
                visited[k][j]=1;
            }
        }
    }
}///ans:1635
int main() {
    read();
    solve1();
    cout<<nrs;
    return 0;
}