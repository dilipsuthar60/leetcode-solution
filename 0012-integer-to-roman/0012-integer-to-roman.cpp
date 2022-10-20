class Solution {
public:
        // int normal[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        // string roman[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    string intToRoman(int num) 
    {
        string ans="";
        vector<pair<string,int>>mp={{"M",1000},{"CM",900},{"D",500},{"CD",400},{"C",100},{"XC",90},{"L",50},{"XL",40},{"X",10},{"IX",9},{"V",5},{"IV",4},{"I",1}};
        int i=0;
        while(num>0)
        {
            while(num>=mp[i].second)
            {
                ans.append(mp[i].first);
                num-=mp[i].second;
            }
            i++;
        }
        return ans;
    }
};