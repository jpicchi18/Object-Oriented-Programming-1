//
//  Tickets.cpp
//  Project 5: Box Office
//
//  Created by Joseph Picchi on 2/22/19.
//  Copyright © 2019 Joseph Picchi. All rights reserved.
//

#include "Ticket.h"
#include <string>
using namespace std;

Ticket::Ticket(string row, int seat, string event, string venue, double price, KIND kind, string daytime) : mRow(row), mSeat(seat), mEvent(event), mVenue(venue), mPrice(price), mKind(kind), mDayTime(daytime) {
}

Ticket::Ticket() {
    mRow = 3;
}

string Ticket::getRow() {
    return mRow;
}

int Ticket::getSeat() {
    return mSeat;
}

string Ticket::getEvent() {
    return mEvent;
}

string Ticket::getVenue() {
    return mVenue;
}

double Ticket::getPrice() {
    return mPrice;
}

void Ticket::setPrice(double price) {
    mPrice = price;
}

Ticket::KIND Ticket::getKind() {
    return mKind;
}

string Ticket::getDayTime() {
    return mDayTime;
}
