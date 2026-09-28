class Solution {
   public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;

        for (auto v : words) {
            for (auto c : v) {
                adj[c];
                indegree[c] = 0;
            }
        }

        for (int i = 0; i < words.size() - 1; i++) {
            int j = 0, k = 0;
            string a = words[i], b = words[i + 1];
            if (words[i].size() > words[i + 1].size() && a.substr(0, b.size()) == b) {
                return "";
            }
            while (j < min(a.size(), b.size())) {
                if (a[j] != b[k]) {
                    if (adj[a[j]].count(b[k]) == 0) {
                        adj[a[j]].insert(b[k]);
                        indegree[b[k]]++;
                    }

                    break;
                }
                j++;
                k++;
            }
        }

        queue<char> q;
        for (auto& [c, v] : indegree) {
            if (v == 0) {
                q.push(c);
            }
        }

        string res = "";
        while (!q.empty()) {
            char c = q.front();
            q.pop();

            res += c;
            for (auto x : adj[c]) {
                indegree[x]--;
                if (indegree[x] == 0) q.push(x);
            }
        }
        return res.size() == indegree.size() ? res : "";
    }
};
