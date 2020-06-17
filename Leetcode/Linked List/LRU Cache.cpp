/* Idea is to move the node to [rear] each time it is referenced, either through get() method or put() method */

class LRUCache {
private:
    int size;
    list<pair<int, int>> dq;
    unordered_map<int,  list<pair<int, int>>::iterator> hash;
    
public:
    LRUCache(int capacity) 
    {
        size=capacity;
    }
    
    int get(int key) 
    {
        auto it = hash.find(key);
        if(it==hash.end())
            return -1;
        
        dq.splice(dq.begin(), dq, it->second);  //If key is present then move the it.second from it's position to start(rare) of list, becz it has been currently referred
        return it->second->second;    //return the value of key 
    }
    
    void put(int key, int value) 
    {
        auto it = hash.find(key);
        if(it != hash.end())
        {
            dq.splice(dq.begin(), dq, it->second);   //when this key is referenced then bring this key at rear end
            it->second->second = value;             //update the value of node
            return;
        }
        if(size==hash.size())   //when our cache is full
        {
            int key_to_delete = dq.back().first;    //the element which isn't being referred since times, will be present at back() so delete it
            dq.pop_back();     //remove that element
                
            hash.erase(key_to_delete);
        }
        dq.push_front({key, value});
        hash[key]=dq.begin();
    }
};