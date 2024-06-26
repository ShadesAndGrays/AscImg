
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>


class BinaryBraille{
    public:
        bool arr[6];
        BinaryBraille();
        BinaryBraille(bool val);
        BinaryBraille(bool val[6]);
        const bool&  operator[]( int x) const;
        void operator()() const;
        bool operator==(const BinaryBraille &cmp ) const;

};

struct BinaryBrailleHash {
    size_t operator()(const BinaryBraille& dots) const;
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
