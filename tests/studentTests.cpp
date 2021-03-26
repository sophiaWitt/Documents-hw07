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

// TODO: office hours for the todo's I have within the lists unit tests. exceptions, comparison, and constructor.
// TODO: questions about the Movie unit tests.

// Helper function declarations (don't change this)
extern bool CheckTextFilesSame(const std::string& fileNameA,
	const std::string& fileNameB);

TEST_CASE("Student list tests", "[student]")
{
    
	SECTION("Default constructor, size, and destructor")
	{
        // testing the constructor
        std::list<std::string> list;
        REQUIRE(list.size() == 0);
        
        // testing the destructor
        list.~list();
        REQUIRE(list.size() == 0);
        
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_front, front, back")
	{
        // testing push_front
        std::list<std::string> list;
        list.push_front("---");
        // testing front and push_back
        REQUIRE(list.front() == "---");
        
        // testing back and front
        list.push_front("...");
        REQUIRE(list.front() == "...");
        REQUIRE(list.back() == "---");
        
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_front, front, back, pop_front")
	{
        // testing push_front
        std::list<std::string> list;
 
        list.push_front("---");
        list.push_front("!!!");
        
        // testing front - returns the data at the head node - and testing push_back by ensuring through front() that the input that was pushed back is in the doubly linked list
        REQUIRE(list.front() == "!!!");
        
        // testing back - returns the data at the tail node
        REQUIRE(list.back() == "---");
        
        // testing pop front - removes the node at the front of the list
        list.push_front("...");
        int size1 = list.size();
        list.pop_front();
        REQUIRE(list.size() < size1);
        
        bool includes;
        // iterate through the movie player to see if it still includes "...", which was popped_back
        for (std::string str : list) {
            if (str == "...") {
                includes = true;
            }
            else {
                includes = false;
            }
        }
        REQUIRE(includes == false);
        
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_back, front, back")
	{
        // testing push_front
        std::list<std::string> list;
 
        list.push_back("---");
        list.push_back("...");
        
        // testing front - returns the data at the head node - and testing push_back by ensuring through front() that the input that was pushed back is in the doubly linked list
        REQUIRE(list.front() == "---");
        
        // testing back - returns the data at the tail node
        REQUIRE(list.back() == "...");

		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_back, front, back, pop_back")
	{
        std::list<std::string> list;
 
        list.push_back("---");
        list.push_back("...");

        // testing front - returns the data at the head node - and testing push_back by ensuring through front() that the input that was pushed back is in the doubly linked list
        REQUIRE(list.front() == "---");
        
        // testing back - returns the data at the tail node
        REQUIRE(list.back() == "...");

        // testing pop back - removes the node at the back of the list
        list.push_back("!!!");
        int size1 = list.size();
        list.pop_back();
        REQUIRE(list.size() < size1);
        
        bool includes;
        // iterate through the movie player to see if it still includes "...", which was popped_back
        for (std::string str : list) {
            if (str == "!!!") {
                includes = true;
            }
            else {
                includes = false;
            }
        }
        REQUIRE(includes == false);
        
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_back, clear")
	{
        std::list<std::string> list;
        list.push_back("---");
        
        // testing push_back by ensuring through back() that the input that was pushed back is at the back of the doubly linked list
        REQUIRE(list.back() == "---");
		
        //testing clear
        list.clear();
        REQUIRE(list.size() == 0);
        
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_back, front, back, pop_back, copy constructor")
	{
        std::list<std::string> list;
        list.push_back("---");
        list.push_back("...");
   
        // testing push_back by ensuring through back() that the input that was pushed back is at the back of the doubly linked list
        // testing back
        REQUIRE(list.back() == "...");
        
        //testing front
        REQUIRE(list.front() == "---");
        
        // testing pop back - removes the node at the back of the list
        list.push_back("!!!");
        int size1 = list.size();
        list.pop_back();
        REQUIRE(list.size() < size1);
        
        bool includes;
        // iterate through the movie player to see if it still includes "...", which was popped_back
        for (std::string str : list) {
            if (str == "!!!") {
                includes = true;
            }
            else {
                includes = false;
            }
        }
        REQUIRE(includes == false);
        
        // testing the copy constructor
        std::list<std::string> copyList = std::list<std::string>(list);
        bool theSame;
        REQUIRE(copyList.size() == list.size());
        
        // loop through the two lists and ensure that the contents are the same
        for (std::string copy : copyList) {
            for (std::string str : list) {
                if (copy == str) {
                    theSame = true;
                }
                else {
                    theSame = false;
                }
            }
        }
        REQUIRE(theSame == true);
        
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_back, front, back, pop_back, assignment")
	{
        std::list<std::string> list;
        list.push_back("---");
        list.push_back("...");
        
        // testing push_back by ensuring through back() that the input that was pushed back is at the back of the doubly linked list
        // testing back
        REQUIRE(list.back() == "...");
        
        //testing front
        REQUIRE(list.front() == "---");
        
        // testing pop back - removes the node at the back of the list
        list.push_back("!!!");
        int size1 = list.size();
        list.pop_back();
        REQUIRE(list.size() < size1);
        
        bool includes;
        // iterate through the movie player to see if it still includes "...", which was popped_back
        for (std::string str : list) {
            if (str == "!!!") {
                includes = true;
            }
            else {
                includes = false;
            }
        }
        REQUIRE(includes == false);
        
        // testing the assignment operator
        std::list<std::string> otherList = list;
        bool theSame;
        REQUIRE(otherList.size() == list.size());
        
        // loop through the two lists and ensure that the contents are the same
        for (std::string other : otherList) {
            for (std::string s : list) {
                if (other == s) {
                    theSame = true;
                }
                else {
                    theSame = false;
                }
            }
        }
        REQUIRE(theSame == true);

		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Back, front, pop_front, pop_back, exceptions")
	{
        std::list<std::string> list;
        list.push_back("---");
        list.push_back("...");
        list.push_back("!!!");
        
        // testing front and back
        REQUIRE(list.front() == "---");
        REQUIRE(list.back() == "!!!");
        
        // testing pop front - removes the node at the front of the list
        int size1 = list.size();
        list.pop_front();
        REQUIRE(list.size() < size1);
        
        bool includes;
        // iterate through the movie player to see if it still includes "...", which was popped_back
        for (std::string str : list) {
            if (str == "---") {
                includes = true;
            }
            else {
                includes = false;
            }
        }
        REQUIRE(includes == false);
        
        // testing pop back - removes the node at the back of the list
        list.push_back("!!!");
        int size2 = list.size();
        list.pop_back();
        REQUIRE(list.size() < size2);
        
        bool inc;
        // iterate through the movie player to see if it still includes "...", which was popped_back
        for (std::string s : list) {
            if (s == "!!!") {
                inc = true;
            }
            else {
                inc = false;
            }
        }
        REQUIRE(includes == false);
  
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_front, front, back, begin, iterator dereference, copy constructor")
	{
		// testing push front
        std::list<std::string> list;
        list.push_front("---");
        list.push_front("...");
        list.push_front("!!!");
        // testing push back using front
        REQUIRE(list.front() == "!!!");
        
        // testing back and front
        list.push_front("hhh");
        REQUIRE(list.front() == "hhh");
        REQUIRE(list.back() == "---");
 
        // testing begin - returns an iterator containing the pointer to the first node
        std::list<std::string>::iterator pos = list.begin();
        REQUIRE(*pos == "hhh");
        
        // testing the iterator dereference
        pos++;
        REQUIRE(*pos == "!!!");
        
        // testing the copy constructor
        std::list<std::string> copyList = std::list<std::string>(list);
        bool theSame;
        REQUIRE(copyList.size() == list.size());
        
        // loop through the two lists and ensure that the contents are the same
        for (std::string copy : copyList) {
            for (std::string str : list) {
                if (copy == str) {
                    theSame = true;
                }
                else {
                    theSame = false;
                }
            }
        }
        REQUIRE(theSame == true);

		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("List: begin, end; Iterator: dereference, assignment, comparison")
	{
		
        std::list<std::string> list;
        list.push_back("---");
        list.push_back("...");
        list.push_back("!!!");
        
        // testing list begin and end
        std::list<std::string>::iterator pos = list.begin();
        REQUIRE(*pos == "---");
        pos = list.end();
        pos--;
        REQUIRE(*pos == "!!!");
        
        // testing iterator dereference
        pos--;
        REQUIRE(*pos == "...");
        
        // testing iterator assignment
        *pos = "hhh";
        REQUIRE(*pos == "hhh");
        
        // testing iterator comparison
        std::list<std::string>::iterator it = list.begin();
        pos = list.begin();
        REQUIRE(it == pos);
        
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("List: begin, end; Iterator: dereference, increment")
	{
        std::list<std::string> list;
        list.push_back("---");
        list.push_back("...");
        list.push_back("!!!");
        
        // testing list begin and end
        std::list<std::string>::iterator pos = list.begin();
        REQUIRE(*pos == "---");
        pos = list.end();
        pos--;
        REQUIRE(*pos == "!!!");
        
        // testing iterator dereference
        pos--;
        REQUIRE(*pos == "...");
        
        // testing iterator increment
        pos++;
        REQUIRE(*pos == "!!!");
        
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("List: begin, end; Iterator: dereference, increment, decrement")
	{
        std::list<std::string> list;
        list.push_back("---");
        list.push_back("...");
        list.push_back("!!!");
        
        // testing list begin and end
        std::list<std::string>::iterator pos = list.begin();
        REQUIRE(*pos == "---");
        pos = list.end();
        pos--;
        REQUIRE(*pos == "!!!");
        
        // testing iterator dereference
        pos--;
        REQUIRE(*pos == "...");
        
        // testing iterator increment and decrement
        pos = list.begin();
        pos++;
        REQUIRE(*pos == "...");
        pos--;
        REQUIRE(*pos == "---");
        
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("List: insert with iterator at begin, middle, and one away from end")
	{
        std::list<std::string> list;
        std::list<std::string>::iterator pos;
        list.push_back("---");
        list.push_back("...");
        list.push_back("!!!");
        
		// insert in list with iterator at begin
        pos = list.insert(list.begin(), "***");
        REQUIRE(list.front() == "***");
        
        // at middle
        pos++;
        pos++;
        *pos = "^^^";
        REQUIRE(*pos == "^^^");
        
        // at one away from end
        pos = list.end();
        pos--;
        pos = list.insert(pos, "yyy");
        REQUIRE(*pos == "yyy");
        
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("List: erase with iterator at begin, middle, and one away from end")
	{
        std::list<std::string> list;
        std::list<std::string>::iterator pos;
        list.push_back("***");
        list.push_back("^^^");
        list.push_back("---");
        list.push_back("...");
        list.push_back("!!!");
        
        // erase with iterator at begin
        pos = list.erase(list.begin());
        REQUIRE(list.front() == "^^^");
        bool includes;
        for (std::string str : list) {
            if (str == "***") {
                includes = true;
            }
            else {
                includes = false;
            }
        }
        REQUIRE(includes == false);
        
        // at middle
        pos++;
        pos = list.erase(pos);
        bool inc;
        for (std::string s : list) {
            if (s == "---") {
                inc = true;
            }
            else {
                inc = false;
            }
        }
        REQUIRE(inc == false);
        
        // at one away from end
        pos = list.end();
        pos--;
        pos = list.erase(pos);
        bool is;
        for (std::string stri : list) {
            if (stri == "!!!") {
                is = true;
            }
            else {
                is = false;
            }
        }
        REQUIRE(is == false);

		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}
}

TEST_CASE("Student movie", "[student]") 
{
	SECTION("Bad constructor")
	{
        // testing a bad constructor
        bool badConstructor;
        try {
            // create a Movie Player using a string that does not reference a real file
            MoviePlayer mp = MoviePlayer("hi/notAnActualFile");
            badConstructor = false;
        }
        catch (const std::invalid_argument& e) {
            // if you caught the exception, then the contructor was bad
            badConstructor = true;
        }
        REQUIRE(badConstructor);
        
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Creating scene 2")
	{
        //creating a movie player object for scene 2
        bool works;
        try {
            MoviePlayer mp = MoviePlayer("input/scene2.ani");
            REQUIRE(mp.getFrameSize() == 13);
            works = true;
        }
        catch (const std::invalid_argument& e) {
            works = false;
        }
        REQUIRE(works);
        
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Checking frames, scene 2")
	{
		// checking frames for scene 2
        MoviePlayer mp = MoviePlayer("input/scene2.ani");
        
        std::stringstream ss;
        
        
        ss << "       /~\\                                   |       _______\n";
        ss << "      ( oo|                                  | \"\"   /       \\  oo*o\n";
        ss << "      _\\=/_                                  | :.  |         | o**o\n";
        ss << "     /     \\                       ___       |     |         | *oo*\n";
        ss << "    //|/.\\|\\\\                     / ()\\      | ##  |         | o**o\n";
        ss << "   ||  \\_/  ||                  _|_____|_    | ##   \\_______/\n";
        ss << "   || |\\ /| ||                 | | === | |   |______________________\n";
        ss << "   #  \\_ _/ #                  |_|  O  |_|  /\n";
        ss << "      | | |                     ||  O  ||  |------------------------\n";
        ss << "      | | |                     ||__*__||  | (*)\n";
        ss << "      []|[]                    |~ \\___/ ~| |\n";
        ss << "      | | |                    /=\\ /=\\ /=\\ |\n";
        ss << " ____/_]_[_\\___________________[_]_[_]_[_]_|________________________\n";
         
        

        REQUIRE(ss.str() == mp.getCurrFrame());
        
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}
}

