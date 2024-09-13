#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>

using namespace std;

class Solution {
public:
    string arrangeWords(string text) {
        // Multimap to store word length as the key and pairs of (word, last index) as values
        multimap<int, pair<string, int>> wordMap;
        vector<string> wordList; // To preserve the order of appearance
        
        // Convert text to lowercase
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        
        // Process the text to extract words and their last occurrence index
        istringstream iss(text);
        string word;
        int index = 0;
        while (iss >> word) {
            int lastIndex = index + word.length() - 1;  // Last index of the current word
            wordMap.emplace(word.length(), make_pair(word, lastIndex));
            wordList.push_back(word);
            index += word.length() + 1; // Move index to the end of the current word and the next space
        }

        // Prepare to extract and sort the data
        vector<pair<int, pair<string, int>>> sortedWords(wordMap.begin(), wordMap.end());

        // Sort words first by length and then by last occurrence index
        stable_sort(sortedWords.begin(), sortedWords.end(), [](const pair<int, pair<string, int>>& a, const pair<int, pair<string, int>>& b) {
            if (a.first == b.first) {
                return a.second.second < b.second.second; // Compare by last occurrence index
            }
            return a.first < b.first; // Compare by word length
        });

        // Construct the result
        string ans;
        for (const auto& p : sortedWords) {
            ans += p.second.first + " ";
        }

        // Remove trailing space
        if (!ans.empty()) {
            ans.pop_back();
        }

        // Capitalize the first letter
        if (!ans.empty() && islower(ans[0])) {
            ans[0] = toupper(ans[0]);
        }

        return ans;
    }
};