class Solution {
  public:
    vector<vector<int>> countFreq(vector<int>& arr) {
        // code here
        unordered_map <int,int> mp;
        for( auto i: arr){
            mp[i]++;
        }
        vector<vector<int>> result;
        for(auto i:mp){
            result.push_back({i.first,i.second});
        }
        return result;
    }
};