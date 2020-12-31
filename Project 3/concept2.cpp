//
//  main.cpp
//  concept2
//
//  Created by Joseph Picchi on 2/1/19.
//  Copyright © 2019 Joseph Picchi. All rights reserved.
//

#include <iostream>
#include <string>
#include <cassert>
#include <cctype>
using namespace std;

int stringToNumber( string s, int& startingPosition);
bool isValidRowerString(string rowerString);
int totalDistance(string rowerString);
int locateMChar(string rowerstring);
int heartRate(string rowerString);
int locateM2(string rowerString);
int strokesPerMinute(string rowerString);
int colonLocation(string rowerString);
int elapsedSeconds(string rowerString);
int elapsedMinutes(string rowerString);

int main()
{
    
    string test;
    cout << "give a string ";
    getline(cin, test);
    
    cout << "isValidRowerString returns: " << isValidRowerString(test) << endl;
    cout << "elapsedMinutes returns: " << elapsedMinutes(test) << endl;
    cout << "elapsedSeconds returns: " << elapsedSeconds(test) << endl;
    cout << "strokesPerMinute returns: " << strokesPerMinute(test) << endl;
    cout << "totalDistance returns: " << totalDistance(test) << endl;
    cout << "heartRate returns: " << heartRate(test) << endl;
    
    return 0;
}


int stringToNumber(string s, int& startingPosition)  //takes numbers in strings and converts them to type int
{
    int result = 0;
    
    //to ignore leading whitespace:
    while (startingPosition < s.length() && isspace(s[startingPosition]))
        startingPosition++;
    
    if (startingPosition <= s.length())
    {
        while (startingPosition < s.length() && s.at(startingPosition) >= '0' && s[startingPosition] <= '9')
        {
            int value = s[startingPosition] - '0';
                
            result = (result * 10) + value;
            startingPosition++;
        }
    }
    else{
        result = -1;
    }
    
    return result;
}
//end of stringToNumber function



bool isValidRowerString(string rowerString)
{
    int posInString = 0, posAtPoint = 0;
    int minuteValue = 0, secondsValue = 0, strokeValue = 0, distanceValue = 0, heartRate = 0;
    
    //tags the empty string as invalid:
    if (rowerString.size() <= 0)
        return false;
    
    //ignores leading whitespace:
    while (posInString < rowerString.size() && isspace(rowerString[posInString]))
        posInString++;
    
    //checks to make sure first character in time field is int '1'-'9' or ':'
    if ( !( (rowerString[posInString] >= '1' && rowerString[posInString] <= '9') || rowerString[posInString] == ':'))
        return false;
    
    //records the minute value in variable minuteValue:
    if (rowerString[posInString] >= '1' && rowerString[posInString] <= '9')
    {
        minuteValue += stringToNumber(rowerString, posInString);
    }
    
    //checks to make sure minuteValue is valid:
    if (minuteValue > 0)
    {
        if (minuteValue < 1 || minuteValue > 59)
            return false;
    }
    else
        posInString++;
    
    //checks to make sure there's a ':'' after the minutes field:
    if (minuteValue > 0) {
        if (rowerString[posInString] != ':')
            return false;
        posInString++;
    }
    
    //makes sure the seconds field is only 2 digits long:
    if (rowerString[posInString + 2] != ' ')
        return false;
    
    //records the seconds value in the variable secondsValue:
    if (posInString < rowerString.size() && rowerString[posInString] >= '0' && rowerString[posInString] <= '5') {
        posAtPoint = posInString;
        secondsValue += stringToNumber(rowerString, posInString);
    }
    else
        return false;
    
    //makes sure the seconds value is valid:
    if (secondsValue < 0 || secondsValue > 59)
        return false;
    else if (secondsValue < 10 && secondsValue > 0 && (rowerString[posAtPoint] != '0' || rowerString[posAtPoint + 1] == '0'))
        return false;
    else if (secondsValue == 0 && (rowerString[posAtPoint] != '0' || rowerString[posAtPoint + 2] != ' '))
        return false;
    
    //makes sure the character after the seconds field is a white space:
    if (rowerString[posInString] != ' ')
        return false;
    
    //ignores white space btw seconds and strokes number:
    while (posInString < rowerString.size() && isspace(rowerString[posInString]))
        posInString++;
    
    //records the stroke rate in the variable strokeValue:
    if (posInString < rowerString.size() && rowerString[posInString] >= '1' && rowerString[posInString] <= '9') {
        strokeValue += stringToNumber(rowerString, posInString);
    }
    else
        return false;
    
    //makes sure the stroke value is valid:
    if (strokeValue < 1 || strokeValue > 999)
        return false;
    
    //makes sure stroke value is followed by " s/m" exactly
    if (posInString+3 >= rowerString.size() || rowerString[posInString] != ' ' || rowerString[posInString+1] != 's' || rowerString[posInString+2] != '/' || rowerString[posInString+3] != 'm')
        return false;
    else
        posInString += 4;
    
    //ignores white space following " s/m"
    while (posInString < rowerString.size() && isspace(rowerString[posInString]))
        posInString++;
    
    //checks for and records the distance in the variable distanceValue:
    if (posInString < rowerString.size() && rowerString[posInString] >= '1' && rowerString[posInString] <= '9') {
        distanceValue += stringToNumber(rowerString, posInString);
    }
    else
        return false;
    
    //NOTE: above code ^ also checks if distance value is valid
    
    //checks if " m" appears after distance value
    if (posInString+1 >= rowerString.size() || rowerString[posInString] != ' ' || rowerString[posInString+1] != 'm')
        return false;
    else
        posInString += 2;
    
    //ignores white space following " m"
    while (posInString < rowerString.size() && isspace(rowerString[posInString]))
        posInString++;
    
    //checks for and records heart rate in variable heartRate
    if (posInString < rowerString.size() && rowerString[posInString] >= '1' && rowerString[posInString] <= '9') {
        heartRate += stringToNumber(rowerString, posInString);
    }
    else
        return false;
    
    //Checks if heart rate is valid
    if (heartRate < 1 || heartRate > 999)
        return false;
    
    if (posInString < rowerString.size())
        return false;
    
    return true;
}
//end of isValidRowerString function




int totalDistance(string rowerString)
{
    int strPosition = 0;
    int distanceValue = 0;
    
    
    if (isValidRowerString(rowerString) == false)
    {
        return -1;
    }
    else
    {
        strPosition = locateMChar(rowerString) + 1;
        
        //ignores white space up until the 'm' char:
        while (strPosition < rowerString.size() && isspace(rowerString[strPosition]))
            strPosition++;
        
        //records the distance value
        if (strPosition < rowerString.size() && rowerString[strPosition] >= '1' && rowerString[strPosition] <= '9')
            distanceValue += stringToNumber(rowerString, strPosition);
    }
    
    return distanceValue;
}
//end of totalDistance function




int locateMChar(string rowerString) //finds location of the first m character in the string
{
    for (int i = 0; i < rowerString.size(); i++)
    {
        if (rowerString[i] == 'm')
            return i;
    }
    
    return -1;
}
//end of loateMChar function



int heartRate(string rowerString)
{
    int heartRate = 0;
    int strPosition = 0;
    
    if (isValidRowerString(rowerString) == false)
    {
        return -1;
    }
    else
    {
        strPosition = locateM2(rowerString) + 1;
        
        //skip over some white space
        while (strPosition < rowerString.size() && isspace(rowerString[strPosition]))
            strPosition++;
        
        if (strPosition < rowerString.size() && rowerString[strPosition] >= '1' && rowerString[strPosition] <= '9')
            heartRate += stringToNumber(rowerString, strPosition);
    }
    
    return heartRate;
}
//end of heartRate function




int locateM2(string rowerString) //finds location of the second m character in a string
{
    int mCount = 0;
    
    for (int i = 0; i < rowerString.size(); i++)
    {
        if (rowerString[i] == 'm')
        {
            if (mCount == 1)
                return i;
            else
                mCount += 1;
        }
    }
    
    return -1;
}
//end of locateM2 function




int strokesPerMinute(string rowerString)
{
    int strokesPerMinute = 0;
    int strPosition = 0;
    
    if (isValidRowerString(rowerString) == false)
    {
        return -1;
    }
    else
    {
        strPosition = colonLocation(rowerString) + 3;
        
        //ignore some white space
        while (strPosition < rowerString.size() && isspace(rowerString[strPosition]))
            strPosition++;
        
        //record the strokesPerMinute
        if (strPosition < rowerString.size() && rowerString[strPosition] >= '1' && rowerString[strPosition] <= '9')
            strokesPerMinute += stringToNumber(rowerString, strPosition);
        
    }
    
    return strokesPerMinute;
}
//end of strokesPerMinute Function




int colonLocation(string rowerString)  //finds the location of the colon in a string
{
    for (int i = 0; i < rowerString.size(); i++)
    {
        if (rowerString[i] == ':')
        {
            return i;
        }
    }
    
    return -1;
}
//end of colonLocation function




int elapsedMinutes(string rowerString)
{
    int strPosition = 0;
    int elapsedMinutes = 0;
    
    if (isValidRowerString(rowerString) == false)
    {
        return -1;
    }
    else
    {
        //ignore some white space
        while (strPosition < rowerString.size() && isspace(rowerString[strPosition]))
            strPosition++;
        
        //record the elapsed minutes
        if (rowerString[strPosition] >= '1' && rowerString[strPosition] <= '9')
        {
            elapsedMinutes += stringToNumber(rowerString, strPosition);
        }
        else
            return 0;
    }
    
    return elapsedMinutes;
}



int elapsedSeconds(string rowerString)
{
    int strPosition = 0;
    int elapsedSeconds = 0;
    
    if (isValidRowerString(rowerString) == false)
    {
        return -1;
    }
    else
    {
        strPosition = colonLocation(rowerString) + 1;
        
        //record the seconds value
        if (strPosition < rowerString.size() && rowerString[strPosition] >= '0' && rowerString[strPosition] <= '5') {
            elapsedSeconds += stringToNumber(rowerString, strPosition);
        }
    }
    
    return elapsedSeconds;
}
