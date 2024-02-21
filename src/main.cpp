#include <fmt/core.h>
#include <CImg.h>

using namespace cimg_library;

int to_gray_scale(const unsigned int red,const unsigned int green,const unsigned int blue){
    return 0.299 * red + 0.587 * green + 0.114 * blue;
}

void img_to_gray_scale(CImg<unsigned char> &img, const unsigned int x, const unsigned int y){

    unsigned int red =  img(x,y,0,0);
    unsigned int blue =  img(x,y,0,1) ;
    unsigned int green  = img(x,y,0,2);
    for (int i = 0; i < 3; i++)
        img(x,y,0,i) = to_gray_scale(red, green, blue);

}


int main(){
    CImg<unsigned char> image("../images/image1.jpeg");
    const unsigned char red[] = { 255,0,0 }, green[] = { 0,255,0 }, blue[] = { 0,0,255 };
    //0.299 ∙ Red + 0.587 ∙ Green + 0.114 ∙ Blue
    for (int i  = 0; i < image.width();i++){
        for(int j = 0; j < image.height(); j++)
            img_to_gray_scale(image,i ,j);
    }
    

    CImgDisplay main_disp(image,"AscImg");
    while (!main_disp.is_closed()) {
        main_disp.wait();
    }
    fmt::println("Hello world");
}
