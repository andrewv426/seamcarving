#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using std::cout, std::endl, std::string;

void initializeImage(Pixel image[][MAX_HEIGHT]) {
  // iterate through columns
  for (unsigned int col = 0; col < MAX_WIDTH; col++) {
    // iterate through rows
    for (unsigned int row = 0; row < MAX_HEIGHT; row++) {
      // initialize pixel
      image[col][row] = {0, 0, 0};
    }
  }
}

void loadImage(string filename, Pixel image[][MAX_HEIGHT], unsigned int& width, unsigned int& height) {
  // TODO: implement (part 1)
  std::ifstream ppmFile(filename);
  if (!ppmFile.is_open()){
    throw std::runtime_error("Failed to open " + filename);
  }
  std::string fileType;
   ppmFile >> fileType;
  if (!(fileType == "P3" || fileType == "p3")) {
  throw std::runtime_error("Invalid type " + fileType);
}
  unsigned int maxColorVal;
  ppmFile >> width >> height >> maxColorVal;
  if (!((width > 0 && width <= 1920) && (height > 0 && height <= 1080))) {
    throw std::runtime_error("Invalid dimensions");
  }
  if (maxColorVal != 255) {
    throw std::runtime_error("Invalid max color value");
  }
  for (unsigned int row = 0; row < height; row++) {
    for (unsigned int col = 0; col < width; col++) {
      short r = -1, g = -1, b = -1;
      ppmFile >> r >> g >> b;
    if ((r >= 0 && r <=255) && (g >= 0 && g <= 255) && (b >= 0 && b <= 255)) {
      image[col][row] = {r, g, b};
    }
    else if (r == -1 || g == -1 || b == -1){
      throw std::runtime_error("Not enough values");
    }
    else {
      throw std::runtime_error("Invalid color value");
    }
  }
}
    short extra = -1;
    ppmFile >> extra;
    if (extra != -1) {
      throw std::runtime_error("Too many values");
    }
}

void outputImage(string filename, Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height) {
  // TODO: implement (part 1)
  std::ofstream ppmFile(filename);
  if (!ppmFile.is_open()){
    throw std::runtime_error("Failed to open " + filename);
  }
  ppmFile << "P3" << endl;
  ppmFile << width << " " << height << endl;
  ppmFile << "255" << endl;
  for (unsigned int row = 0; row < height; row++) {
    for(unsigned int col = 0; col < width; col++) {
      ppmFile << image[col][row].r << endl;
      ppmFile << image[col][row].g << endl;
      ppmFile << image[col][row].b << endl;
    }
  }

}

unsigned int energy(Pixel image[][MAX_HEIGHT], unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
  // TODO: implement (part 1)
  //if we're at the border we grab from the opp side, iterate for loop row/col, if row = 0 or row = height-1 apply special edge case
  int newColPlus, newColMinus;
      if(x == 0) {
        newColMinus = width-1;
        newColPlus = x + 1;
      }
      else if (x == width -1) {
        newColMinus = x-1;
        newColPlus = 0;
      }
      else {
        newColMinus = x-1;
        newColPlus = x +1;
      }
     int redCalcX = abs(image[newColPlus][y].r - image[newColMinus][y].r);
     int greenCalcX = abs(image[newColPlus][y].g - image[newColMinus][y].g);
     int blueCalcX = abs(image[newColPlus][y].b - image[newColMinus][y].b);
    int xEnergy = redCalcX*redCalcX + greenCalcX*greenCalcX + blueCalcX*blueCalcX;
   int newRowPlus, newRowMinus;
      if(y == 0) {
        newRowMinus = height-1;
        newRowPlus = y + 1;
      }
      else if (y == height -1) {
        newRowMinus = y-1;
        newRowPlus = 0;
      }
      else {
        newRowMinus = y-1;
        newRowPlus = y +1;
      }
     int redCalcY = abs(image[x][newRowPlus].r - image[x][newRowMinus].r);
     int greenCalcY = abs(image[x][newRowPlus].g - image[x][newRowMinus].g);
     int blueCalcY = abs(image[x][newRowPlus].b - image[x][newRowMinus].b);
    int yEnergy = redCalcY*redCalcY + greenCalcY*greenCalcY + blueCalcY*blueCalcY;
     return xEnergy + yEnergy;
     

}

// uncomment functions as you implement them (part 2)

// unsigned int loadVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int start_col, unsigned int width, unsigned int height, unsigned int seam[]) {
//   // TODO: implement (part 2)
//   return 0;
// }

// unsigned int loadHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int start_row, unsigned int width, unsigned int height, unsigned int seam[]) {
//   // TODO: implement (part 2)
//   return 0;
// }

// void findMinVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height, unsigned int seam[]) {
//   // TODO: implement (part 2)
// }

// void findMinHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height, unsigned int seam[]) {
//   // TODO: implement (part 2)
// }

// void removeVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int& width, unsigned int height, unsigned int verticalSeam[]) {
//   // TODO: implement (part 2)
// }

// void removeHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int& height, unsigned int horizontalSeam[]) {
//   // TODO: implement (part 2)
// }
