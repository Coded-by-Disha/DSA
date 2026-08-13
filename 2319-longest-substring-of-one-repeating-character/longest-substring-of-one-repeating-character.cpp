class Solution {
    public:
        struct Node {
                char l, r;
                        int pre, suf, best, len;
                            };

                                vector<Node> tree;

                                    Node merge(Node a, Node b) {
                                            if (!a.len) return b;
                                                    if (!b.len) return a;

                                                            Node c;
                                                                    c.l = a.l;
                                                                            c.r = b.r;
                                                                                    c.len = a.len + b.len;

                                                                                            c.pre = a.pre;
                                                                                                    c.suf = b.suf;
                                                                                                            c.best = max(a.best, b.best);

                                                                                                                    if (a.r == b.l) {
                                                                                                                                c.pre = (a.pre == a.len) ? a.len + b.pre : a.pre;
                                                                                                                                            c.suf = (b.suf == b.len) ? b.len + a.suf : b.suf;
                                                                                                                                                        c.best = max(c.best, a.suf + b.pre);
                                                                                                                                                                }

                                                                                                                                                                        return c;
                                                                                                                                                                            }

                                                                                                                                                                                void build(string &s, int p, int l, int r) {
                                                                                                                                                                                        if (l == r) {
                                                                                                                                                                                                    tree[p] = {s[l], s[l], 1, 1, 1, 1};
                                                                                                                                                                                                                return;
                                                                                                                                                                                                                        }

                                                                                                                                                                                                                                int m = (l + r) / 2;

                                                                                                                                                                                                                                        build(s, 2*p, l, m);
                                                                                                                                                                                                                                                build(s, 2*p+1, m+1, r);

                                                                                                                                                                                                                                                        tree[p] = merge(tree[2*p], tree[2*p+1]);
                                                                                                                                                                                                                                                            }

                                                                                                                                                                                                                                                                void update(string &s, int p, int l, int r, int idx) {
                                                                                                                                                                                                                                                                        if (l == r) {
                                                                                                                                                                                                                                                                                    tree[p] = {s[l], s[l], 1, 1, 1, 1};
                                                                                                                                                                                                                                                                                                return;
                                                                                                                                                                                                                                                                                                        }

                                                                                                                                                                                                                                                                                                                int m = (l + r) / 2;

                                                                                                                                                                                                                                                                                                                        if (idx <= m)
                                                                                                                                                                                                                                                                                                                                    update(s, 2*p, l, m, idx);
                                                                                                                                                                                                                                                                                                                                            else
                                                                                                                                                                                                                                                                                                                                                        update(s, 2*p+1, m+1, r, idx);

                                                                                                                                                                                                                                                                                                                                                                tree[p] = merge(tree[2*p], tree[2*p+1]);
                                                                                                                                                                                                                                                                                                                                                                    }

                                                                                                                                                                                                                                                                                                                                                                        vector<int> longestRepeating(
                                                                                                                                                                                                                                                                                                                                                                                string s,
                                                                                                                                                                                                                                                                                                                                                                                        string queryCharacters,
                                                                                                                                                                                                                                                                                                                                                                                                vector<int>& queryIndices
                                                                                                                                                                                                                                                                                                                                                                                                    ) {
                                                                                                                                                                                                                                                                                                                                                                                                            int n = s.size();

                                                                                                                                                                                                                                                                                                                                                                                                                    tree.resize(4*n);
                                                                                                                                                                                                                                                                                                                                                                                                                            build(s, 1, 0, n-1);

                                                                                                                                                                                                                                                                                                                                                                                                                                    vector<int> ans;

                                                                                                                                                                                                                                                                                                                                                                                                                                            for (int i = 0; i < queryIndices.size(); i++) {
                                                                                                                                                                                                                                                                                                                                                                                                                                                        int idx = queryIndices[i];

                                                                                                                                                                                                                                                                                                                                                                                                                                                                    s[idx] = queryCharacters[i];

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                update(s, 1, 0, n-1, idx);

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            ans.push_back(tree[1].best);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    }

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            return ans;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                };
