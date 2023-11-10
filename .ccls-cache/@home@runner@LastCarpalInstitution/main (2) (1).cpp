#include <iostream>
#include <fstream>
using namespace std;
class Sales {
  private:
    string date;
    string region;
    string rep;
    string item;
    int units;
    float unitCost;
    float total;
    string first;
    
  public:
    void setTotal();
    float getTotal() {return total;}
    void setDate(char a[20]) {date = &a[0];}
    string getDate() {return date;}
    void setRegion(char a[20]) {region = &a[0];}
    string getRegion() {return region;}
    void setRep(char a[20]) {rep = &a[0];}
    string getRep() {return rep;}
    void setItem(char a[20]) {item = &a[0];}
    string getItem() {return item;}
    void setUnits(int u) {units = u;}
    int getUnits() {return units;}
    void setUnitCost(float a) {unitCost = a;}
    float getUnitCost() {return unitCost;}
    void setFirst(string a) { first += a;}
    string getFirst() {return first;}
    
    


};

void Sales::setTotal() {
  total = units * unitCost;
}
void simpleSortTotal(Sales* a[] , int c)
{
	
	for (int i=0; i < c; i++)
		for (int j=i; j < c; j++)
		if (a[i]->getTotal() < a[j]->getTotal())
		{
			Sales* temp;
      temp = a[j];
      
      a[j] = a[i];
      a[i] = temp;
      
		}
}
int main() {
  
  Sales saledata[31];
  Sales* s[31];
  int ssize = 30;
  char input[20];
  string line;
  float fin;
  int iin;
  int i = 0;
  int idx = 1;
  ifstream data;
  data.open("SalesDataPt2.csv");
  if(data.is_open()){
    while(data.good()) {
      if(i == 0) {
        getline(data, line, ' ');
        saledata[0].setFirst(line);
        
        
        getline(data, line, ' ');
        
        saledata[0].setFirst(line);
        getline(data, line, ' ');
      
        saledata[0].setFirst(line);
        getline(data, line, ' ');
        saledata[0].setFirst(line);
        getline(data, line, ' ');
        saledata[0].setFirst(line);
        getline(data, line, '\n');
        saledata[0].setFirst(line);
        saledata[0].setFirst(",Total");
       
        i++;
      }
      else {
        data.getline(input, 256, ',');
        saledata[i].setDate(input);
        getline(data, line, ' ');
        
        data.getline(input, 256, ',');
        saledata[i].setRegion(input);
        getline(data, line, ' ');
        data.getline(input, 256, ',');
        
        saledata[i].setRep(input);
        getline(data, line, ' ');
        data.getline(input, 256, ',');
        saledata[i].setItem(input);
        
        data.getline(input,256,',');
        iin = atoi(input);
        saledata[i].setUnits(iin);
        data.getline(input, 256, '\n');
        fin = atof(input);
        saledata[i].setUnitCost(fin);
        
        saledata[i].setTotal();
        i++;
      }
      
      
      
      
    }
    data.close();
  }
  for(int i = 0; i<ssize; i++) {
    s[i] = &saledata[idx];
    idx++;
  }
  simpleSortTotal(s, ssize);
  cout << saledata[0].getFirst() << "\n";
  for(int i = 0; i<ssize; i++) {
    cout << s[i]->getDate() << "," << s[i]->getRegion() << "," << s[i]->getRep() << "," << s[i]->getItem() << "," << s[i]->getUnits() << "," << s[i]->getUnitCost() << "," << s[i]->getTotal() << "\n";
  }
}