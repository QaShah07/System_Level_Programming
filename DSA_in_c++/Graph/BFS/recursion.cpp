bool ans(term,op)
{
    
    if(op=='|')
    {
        for(auto it: term)
        {
            if(it=='f')
            {
                ans = ans | 0;
            }
            else
            {
                ans1 = ans1 | 1;
            }
        }
    }
    else if(op=='&')
    {
         for(auto it: term)
        {
            if(it=='f')
            {
                ans1 = ans1 & 0;
            }
            else
            {
                ans1 = ans1 & 1;
            }
        }
    }
    else if(op=='!')
    {
         for(auto it: term)
        {
            if(it=='f')
            {
                ans1 = ans1 ! 0;
            }
            else
            {
                ans1 = ans1 ! 1;
            }
        }
    }

}


class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> s;
        string term = "";
        char op
        for (char ch : expression) s.push(ch);
        while (!(s.size()==1))
         {
            while(s.top() == ')') 
            {
                s.pop();
            }
            while (s.top() != '(')
            {
                term = s.top() + term;
                s.pop();
            }
            s.pop();
            op = s.top();
            s.pop();
         } 
         return ans(term,op);
    }
};