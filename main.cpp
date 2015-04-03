#include "include/basic_types.h"
#include "include/bmpio.h"
#include "include/basic_geometry.h"
#include <ctime>
#include "include/drawer.h"

using namespace std;

PointT picture[width][height], picture2[width][height];
PixelColor output[width*height+10];
Polygon<PointT> p1;

double Rand1(){
  return rand()*1.0/RAND_MAX;
}

PointT RandomPoint(){
  return PointT(Rand1(),Rand1(),Rand1());
}

void Gauss(){
  memcpy(picture2, picture, sizeof picture);
  for(int i=1; i<width-1; i++)
    for(int j=1; j<height-1; j++){
      picture[i][j]=picture[i][j]*4;
      picture[i][j]+=picture[i-1][j]*2+picture[i][j-1]*2+picture[i+1][j]*2+picture[i][j+1]*2;
      picture[i][j]+=picture[i-1][j-1]+picture[i-1][j+1]+picture[i+1][j-1]+picture[i+1][j+1];
      picture[i][j]=picture[i][j]/16.0;
    }
}

int main(int argc, char **argv){

  //  DrawLine<PointT>( PointT2d(1,1), PointT2d(1000,700), picture, PointT(1.0, 1.0, 1.0) );
  //DrawLine<PointT>( PointT2d(800,700), PointT2d(200,1), picture, PointT(1.0, 1.0, 1.0), PointT(0.0, 0.0, 0.0));
  //  DrawLine<PointT>( PointT2d(500,1), PointT2d(1,700), picture, PointT(1.0, 1.0, 0.0), PointT(0.0, 1.0, 1.0));
  //  DrawLine<PointT>( PointT2d(1,700), PointT2d(1000,1), picture, PointT(1.0, 0.0, 0.0), PointT(1.0, 0.0, 1.0));

  //srand(time(0));

  p1.Add(500,1000,RandomPoint());
  p1.Add(700,600,RandomPoint());
  p1.Add(1000,650,RandomPoint());
  p1.Add(700,400,RandomPoint());
  p1.Add(700,2,RandomPoint());
  p1.Add(500,300,RandomPoint());
  p1.Add(400,2,RandomPoint());
  p1.Add(400,400,RandomPoint());
  p1.Add(1,500,RandomPoint());
  p1.Add(450,600,RandomPoint());

  //  p1.Draw(picture);

  p1.Clear();

  p1.Add(500,1, RandomPoint());
  p1.Add(1000,500, RandomPoint());
  p1.Add(500,1000, RandomPoint());
  p1.Add(1,500, RandomPoint());

  p1.Draw(picture);

  Gauss();

  for(int i=0; i<width; i++)
    for(int j=0; j<height; j++)
      output[j*width+i]=PointT::ToPixelColor(picture[i][j]);

  OutputBmp(width, height, output, "a.bmp");


  return 0;
}
 
