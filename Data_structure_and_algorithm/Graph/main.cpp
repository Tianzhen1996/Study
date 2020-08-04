#include"Graph.h"
int main() {
    string s;
    Graph G;
    while (cin >> s) {
        int pos = s.find(',');
        string s1 = s.substr(0, pos);
        string s2 = s.substr(pos + 1, s.size() - pos);
        G.insert(s1, s2);
    }
    vector<string> top_result = G.topsort();
    for (auto node : top_result)
        cout << node << ' ';
    return 0;
}
