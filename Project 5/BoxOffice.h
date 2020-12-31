//
//  BoxOffice.h
//  Project 5: Box Office
//
//  Created by Joseph Picchi on 2/22/19.
//  Copyright © 2019 Joseph Picchi. All rights reserved.
//

#ifndef BoxOffice_h
#define BoxOffice_h

#include "Ticket.h"
#include <string>

class BoxOffice {
    
public:
    //declaring the public functions of the class
    double priceForKindAndTime(Ticket::KIND kind, const std::string & daytime);
    
    Ticket buyTicket(std::string row, int seat, std::string event, std::string venue, Ticket::KIND kind, std::string daytime);
    
    Ticket buyRoyceHallStudentTicket(std::string row, int seat, std::string event, Ticket::KIND kind, std::string daytime);

    Ticket buyRoyceHallStaffTicket(std::string row, int seat, std::string event, Ticket::KIND kind, std::string daytime);
    
    Ticket buyRoyceHallTicket(std::string row, int seat, std::string event, Ticket::KIND kind, std::string daytime);
    
};
#endif /* BoxOffice_h */
