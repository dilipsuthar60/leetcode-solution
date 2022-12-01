class Solution {
    private:
    int check(string checkString)
    {
        int counter=0;
        int sizeOfcheckString=checkString.size();
        string totalString="aeiouAEIOU";
        for(int currIndex=0;currIndex<sizeOfcheckString;currIndex++)
        {
            if(totalString.find(checkString[currIndex])!=string::npos)
            {
                counter++;
            }
        }
        return counter;
    }
public:
    bool halvesAreAlike(string s) 
    {
        int sizeOfString=s.size();
        int midPointOfString=sizeOfString/2;
        string firstPartOfString=s.substr(0,midPointOfString);
        string secondPartOfString=s.substr(midPointOfString);
        if(check(firstPartOfString)==check(secondPartOfString))
        {
            // matching condition 
            return true;
        }
        return false;
    }
};