#include "libaoc.h";
ifstream fin("input.txt");
struct coords{
    int x,y;
    friend istream&operator>>(istream&in,coords&c){
        char t;
        in>>c.x>>t>>c.y;
        return in;
    }
    friend ostream&operator<<(ostream&out,coords&c){
        out<<c.x<<","<<c.y;
        return out;
    }
};
vector<coords> v;
vector<pair<int,int>> p;
long long area(int x,int y){
    return (abs(v[x].x-v[y].x)+1)*(abs(v[x].y-v[y].y)+1);
}
void solve1(){
    coords c;
    v.push_back({0,0});
    while (fin>>c){
        v.push_back(c);
    }

    int n=v.size()-1;
    for (int i=1; i<n; i++){
        for (int j=i+1; j<=n; j++){
            p.push_back({i,j});
        }
    }
    sort(p.begin(),p.end(),[](pair<int,int>a, pair<int,int> b){
         return area(a.first,a.second)>area(b.first,b.second);
    });
    cout<<area(p[0].first,p[0].second);
}
vector<pair<int,int>> pl;
bool valid (int i, int j){
    int xmin=min(pl[i].first,pl[j].first);
    int xmax=max(pl[i].first,pl[j].first);
    int ymin=min(pl[i].second,pl[j].second);
    int ymax=max(pl[i].second,pl[j].second);
    for (int l=0; l<pl.size(); l++){
        int nextl=(l+1+pl.size())%pl.size();
        if (xmin<max(pl[l].first,pl[nextl].first)&&xmax>min(pl[l].first,pl[nextl].first)&&ymin<max(pl[l].second,pl[nextl].second)&&ymax>min(pl[l].second,pl[nextl].second)){
            return false;
        }
    }
    return true;
}
long long area2(int i,int j){
    return (abs(pl[i].first-pl[j].first)+1)*(abs(pl[i].second-pl[j].second)+1);
}
void solve2(){
    char c;
    int a,b;
    while (fin>>a>>c>>b){
        pl.push_back({a,b});
    }
    long long max_area=0;
    for (int i=0; i<pl.size()-1; i++){
        for (int j=i+1; j<pl.size(); j++){
            long long current_area;
            if (valid(i,j)==true){
                current_area=area2(i,j);
                if (current_area>max_area)
                    max_area=current_area;
            }
        }
    }
    cout<<max_area;
}///ans:1429596008
int main(){
    ///solve1();
    solve2();
    return 0;
}
