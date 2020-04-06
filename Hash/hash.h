/* 
 * File:   hash.h
 * Author: Uesr
 *
 * Created on May 10, 2015, 2:15 PM
 */
#include <iostream>
#include<vector>
#include<cstring>
#include<cctype>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>

using namespace std;

#ifndef HASH_H
#define	HASH_H

class hash{
private:
    static const int tableSize = 40 ;
    
    struct item
    {
        string name;
        string drink;
        item *next;
    };
    
    item* HashTable[tableSize];
    
public:
    hash();
    int Hash(string key);
    void AddItem(string name,string drink);
    int  NumberOfItemsInIndex(int index);
    void PrintTable();
    void PrintItemsInIndex(int index);
    void FindDrink(string name);
};

#endif	/* HASH_H */

