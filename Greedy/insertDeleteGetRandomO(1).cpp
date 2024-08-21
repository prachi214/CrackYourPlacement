class RandomizedCollection {

    vector<int> v;

    unordered_map<int, unordered_set<int>> mpp;

public:
    RandomizedCollection() {

    }

    bool insert(int val) {

        v.push_back(val);

        int index = v.size() - 1;
        mpp[val].insert(index);
        return mpp[val].size() == 1;
    }

    bool remove(int val) {
        if (!mpp.count(val))
            return 0;
        int index = *(mpp[val].begin());
        int lastIndex = v.size() - 1;
        mpp[val].erase(index);
        if (index != lastIndex) {
            mpp[v[lastIndex]].erase(lastIndex);
            mpp[v[lastIndex]].insert(index);
            swap(v[index], v[lastIndex]);
        }
        v.pop_back();
        if (mpp[val].size() == 0)
            mpp.erase(val);
        return 1;
    }
    int getRandom() {
        int randomIndex = rand() % v.size();
        return v[randomIndex];
    }
};