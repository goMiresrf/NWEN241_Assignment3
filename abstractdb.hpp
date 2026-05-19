/**
 * abstractdb.hpp
 * C++ header file that should contain declaration for
 * - struct movie (given)
 * - AbstractDbTable abstract class
 * 
 * You need to modify this file to declare AbstractDbTable abstract class 
 * as specified in the hand-out (Task 1)
 */ 



#ifndef __ABSTRACT_DB_HPP__
#define __ABSTRACT_DB_HPP__

#include <string>

namespace nwen 
{
    struct movie {
        unsigned long id;
        char title[50];
        unsigned short year;
        char director[50];
    };


	class AbstractDbTable{

public:
	virtual int rows() const=0;
	virtual const movie* get(int) const=0;
	virtual bool add(movie)=0;
	virtual bool update(unsigned long ,movie)=0;
	virtual bool remove(unsigned long)=0;
	
	bool loadCSV(const std::string &);
	bool saveCSV(const std::string &);


};

}






#endif /* __ABSTRACT_DB_HPP__ */
