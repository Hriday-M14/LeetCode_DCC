// Insert Delete GetRandom O(1)

class RandomizedSet {
private:
    vector<int> SetList;
    unordered_map<int,int> SetMap;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(SetMap[val] > 0)
            return false;
        else
        {
            SetList.push_back(val);
            SetMap[val] = SetList.size();
            return true;
        }
    }
    
    bool remove(int val) {
        if(SetMap[val] > 0)
        {
            int LastElement = SetList.back();
            SetList[SetMap[val]-1] = LastElement;
            SetList.pop_back();
            SetMap[LastElement] = SetMap[val];
            SetMap.erase(val);
            return true;
        }
        else
            return false;
    }
    
    int getRandom() {
        return SetList[rand()%SetList.size()];
    }
};