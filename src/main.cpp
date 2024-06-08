#include <cstdio>
#include <iostream>
#include <math.h>
#include <stdexcept>
#include <vector>
#define cimg_display 0
#include <CImg.h>
#include <braille.hpp>

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
            for (int k = 0; k < 3; k++)
                img(i,j,0,k) = to_gray_scale(red, green, blue);
        }

    }
}

int main(int argc, char** argv){
    printf("\u0280");
        float scale_factor = 0.5f;
        std::vector<std::string> options(argv + 1, argv + argc);   

      if (std::find(options.begin(), options.end(), "--help") != options.end() ||
        std::find(options.begin(), options.end(), "-h") != options.end()) {
        std::cout << "Usage: AscImg [OPTION] [FILE]..." << std::endl;
        std::cout << "Example: AscImg --scale-factor 0.5 meme.jpg" << std::endl;
        return 0;
    }

      auto scale_factor_it = std::find(options.begin(),options.end(),"--scale-factor");
        if (scale_factor_it != options.end()){
            if (scale_factor_it + 1 == options.end()){
            std::cerr << "Error: Missing value for scale factor" << std::endl;
            return 1;
            }

            try {
               scale_factor = std::stof(*(scale_factor_it +1));
            }catch(const std::invalid_argument e){
                std::cerr << "Error: Invalid argument for scale factor"<< std::endl;
                return 1;
            }
            
        }
        else{
            std::cerr << "Error: Missing scale factor argument"<< std::endl;
            return 1;
        }
        options.erase(scale_factor_it, scale_factor_it + 2);
        if (options.empty()){
            std::cerr << "Error: No images we given" << std::endl;
            return 0;
        }

        for ( std::string i :options)
        { 
            // Tempoary file path to used image
            try{
                CImg<unsigned char> image(i.c_str());
                const unsigned char red[] = { 255,0,0 }, green[] = { 0,255,0 }, blue[] = { 0,0,255 };

                // Custom grayscale converter
                img_to_gray_scale(image);
                image.resize(image.width() * scale_factor , image.height() * scale_factor);


                char shade[] = {'.', ',', ':', ';', '|', '/', '$', '#', '@'};

                for (int i = 0; i < image.height(); i++){
                    for (int j = 0; j < image.width(); j++){
                        int value = image(j,i,0,1);
                        double valuef = value/255.0 * sizeof(shade)/sizeof(char); 
                        std::cout << shade[(int)ceil(valuef)];
                    }
                    std::cout<<std::endl;
                }
                for (int i = 0; i < image.height(); i+=6){
                    for (int j = 0; j < image.width(); j+=2){
                        bool values[6] = {
                            image(j,i,0,1) > 60,
                            image(j,i+1,0,1) > 60,
                            image(j,i+2,0,1) > 60,
                            image(j+1,i,0,1) > 60,
                            image(j+1,i+1,0,1) >60,
                            image(j+1,i+2,0,1) >60,
                        };
                        std::cout << BrailleMapping::bmap.at(BinaryBraille(values));
                    }
                    std::cout<<std::endl;
                }

            }catch(CImgIOException &e){
                std::cerr << "Could not find file "<< i << std::endl;
                std::cerr << "Error: " <<e.what()<< std::endl;
            }

        }
}
