class ProductOfNumbers {
public:
    vector<int> v;
    int size = 0;
    ProductOfNumbers() {
        v.push_back(1);
        size = 0;
    }
    
    void add(int num) {
        if(num==0)
        {
            v = {1};
            size = 0;
        }
        else
        {
            v.push_back(num*v[size]);
            size++;
        }
    }
    
    int getProduct(int k) {
        if(k>size) return 0;
        return v[size]/v[size-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */