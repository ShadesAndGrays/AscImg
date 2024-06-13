#include <exception>
#include <iostream>
#include <math.h>
#include <stdexcept>
#include <vector>
#define cimg_display 0
#include <CImg.h>
#include <braille.hpp>
#include <argparse/argparse.hpp>

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
    argparse::ArgumentParser program("AscImg", "0.1.0");

    program.add_description("A cli based tool for generating ascii art from images");


    program.add_argument("-s","--scale-factor")
        .help("ratio of image size")
        .default_value(0.5f)
        .scan<'f', float>();


    program.add_argument("-t","--threshold")
        .help("cutoff for light and darnkess")
        .default_value(0.5f)
        .nargs(1)
        .scan<'f', float>();


    auto &style = program.add_mutually_exclusive_group();

    style.add_argument("-A","--ascii")
        .default_value(true)
        .implicit_value(true);

    style.add_argument("-B","--braille")
        .default_value(false)
        .implicit_value(true);

    program.add_argument("img")
        .nargs(argparse::nargs_pattern::at_least_one)
        .remaining();

    try{
        program.parse_args(argc,argv);

    }catch(const std::logic_error &err){
        std::cerr << err.what() << std::endl;
        std::cerr << program;
        std::exit(1);
    }catch(const std::exception& err){
        std::cerr << err.what() << std::endl;
        std::cerr << program;
        std::exit(1);
    }
    float scale_factor = program.get<float>("--scale-factor");
    float threshold = program.get<float>("--threshold");

    const unsigned char red[] = { 255,0,0 }, green[] = { 0,255,0 }, blue[] = { 0,0,255 };
    const char shade[] = {'.', ',', ':', ';', '|', '/', '$', '#', '@'};

    std::vector<std::string> images = {};
    try{
       images = program.get<std::vector<std::string>>("img");
       std::cout << "Image count: " << images.size() << std::endl;
    }catch(const std::logic_error &err){

        std::cerr <<"No images: " << err.what() <<  std::endl;
        std::cerr << program;
        std::exit(1);
    }

       std::cout << "Image count: " << images.size() << std::endl;
    for ( std::string i : images)
    { 
        // Tempoary file path to used image
        try{
            CImg<unsigned char> image(i.c_str());

            // Custom grayscale converter
            img_to_gray_scale(image);
            image.resize(image.width() * scale_factor , image.height() * scale_factor);

            if (program.get<bool>("ascii")){
                for (int i = 0; i < image.height(); i++){
                    for (int j = 0; j < image.width(); j++){
                        int value = image(j,i,0,1);
                        double valuef = value/255.0 * sizeof(shade)/sizeof(char); 
                        std::cout << shade[(int)ceil(valuef)];
                    }
                    std::cout<<std::endl;
                }
            }else if (program.get<bool>("braille")) {
                for (int i = 0; i < image.height(); i+=6){
                    for (int j = 0; j < image.width(); j+=2){
                        bool values[6] = {
                            image(j,i,0,1) >  255 * threshold,
                            image(j,i+1,0,1) >  255 * threshold,
                            image(j,i+2,0,1) >  255 * threshold,
                            image(j+1,i,0,1) >  255 * threshold,
                            image(j+1,i+1,0,1) > 255 * threshold,
                            image(j+1,i+2,0,1) > 255 * threshold,
                        };
                        std::cout << BrailleMapping::bmap.at(BinaryBraille(values));
                    }
                    std::cout<<std::endl;
                }
            }
        }catch(CImgIOException &e){
            std::cerr << "Could not find file "<< i << std::endl;
            std::cerr << "Error: " <<e.what()<< std::endl;
        }

    }
}
