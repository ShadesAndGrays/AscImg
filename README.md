## AscImg
A small program to convert images to ascii art for consoles

Why you ask? 

Why not I ask?

### Usage 

```
Usage: AscImg [--help] [--version] [--scale-factor VAR] [--threshold VAR] [--ascii] [--braille] img

A cli based tool for generating ascii art from images

Positional arguments:
  img                 [nargs: 0 or more] 

Optional arguments:
  -h, --help          shows help message and exits 
  -v, --version       prints version information and exits 
  -s, --scale-factor  ratio of image size [default: 0.5]
  -t, --threshold     cutoff for light and darnkess [default: 0.5]
  -A, --ascii         
  -B, --braille 
  ```

#### Example
` AscImg -s 0.4  -t 0.3 -B /path/to/img `

### Dependencies
- CImg 3.2.6-1 Open-source C++ toolkit for image processing  
- argparse 3.0-2 Command line arguement parser  

