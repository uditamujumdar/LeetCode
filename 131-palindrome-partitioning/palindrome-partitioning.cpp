class Solution {
private:
bool isPalin(int start,int end,string a)
{
    while(start<=end)
    {
        if(a[start++]!=a[end--])
        {
            return false;
        }
    }
    return true;
}
void isPal(int index,vector<string>path,vector<vector<string>> &ans,string s)
{
    if(index>=s.length())
    {
        ans.push_back(path);
        return;
    }

    for(int i=index;i<s.length();i++)
    {
        if(isPalin(index,i,s))
        {
            path.push_back(s.substr(index,i-index+1));
            isPal(i+1,path,ans,s);
            path.pop_back();
        }
    }
}
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>path;
        isPal(0,path,ans,s);
        return ans;
    }
};