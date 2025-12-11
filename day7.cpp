#include "libaoc.h";
ifstream file ("input.txt");
vector<string> m;
string line;
vector<bitset<150>> visited;
vector<vector<long long>> dp;
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
void solve2(){
    int n=m.size();
    int mm=m[0].size();
    dp=vector<vector<long long>>(n+1,vector<long long>(mm+1));
    for (int i=0; i<mm; i++){
        dp[n][i]=1;
    }
    for (int i=n-1; i>=0; i--){
        for(int j=0; j<mm; j++){
            if (m[i][j]=='.'||m[i][j]=='S'){
                dp[i][j]=dp[i+1][j];
            }
            else {
                long long left,right;
                left=(j>0 ? dp[i+1][j-1] :0);
                right=(j<mm ? dp[i+1][j+1] : 0);
                dp[i][j]=left+right;
            }
        }
    }
}///ans:58097428661390
int main() {
    read();
    ///solve1();
    ///cout<<nrs;
    solve2();
    int s=m[0].find('S');
    cout<<dp[0][s];
    return 0;
}
