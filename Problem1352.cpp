// class ProductOfNumbers {
// public:
//     ProductOfNumbers() {
        
//     }
    
//     void add(int num) {
//         if (num == 0) {
//             lastZero = currIndex;
//             currProd = 1;
//         } else {
//             currProd *= num;
//         } 
//         indexProdMap[currIndex] = currProd;
//         ++currIndex;
//     }
    
//     int getProduct(int k) {
//         int i = indexProdMap.size() - k - 1;
//         if (i <= lastZero) {
//             return 0;
//         }
//         return currProd / indexProdMap[i - 1];
//     }

// private:
//     unordered_map<int, int> indexProdMap = {{-1, 1}};
//     int lastZero = -1;
//     int currProd = 1;
//     int currIndex = 0;
// };

// prefix product
// time: O(1)
// space: O(n)

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

class ProductOfNumbers {
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if (num) {
            prefixProds.push_back(prefixProds.back() * num);
        } else {
            prefixProds = {1};
        }
    }
    
    int getProduct(int k) {
        return k <= prefixProds.size() - 1 ? 
               prefixProds.back() / prefixProds[prefixProds.size() - k - 1] 
               : 0;
    }

private:
    vector<int> prefixProds = {1};
};

// prefix product
// time: O(1)
// space: O(n)

