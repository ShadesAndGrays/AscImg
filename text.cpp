#include <iostream>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

// typedef bool binarybraille[6];

class BinaryBraille{
    public:
        bool arr[6];
        BinaryBraille(){
            for ( auto &i : arr) 
                i = false;
        }
        BinaryBraille(bool val){
            for ( auto &i : arr) 
                i = val;
        }
        BinaryBraille(bool val[6]){
            for (int i = 0; i < 6; i++) 
                arr[i] = val[i];
        }
        BinaryBraille(int val[6]){
            for (int i = 0; i < 6; i++) 
                arr[i] = val[i];
        }
        bool&  operator[]( int x){
            return arr[x];
        }

        void operator()() const{
            for(int i = 0; i < 6;i++){
                std::cout << arr[i] << ((i%2 == 0) ? "\n" : " "); 
            }
        }

        bool operator==(const BinaryBraille &cmp ) const{
            for (int i = 0; i < 6; i++) 
                if (arr[i] != cmp.arr[i])
                    return false;
            return true;
        }
};


struct BinaryBrailleHash {
  size_t operator()(const BinaryBraille& dots) const {
    // Combine the dot values into a single integer (better approach)
    size_t hash = 0;
    for (int i = 0; i < 6; ++i) {
      // Use bitwise shift to incorporate dot values into the hash
      hash = (hash << 1) | dots.arr[i];
    }
    return hash;
  }
};

namespace BrailleMapping {

    const std::vector<std::pair<const BinaryBraille, const std::string>> mapping = {
        {BinaryBraille(),"\u2800"},
        {BinaryBraille((bool[]){1,0,0,0,0,0}),"\u2801"},
        {BinaryBraille((bool[]){1,0,0,0,0,0}),"he"},
        {BinaryBraille((bool[]){1,0,0,0,0,0}),"he"},


    };
    

    const std::unordered_map<BinaryBraille, std::string,BinaryBrailleHash> bmap(mapping.begin(),mapping.end());
}

int main(){

    
    bool arr[6] = {};

    auto b = BinaryBraille();
    b();
    auto x = BrailleMapping::bmap.at(BinaryBraille());
    std::cout << "Binary braille of 0x6: " << x<< std::endl;

    return 0;
}

