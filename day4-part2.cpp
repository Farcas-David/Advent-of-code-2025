#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

ifstream fin("date.in");
vector<string> rolls;

int tot=0;
int di[]={-1,-1,-1,0,1,1,1,0},dj[]={-1,0,1,1,1,0,-1,-1};

void citire(){
    string line;
    while(getline(fin,line)){
        rolls.push_back(line);
    }
}
int main() {
    citire();
    int n = rolls.size(), m = rolls[0].size();
    vector<vector<int>> cnt(n,vector<int>(m,0));
    queue<pair<int,int>> q;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (rolls[i][j]!='@')
                continue;
            for (int a=0; a<8; a++){
                int ni=i+di[a],nj=j+dj[a];
                if (ni>=0&&ni<n&&nj>=0&&nj<m&&rolls[ni][nj]=='@')
                    cnt[i][j]++;
            }
            if (cnt[i][j]<4)
                q.push({i,j});
        }
    }
    while (q.empty()==false){
        int i=q.front().first,j=q.front().second;
        q.pop();
        if (rolls[i][j]!='@')
            continue;
        rolls[i][j]='.';
        tot++;
        for(int a=0;a<8;a++){
            int ni=i+di[a], nj=j+dj[a];
            if(ni<0||ni>=n||nj<0||nj>=m)
                continue;
            if(rolls[ni][nj]=='@'){
                cnt[ni][nj]--;
                if(cnt[ni][nj] < 4)
                    q.push(make_pair(ni,nj));
            }
        }
    }
    cout<<tot;
    return 0;;
}
