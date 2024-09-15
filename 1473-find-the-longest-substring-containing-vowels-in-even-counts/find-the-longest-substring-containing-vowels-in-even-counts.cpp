class Solution {
public:
    int findTheLongestSubstring(string s) {
            
    unordered_map<vector<bool>, int>mp;

	
    int ans = 0;
	
    int a = 0;
    int e = 0;
    int i = 0;
    int o = 0;
    int u = 0;
    
    for(int j = 0; j<s.size(); j++)
    {
        if(s[j] == 'a')
        {
            a++;
        }
        if(s[j] == 'e')
        {
            e++;
        }
        if(s[j] == 'i')
        {
            i++;
        }
        if(s[j] == 'o')
        {
            o++;
        }
        if(s[j] == 'u')
        {
            u++;
        }
        
        vector<bool>temp;
        temp.push_back(a%2);
        temp.push_back(e%2);
        temp.push_back(i%2);
        temp.push_back(o%2);
        temp.push_back(u%2);
        
        
        if(a%2==0 && e%2==0 && i%2==0 && o%2==0 && u%2==0)
        {
		// if all evens 
            ans = j+1;
        }
        else if(mp.find(temp) != mp.end())
        {
		// if patteren of odds and evens already present 
            ans = max(ans, j - mp[temp]);
        }
        else
		// to store every unique pattern
            mp[temp] = j;
        
    }
	
    return ans;
    
}
    
};