#include <iostream>
#include <bits/stdc++.h>
#include <functional>

using namespace std;

void score(string S)
{
    stack<int> st;
    vector<int> pos;
    reverse(S.begin(), S.end());
    for(auto c : S)
    {
        if(c == ')')
        {
            st.push(1);
        } else
        {
            pos.push_back(st.size());
            st.pop();
        }

    }
    sort(pos.begin(), pos.end());
    reverse(pos.begin(), pos.end());
    int score = 1;
    for (int i = 0; i < pos.size() - 1; ++i)
    {
        int x = pos[i];
        if(x == pos[i + 1])
            score += 1;
        else
        {
            score *= 2;
        }
    }
    cout << score;
}
int main()
{
    score("()");
    return 0;
}
/*
● Given a balanced parentheses string S, compute the score of the string based on the following rule:
  ● () has score 1
  ● AB has score A + B, Where A and B are balanced parentheses strings
  ● (A) has score 2 * A, Where A is balanced parentheses string

● Use stack
● Inputs
○ () ⇒ 1
○ (()) ⇒ 2
○ ()() ⇒ 2
○ (()()) ⇒ 4
○ (()(())) ⇒ 6
○ ()((())()) ⇒ 7

*/
