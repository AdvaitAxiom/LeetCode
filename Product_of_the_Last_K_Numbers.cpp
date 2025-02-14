class ProductOfNumbers {
    private:
    vector<int> prefixProduct;
public:
    ProductOfNumbers() {
        prefixProduct = {1}; // Initialize with 1 to handle multiplication easily
    }
    
    void add(int num) {
         if (num == 0) {
            // If zero is added, reset the prefixProduct array
            prefixProduct = {1};
        } else {
            // Append the new product to the prefix product array
            prefixProduct.push_back(prefixProduct.back() * num);
        }
    }
    
    int getProduct(int k) {
         int n = prefixProduct.size();
        if (k >= n) {
            return 0; // If k is larger than available numbers, zero was encountered
        }
        return prefixProduct[n - 1] / prefixProduct[n - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */