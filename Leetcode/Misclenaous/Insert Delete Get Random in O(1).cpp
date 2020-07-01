/* Without duplicates */
class RandomizedSet {
public:
    RandomizedSet() 
    {
        
    }
    
    bool insert(int val) 
    {
        if(m.find(val) != m.end())
            return false;
        v.emplace_back(val);
        m[val]=v.size()-1;    
        
        return true;
    }
    
    bool remove(int val) 
    {
        if(m.find(val) == m.end())
            return false;
                
        int last = v.back();
        
        m[last] = m[val];
        v[m[val]] = last;
        
        v.pop_back();
        
        m.erase(val);
        return true;
        
    }

    int getRandom() 
    {
        int r = rand() % v.size();
        return v[r];
    }
    
private:
    unordered_map<int, int> m;
    vector<int> v;
};

/* With duplicates */

  vector<int> v;
  unordered_map<int, unordered_set<int>> m;   // here we map all the indicies on which 'val' is stored

  bool insert(int val) 
  {
    v.push_back(val);
    m[val].insert(v.size() - 1);
    return m[val].size() == 1;  //if not already present return true else return false
  }

  bool remove(int val) 
  {
    auto it = m.find(val);
    if (it != m.end())
    {
      auto free_pos = *it->second.begin();  //delete the first position
      it->second.erase(it->second.begin());
      v[free_pos] = v.back();
      m[v.back()].insert(free_pos);
      m[v.back()].erase(v.size() - 1);
      v.pop_back();
      if (it->second.size() == 0) 
        m.erase(it);
      return true;
    }
    return false;
  }
  
int getRandom() 
{ 
    return v[rand() % v.size()];
}
