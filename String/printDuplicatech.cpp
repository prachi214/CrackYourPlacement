// Print all the duplicates in the string

#include <bits/stdc++.h> 

vector<pair<char,int>> duplicate_char(string s, int n){


    map<char, int> countsMap;
    vector<pair<char, int>> result;


    for (int i = 0; i < s.length(); i++)
    // store each char total occurance
        countsMap[s[i]]++;

  
//   fetch countsMap key and values into repeatedchars map
    for (auto &repeatedchars: countsMap) {
        // is value >1
        if (repeatedchars.second > 1) {
            // put on pair {key,value}
            result.push_back(repeatedchars); 
        }
    }

    return result;
}