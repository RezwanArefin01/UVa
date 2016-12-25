#include<bits/stdc++.h>
using namespace std;

int main() {
    int t,op, x;  while(cin>>t) {
        stack<int> st; priority_queue<int> pq; queue<int> Q;
        bool isS = true, isPQ = true, isQ = true;
        while(t--) {
            cin>>op>>x;
            if(op == 1){
                if(isS) st.push(x);
                if(isPQ) pq.push(x);
                if(isQ) Q.push(x);
            } else {
                if(isS) {
                    if(st.empty() || st.top() != x)
                        isS = false;
                    else st.pop();
                } if(isQ) {
                    if(Q.empty() || Q.front() != x)
                        isQ = false;
                    else Q.pop();
                } if(isPQ) {
                    if(pq.empty() || pq.top() != x)
                        isPQ = false;
                    else pq.pop();
                }
            }
        }
        if(isS && !isQ && !isPQ) puts("stack");
        else if(!isS && isQ && !isPQ) puts("queue");
        else if(!isS && !isQ && isPQ) puts("priority queue");
        else if(!isS && !isQ && !isPQ) puts("impossible");
        else puts("not sure");
    }
}
