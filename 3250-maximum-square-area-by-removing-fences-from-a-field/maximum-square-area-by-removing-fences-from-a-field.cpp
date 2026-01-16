class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const long long MOD = 1000000007;

        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<long long> hdiff;

        for (int i = 0; i < (int)hFences.size(); i++) {
            for (int j = i + 1; j < (int)hFences.size(); j++) {
                hdiff.insert((long long)hFences[j] - hFences[i]);
            }
        }

        long long side = -1;

        for (int i = 0; i < (int)vFences.size(); i++) {
            for (int j = i + 1; j < (int)vFences.size(); j++) {
                long long d = (long long)vFences[j] - vFences[i];
                if (hdiff.count(d)) side = max(side, d);
            }
        }

        if (side == -1) return -1;

        return (long long)((__int128)side * side % MOD);
    }
};
