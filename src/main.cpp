#include <fmt/core.h>
#include <CImg.h>

using namespace cimg_library;

int to_gray_scale(const unsigned int red,const unsigned int green,const unsigned int blue){
    //  gray scale  = 0.299 ∙ Red + 0.587 ∙ Green + 0.114 ∙ Blue
    return 0.299 * red + 0.587 * green + 0.114 * blue;
}


// Would convert image to grayscale, takes the coordinates of the image
void img_to_gray_scale(CImg<unsigned char> &img){

    // Iterate over the all pixels of the image
    for (int i  = 0; i < img.width();i++){
        for(int j = 0; j < img.height(); j++){
            unsigned int red =  img(i,j,0,0);
            unsigned int blue =  img(i,j,0,1) ;
            unsigned int green  = img(i,j,0,2);
            for (int i = 0; i < 3; i++)
                img(i,j,0,i) = to_gray_scale(red, green, blue);
        }

    }
}


int main(){
    // Tempoary file path to used image
    CImg<unsigned char> image("../images/image1.jpeg");
    const unsigned char red[] = { 255,0,0 }, green[] = { 0,255,0 }, blue[] = { 0,0,255 };

    // Custom grayscale converter
    img_to_gray_scale(image);

    // Opens image in display window for preview
    CImgDisplay main_disp(image,"AscImg");
    while (!main_disp.is_closed()) {
        main_disp.wait();
    }
}
