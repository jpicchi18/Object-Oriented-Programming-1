//
//  Tickets.h
//  Project 5: Box Office
//
//  Created by Joseph Picchi on 2/22/19.
//  Copyright © 2019 Joseph Picchi. All rights reserved.
//

#ifndef Tickets_h
#define Tickets_h

#include <string>

class Ticket {
    
public:
    
    //declaring the only public member function
    enum KIND {ATHLETICGAME, CONCERT, MOVIE, OTHER};
    
    //declaring the constructor
    Ticket(std::string row, int seat, std::string event, std::string venue, double price, KIND kind, std::string daytime);
    
    Ticket();
    
    //declaring the member functions
    std::string getRow();
    int getSeat();
    std::string getEvent();
    std::string getVenue();
    double getPrice();
    void setPrice(double price);
    KIND getKind();
    std::string getDayTime();
    
private:
    
    //declaring all of the private member functions
    std::string mRow;
    int mSeat;
    std::string mEvent;
    std::string mVenue;
    double mPrice;
    KIND mKind;
    std::string mDayTime;
};

#endif /* Tickets_h */
