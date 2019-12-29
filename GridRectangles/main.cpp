/*
This is a solution to the following competitive programming problem:
Given the Cartesian coordinates of a grid, how many rectangles can be
drawn in which the sides are along the x y axis.

Read in the data from Data/datapoints.txt, and print to stdout.
*/
//////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
//include all of STL, used in competitive programming for speed
using namespace std;
#define DATAPATH "Data/datapoints.txt"
//Preprocessor directives to improve code readability and make changing easier

struct Coordinate
{
  int x, y;
  friend istream& operator>>(istream& input, Coordinate& c);
};
// Custom structure to read in coordinates from datafile.
// >> stream operator overridden for this purpose.

istream& operator>>(istream& input, Coordinate& c)
{
  input >> c.x >> c.y;
  return input;
}


///////////////////////////////////////////////////////////////////////////

std::vector<Coordinate> points;
//global vector of coordinates to store grid points

void ReadData(fstream& inFile){
    Coordinate c;
    while (inFile >> c)
    {
    points.push_back(c);
    }
}
//function which reads in data and pushes it to points


int main()
{
    fstream inFile;
    inFile.open(DATAPATH);
    ReadData(inFile);
    //Read in data and push to points global
    map<pair<int,int>,int> y_pair_counter;
    //map which counts the instances of a given y pair
    //Note: in this code, two points with the same x coords
    //are considered, and so counting rectangles in equivalent
    //to counting y pairs.

    int nRectangles = 0;
    //This is a cumulative count of the answer

    for(Coordinate point1 : points){//loop 1 over points
        for(Coordinate point2 : points){//loops 2 over points
            if(point2.x == point1.x && point2.y > point1.y){
                //choose points with same x, point 2 above point 1
                pair<int,int> y_pair {point1.y,point2.y};
                //pair variable corresponding to this pair of points
                nRectangles += y_pair_counter[y_pair];
                //pairs are defaulted to 0. This is important, as when this
                //y pair is first found, there is only a single line and therefore
                //no rectangle. The NEXT time the same y pair is found for a different
                //x, then 1 is added to the nRectangles count.
                y_pair_counter[y_pair]++;
                //increment to pair value
            }

        }
    }
    cout << nRectangles;
    return 0;
}
