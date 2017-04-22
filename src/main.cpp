/* 
 * File:   newmain.cpp
 * Author: Didac
 *
 * Created on 10 April 2017, 20:24
 */
#include <vector>
#include <fstream>
#include <iostream>
#include "MovieDatabase.h"
#include "Ratings.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream db_file("res/movies.txt");
    ifstream ratings_file("res/ratings.txt");
    
    MovieDatabase *db_ptr = new MovieDatabase();
    Ratings *r_ptr = new Ratings();
    
    if (db_file.is_open()) { db_file >> db_ptr; }
    else { cerr<<"Couldn't open movies.txt in res/movies.txt"<<endl; return 0;}
  
    if (ratings_file.is_open()) { ratings_file >> r_ptr; db_ptr->apply_ratings(*r_ptr); }
    else {cerr<<"Couldn't open ratings.txt in res/ratings.txt"<<endl;}
 

    cout<<"//*************************************************************//"<<endl;
    cout<<"//**************             Task 1           *****************//"<<endl;
    cout<<"//*************************************************************//"<<endl; 
    // sort_mdb accepts a custom comparison to change the sorting  
    // E.g: auto comp = [](Movie const &m, Movie const &_m)        
    //                    {return (m.get_date() > _m.get_date());}
    //db_ptr->sort_mdb(comp);
    db_ptr->sort_mdb(); 
    cout << *db_ptr << endl;


    cout<<"//*************************************************************//"<<endl;
    cout<<"//**************             Task 2           *****************//"<<endl;
    cout<<"//*************************************************************//"<<endl;
    // retrieve accepts a criteria, a custom comparison (optional)
    // and a position (optional) 
    auto criteria_t2 = [](Movie *m)
	               {return (m->get_genres().find("Film-Noir") != string::npos);};
    auto comparison_t2 = [](Movie const &m, Movie const &_m)
	                 {return (m.get_duration() > _m.get_duration());};
    int pos_t2 = 2; // Third (0 index)

    try { cout << db_ptr->retrieve(pos_t2, comparison_t2, criteria_t2) << endl;}
    catch (const char* msg){ cerr << msg << endl; }
    
    cout<<"//*************************************************************//"<<endl;
    cout<<"//**************             Task 3           *****************//"<<endl;
    cout<<"//*************************************************************//"<<endl;
    auto criteria_t3 = [](Movie *m)
	               {return (m->get_genres().find("Sci-Fi") != string::npos);};
    auto comparison_t3 = [](Movie const &m, Movie const &_m)
	               {return (m.get_avg_rating() > _m.get_avg_rating());};
    int pos_t3 = 9; // Tenth (0 index)
    
    try { cout << db_ptr->retrieve(pos_t3, comparison_t3, criteria_t3) << endl;}
    catch (const char* msg){ cerr << msg << endl; }
    
    cout<<"//*************************************************************//"<<endl;
    cout<<"//**************             Task 4           *****************//"<<endl;
    cout<<"//*************************************************************//"<<endl;
    auto comparison_t4 = [](Movie const &m, Movie const &_m)
	               {return (m.get_avg_rating() > _m.get_avg_rating());};
    //int pos_t3; // 

    try { cout << db_ptr->retrieve(0, comparison_t4) << endl;}
    catch (const char* msg){ cerr << msg << endl; }
    
    cout<<"//*************************************************************//"<<endl;
    cout<<"//**************             Task 5           *****************//"<<endl;
    cout<<"//*************************************************************//"<<endl;
    auto comparison_t5 = [](Movie const &m, Movie const &_m)
	                 {return (m.get_title().size() > _m.get_title().size());};

    try { cout << db_ptr->retrieve(0, comparison_t5) << endl; }
    catch (const char* msg){ cerr << msg << endl; }

    cout<<"//*************************************************************//"<<endl;
    cout<<"//**************             Task 6           *****************//"<<endl;
    cout<<"//*************************************************************//"<<endl;
    auto comparison_t6 = [](Rating const &r, Rating const &_r)
	                 {return (r < _r);};

    try { cout << r_ptr->retrieve(100, comparison_t6) << endl; }
    catch (const char* msg){ cerr << msg << endl; }

    // Info
    cout << "Movies in database: " << db_ptr->size() << endl;
    cout << "Number of ratings: " << r_ptr->size() << endl;
    delete(db_ptr);
    delete(r_ptr);
    
    return 0;
}

