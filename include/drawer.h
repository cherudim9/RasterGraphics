#ifndef DRAWER_H_
#define DRAWER_H_

#include "basic_geometry.h"
#include <vector>

template<class T>
void DrawLine(const PointT2d &end1, const PointT2d &end2, T result[width][height], T color1, T color2){
  int dx = end2.GetX() - end1.GetX(), dy = end2.GetY() - end1.GetY();
  int x = end1.GetX(), y = end1.GetY();
  T dcolor = ( color2 - color1 ) / Max ( Abs(dx), Abs(dy) ), color=color1;
  if ( Abs(dx) > Abs(dy) ){
    if (dx<0){
      DrawLine<T>(end2, end1, result, color2, color1);
      return;
    }
    int e=-dx;
    for(int i=0; i<=dx; i++){
      result[x][y] += color;
      color+=dcolor;
      x++;
      e+=2*Abs(dy);
      if (e>=0){
	if (dy>0) y++; else y--;
	e-=2*dx;
      }
    }
  }else{
    if (dy<0){
      DrawLine<T>(end2, end1, result, color2, color1);
      return;
    }
    int e=-dy;
    for(int i=0; i<=dy; i++){
      result[x][y] += color;
      color+=dcolor;
      y++;
      e+=2*Abs(dx);
      if (e>=0){
	if (dx>0) x++; else x--;
	e-=2*dy;
      }
    }
  }
}

template<class T>
void DrawLine(const PointT2d &end1, const PointT2d &end2, T result[width][height], T color1){
  DrawLine<T>(end1, end2, result, color1, color1);
}

bool tmp[width][height];

template<class T>
class Polygon{

 public:

  void Clear(){
    point_array.clear();
    info_array.clear();
  }
  
  void Add(int x, int y, T info){
    point_array.push_back(PointT2d(x,y));
    info_array.push_back(info);
  }

  void Draw(T result[width][height]){
    memset(tmp, 0, sizeof tmp);
    int n=point_array.size();

    for(int i=0; i<n; i++){
      int j=i+1;
      if (j==n) j=0;
      DrawLine(point_array[i], point_array[j], tmp, true);
      DrawLine(point_array[i], point_array[j], result, PointT(0.0, 1.0, 0.0));
      DrawLine(point_array[i], point_array[j], tmp1, info_array[i], info_array[j]);
    }

    for(int i=0; i<width; i++)
      for(int j=0; j<height-1;)
	if (tmp[i][j] && !tmp[i][j+1]){
	  int k=j+2;
	  while(k<height && !tmp[i][k]) k++;
	  if (k==height){
	    j=k+1;
	    continue;
	  }
	  T curT=tmp1[i][j], dT=(tmp1[i][k]-tmp1[i][j])/(k-j);
	  //	  printf("%d\n",k-j);
	  for(int y=j; y<=k; y++){
	    result[i][y]=curT;
	    curT+=dT;
	  }
	  j=k+1;
	  while(j<height && tmp[i][j]){
	    result[i][j]=tmp1[i][j];
	    j++;
	  }
	}else{
	  if (tmp[i][j]){
	    result[i][j]=tmp1[i][j];
	  }
	  j++;
	}

    for(int j=0; j<height; j++)
      for(int i=0; i<width-1;)
	if ((i==0 || !tmp[i-1][j]) && tmp[i][j] && !tmp[i+1][j]){
	  int k=i+2;
	  while(k<width && !tmp[k][j]) k++;
	  if (k==width){
	    i=k+1;
	    continue;
	  }
	  T curT=tmp1[i][j], dT=(tmp1[k][j]-tmp1[i][j])/(k-i);
	  for(int x=i; x<=k; x++){
	    //result[x][j]=curT;
	    curT+=dT;
	  }
	  i=k+1;
	}else{
	  i++;
	}
  }

  T tmp1[width][height];

 private:

  std::vector<PointT2d> point_array;
  std::vector<T> info_array;

};

#endif
