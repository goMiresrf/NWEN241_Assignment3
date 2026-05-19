/**
 * vectordb.hpp
 * C++ header file that should contain declaration for
 * - VectorDbTable class
 * 
 * You need to modify this file to declare VectorDbTable class 
 * as specified in the hand-out (Task 2)
 */ 

#include "abstractdb.hpp"
#include <vector>


namespace nwen {


	class VectorDbTable : public AbstractDbTable{

	public:

		VectorDbTable()= default;// constructor 
		
		int rows() const override;
		const movie* get(int id) const override;
		bool add (movie m) override ;
		bool update(unsigned long id, movie m) override;
		bool remove(unsigned long id ) override;

		
private:
		
		std::vector<movie>table; // the vector storing movie records

	};
}
