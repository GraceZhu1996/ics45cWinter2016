#include "MapArray.h"
#include "SetList.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iterator>
using namespace std;

int main(){
    MapArray<string, int> myMap;
    SetList<string> mySet;
    ifstream in_sample("sample_doc.txt");
    ifstream in_stop("stopwords.txt");
    for_each( istream_iterator<string>(in_stop),
              istream_iterator<string>(),
              [&](string s1){
                  mySet.insert(s1);
              });
    mySet.print();
    

        for_each( istream_iterator<string>(in_sample),
              istream_iterator<string>(),
              [&](string s2){
                  string s3(s2);
                  transform(s2.begin(), s2.end(), s3.begin(), ::tolower);

                  if( mySet.find(s3) == mySet.end() )
                  {
                      myMap[s2] += 1;
                  }

              });
    ofstream freq;
    freq.open("frequency.txt");
    for (auto  E: myMap){
        cout << E.first << ": " << E.second << endl;
        freq << E.first << ": " << E.second << endl;
    }
    cout << endl;
    freq.close();
    return 0;
}
