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

// takes a file name and writes the table into it
bool AbstractDbTable::saveCSV(const std:: string &filename){

	std::ofstream file(filename);// open the file for writing 

	if(!file.is_open())	return false;// checks if file opend succcessfully 
	
	//loops through each line and write to file with the given format 
		for(int i=0; i< rows(); i++){


			const movie *m = get (i);

			if (m== nullptr) return false;

		// writing to file with the given format
			file<< m->id << ","
		 		<< "\""<<m->title<<"\""
				<<","<< m->year<<","<<
			"\""<< m->director<<"\""
				<<"\n";

		// if writing fails return false
			if (!file) return false;
		



		}
	
		file.close();
		return true; // if writing file succceds return true
}


// read the table from file and add into table vector 
bool AbstractDbTable::loadCSV(const std::string &filename)
{
    std::ifstream file(filename);// open file for reading

	//if file fails to open return false
    if (!file.is_open()) {
        return false;
    }

    std::string line;// buffer to store a row of table  read from file 

	// loops through the row of table in the buffer and parse 
    while (std::getline(file, line)) {
        movie m; //

        size_t comma1 = line.find(',');// find the first comma
        if (comma1 == std::string::npos) return false;// check the comma exsists

        size_t comma2 = line.find(',', comma1 + 1);// find the second comma
        if (comma2 == std::string::npos) return false; // check the comma exsists

        size_t comma3 = line.find(',', comma2 + 1);// find the third comma
        if (comma3 == std::string::npos) return false;// check the comma exsists 

        std::string id = line.substr(0, comma1);// parsed id
        std::string title = line.substr(comma1 + 1, comma2 - comma1 - 1);//parsed title 
        std::string year = line.substr(comma2 + 1, comma3 - comma2 - 1);// pased year
        std::string director = line.substr(comma3 + 1);// parsed director

		//checks for character overflowing
        if (title.size() >= 50 || director.size() >= 50) return false;


		// try converting the id & year strings into integers before adding  
        try {
            m.id = std::stoul(id);
            m.year = static_cast<unsigned short>(std::stoul(year));
        } catch (...) {
            return false;
        }
		
		//convert c++ string into c string and copy into buffer "m" 
        std::strncpy(m.title, title.c_str(), 49);
        m.title[49] = '\0';

        std::strncpy(m.director, director.c_str(), 49);
        m.director[49] = '\0';

		// adding the buffer containing fields into vector containing records
        if (!add(m)) {
            return false;
        }
    }

    file.close();
    return true;// return true if every thing succceds
}





}
