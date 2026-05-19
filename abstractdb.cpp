/**
 * abstractdb.cpp
 * C++ source file that should contain implementation for member functions
 * - loadCSV()
 * - saveCSV()
 * 
 * You need to modify this file to implement the above-mentioned member functions
 * as specified in the hand-out (Tasks 4 and 5)
 */ 

#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include "abstractdb.hpp"

namespace nwen {


bool AbstractDbTable::saveCSV(const std:: string &filename){

	std::ofstream file(filename);

	if(!file.is_open())	return false;
	
	
		for(int i=0; i< rows(); i++){


			const movie *m = get (i);

			if (m== nullptr) return false;

		
			file<< m->id << ","
		 		<< "\""<<m->title<<"\""
				<<","<< m->year<<","<<
			"\""<< m->director<<"\""
				<<"\n";


			if (!file) return false;
		



		}
	
		file.close();
		return true;
}



bool AbstractDbTable::loadCSV(const std:: string &filename){


	std::ifstream file(filename);


	if (!file.is_open()) return false;


	std:: string line;

	while (std::getline(file,line)){

	movie m;

	//finding  first comma 
	
	size_t comma1=line.find(',');
	if (comma1 == std::string::npos) return false;
	
	// finding the first title quote 
	
	if(comma1 + 1 >= line.size() || line [comma1 + 1] != '"') return false;

	

	//finding the closing quote
	
	size_t start_of_title = comma1+ 2;
	size_t end_of_title = line.find('"',start_of_title);
	if (end_of_title == std::string::npos) return false;


	//there should  be a comma after title quote
	if (end_of_title + 1>= line.size() || line[end_of_title +1] != ',') return false;


	//comma after year 	
	
	size_t start_of_year= end_of_title+ 2 ;
	size_t comma3 = line.find(',',start_of_year);
	if (comma3 == std::string::npos) return false;
	
	//director should start with quote 

	if (comma3 + 1 >= line.size() || line[comma3 + 1] != '"') return false;

	// closing quote of director 
	
	size_t start_of_director= comma3+ 2;
	size_t end_of_director= line.find('"',start_of_director);
	if(end_of_director == std::string::npos) return false;

	//nothing should come after final quote 
	
	if (end_of_director +1 != line.size()) return false;

	std::string id =line.substr(0,comma1);
	std::string title =line.substr(start_of_title,end_of_title-start_of_title);
	std::string year =line.substr(start_of_year,comma3-start_of_year);
	std::string director =line.substr(start_of_director,end_of_director-start_of_director);
	
	if (title.size()>=50 || director.size()>=50) return false;

	try{

		m.id = std::stoul(id);
		m.year = static_cast <unsigned short>(std::stoul(year));

	} catch(...){
		return false;
	}


	// copyt string into array

	std::strncpy(m.title,title.c_str(),49);
	m.title[49] = '\0';

	std::strncpy(m.director,director.c_str(),49);
	m.director[49] = '\0';
	
	if(!add(m)) return false;

	}//end of while loop

	file.close();
	return true;


}//end of loadCSV()





}
