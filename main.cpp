
#include "graph.h"
int main() {
    graph G;
    string s;
    while(cin>>s){
        int pos = s.find(',');
        string s1 = s.substr(0,pos);
        string s2 = s.substr(pos + 1,s.size() - pos);
        G.insert(s1,s2);
    }
    vector<string> res = G.topsort();
    for (auto s : res)
        cout << s << ' ';
    return 0;
}
