#include "libaoc.h";
ifstream file("input.txt");
vector<bitset<150>> buttons;
bitset<150> fstate;
#define ll long long
ll minim=0;
ll sum=0;
void apmin(ll nr, bitset<150> sf, const vector<bitset<150>> &buttons, int d) {
    if (nr>=minim) return;
    if (sf.none()==true) {
        minim=min(minim,nr);
        return;
    }
    for (int i=d; i<buttons.size(); i++) {
        apmin(nr+1, sf^buttons[i], buttons, i+1);
    }
}
void solve1() {
    string s;
    while (getline(file, s)) {
        while (s.back()!='{') {
            s.pop_back();
        }
        s.pop_back();
        int j=0;
        fstate=0;
        reverse(s.begin(), s.end());
        s.pop_back();
        for (int i=s.size()-1; s[i]!=']'; i--) {
            if (s[i]=='#') {
                fstate[j]=true;
            }
            else {
                fstate[j]=false;
            }
            j++;
            s.pop_back();
        }
        s.pop_back();
        reverse(s.begin(), s.end());
        stringstream ss(s);
        string g;
        vector<string> sbuttons;
        while (ss>>g) {
            g.pop_back();
            reverse(g.begin(), g.end());
            g.pop_back();
            reverse(g.begin(), g.end());
            for (int i=0; i<g.size(); i++) {
                if (g[i]==',') {
                    g[i]=' ';
                }
            }
            sbuttons.push_back(g);
        }
        buttons.clear();
        for (auto c:sbuttons) {
            stringstream sss(c);
            int a;
            buttons.push_back(0);
            while (sss>>a) {
                buttons.back()[a]=true;
            }
        }
        cout<<endl<<endl;
        minim=(1<<30);
        apmin(0,fstate,buttons,0);
        sum+=minim;
    }
    cout<<sum;
}
int main() {
    solve1();
    return 0;
}