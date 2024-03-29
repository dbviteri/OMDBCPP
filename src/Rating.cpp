/*
 * File: Rating.cpp
 * Author: Diego Viteri
 *
 * Created on 15 April 2017, 20:23
 */

#include <iostream>
#include "Rating.h"

using namespace std;

Rating::Rating(){}

Rating::Rating(TimeCode &t, string name, string movie_title, int rating)
{
    this->t = t;
    this->name = name;
    this->movie_title = movie_title;
    this->rating = rating;
}

Rating::Rating(const Rating& orig)
{
    this->t = orig.t;
    this->name = orig.name;
    this->movie_title = orig.movie_title;
    this->rating = orig.rating;
}

Rating::~Rating(){}

std::istream& operator>>(std::istream &is, Rating &r)
{
    TimeCode t;
    string name, movie_title;
    int rating;
    char c;

    if(is >> t >> c >> quoted(name) >> c >> quoted(movie_title) >> c >> rating){
	    r = Rating(t, name, movie_title, rating);
    } else {
        is.clear(ios_base::failbit);
    }
    
    return is;
}
