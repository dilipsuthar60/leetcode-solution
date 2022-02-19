class Solution {
public:
//          if(n%2) // odd
//             return {};

// 		vector<long long> ans;
//         long long i = 2;
//         long long crSum=0;
		
//         while((crSum+i)<= n)
//         {
//             ans.push_back(i);
//             crSum+=i;
//             i+=2;
//         }
		
// 		// add remaining difference to the last value in answer list
// 		int sz = ans.size();
//         ans[sz-1] += (n-crSum);
//         return ans;
    vector<long long> maximumEvenSplit(long long num) 
    {
        if(num%2==1)
        {
            return {};
        }
        vector<long long>ans;
        long long sum=0;
        for(int i=1;;i++)
        {
            if(sum+i*2<=num)
            {
                ans.push_back(i*2);
                sum+=i*2;
            }
            else
            {
                break;
            }
        }
        ans.back()+=(num-sum);
        return ans;
    }
};