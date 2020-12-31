//
//  main.cpp
//  Project 5: Box Office
//
//  Created by Joseph Picchi on 2/22/19.
//  Copyright © 2019 Joseph Picchi. All rights reserved.
//

#include <cassert>
#include <iostream>
#include "Project5Helper.h"
#include "Ticket.h"
#include <string>
#include "BoxOffice.h"
using namespace std;

int main( ) {
    
    //testing the project helper
    Project5Helper helper;
    assert( helper.endsWithPM( "sdfasddf PM" ) );
    assert( !helper.endsWithPM( "asdasdfs AM" ) );
    assert( helper.startsWithOrchestra( "Orchestra 12445" ) );
    assert( !helper.startsWithOrchestra( "122334 Orchestra" ) );
    assert( !helper.startsWithOrchestra(" Orchestra"));
    assert( !helper.endsWithPM("PM "));
    
    
    //testing the ticket class functions:
        //testing the constructor:
    
    Ticket newTicket("row", 1, "event", "venue", 1.11, Ticket::KIND::CONCERT, "daytime");
    assert(newTicket.getRow() == "row");
    assert(newTicket.getEvent() == "event");
    assert(newTicket.getSeat() == 1);
    assert(to_string(newTicket.getPrice()) == "1.110000");
    assert(newTicket.getKind() == Ticket::CONCERT);
    assert(newTicket.getDayTime() == "daytime");
    
    
    //testing BoxOffice function buyTicket:
    BoxOffice b;
    Ticket t = b.buyTicket("4", 3, "yee", "theater", Ticket::KIND::MOVIE, "5:30 pm");
    assert(t.getRow() == "4");
    assert(t.getSeat() == 3);
    assert(t.getEvent() == "yee");
    assert(t.getVenue() == "theater");
    assert(t.getKind() == Ticket::MOVIE);
    assert(t.getDayTime() == "5:30 pm");
    assert(to_string(t.getPrice()) == "0.000000");
    t.setPrice(3.2);
    assert(to_string(t.getPrice()) == "3.200000");
    t.setPrice(14);
    assert(to_string(t.getPrice()) == "14.000000");
    t.setPrice(24.333333);
    assert(to_string(t.getPrice()) == "24.333333");
    t.setPrice( 150.00 );
    assert(to_string(t.getPrice()) == "150.000000");
    
    
    //testing BoxOffice function priceForKind:
    string hasPM = "asdfasdfPM";
    string notPM = "asdfddas   PM ";
    assert(to_string(b.priceForKindAndTime(Ticket::KIND::ATHLETICGAME, hasPM)) == "75.000000");
    assert(to_string(b.priceForKindAndTime(Ticket::KIND::ATHLETICGAME, notPM)) == "75.000000");
    assert(to_string(b.priceForKindAndTime(Ticket::KIND::CONCERT, notPM)) == "50.000000");
    assert(to_string(b.priceForKindAndTime(Ticket::KIND::CONCERT, hasPM)) == "65.000000");
    assert(to_string(b.priceForKindAndTime(Ticket::KIND::MOVIE, hasPM)) == "12.500000");
    assert(to_string(b.priceForKindAndTime(Ticket::KIND::MOVIE, notPM)) == "12.500000");
    assert(to_string(b.priceForKindAndTime(Ticket::KIND::OTHER, notPM)) == "40.000000");
    assert(to_string(b.priceForKindAndTime(Ticket::KIND::OTHER, hasPM)) == "55.000000");
    

    //testing the BoxOffice function buyRoyceHallStudentTicket
    Ticket RoyceHallStudentTicket1 = b.buyRoyceHallStudentTicket("Not Orchestra Row U", 20, "Episode: The Force Awakens", Ticket::KIND::ATHLETICGAME, "September 1, 7:30 PM");
    assert(to_string(RoyceHallStudentTicket1.getPrice()) == "45.000000");
    
    Ticket RoyceHallStudentTicket2 = b.buyRoyceHallStudentTicket("Orchestra Row U", 20, "Episode: The Force Awakens", Ticket::KIND::ATHLETICGAME, "September 1, 7:30 PM");
    assert(to_string(RoyceHallStudentTicket2.getPrice()) == "120.000000");
    
    Ticket RoyceHallStudentTicket3 = b.buyRoyceHallStudentTicket("Orchestra Row U", 20, "Episode: The Force Awakens", Ticket::KIND::CONCERT, "September 1, 7:30 AM");
    assert(to_string(RoyceHallStudentTicket3.getPrice()) == "70.000000");
    
    Ticket RoyceHallStudentTicket4 = b.buyRoyceHallStudentTicket(" Row U", 20, "Episode: The Force Awakens", Ticket::KIND::CONCERT, "September 1, 7:30 AM");
    assert(to_string(RoyceHallStudentTicket4.getPrice()) == "20.000000");
    
    Ticket RoyceHallStudentTicket5 = b.buyRoyceHallStudentTicket("Orchestra Row U", 20, "Episode: The Force Awakens", Ticket::KIND::CONCERT, "September 1, 7:30 PM");
    assert(to_string(RoyceHallStudentTicket5.getPrice()) == "100.000000");
    
    Ticket RoyceHallStudentTicket6 = b.buyRoyceHallStudentTicket(" Row U", 20, "Episode: The Force Awakens", Ticket::KIND::CONCERT, "September 1, 7:30 PM");
    assert(to_string(RoyceHallStudentTicket6.getPrice()) == "35.000000");
    
    Ticket RoyceHallStudentTicket7 = b.buyRoyceHallStudentTicket("Orchestra Row U", 20, "Episode: The Force Awakens", Ticket::KIND::MOVIE, "September 1, 7:30 PM");
    assert(to_string(RoyceHallStudentTicket7.getPrice()) == "20.000000");
    
    Ticket RoyceHallStudentTicket8 = b.buyRoyceHallStudentTicket(" Row U", 20, "Episode: The Force Awakens", Ticket::KIND::MOVIE, "September 1, 7:30 PM");
    assert(to_string(RoyceHallStudentTicket8.getPrice()) == "10.000000");
    
    Ticket RoyceHallStudentTicket9 = b.buyRoyceHallStudentTicket("Orchestra Row U", 20, "Episode: The Force Awakens", Ticket::KIND::OTHER, "September 1, 7:30 AM");
    assert(to_string(RoyceHallStudentTicket9.getPrice()) == "50.000000");
    
    Ticket RoyceHallStudentTicket10 = b.buyRoyceHallStudentTicket(" Row U", 20, "Episode: The Force Awakens", Ticket::KIND::OTHER, "September 1, 7:30 AM");
    assert(to_string(RoyceHallStudentTicket10.getPrice()) == "10.000000");
    
    Ticket RoyceHallStudentTicket11 = b.buyRoyceHallStudentTicket("Orchestra Row U", 20, "Episode: The Force Awakens", Ticket::KIND::OTHER, "September 1, 7:30 PM");
    assert(to_string(RoyceHallStudentTicket11.getPrice()) == "80.000000");
    
    Ticket RoyceHallStudentTicket12 = b.buyRoyceHallStudentTicket(" Row U", 20, "Episode: The Force Awakens", Ticket::KIND::OTHER, "September 1, 7:30 PM");
    assert(to_string(RoyceHallStudentTicket12.getPrice()) == "25.000000");
    
    Ticket RoyceHallStudentTicket = b.buyRoyceHallStudentTicket("Orchestra Row U", 20, "Episode: The Force Awakens", Ticket::KIND::MOVIE, "September 1, 7:30 PM");
    assert(RoyceHallStudentTicket.getRow() == "Orchestra Row U");
    assert(RoyceHallStudentTicket.getSeat() == 20);
    assert(RoyceHallStudentTicket.getEvent() == "Episode: The Force Awakens");
    assert(RoyceHallStudentTicket.getKind() == Ticket::KIND::MOVIE);
    assert(RoyceHallStudentTicket.getDayTime() == "September 1, 7:30 PM");
    assert(to_string(RoyceHallStudentTicket.getPrice()) == "20.000000");
    
    
    ////testing the BoxOffice function buyRoyceHallStaffTicket
    Ticket RoyceHallStaffTicket = b.buyRoyceHallStaffTicket("Orchestra Row U", 20, "Episode: The Force Awakens", Ticket::KIND::MOVIE, "September 1, 7:30 PM");
    assert(RoyceHallStaffTicket.getRow() == "Orchestra Row U");
    assert(RoyceHallStaffTicket.getSeat() == 20);
    assert(RoyceHallStaffTicket.getEvent() == "Episode: The Force Awakens");
    assert(RoyceHallStaffTicket.getKind() == Ticket::KIND::MOVIE);
    assert(RoyceHallStaffTicket.getDayTime() == "September 1, 7:30 PM");
    assert(to_string(RoyceHallStaffTicket.getPrice()) == "22.500000");
    
    Ticket RoyceHallStaffTicket1 = b.buyRoyceHallStaffTicket(" Row U", 20, "Episode: The Force Awakens", Ticket::KIND::ATHLETICGAME, "September 1, 7:30");
    assert(to_string(RoyceHallStaffTicket1.getPrice()) == "55.000000");
    
    Ticket RoyceHallStaffTicket2 = b.buyRoyceHallStaffTicket(" Row U", 20, "Episode: The Force Awakens", Ticket::KIND::ATHLETICGAME, "September 1, 7:30 PM");
    assert(to_string(RoyceHallStaffTicket2.getPrice()) == "55.000000");
    
    Ticket RoyceHallStaffTicket3 = b.buyRoyceHallStaffTicket("Orchestra Row U", 20, "Episode: The Force Awakens", Ticket::KIND::ATHLETICGAME, "September 1, 7:30");
    assert(to_string(RoyceHallStaffTicket3.getPrice()) == "130.000000");
    
    Ticket RoyceHallStaffTicket4 = b.buyRoyceHallStaffTicket("Orchestra Row U", 20, "Episode: The Force Awakens", Ticket::KIND::ATHLETICGAME, "September 1, 7:30 PM");
    assert(to_string(RoyceHallStaffTicket4.getPrice()) == "130.000000");
    
    Ticket RoyceHallStaffTicket5 = b.buyRoyceHallStaffTicket("Row U", 20, "Episode: The Force Awakens", Ticket::KIND::CONCERT, "September 1, 7:30");
    assert(to_string(RoyceHallStaffTicket5.getPrice()) == "30.000000");
    
    Ticket RoyceHallStaffTicket6 = b.buyRoyceHallStaffTicket(" Row U", 20, "Episode: The Force Awakens", Ticket::KIND::CONCERT, "September 1, 7:30PM");
    assert(to_string(RoyceHallStaffTicket6.getPrice()) == "45.000000");
    
    Ticket RoyceHallStaffTicket7 = b.buyRoyceHallStaffTicket("Orchestra Row U", 20, "Episode: The Force Awakens", Ticket::KIND::CONCERT, "September 1, 7:30 PM ");
    assert(to_string(RoyceHallStaffTicket7.getPrice()) == "80.000000");
    
    Ticket RoyceHallStaffTicket8 = b.buyRoyceHallStaffTicket("Orchestra Row U", 20, "Episode: The Force Awakens", Ticket::KIND::CONCERT, "September 1, 7:30PM");
    assert(to_string(RoyceHallStaffTicket8.getPrice()) == "110.000000");
    
    Ticket RoyceHallStaffTicket9 = b.buyRoyceHallStaffTicket(" Row U", 20, "Episode: The Force Awakens", Ticket::KIND::MOVIE, "September 1, 7:30");
    assert(to_string(RoyceHallStaffTicket9.getPrice()) == "11.250000");
    
    Ticket RoyceHallStaffTicket10 = b.buyRoyceHallStaffTicket(" Row U", 20, "Episode: The Force Awakens", Ticket::KIND::MOVIE, "September 1, 7:30 PM");
    assert(to_string(RoyceHallStaffTicket10.getPrice()) == "11.250000");
    
    Ticket RoyceHallStaffTicket11 = b.buyRoyceHallStaffTicket("Orchestra Row U", 20, "Episode: The Force Awakens", Ticket::KIND::MOVIE, "September 1, 7:30");
    assert(to_string(RoyceHallStaffTicket11.getPrice()) == "22.500000");
    
    Ticket RoyceHallStaffTicket12 = b.buyRoyceHallStaffTicket("Orchestra Row U", 20, "Episode: The Force Awakens", Ticket::KIND::MOVIE, "September 1, 7:30 PM");
    assert(to_string(RoyceHallStaffTicket12.getPrice()) == "22.500000");
    
    Ticket RoyceHallStaffTicket13 = b.buyRoyceHallStaffTicket(" w U", 20, "Episode: The Force Awakens", Ticket::KIND::OTHER, "September 1, 7:");
    assert(to_string(RoyceHallStaffTicket13.getPrice()) == "20.000000");
    
    Ticket RoyceHallStaffTicket14 = b.buyRoyceHallStaffTicket(" w U", 20, "Episode: The Force Awakens", Ticket::KIND::OTHER, "September 1, 7:PM");
    assert(to_string(RoyceHallStaffTicket14.getPrice()) == "35.000000");
    
    Ticket RoyceHallStaffTicket15 = b.buyRoyceHallStaffTicket("Orchestra w U", 20, "Episode: The Force Awakens", Ticket::KIND::OTHER, "September 1, 7:");
    assert(to_string(RoyceHallStaffTicket15.getPrice()) == "60.000000");
    
    Ticket RoyceHallStaffTicket16 = b.buyRoyceHallStaffTicket("Orchestra w U", 20, "Episode: The Force Awakens", Ticket::KIND::OTHER, "September 1, 7:PM");
    assert(to_string(RoyceHallStaffTicket16.getPrice()) == "90.000000");
    
    
    //testing the BoxOffice function buyRoyceHallTicket
    Ticket RoyceHallTicket1 = b.buyRoyceHallTicket(" dis row", 40230, "big bois", Ticket::KIND::ATHLETICGAME, "5:41 in the aftermorning");
    assert(RoyceHallTicket1.getRow() == " dis row");
    assert(RoyceHallTicket1.getSeat() == 40230);
    assert(RoyceHallTicket1.getEvent() == "big bois");
    assert(RoyceHallTicket1.getKind() == Ticket::KIND::ATHLETICGAME);
    assert(RoyceHallTicket1.getDayTime() == "5:41 in the aftermorning");
    assert(RoyceHallTicket1.getVenue() == "Royce Hall");
    assert(to_string(RoyceHallTicket1.getPrice()) == "75.000000");
    
    Ticket RoyceHallTicket2 = b.buyRoyceHallTicket("Orchestra dis row", 40230, "big bois", Ticket::KIND::ATHLETICGAME, "5:41 in the aftermorning");
    assert(to_string(RoyceHallTicket2.getPrice()) == "150.000000");
    
    Ticket RoyceHallTicket3 = b.buyRoyceHallTicket("Orchestra dis row", 40230, "big bois", Ticket::KIND::ATHLETICGAME, "5:41 in the aftermorning PM");
    assert(to_string(RoyceHallTicket3.getPrice()) == "150.000000");
    
    Ticket RoyceHallTicket4 = b.buyRoyceHallTicket(" dis row", 40230, "big bois", Ticket::KIND::ATHLETICGAME, "5:41 in the aftermorning PM");
    assert(to_string(RoyceHallTicket4.getPrice()) == "75.000000");
    
    Ticket RoyceHallTicket5 = b.buyRoyceHallTicket(" dis row", 40230, "big bois", Ticket::KIND::CONCERT, "5:41 in the aftermorning ..");
    assert(to_string(RoyceHallTicket5.getPrice()) == "50.000000");
    
    Ticket RoyceHallTicket6 = b.buyRoyceHallTicket(" dis row", 40230, "big bois", Ticket::KIND::CONCERT, "5:41 in the aftermorning .. PM");
    assert(to_string(RoyceHallTicket6.getPrice()) == "65.000000");
    
    Ticket RoyceHallTicket7 = b.buyRoyceHallTicket("Orchestra dis row", 40230, "big bois", Ticket::KIND::CONCERT, "5:41 in the aftermorning .. PM");
    assert(to_string(RoyceHallTicket7.getPrice()) == "130.000000");
    
    Ticket RoyceHallTicket8 = b.buyRoyceHallTicket("Orchestra dis row", 40230, "big bois", Ticket::KIND::CONCERT, "5:41 in the aftermorning .. asd");
    assert(to_string(RoyceHallTicket8.getPrice()) == "100.000000");
    
    Ticket RoyceHallTicket9 = b.buyRoyceHallTicket(" dis row", 40230, "big bois", Ticket::KIND::MOVIE, "5:41 in the aftermo");
    assert(to_string(RoyceHallTicket9.getPrice()) == "12.500000");
    
    Ticket RoyceHallTicket10 = b.buyRoyceHallTicket(" dis row", 40230, "big bois", Ticket::KIND::MOVIE, "5:41 in the aftermoPM");
    assert(to_string(RoyceHallTicket10.getPrice()) == "12.500000");
    
    Ticket RoyceHallTicket11 = b.buyRoyceHallTicket("Orchestra dis row", 40230, "big bois", Ticket::KIND::MOVIE, "5:41 in the aftermodsf.df");
    assert(to_string(RoyceHallTicket11.getPrice()) == "25.000000");
    
    Ticket RoyceHallTicket12 = b.buyRoyceHallTicket("Orchestra dis row", 40230, "big bois", Ticket::KIND::MOVIE, "5:41 in the aftermoPM");
    assert(to_string(RoyceHallTicket12.getPrice()) == "25.000000");
    
    Ticket RoyceHallTicket13 = b.buyRoyceHallTicket("is row", 40230, "big bois", Ticket::KIND::OTHER, "5:41 in the aftermo");
    assert(to_string(RoyceHallTicket13.getPrice()) == "40.000000");
    
    Ticket RoyceHallTicket14 = b.buyRoyceHallTicket("is row", 40230, "big bois", Ticket::KIND::OTHER, "5:41 in the aftermoPM");
    assert(to_string(RoyceHallTicket14.getPrice()) == "55.000000");
    
    Ticket RoyceHallTicket15 = b.buyRoyceHallTicket("Orchestrais row", 40230, "big bois", Ticket::KIND::OTHER, "5:41 in the aftermo");
    assert(to_string(RoyceHallTicket15.getPrice()) == "80.000000");
    
    Ticket RoyceHallTicket16 = b.buyRoyceHallTicket("Orchestrais row", 40230, "big bois", Ticket::KIND::OTHER, "5:41 in the aftermoPM");
    assert(to_string(RoyceHallTicket16.getPrice()) == "110.000000");
    
    
    cout << "get this bread" << endl;
    
    return 0;
}
