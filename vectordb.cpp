/**
 * vectordb.cpp
 * C++ source file that should contain implementation for member functions
 * - rows()
 * - get()
 * - add()
 * - update()
 * - remove()
 * 
 * You need to modify this file to implement the above-mentioned member functions
 * as specified in the hand-out (Task 3)
 */ 

#include "vectordb.hpp"
#include "abstractdb.hpp"

namespace nwen {



int VectorDbTable::rows() const{

	return table.size();
}

const movie* VectorDbTable::get(int row) const{

	if (row <0 || row >= table.size()) return nullptr;

	return &table[row];

}

bool VectorDbTable::add(movie m){

	for(const movie &mv : table){

	if(mv.id == m.id ) return false;
		
	}

	table.push_back(m);

	return true;
}



bool VectorDbTable::update(unsigned long id ,movie m){


for (movie &mv: table){

	if (mv.id == id){
		
	 mv=m;
	 
	 return true;

	}

}


	return false;

}



bool VectorDbTable::remove(unsigned long id){


	for (size_t i=0 ; i< table.size(); i++){

	if(table[i].id == id){

		table.erase(table.begin()+i);		
	
		return true;

	}

	
	}			

	return false;



}
}
