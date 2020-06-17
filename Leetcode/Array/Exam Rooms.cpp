/* seat() => O(N) and leave() => O(1) */

class ExamRoom {
    int N;
    list<int> seats;
    unordered_map<int, list<int>::iterator> hash_map;
public:
    ExamRoom(int N) {
        this->N = N;
    }
    
    int seat() {
        if (seats.empty())
            return seats.push_back(0), hash_map[0] = seats.begin(), 0;
            
        int last = -1, dist, val;
        list<int>::iterator pos;
        for (auto it = seats.begin(); it != seats.end(); ++it) {
            if (last == -1)
                dist = *it, pos = it, val = 0;
            else if ((*it - last) / 2 > dist)
                dist = (*it - last) / 2, pos = it, val = (*it + last) / 2;
            last = *it;
        }
        if (N - 1 - seats.back() > dist)
            pos = seats.end(), val = N - 1;
        return hash_map[val] = seats.insert(pos, val), val;
    }
    
    void leave(int p) {
        seats.erase(hash_map[p]);
    }
};