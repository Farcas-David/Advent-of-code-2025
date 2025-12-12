#include "libaoc.h";
#define ull unsigned long long
ifstream file ("input.txt");
vector<int> presents;
vector<int> nrpresents;
void solve1() {
    string s;
    presents=vector<int>(6);
    for (int i=0;i<6;i++) {
        getline(file,s);
        int count=0;
        for (int j=0; j<3; j++) {
            getline(file,s);
            for (auto c: s) {
                if (c=='#') {
                    count++;
                }
            }
        }
        presents[i]=count;
        getline(file,s);
    }
    ull sol=0;
    int n,m;
    char junk;
    while (file>>n>>junk>>m>>junk) {
        nrpresents=vector<int>(6);
        for (int i=0;i<6;i++) {
            file>>nrpresents[i];
        }
        ull rarea=0;
        for (int i=0;i<6;i++) {
            rarea+=(ull)nrpresents[i]*presents[i];
        }
        ull area=(ull)n*m;
        if (rarea<=area)
            sol++;
    }
    cout<<sol<<endl;
}
int main() {
    solve1();
    return 0;
}