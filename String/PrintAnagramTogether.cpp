class Solution{
  public:
  std::array<int, 256>hash(string string_list){
   std::array<int, 256>hash={0};
   for(int i = 0;i<string_list.size();i++){
    hash[string_list[i]]++;
   }
   return hash;
}
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        // arr as key and strings as value
          map<std::array<int,256>,vector<string>>mp; 
      for(auto str:string_list) {
// for each str above function invokes
        mp[hash(str)].push_back(str);
      }
      vector<vector<string>>ans;
      for(auto it = mp.begin();it!=mp.end();it++){
        // map values
        ans.push_back(it->second);
      }
      return ans;
    }
};