//
//  main.cpp
//  mealplan
//
//  Created by Joseph Picchi on 1/17/19.
//  Copyright © 2019 Joseph Picchi. All rights reserved.
//

#include <iostream>
using namespace std;
#include <string>

int main()
{
    string paymentType;  //All variables are inisitialized here
    string mealType;
    string dinerType;
    string residentType;
    
    cout << "Ticket or BruinCard? "; //user is prompted to enter payment type
    getline(cin, paymentType);    //getline is used so that the empty string is treated as an error
    
    if (paymentType == "Ticket")   //This is the outermost if statement that initiates separate paths
    {                              //depending on the inputed payment type
        cout << "Breakfast, Lunch or Dinner? "; //user prompted to enter meal type
        getline(cin, mealType);
        
        if (mealType == "Breakfast") //initiates the Ticket/Breakfast code block
        {
            cout << "Thank you for eating at UCLA today.  Your meal cost is $12.50.\n";
            return (0); //0 outputted if program doesn't terminate with an error message
        }
        else if (mealType == "Lunch") //initiates the Ticket/Lunch code block
        {
            cout << "Thank you for eating at UCLA today.  Your meal cost is $14.50.\n";
            return (0);
        }
        else if (mealType == "Dinner") //initiates the Ticket/Dinner code block
        {
            cout << "Thank you for eating at UCLA today.  Your meal cost is $17.00.\n";
            return (0);
        }
        else //initiates error message if meal type isn't Breakfast, Lunch, or Dinner
        {
            cout << "The meal value must either be Breakfast, Lunch or Dinner.\n";
            return (1); //1 outputted if program terminates with an error message
        }
    }
    else if (paymentType == "BruinCard") //initiates the code block corresponding a BruinCard payment
    {
        cout << "Breakfast, Lunch or Dinner? "; //prompts user to enter meal type
        getline(cin, mealType);
        
        if (mealType == "Breakfast") //intiates Bruincard/Breakfast code block
        {
            cout << "Student or Staff? "; //prompts user to enter diner type
            getline(cin, dinerType);
            
            if (dinerType == "Staff") //intiates Bruincard/Breakfast/Staff code block
            {
                cout << "Thank you for eating at UCLA today.  Your meal cost is $11.25.\n";
                return (0);
            }
            else if (dinerType == "Student") //intiaites Bruincard/Breakfast/Student code block
            {
                cout << "Resident? "; //prompts user to declare if they are a resident
                getline(cin, residentType);
                
                if (residentType == "Yes") //intiaites Bruincard/Breakfast/Student/Yes code block
                {
                    cout << "Thank you for eating at UCLA today.  Your meal cost is $9.75." << endl;
                    return (0);
                }
                if (residentType == "No") //intiaites Bruincard/Breakfast/Student/No code block
                {
                    cout << "Thank you for eating at UCLA today.  Your meal cost is $10.00." << endl;
                    return (0);
                }
                else //error message if resident value is neither Yes nor No
                {
                    cout << "The resident value must either be Yes or No.\n";
                    return (1);
                }
            }
            else //error message if diner is not a Student or Staff
            {
                cout << "The type value must either be Student or Staff.\n";
                return (1);
            }
        }
        else if (mealType == "Lunch") //intiaites Bruincard/Lunch code block
        {
            cout << "Student or Staff? ";
            getline(cin, dinerType);
            
            if (dinerType == "Staff") //intiaites Bruincard/Lunch/Staff code block
            {
                cout << "Thank you for eating at UCLA today.  Your meal cost is $12.75.\n";
                return (0);
            }
            else if (dinerType == "Student") //intiaites Bruincard/Lunch/Student code block
            {
                cout << "Resident? ";
                getline(cin, residentType);
                
                if (residentType == "Yes") //intiaites Bruincard/Lunch/Student/Yes code block
                {
                    cout << "Thank you for eating at UCLA today.  Your meal cost is $11.25." << endl;
                    return (0);
                }
                if (residentType == "No") //intiaites Bruincard/Lunch/Student/No code block
                {
                    cout << "Thank you for eating at UCLA today.  Your meal cost is $11.75." << endl;
                    return (0);
                }
                else //Error if Resident value is not Yes or No
                {
                    cout << "The resident value must either be Yes or No.\n";
                    return (1);
                }
            }
            else //Error if diner is not a Student or Staff
            {
                cout << "The type value must either be Student or Staff.\n";
                return (1);
            }
        }
        else if (mealType == "Dinner") //intiaites Bruincard/Dinner code block
        {
            cout << "Student or Staff? ";
            getline(cin, dinerType);
            
            if (dinerType == "Staff") //intiaites Bruincard/Dinner/Staff code block
            {
                cout << "Thank you for eating at UCLA today.  Your meal cost is $14.75.\n";
                return (0);
            }
            else if (dinerType == "Student") //intiaites Bruincard/Dinner/Student code block
            {
                cout << "Resident? ";
                getline(cin, residentType);
                
                if (residentType == "Yes") ///intiaites Bruincard/Dinner/Student/Yes code block
                {
                    cout << "Thank you for eating at UCLA today.  Your meal cost is $12.25." << endl;
                    return (0);
                }
                if (residentType == "No") //intiaites Bruincard/Dinner/No code block
                {
                    cout << "Thank you for eating at UCLA today.  Your meal cost is $12.75." << endl;
                    return (0);
                }
                else
                {
                    cout << "The resident value must either be Yes or No.\n";
                    return (1);
                }
            }
            else
            {
                cout << "The type value must either be Student or Staff.\n";
                return (1);
            }
        }
        else //error if meal type is not Breakfast, Lunch, or Dinner
        {
            cout << "The meal value must either be Breakfast, Lunch or Dinner.\n";
            return (1);
        }
    }
    else  //produces the error message if the payment type is neither Ticket nor Bruincard
    {
        cout << "The kind value must either be Ticket or BruinCard." << endl;
        return (1);
    }
    
    return 0; //0 outputted if program runs without an error message
}
