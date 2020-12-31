//
//  BoxOffice.cpp
//  Project 5: Box Office
//
//  Created by Joseph Picchi on 2/22/19.
//  Copyright © 2019 Joseph Picchi. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include "BoxOffice.h"
#include <string>
#include "Ticket.h"
#include "Project5Helper.h"



double BoxOffice::priceForKindAndTime(Ticket::KIND kind, const std::string & daytime)
{
    double price = 0;
    Project5Helper helper;
    
    if (kind == Ticket::ATHLETICGAME)
        price += 75;
    else if (kind == Ticket::CONCERT)
    {
        if (helper.endsWithPM(daytime) == true)
            price += 65;
        else
            price += 50;
    }
    else if (kind == Ticket::MOVIE)
        price += 12.5;
    else if (kind == Ticket::OTHER)
    {
        if (helper.endsWithPM(daytime) == true)
            price += 55;
        else
            price += 40;
    }
    
    return price;
}






Ticket BoxOffice::buyTicket(std::string row, int seat, std::string event, std::string venue, Ticket::KIND kind, std::string daytime) {
    return Ticket(row, seat, event, venue, 0, kind, daytime);
}




//function 
Ticket BoxOffice::buyRoyceHallStudentTicket(std::string row, int seat, std::string event, Ticket::KIND kind, std::string daytime)
{
    double price = 0;
    
    //create class objects in the function
    BoxOffice b;
    Project5Helper helper;
    
    //sets the general public price based on the kind and morning/evening
    price = b.priceForKindAndTime(kind, daytime);
    
    //double the price if it's orchestra seating:
    if (helper.startsWithOrchestra(row) == true)
        price *= 2;
    
    //applying the student discount:
    if (price >= 40)
        price -= 30;
    else
        price *= 0.8;
    
    return Ticket(row, seat, event, "Royce Hall", price, kind, daytime);
}



Ticket BoxOffice::buyRoyceHallStaffTicket(std::string row, int seat, std::string event, Ticket::KIND kind, std::string daytime)
{
    double price = 0;
    
    //create class objects in the function
    BoxOffice b;
    Project5Helper helper;
    
    //sets the general public price based on the kind and morning/evening
    price = b.priceForKindAndTime(kind, daytime);
    
    //double the price for orchestra seating
    if (helper.startsWithOrchestra(row) == true)
        price *= 2;
    
    //apply the staff discount
    if (price >= 40)
        price -= 20;
    else
        price *= 0.9;
    
    return Ticket(row, seat, event, "Royce Hall", price, kind, daytime);
}



Ticket BoxOffice::buyRoyceHallTicket(std::string row, int seat, std::string event, Ticket::KIND kind, std::string daytime)
{
    double price = 0;
    
    //create class objects in the function
    BoxOffice b;
    Project5Helper helper;
    
    //sets the general public price based on the kind and morning/evening
    price = b.priceForKindAndTime(kind, daytime);
    
    //double the price for orchestra seating:
    if (helper.startsWithOrchestra(row) == true)
        price *= 2;
    
    return Ticket(row, seat, event, "Royce Hall", price, kind, daytime);
}

