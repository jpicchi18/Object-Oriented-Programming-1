//
//  Project5Helper.hpp
//  Project 5: Box Office
//
//  Created by Joseph Picchi on 2/22/19.
//  Copyright © 2019 Joseph Picchi. All rights reserved.
//

#ifndef PROJECT5HELPER_H
#define PROJECT5HELPER_H
#include <string>

class Project5Helper
{
public:
    Project5Helper();
    
    bool startsWithOrchestra(const std::string & mainStr );
    bool startsWith(const std::string & mainStr, const std::string & toMatch);
    
    bool endsWithPM(const std::string & mainStr );
    bool endsWith(const std::string & mainStr, const std::string & toMatch);
};

#endif
