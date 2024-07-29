class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>qt;
        unordered_set<string>st(wordList.begin(),wordList.end());
        
        qt.push({beginWord,1});
        st.erase(beginWord);

        while(!qt.empty()){
            string word = qt.front().first;
            int seq = qt.front().second;
            
            if(word == endWord) return seq;

            for(int i=0;i<word.size();i++){
                string originalWord = word;
                for(char j='a';j<='z';j++){
                    word[i] = j;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        qt.push({word,seq+1});
                    }
                }
                word = originalWord;
            }
            qt.pop();
        }
        return 0;
    }
};