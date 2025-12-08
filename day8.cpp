#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
ifstream fin("input.txt");
struct coords{
    int x,y,z;
    friend istream&operator>>(istream&in,coords&co){
        char c;
        in>>co.x>>c>>co.y>>c>>co.z;
        return in;
    }
    friend ostream&operator<<(ostream&out,coords&co){
        out<<co.x<<","<<co.y<<","<<co.z;
        return out;
    }
};
vector<pair<int,int>> p;
vector<int> root,rang;
vector<coords> v;
set<pair<int,int>> s;
long double dist (int  x,int  y) {
    return sqrt(pow(v[x].x-v[y].x,2)+pow(v[x].y-v[y].y,2)+pow(v[x].z-v[y].z,2));
}
int getRoot(int x) {
    if (root[x]==x) {
        return x;
    }
    return root[x] = getRoot(root[x]);
}
void unite(int x,int y) {
    x=getRoot(x);
    y=getRoot(y);
    if (x==y) return;
    if (rang[x]>rang[y]) {
        root[y]=x;
    }else if (rang[x]!=rang[y]) {
        root[x]=y;
    }
    else {
        root[y]=x;
        rang[x]++;
    }
}
void solve1() {
    coords c;
    v.push_back({0,0,0});
    while (fin>>c) {
        v.push_back(c);
    }
    int n=v.size()-1,fixed_size=1000;
    root.resize(n+1);
    rang.resize(n+1);
    for (int i=1; i<=n; i++) {
        root[i]=i;
        rang[i]=0;
    }
    for (int i=1; i<n; i++) {
        for (int j=i+1; j<=n; j++) {
            p.push_back({i,j});
        }
    }
    sort(p.begin(),p.end(),[](pair<int,int> a,pair<int,int> b) {
        return (dist(a.first,a.second)<dist(b.first,b.second));
    });
    for(int i=0; fixed_size; ++i,--fixed_size){
        int x=p[i].first,y=p[i].second;
        unite(x,y);
    }
    vector<int> sizes;
    vector<bool> counted(n+1,false);
    for(int i=1;i<=n;++i){
        int r=getRoot(i);
        if(!counted[r]){
            int cnt=0;
            for(int j=1;j<=n;++j) {
                if(getRoot(j)==r) {
                    ++cnt;
                }
            }
            sizes.push_back(cnt);
            counted[r]=true;
        }
    }
    sort(sizes.rbegin(),sizes.rend());
    long long prod=1;
    for(int i=0; i<3&&i<sizes.size(); ++i)
        prod*=sizes[i];
    cout<<prod;
}///ans:153328
int main() {
    solve1();
    return 0;
}
