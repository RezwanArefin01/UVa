#include<bits/stdc++.h>
using namespace std;
bool open(char c) {
    if(c=='(' || c=='<' || c=='{' || c=='[')
        return true;
    return false;
}
bool close(char c) {
    if(c==')' || c=='>' || c=='}' || c==']')
        return true;
    return false;
} map<char,char> op;
int main() { op[')'] = '(' ;op['}'] = '{'; op['>'] = '<'; op[']'] = '[' ;
    char str[3001];
    while(gets(str)) { stack<char> st; int cnt = 0, i = 0;
        int len = strlen(str); for(i=0; i<len; i++) { cnt++;
            if(open(str[i])) {
                if( str[i] == '(' && str[i+1] == '*') st.push('*'), i++;
                else st.push(str[i]);
            } else if(close(str[i]) || (str[i] == '*' && str[i+1] == ')')) {
                if(st.empty()) break;
                if(str[i] == '*') {
                    if(st.top()!= '*') break;
                    st.pop(); i++;
                }
                else {
                    if(st.top() != op[str[i]]) break;
                    st.pop();
                }
            }
        } if(i < len || !st.empty()) {
            if(i >= len && !st.empty()) cnt++;
            printf("NO %d\n", cnt);
        }else puts("YES");
    }
}
