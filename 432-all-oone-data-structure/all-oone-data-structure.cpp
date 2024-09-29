class AllOne {
public:
    map<string,int>cnts;
    int mini,maxi;
    map<int,set<string>>mp;
    AllOne() {
        maxi=0, mini=0;
    }
    
    void inc(string key) {
        if(cnts.find(key)==cnts.end()){
            cnts[key]=1;
            mp[1].insert(key);
            mini=1;
            if(maxi<1){
                maxi=1;
            }
        }
        else{
            mp[cnts[key]].erase(key);
            if(mini==cnts[key] && mp[cnts[key]].empty()){
                mini++;
            }
            cnts[key]++;
            mp[cnts[key]].insert(key);
            if(cnts[key]>maxi){
                maxi=cnts[key];
            }
        }
    }
    
    void dec(string key) {
        mp[cnts[key]].erase(key);
        if(mini==cnts[key] && mp[cnts[key]].empty()){
            mini--;
        }
        if(cnts[key]==maxi && mp[cnts[key]].empty()){
            maxi--;
        }
        cnts[key]--;

        if(cnts[key]>0){
            mp[cnts[key]].insert(key);
        }
        else{
            cnts.erase(key);
        }
    }
    
    string getMaxKey() {
        if(!mp[maxi].empty()){
            return *mp[maxi].begin();
        }
        return "";
    }
    
    string getMinKey() {
        if(!mp[mini].empty()){
            return *mp[mini].begin();
        }
        if(mini==0 && !cnts.empty()){
            while(mp[mini].empty()){
                mini++;
            }
            return *mp[mini].begin();
        }
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */