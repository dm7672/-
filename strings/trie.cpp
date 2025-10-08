struct Node {
    int isTerm;
    int cnt;
    map<char, int> list;
    Node() {
        isTerm = 0;
        cnt = 0;
    }
};

vector<Node> trie(1);

void addX(const string& s) {
    int v = 0;
    trie[v].cnt++;
    for (auto c : s) {
        if (trie[v].list[c] == 0) {
            trie.push_back(Node());
            trie[v].list[c] = (int)trie.size() - 1;
        }
        v = trie[v].list[c];
        trie[v].cnt++;
    }
    trie[v].isTerm++;
}

void delX(const string& s) {
    int v = 0;
    trie[v].cnt--;
    for (auto c : s) {
        v = trie[v].list[c];
        trie[v].cnt--;
    }
    trie[v].isTerm--;
}
