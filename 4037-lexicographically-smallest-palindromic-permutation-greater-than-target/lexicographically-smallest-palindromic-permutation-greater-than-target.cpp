class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n=s.length();
        vector<int> count(26,0);
        for(char c:s) count[c - 'a']++;

        int odd_count =0, odd_char = -1;
        for (int i =0; i<26; i++) {
            if (count [i] %2 !=0){
                odd_count ++;
                odd_char=i;
            }
        }
        if (odd_count >1) return "";

        vector<int> half_count (26,0);
        for (int i =0;i<26;i++) half_count[i] =count[i]/2;
        int half_len =n/2;

        auto build =[&](string first_half) {
            string res= first_half;
            if (n%2 !=0) res += (char)('a' + odd_char);
            for (int i=half_len -1; i>=0; i--) res+= first_half[i];
            return res;
       };

       for (int len = half_len; len>=0; len-- ) {
        vector<int> avail = half_count;
        bool ok = true;

        for (int i =0; i<len;i++) {
            if( --avail[target[i]- 'a']<0){
                ok= false;
                break;

            }
        }
        if (!ok) continue;

        if(len == half_len) {
            string full = build(target.substr(0, half_len));
            if (full> target) return full;
            continue;

        }
        for (int c= target[len] - 'a' +1; c<26; c++)
        {
            if (avail[c] >0) {
                string half = target.substr(0,len);
                half += (char) ('a' +c);
                avail[c] --;

                for (int ch=0;ch<26; ch++) {
                    while (avail[ch]-- >0) half+= (char)('a' + ch);
                }
                return build(half);
            }

        }
       }
       return "";


    }
};