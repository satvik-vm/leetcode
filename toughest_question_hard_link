#include <bits/stdc++.h>
using namespace std;

struct Node{
    int sq_cnt = 0, cnt = 0, lazy = 0;
};

class BIT{
public:
    const int MOD = 1e9 + 7;
    const int N = 1e5 + 1;
    vector<int> last_seen;
    vector<Node> tree;

    BIT(int n) : tree(4 * n), last_seen(N + 1, -1) {}

    void add(int node, int st, int end, int x){
        int len = end - st + 1;
        tree[node].sq_cnt = (0LL + tree[node].sq_cnt + 2LL * x * tree[node].cnt + 1LL * x * x % MOD * len) % MOD;

        tree[node].cnt = (1LL * len * x + tree[node].cnt) % MOD;

        tree[node].lazy = (1LL * tree[node].lazy + x) % MOD;
    }

    void lazy(int node, int st, int end){
        if (tree[node].lazy == 0) return;
        int x = tree[node].lazy;
        int mid = st + (end - st) / 2;

        add(2 * node, st, mid, x);
        add(2 * node + 1, mid + 1, end, x);

        tree[node].lazy = 0;
    }

    void merge(int node, int left, int right) {
        tree[node].cnt = (0LL + tree[left].cnt + tree[right].cnt) % MOD;
        tree[node].sq_cnt = (0LL + tree[left].sq_cnt + tree[right].sq_cnt) % MOD;
    }

    void update(int node, int st, int end, int ql, int qr) {
        if (qr < st || end < ql) return;

        if (ql <= st && end <= qr) {
            add(node, st, end, 1);
            return;
        }

        lazy(node, st, end);
        int mid = st + (end - st) / 2;
        update(2 * node, st, mid, ql, qr);
        update(2 * node + 1, mid + 1, end, ql, qr);
        merge(node, 2 * node, 2 * node + 1);
    }
};

class Solution {

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        BIT *bit = new BIT(n);
        int ans = 0;

        for(int i = 0; i < n; i++){
            int start = bit->last_seen[nums[i]] + 1;
            bit->last_seen[nums[i]] = i;

            bit->update(1, 0, n - 1, start, i);

            ans = (1LL * bit->tree[1].sq_cnt + ans) % bit->MOD;
        }
        return ans;
    }
};