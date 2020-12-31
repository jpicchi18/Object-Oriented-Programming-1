//
//  main.cpp
//  array
//
//  Created by Joseph Picchi on 2/14/19.
//  Copyright © 2019 Joseph Picchi. All rights reserved.
//

#include <iostream>
#include <string>
#include <cassert>
#include <cctype>
using namespace std;

//declaring the functions:
bool hasDuplicates( const string array[ ],  int size );
int  countAllDigits( const string array[ ] , int size );
bool isInDecreasingOrder( const string array[ ], int size );
int  shiftRight( string array[ ], int size, int amount, string placeholder );
int  find( const string array[ ], int size, string match );
int  replaceAllCharacters( string array[ ], int size, char findLetter, char replaceLetter );

int main() {
    // insert code here...
    string folks[8] = {"samwell", "jon", "margaery", "daenerys","tyrion", "sansa", "howard123", "jon"};
    string food[21] = {"sa02sa1", "hound", "", "1m3e4at","chee6se", "fish"};
    string allLetters[4] = {"math", "science", "bread", "water"};
    string isDecreasingOrder[5] = {"Elephant", "Dogggggggggg", "Catttt", "Betafish", "Ant"};
    string also[6] = {"z", "oh", "R", "&&&&", "&", "\0"};
    string alsoDecreasing[6] = {"zeta", "zet", "mze", "mpe","123", ""};
    string shiftTest[6] = {"foo", "zeta", "foo", "cat", "dog"};
    string findTest[6] = {"foo", "test", "foo", " ", "", "test"};
    
    //testing the hasDuplicates function:
    assert(!hasDuplicates(folks, 5));
    assert(hasDuplicates(folks, 8));
    assert(!hasDuplicates(folks, 7));
    assert(hasDuplicates(food, 21));
    assert(!hasDuplicates(food, -1));
    assert(!hasDuplicates(food, 0));
    assert(hasDuplicates(food, 10));
    assert(!hasDuplicates(folks, 0));
    assert(!hasDuplicates(folks, -1));
    
    //testing the countAllDigits function:
    assert(isdigit('5'));
    assert(countAllDigits(folks, 8) == 3);
    assert(countAllDigits(food, 21) == 7);
    assert(countAllDigits(food, 0) == -1);
    assert(countAllDigits(food, -121) == -1);
    assert(countAllDigits(allLetters, 4) == 0);
    assert(countAllDigits(folks, -3) == -1);
    assert(countAllDigits(folks, 0) == -1);
    
    //testing the IsInDecreasingOrder function:
    assert(isInDecreasingOrder(isDecreasingOrder, 5));
    assert(!isInDecreasingOrder(isDecreasingOrder, -1));
    assert(!isInDecreasingOrder(food, 21));
    assert(isInDecreasingOrder(food, 0));
    assert(isInDecreasingOrder(food, 1));
    assert(isInDecreasingOrder(alsoDecreasing, 6));
    assert(isInDecreasingOrder(also, 6));
    assert(!isInDecreasingOrder(alsoDecreasing, -24));
    
    //testing the shiftRight function:
    assert(shiftRight(food, -2, 3, "hello") == -1);
    assert(shiftRight(food, 0, -2, "hello") == -1);
    assert(shiftRight(folks, 8, 3, "hello") == 3);
    assert(folks[0] == "hello");
    assert(folks[1] == "hello");
    assert(folks[2] == "hello");
    assert(folks[3] == "samwell");
    assert(folks[4] == "jon");
    assert(folks[5] == "margaery");
    assert(folks[6] == "daenerys");
    assert(folks[7] == "tyrion");
    assert(shiftRight(food, 21, 16, "hi") == 16);
    assert(shiftRight(food, 0, 16, "hi") == 0);
    assert(shiftRight(isDecreasingOrder, 2, 10, "hi") == 2);
    assert(shiftRight(food, 21, 0, "hi") == 0);
    assert(shiftRight(allLetters, 3, 4, "hello") == 3);
    assert(shiftRight(shiftTest, 6, 4, "foo") == 4);
    
    //testing find function:
    assert(find(findTest, 6, "foo") == 0);
    assert(find(findTest, 0, "foo") == -1);
    assert(find(findTest, -1, "foo") == -1);
    assert(find(findTest, 6, "dog") == -1);
    assert(find(findTest, 6, "test") == 1);
    assert(find(folks, 5, "foo") == -1);
    
    //resetting all the test arrays:
    string folksN[8] = {"samwell", "jon", "margaery", "daenerys","tyrion", "sansa", "howard123", "jon"};
    string foodN[21] = {"sa32sa1", "fish", "", "1m3e4at","chee6se", "fish"};
    string allLettersN[4] = {"math", "science", "bread", "water"};
    string isDecreasingOrderN[5] = {"Elephant", "Dogggggggggg", "Catttt", "Betafish", "Ant"};
    string alsoDecreasingN[6] = {"zeta", "zet", "mze", "mpe","123", ""};
    string shiftTestN[6] = {"foo", "zeta", "foo", "cat", "dog"};
    string findTestN[6] = {"foo", "test", "foo", " ", "", "test"};
    
    //testing the replaceAllCharacters function
//    assert
    assert(replaceAllCharacters(folksN, 5, 'a', '_') == 4);
    assert(folksN[0][1] == '_' && folksN[2][1] == '_' && folksN[2][4] == '_' && folksN[3][1] == '_' && folksN[0][2] == 'm');
    assert(folksN[2] == "m_rg_ery");
    assert(replaceAllCharacters(foodN, 0, 'a', '_') == -1);
    assert(replaceAllCharacters(foodN, -25, 'a', '_') == -1);
    assert(replaceAllCharacters(foodN, 21, '2', '?') == 1);
    assert(foodN[0][2] == '3');
    assert(foodN[0][3] == '?');
    assert(foodN[0] == "sa3?sa1");
    assert(foodN[4] == "chee6se");
    assert(replaceAllCharacters(folks, 0, 'a', '_') == -1);
    assert(replaceAllCharacters(folks, -25, 'a', '_') == -1);
    assert(replaceAllCharacters(folks, 8, '3', '_') == 0);
    
    //makes sure the program reaches the end
    cout << "all tests successful!" << endl;
    return 0;
}


//Definition of hasDuplicates begins here:
bool hasDuplicates( const string array[ ],  int size )
{
    if (size <= 0)
        return false;
    
    for (int i = 0; i < size; i++)
    {
        for (int k = 0; k < size; k++)
        {
            if (i != k  && array[i] == array[k])
                return true;
        }
    }
    
    return false;
}
//end of hasDuplicates function


//countAllDigits defined below:
int  countAllDigits( const string array[ ] , int size )
{
    int counter = 0;
    
    if (size <= 0)
        return -1;
    
    for (int i = 0; i < size; i++)
    {
        string element = array[i];
        
        //allows us to loop through each string element of the array:
        for (int k = 0; k < element.size(); k++)
        {
            if (isdigit(element[k]))
            {
                counter++;
            }
        }
    }
    
    return counter;
}
//end of the countAllDigits function


//isIncreasingOrder function defined below
bool isInDecreasingOrder( const string array[ ], int size )
{
    //makes sure standard conditions are met;
    if (size < 0)
        return false;
    else if (size  == 0 || size  == 1)
        return true;
    
    string lastElement = array[0];
    
    for (int i = 1; i < size; i++)
    {
        string newElement = array[i];
        
        if ( !(newElement < lastElement) )
            return false;
        
        lastElement = newElement;
    }
    
    return true;
}
//end of IsInDecreasingOrder function


//shiftRight function defined below
int  shiftRight( string array[ ], int size, int amount, string placeholder )
{
    int addedPlaceholders = 0;
    
    if (size < 0 || amount < 0)
        return -1;
    else if (size == 0 || amount == 0)
        return 0;
        
    //loops through array from right to left and moves entries if it can
    for (int i = size-1; i >= 0; i--)
    {
        if ((i + amount) < size)
        {
            array[i+amount] = array[i];
            array[i] = placeholder;
        }
        else
        {
            array[i] = placeholder;
        }
    }
    
    //conditions for counting the added placeholders after shifting is completed
    if (amount <= size)
        addedPlaceholders = amount;
    else if (amount > size)
        addedPlaceholders = size;
    
    return addedPlaceholders;
}
// end of shiftRight function


// find function defined below:
int  find( const string array[ ], int size, string match )
{
    int smallestIndex = 0;
    int count = 0;
    
    //checks if array size is valid
    if (size <= 0)
        return -1;
    
    //loops through string and checks for a match
    for (int i = 0; i < size; i++)
    {
        if (array[i] == match)
        {
            count++;
            smallestIndex = i;
            break;
        }
    }
    
    if (count <= 0)
        return -1;
    else
        return smallestIndex;
}
//end of find function


//replaceAllCharacters function defined below
int  replaceAllCharacters( string array[ ], int size, char findLetter, char replaceLetter )
{
    int numberReplaced = 0;
    
    if (size <= 0)
        return -1;
    
    for (int i = 0; i < size; i++)
    {
        for (int k = 0; k < array[i].size(); k++)
        {
            if (array[i][k] == findLetter)
            {
                array[i][k] = replaceLetter;
                numberReplaced++;
            }
        }
    }
    
    return numberReplaced;
}
//end of replaceAllCharacters function
