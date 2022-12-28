class TextEditor
{
public:
    stack<char>left,right;
    TextEditor()
    {   
    }
    void addText(string text) 
    {       
        int n=text.size();
        for(int i=0;i<n;i++)
        {
            left.push(text[i]);
        }
    }
    int deleteText(int k)     
    { 
        int count=0;
        while(left.size()&&k--)
        {
            left.pop();
            count++;
        }
        return count;
    }
    string cursorLeft(int k) 
    {   
        while(left.size()&&k--)
        {
            right.push(left.top());
            left.pop();
        }
        string ans="";
        int count=10;
        while(left.size()&&count--)
        {
            ans.push_back(left.top());
            left.pop();
        }
        reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)
        {
            left.push(ans[i]);
        }
        return ans;
    }
    string cursorRight(int k)     
    {
        while(right.size()&&k--)
        {
            left.push(right.top());
            right.pop();
            
        }
        string ans="";
        int count=10;
        while(left.size()&&count--)
        {
            ans.push_back(left.top());
            left.pop();
        }
        reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)
        {
            left.push(ans[i]);
        }
        return ans;
    }
};