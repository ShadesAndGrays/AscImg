#include <iostream>
#include <braille.hpp>
#include <cstddef>

        BinaryBraille::BinaryBraille(){
            for ( auto &i : arr) 
                i = false;
        }
        BinaryBraille::BinaryBraille(bool val){
            for ( auto &i : arr) 
                i = val;
        }
        BinaryBraille::BinaryBraille(bool val[6]){
            for (int i = 0; i < 6; i++) 
                arr[i] = val[i];
        }
        const bool&  BinaryBraille::operator[]( int x) const{
            return arr[x];
        }

        void BinaryBraille::operator()() const{
            for(int i = 0; i < 6;i++){
                std::cout << arr[i] << ((i%2 == 0) ? "\n" : " "); 
            }
        }

        bool BinaryBraille::operator==(const BinaryBraille &cmp ) const{
            for (int i = 0; i < 6; i++) 
                if (arr[i] != cmp.arr[i])
                    return false;
            return true;
        }

size_t BinaryBrailleHash::operator()(const BinaryBraille& dots) const{
        // Combine the dot values into a single integer (better approach)
        size_t hash = 0;
        for (int i = 0; i < 6; ++i) {
            // Use bitwise shift to incorporate dot values into the hash
            hash = (hash << 1) | dots.arr[i];
        }
        return hash;
}


/* int main(){


    bool arr[6] = {1,1,1,1,1,1};

    std::cout <<     BrailleMapping::bmap.at(arr) << std::endl;

    return 0;
} */

