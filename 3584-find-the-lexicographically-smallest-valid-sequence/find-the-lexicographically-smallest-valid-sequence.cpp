class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> last(m+1, -1);
        last[m] =n;

        int p= n-1;
        for(int i=m-1; i>=0; i--) {
            while(p >= 0 && word1[p] != word2[i]) {
                p--;
            }
            last[i] = p;
            if (p >=0) {
                p--;

            }
        }
        vector<int> ans;
        int w1_idx=0;
        bool changed = false;

        for(int i=0; i<m ; i++) {
            bool found = false;
            for (int k=w1_idx; k<n ; k++) {
                if(word1[k] == word2[i]) {
                    if (!changed || i+1 == m || last[i+1] >k) {
                        ans.push_back(k) ;  
                        w1_idx =k+1;
                        found = true;
                        break;                 
                }
            } else {
                if (!changed && (i+1 == m || last[i+1] > k)) {
                    changed =  true;
                    ans.push_back(k);
                    w1_idx = k+1;
                    found = true;
                    break;
                }
            }
        }
        if (!found) {
            return{};
        }   
    }
    return ans;
   
}
};