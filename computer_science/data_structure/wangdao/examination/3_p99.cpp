#include <stack>
#include <vector>
using namespace std;
bool brackets_are_valid(vector<char> s)
{
    for (char e : s)
    {
        stack<char> s;
        if (e == '\0')
        {
            break;
        }
        if (e == '(' || e == '[' || e == '{')
        {
            s.push(e);
            // ! 忘记加break了
            break;
        }
        switch (e)
        {
        case ')':
            if (s.top() == '(')
            {
                s.pop();
            }
            else
            {
                return false;
            }
            break;
        case ']':
            if (s.top() == '[')
            {
                s.pop();
            }
            else
            {
                return false;
            }
            break;
        case '}':
            if (s.top() == '{')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        default:
            break;
        }
    }
    if (s.empty())
        return true;
    else
        return false;
}