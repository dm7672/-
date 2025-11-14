const int B = 330;  // √n

struct Query {
    int index, left, right;
};

bool compareQueries(const Query& a, const Query& b) {
    int blockA = a.left / B;
    int blockB = b.left / B;
    if (blockA != blockB) return blockA < blockB;
    return a.right < b.right;
}

int uniqueCount = 0;

//TODO
void add(int pos) {}
void remove(int pos) {}

int getAns() {
    return uniqueCount;
}

int calcShort(int l, int r) {
    for (int i = l; i <= r; ++i) {
        add(i);
    }
    for (int i = l; i <= r; ++i) {
        remove(i);
    }
    int res = uniqueCount;
    uniqueCount = 0;
    return res;
}

vector<int> MoAlgorithm(vector<Query>& queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end(), compareQueries);
    int blocksCount = a.size() / B + 1;
    vector<vector<Query>> blocks(blocksCount);
    for (Query q : queries) {
        if (q.right - q.left <= (2 * B)) {
            answers[q.index] = calcShort(q.left, q.right);
        } else {
            blocks[q.left / B].push_back(q);
        }
    }
    for (int i = 0; i < blocksCount; i++) {
        int curLeft = i * B + B, curRight = i * B - 1 + B;
        fill(freqCount.begin(), freqCount.end(), 0);
        uniqueCount = 0;
        for (Query q : blocks[i]) {
            while (curRight < q.right)
                add(++curRight);
            int backup = getAns();
            while (curLeft > q.left)
                add(--curLeft);
            answers[q.index] = getAns();
            while (curLeft < (i * B + B))
                remove(curLeft++);
            
            uniqueCount = backup;
        }
    }
    return answers;
}