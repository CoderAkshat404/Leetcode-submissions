class Solution {
public:
    string toGoatLatin(string s) {
        string ans = "";
        int wordIndex = 1; // This will keep track of the current word's index in the sentence
        
        for (int i = 0; i < s.length(); ) {
            // Extract the current word
            string word = "";
            while (i < s.length() && s[i] != ' ') {
                word += s[i];
                i++;
            }

            // Move to next word (skip space)
            i++;

            // Check if the first character is a vowel
            bool isVowel = (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u' ||
                            word[0] == 'A' || word[0] == 'E' || word[0] == 'I' || word[0] == 'O' || word[0] == 'U');

            if (isVowel) {
                word += "ma";
            } else {
                // Move the first character to the end
                char firstChar = word[0];
                word = word.substr(1) + firstChar + "ma";
            }

            // Append 'a' based on the word index
            word += string(wordIndex, 'a');

            // Add the processed word to the result
            ans += word + " ";

            // Move to the next word
            wordIndex++;
        }

        // Remove the trailing space
        if (!ans.empty()) {
            ans.pop_back();
        }

        return ans;
    }
};
