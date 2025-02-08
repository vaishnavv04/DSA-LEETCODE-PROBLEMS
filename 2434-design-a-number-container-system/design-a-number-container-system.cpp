class NumberContainers {
public:
    unordered_map<int,set<int>> mn;
    unordered_map<int,int> mi;
    NumberContainers() {
        
    }
    
    void change(int i, int no) {
        if(mi.find(i)!=mi.end())
        {
            int x = mi[i];
            mn[x].erase(i);
        }
        mn[no].insert(i);
        mi[i] = no;
    }
    
    int find(int no) {
        if(mn.find(no)==mn.end() || mn[no].empty())
        return -1;
        return *mn[no].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */