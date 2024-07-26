class Solution {
public:

bool isCheck(string st){
    stack<char>s;

    for(int i=0;i<st.size();i++){
        if(st[i] == '('){
            s.push('(');
        }
        else{
            if(!s.empty() && s.top() == '(' && st[i] == ')'){
                s.pop();
            }
            else{
                return false;
            }
        }
    }

    if(s.empty()) return true;

    return false;
}

void solve(vector<string>&ans,string &st,int size){
    if(st.size() == size){
        if(isCheck(st)){
            ans.push_back(st);
        }
        return;
    }

    st.push_back('(');
    solve(ans,st,size);
    st.pop_back();
    st.push_back(')');
    solve(ans,st,size);
    st.pop_back();
}


    vector<string> generateParenthesis(int n) {
        string st ="";
        vector<string>ans;

        solve(ans,st,n*2);

        return ans;
    }
};