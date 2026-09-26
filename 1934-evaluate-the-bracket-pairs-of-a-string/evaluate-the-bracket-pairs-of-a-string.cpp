#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
            // Build a hash map for fast key-value lookups
                    unordered_map<string, string> dict;
                            for (const auto& kv : knowledge) {
                                        dict[kv[0]] = kv[1];
                                                }

                                                        string result = "";
                                                                string current_key = "";
                                                                        bool inside_bracket = false;

                                                                                for (char c : s) {
                                                                                            if (c == '(') {
                                                                                                            inside_bracket = true;
                                                                                                                        } else if (c == ')') {
                                                                                                                                        inside_bracket = false;
                                                                                                                                                        // Check if key exists in map
                                                                                                                                                                        auto it = dict.find(current_key);
                                                                                                                                                                                        if (it != dict.end()) {
                                                                                                                                                                                                            result += it->second;
                                                                                                                                                                                                                            } else {
                                                                                                                                                                                                                                                result += '?';
                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                current_key = ""; // Reset key buffer
                                                                                                                                                                                                                                                                                            } else {
                                                                                                                                                                                                                                                                                                            if (inside_bracket) {
                                                                                                                                                                                                                                                                                                                                current_key += c;
                                                                                                                                                                                                                                                                                                                                                } else {
                                                                                                                                                                                                                                                                                                                                                                    result += c;
                                                                                                                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                                                                                                                                        }

                                                                                                                                                                                                                                                                                                                                                                                                                return result;
                                                                                                                                                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                                                                                                                                                    };