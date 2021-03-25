#include <string>
#include <sstream>
#include <fstream>

#include "catch.hpp"
#include "ITPMemLeaks.h"
#include "ITPDoubleList.hpp"
#include "movie.h"

// ITP 365 Spring 2021
// HW07 – Movie Player
// Name: Sophia Wittmeier
// Email: wittmeie@usc.edu
// Platform: Mac

// Helper function declarations (don't change this)
extern bool CheckTextFilesSame(const std::string& fileNameA,
	const std::string& fileNameB);

TEST_CASE("Student list tests", "[student]")
{
    
	SECTION("Default constructor, size, and destructor")
	{
        MoviePlayer mp = MoviePlayer("input/scene1.ani");
        
        
        
        
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_front, front, back")
	{
//        MoviePlayer mp;
//        mp.push_front("---");
//        mp.front();
//        mp.back();
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_front, front, back, pop_front")
	{
		
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_back, front, back")
	{

		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_back, front, back, pop_back")
	{
		
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_back, clear")
	{
		
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_back, front, back, pop_back, copy constructor")
	{
		
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_back, front, back, pop_back, assignment")
	{
		
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Back, front, pop_front, pop_back, exceptions")
	{
		
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_front, front, back, begin, iterator dereference, copy constructor")
	{
		
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("List: begin, end; Iterator: dereference, assignment, comparison")
	{
		
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("List: begin, end; Iterator: dereference, increment")
	{
		
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("List: begin, end; Iterator: dereference, increment, decrement")
	{
		
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("List: insert with iterator at begin, middle, and one away from end")
	{
		
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("List: erase with iterator at begin, middle, and one away from end")
	{
		
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}
}

TEST_CASE("Student movie", "[student]") 
{
	SECTION("Bad constructor")
	{

		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Creating scene 2")
	{
		
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Checking frames, scene 2")
	{
		
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}
}


