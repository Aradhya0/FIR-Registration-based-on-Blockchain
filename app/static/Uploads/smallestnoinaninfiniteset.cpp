class SmallestInfiniteSet {
    set<int> st;
public:
    SmallestInfiniteSet() {
        
        for(int i = 1; i <= 1000; i++)
            st.insert(i);
    }
    
    int popSmallest() {
        
        int tmp = *(st.begin());
        st.erase(tmp);
        return tmp;
    }
    
    void addBack(int num) {
        
        st.insert(num);
    }
};
