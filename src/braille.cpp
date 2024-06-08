#include <charconv>
#include <iostream>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <sstream>

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
        {BinaryBraille((bool[]){0 , 0 , 0 , 0 , 0 , 0 }),"\u2800"},
        {BinaryBraille((bool[]){1 , 0 , 0 , 0 , 0 , 0 }),"\u2801"},
        {BinaryBraille((bool[]){0 , 1 , 0 , 0 , 0 , 0 }),"\u2802"},
        {BinaryBraille((bool[]){1 , 1 , 0 , 0 , 0 , 0 }),"\u2803"},
        {BinaryBraille((bool[]){0 , 0 , 1 , 0 , 0 , 0 }),"\u2804"},
        {BinaryBraille((bool[]){1 , 0 , 1 , 0 , 0 , 0 }),"\u2805"},
        {BinaryBraille((bool[]){0 , 1 , 1 , 0 , 0 , 0 }),"\u2806"},
        {BinaryBraille((bool[]){1 , 1 , 1 , 0 , 0 , 0 }),"\u2807"},
        {BinaryBraille((bool[]){0 , 0 , 0 , 1 , 0 , 0 }),"\u2808"},
        {BinaryBraille((bool[]){1 , 0 , 0 , 1 , 0 , 0 }),"\u2809"},
        {BinaryBraille((bool[]){0 , 1 , 0 , 1 , 0 , 0 }),"\u280A"},
        {BinaryBraille((bool[]){1 , 1 , 0 , 1 , 0 , 0 }),"\u280B"},
        {BinaryBraille((bool[]){0 , 0 , 1 , 1 , 0 , 0 }),"\u280C"},
        {BinaryBraille((bool[]){1 , 0 , 1 , 1 , 0 , 0 }),"\u280D"},
        {BinaryBraille((bool[]){0 , 1 , 1 , 1 , 0 , 0 }),"\u280E"},
        {BinaryBraille((bool[]){1 , 1 , 1 , 1 , 0 , 0 }),"\u280F"},
        {BinaryBraille((bool[]){0 , 0 , 0 , 0 , 1 , 0 }),"\u2810"},
        {BinaryBraille((bool[]){1 , 0 , 0 , 0 , 1 , 0 }),"\u2811"},
        {BinaryBraille((bool[]){0 , 1 , 0 , 0 , 1 , 0 }),"\u2812"},
        {BinaryBraille((bool[]){1 , 1 , 0 , 0 , 1 , 0 }),"\u2813"},
        {BinaryBraille((bool[]){0 , 0 , 1 , 0 , 1 , 0 }),"\u2814"},
        {BinaryBraille((bool[]){1 , 0 , 1 , 0 , 1 , 0 }),"\u2815"},
        {BinaryBraille((bool[]){0 , 1 , 1 , 0 , 1 , 0 }),"\u2816"},
        {BinaryBraille((bool[]){1 , 1 , 1 , 0 , 1 , 0 }),"\u2817"},
        {BinaryBraille((bool[]){0 , 0 , 0 , 1 , 1 , 0 }),"\u2818"},
        {BinaryBraille((bool[]){1 , 0 , 0 , 1 , 1 , 0 }),"\u2819"},
        {BinaryBraille((bool[]){0 , 1 , 0 , 1 , 1 , 0 }),"\u281A"},
        {BinaryBraille((bool[]){1 , 1 , 0 , 1 , 1 , 0 }),"\u281B"},
        {BinaryBraille((bool[]){0 , 0 , 1 , 1 , 1 , 0 }),"\u281C"},
        {BinaryBraille((bool[]){1 , 0 , 1 , 1 , 1 , 0 }),"\u281D"},
        {BinaryBraille((bool[]){0 , 1 , 1 , 1 , 1 , 0 }),"\u281E"},
        {BinaryBraille((bool[]){1 , 1 , 1 , 1 , 1 , 0 }),"\u281F"},
        {BinaryBraille((bool[]){0 , 0 , 0 , 0 , 0 , 1 }),"\u2820"},
        {BinaryBraille((bool[]){1 , 0 , 0 , 0 , 0 , 1 }),"\u2821"},
        {BinaryBraille((bool[]){0 , 1 , 0 , 0 , 0 , 1 }),"\u2822"},
        {BinaryBraille((bool[]){1 , 1 , 0 , 0 , 0 , 1 }),"\u2823"},
        {BinaryBraille((bool[]){0 , 0 , 1 , 0 , 0 , 1 }),"\u2824"},
        {BinaryBraille((bool[]){1 , 0 , 1 , 0 , 0 , 1 }),"\u2825"},
        {BinaryBraille((bool[]){0 , 1 , 1 , 0 , 0 , 1 }),"\u2826"},
        {BinaryBraille((bool[]){1 , 1 , 1 , 0 , 0 , 1 }),"\u2827"},
        {BinaryBraille((bool[]){0 , 0 , 0 , 1 , 0 , 1 }),"\u2828"},
        {BinaryBraille((bool[]){1 , 0 , 0 , 1 , 0 , 1 }),"\u2829"},
        {BinaryBraille((bool[]){0 , 1 , 0 , 1 , 0 , 1 }),"\u282A"},
        {BinaryBraille((bool[]){1 , 1 , 0 , 1 , 0 , 1 }),"\u282B"},
        {BinaryBraille((bool[]){0 , 0 , 1 , 1 , 0 , 1 }),"\u282C"},
        {BinaryBraille((bool[]){1 , 0 , 1 , 1 , 0 , 1 }),"\u282D"},
        {BinaryBraille((bool[]){0 , 1 , 1 , 1 , 0 , 1 }),"\u282E"},
        {BinaryBraille((bool[]){1 , 1 , 1 , 1 , 0 , 1 }),"\u282F"},
        {BinaryBraille((bool[]){0 , 0 , 0 , 0 , 1 , 1 }),"\u2830"},
        {BinaryBraille((bool[]){1 , 0 , 0 , 0 , 1 , 1 }),"\u2831"},
        {BinaryBraille((bool[]){0 , 1 , 0 , 0 , 1 , 1 }),"\u2832"},
        {BinaryBraille((bool[]){1 , 1 , 0 , 0 , 1 , 1 }),"\u2833"},
        {BinaryBraille((bool[]){0 , 0 , 1 , 0 , 1 , 1 }),"\u2834"},
        {BinaryBraille((bool[]){1 , 0 , 1 , 0 , 1 , 1 }),"\u2835"},
        {BinaryBraille((bool[]){0 , 1 , 1 , 0 , 1 , 1 }),"\u2836"},
        {BinaryBraille((bool[]){1 , 1 , 1 , 0 , 1 , 1 }),"\u2837"},
        {BinaryBraille((bool[]){0 , 0 , 0 , 1 , 1 , 1 }),"\u2838"},
        {BinaryBraille((bool[]){1 , 0 , 0 , 1 , 1 , 1 }),"\u2839"},
        {BinaryBraille((bool[]){0 , 1 , 0 , 1 , 1 , 1 }),"\u283A"},
        {BinaryBraille((bool[]){1 , 1 , 0 , 1 , 1 , 1 }),"\u283B"},
        {BinaryBraille((bool[]){0 , 0 , 1 , 1 , 1 , 1 }),"\u283C"},
        {BinaryBraille((bool[]){1 , 0 , 1 , 1 , 1 , 1 }),"\u283D"},
        {BinaryBraille((bool[]){0 , 1 , 1 , 1 , 1 , 1 }),"\u283E"},
        {BinaryBraille((bool[]){1 , 1 , 1 , 1 , 1 , 1 }),"\u283F"},

    };


    const std::unordered_map<BinaryBraille, std::string,BinaryBrailleHash> bmap(mapping.begin(),mapping.end());
}

int main(){


    bool arr[6] = {1,1,1,1,1,1};

    std::cout <<     BrailleMapping::bmap.at(arr) << std::endl;

    // auto x = BrailleMapping::bmap.at(BinaryBraille());

    // std::cout << "Binary braille of 0x6: " << x<< std::endl;

    return 0;
}

