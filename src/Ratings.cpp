/*
 * File: Ratings.h
 * Author: Diego Viteri
 *
 * Created on 15 April 2017, 13:57
 */

#include <sstream>
#include <iostream>
#include <vector>
#include <set>
//#include "MovieDatabase.h"
#include "Ratings.h"

using namespace std;

Ratings::Ratings()
{
    //cout << "new ratings" << endl;
}

Ratings::Ratings(const Ratings& orig)
{
}

Ratings::~Ratings()
{
    //cout << "ratings destroyed" << endl;
}

istream& operator>>(istream &is, Ratings* &rs)
{
    string line;
    stringstream ss;

    while(getline(is, line))
    {
	//cout << line << endl;
	Rating r;
	line.append("\n");
	ss.str(line);
	ss >> r;
	//cout << r;
	rs->add_rating(r);
    }
    
    return is;
}
