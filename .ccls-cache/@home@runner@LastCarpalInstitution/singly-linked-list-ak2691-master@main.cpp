//
//  main.cpp
//  LLTemplate
//
//  Created by James Shockey on 12/6/16.
//  Copyright © 2016 James Shockey. All rights reserved.
//


/*
 *
 *	Linked List lab.
 *	- Build a library for singly linked list.
 *	- Replace the airport array in main with a Linked List.
 *  - sort the array. 
 *	
 */


#include <iostream>
#include <fstream>
#include <cmath> 
#include "slist.h"
#define rlat 30.1975
#define rlon -97.6664
using namespace std;
//test
class Airport
{
public:
    char    code[5];
    double   longitude;
    double   latitude;
    
};



void simpleSortTotal(List* list, List* org);



double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);


int main()
{
    ifstream infile;
    //int i=0;
    char cNum[100] ;
    List* airportList = new List();
    List* organizedList = new List();
    //List* airportHundred = new List();
    
    //Airport* airportArr[13500];			// Replace array with Linked List
    //int   airportCount;
    //double m = 0.0;
    double kmMiles = 160.934;
    //Node* maxNode = new Node();
    
    //Airport* a[13500];
    
    infile.open ("airport-codes_US.csv", ifstream::in);
    if (infile.is_open())
    {
        //int   c=0;
        string away;
        char throwaway[256];
        getline(infile, away);
        int counter = 0;
        while (infile.good())
        {
            Node* node = new Node();
            string check;
            infile.getline(node->info.code, 256, ',');
            
            getline(infile, check, ',');
            
            infile.getline(cNum, 256, ',');
            infile.getline(cNum, 256, ',');
            node->info.lon = atof(cNum);
            infile.getline(cNum, 256, ',');
            node->info.lat = atof(cNum);
            infile.getline(throwaway, 256, '\n');

            //cout << node->info.code << " long: " << node->info.lon << " lat: " << node->info.lat <<  endl;
            if(check.find("airport")!= string::npos) {
              airportList->add(node);
              
              /*if(distanceEarth(rlat, rlon,node->info.lat, node->info.lon) > m) {
                m = distanceEarth(rlat, rlon,node->info.lat, node->info.lon);
                maxNode = node;
              }
              */
              if(distanceEarth(rlat, rlon, node->info.lat, node->info.lon)<= kmMiles) {
                
                counter++;
                cout << "Number: " << counter << " " << node->info.code << " long: " << node->info.lon << " lat: " << node->info.lat <<  endl;
              }
            }
            
            
            


            
           
        }
       
        infile.close();
        
        



    }
    else
    {
        cout << "Error opening file";
    }
    
  
    
    simpleSortTotal(airportList, organizedList);
    cout << organizedList->head->info.code << " " << organizedList->head->info.lat << " " << organizedList->head->info.lon << "\n";
    


    
}



#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0


// This function converts decimal degrees to radians
double deg2rad(double deg) {
  return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
  return (rad * 180 / pi);
}


/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

void simpleSortTotal(List* list, List* org)
{
  
  

  Node* current = list->head;
  Node* nextNode;
  while(current!=nullptr) {
    nextNode = current->next;
    int counter = 0;
    Node *curr = org->head;
    
    while(curr != nullptr && distanceEarth(curr->info.lat, curr->info.lon, rlat, rlon) > distanceEarth(current->info.lat, current->info.lon, rlat, rlon)) {
      curr = curr->next;
      counter++;
    }
    org->insert(counter,current);
    current = nextNode;

    //logic: insertion sort, go through each node in list, for each node check if it is less than the next node, swap if it is. In this case, we just insert wherever the node breaks the condition
    
  }
  
 
}

/*
	Provide sort routine on linked list
*/




