class MyHashSet {
public:
        vector<int> arr;
    MyHashSet() {
    }
    
    void add(int key) {
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(key==arr[i]){
                return;
            }
        }
        arr.push_back(key);
    }
    
    void remove(int key) {
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(key == arr[i]){
                arr.erase(arr.begin()+i);
                break;
            }
        }
    }
    
    bool contains(int key) {
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(key ==  arr[i]) return true;
        }        
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */