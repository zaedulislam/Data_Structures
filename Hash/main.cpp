#include <iostream>
#include<vector>
#include<cstring>
#include<cctype>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>

#include "hash.h"
using namespace std;

int main()
{
    hash hashObj;
    
     string name = "";
    
    hashObj.AddItem("Zayed","Lacci");
    hashObj.AddItem("Arnab","Coffee");
    hashObj.AddItem("Shamim","Beer");
    hashObj.AddItem("Pavel","Wine");
    hashObj.AddItem("Hanif","Coke");
    hashObj.AddItem("Shovon","Chai ");
    hashObj.AddItem("Susmoy","Tea");
    hashObj.AddItem("Sagor","Whisky");
    hashObj.AddItem("Tanvir","Lemonade");
    hashObj.AddItem("Arup","Wine");
    
  // hashObj.PrintItemsInIndex(9);
   // hashObj.PrintTable();
    

    while(name != "exit")
    {
        cout << "Search for";
        cin >> name;
        if(name != "exit")
            hashObj.FindDrink(name);
    }
      
    
    
    return 0;
}