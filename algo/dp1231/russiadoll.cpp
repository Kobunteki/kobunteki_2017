#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool env_comp_wid(pair<int, int> i, pair<int, int> j)
{
	return i.first < j.first;
}

bool env_comp_height(pair<int, int> i, pair<int, int> j)
{
	return i.second < j.second;
}

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int> >& envelopes) {
    	//sort envelopes
    	int loop0, loop1;
    	int max_ret = 0;
    	int env_len = envelopes.size();
    	sort(envelopes.begin(), envelopes.end(),env_comp_height);
    	sort(envelopes.begin(), envelopes.end(),env_comp_wid);

    	vector<int> dp(env_len, 1);

    	for (loop0 = 0; loop0 < env_len; loop0 ++)
    	{
    		for (loop1 = 0; loop1 < loop0; loop1 ++)
    		{
    			/* code */
    			if ((envelopes[loop1].first < envelopes[loop0].first)	&&
    				(envelopes[loop1].second < envelopes[loop0].second))
    			{
    				dp[loop0] = (dp[loop0] > dp[loop1] + 1) ? dp[loop0] : (dp[loop1] + 1);
    			}
    		}

    		max_ret = max_ret > dp[loop0] ? max_ret:dp[loop0];
    	}

    	return max_ret;
    }
};





int main(int argc, char *argv[])
{
	Solution s;
	vector<pair<int, int> >  v;
	v.push_back(make_pair(5, 4));
	v.push_back(make_pair(6, 4));
	v.push_back(make_pair(6, 7));
	v.push_back(make_pair(2, 3));

	cout << s.maxEnvelopes(v) << endl;

	return 0;
}


