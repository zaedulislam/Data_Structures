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

hash::hash()
{
    for(int i = 0; i < tableSize; i++)
    {
        HashTable[i] = new item;
        HashTable[i]->name = "empty";
        HashTable[i]->drink = "empty";
        HashTable[i]->next =  NULL;
    }
}

void hash::AddItem(string name,string drink)
{
    int index = Hash(name);
    
    if(HashTable[index]->name == "empty")
    {
        HashTable[index]->name = name;
        HashTable[index]->drink = drink;
    }
    else
    {
      item* Ptr = HashTable[index];
      item* temp = new item;
      
      temp->name = name;
      temp->drink = drink;
      temp->next = NULL;
      while(Ptr->next != NULL)
      {
          Ptr = Ptr ->next;
      }
      Ptr->next = temp;
    }
    
}

int hash::NumberOfItemsInIndex(int index)
{
    int count = 0;
    
    if(HashTable[index]->name == "empty")
        return count;
    else
    {
        count++;
        item* Ptr = HashTable[index];
        while(Ptr->next != NULL)
        {
            count++;
            Ptr = Ptr->next;
        }
    }
    return count;
}

void hash::PrintTable()
{
    int number;
    for(int i = 0; i < tableSize; i++)
    {
        number = NumberOfItemsInIndex(i);
        cout << "..........................................\n";
        cout << "index = " << i << endl;
        cout << HashTable[i]->name << endl;
        cout << HashTable[i]->drink << endl;
        cout << "# of items = " << number << endl;;
        cout <<"..........................................\n";
                
    }
}

void hash::PrintItemsInIndex(int index)
{
    item* Ptr = HashTable[index];

    if(Ptr->name == "empty")
        cout << "Index = " << index << " is Empty" << endl;
    else
    {
        cout << "Index " << index << " contains the following item" << endl;

    while(Ptr != NULL)
    {
        cout << "..........................................\n";
        cout << Ptr->name << endl;
        cout << Ptr->drink << endl;
        cout << "..........................................\n";
        Ptr = Ptr->next;
    }
}

}

int hash::Hash(string key)
{
    int hash = 0;
    int index;
    
    for(int i = 0; i < key.length(); i++)
        hash = (hash + (int)key[i]) * 3;

     
    index = hash % tableSize;
   
    return index;
}

void hash::FindDrink(string name)
{
    int index = Hash(name);
    bool foundName = false;
    string drink;
    
    item* Ptr = HashTable[index];
    while(Ptr != NULL)
    {
        if(Ptr->name == name)
        {
            foundName = true;
            drink = Ptr->drink;
            
        }
        Ptr =  Ptr->next;
    }
    
    if(foundName == true)
        cout << "Favourite drink = " << drink << endl;
    else
        cout << name << "'s info was not found in the Hash Table" << endl;
    
}