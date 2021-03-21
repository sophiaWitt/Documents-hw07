#include <fstream>
#include <iostream>
#include <sstream>

#include "movie.h"

// Function: Parameterized Constructor
// Purpose: Sets member variables to input, clears list, and calls loader
// Input: None
// Returns: Nothing
MoviePlayer::MoviePlayer(std::string filmName)
{
    // set the appropriate member variables
    mFilmName = filmName;
    currFrameNum = 1;
    pos = mFilm.begin();
    
    // ensure the tape is empty
    mFilm = {};
    mFilm.clear();
    
    // call loadTape to fill the tape
    loadTape();
}

MoviePlayer::~MoviePlayer()
{
    mFilm.clear();
}

void MoviePlayer::goFwrd()
{
    // should not go past the end of the movie
    if (currFrameNum == mFilm.size()) {
        rewind();
    }
    else {
        // move the tape forward by 1
        pos++;
        // increment currFrameNum
        currFrameNum++;
    }
}

void MoviePlayer::goBack()
{
    // should not go lower than frame 1
    if (currFrameNum == 1) {
        std::cout << "Beginning of film. Cannot go back." << std::endl;
    }
    else {
        // move the tape backwards by 1
        pos--;
        // decrease currFrameNum
        currFrameNum--;
    }
}

void MoviePlayer::rewind()
{
    // start the film over
    currFrameNum = 1;
    pos = mFilm.begin();
}

std::string MoviePlayer::getCurrFrame()
{
	// TODO: Fix return value
    
    
	return *(new std::string);
}

void MoviePlayer::delCurrFrame()
{
    // delete current frame
    mFilm.erase(pos);
    // move the tape forward by one
    // this function already updates the currPositionNum, keeping track of how many frames have been viewed
    // if the current frame is the end, it will rewind the film
    goFwrd();
}

void MoviePlayer::copyCurrFrame()
{
	// copy the current frame
    std:: string copy = *pos;

    // add the copy to mFilm just before the original frame
    pos--;
    mFilm.insert(pos, copy);
}

unsigned MoviePlayer::getCurrFrameNum() const
{
	return currFrameNum;
}

unsigned int MoviePlayer::getNumFrames() const
{
	return mFilm.size();
}

unsigned int MoviePlayer::getFrameSize() const
{
	return FRAMESIZE;
}

void MoviePlayer::loadTape()
{
    //  TODO: QUESTION: what do I do with the seperator? should I add that to the list too?
    // open the file
    std::ifstream fileInput(mFilmName);
    
    // make sure the file exists
    if (fileInput.is_open()) {
        // only read in lines until the end of the file
        while (!fileInput.eof()) {
            // first line is the seperator
            std::string seperator;
            
            std::getline(fileInput, seperator);
            
            // 13 lines afterwards is the image
            std::string image;
            for (int i = 0; i < FRAMESIZE; i++) {
                std::getline(fileInput, image);
            }
            
            // add the image to the list
            mFilm.push_back(image);
        }
    }
    else {
        std::cout << "Error: File not found :(" << std::endl;
    }
    
    // close the file
    fileInput.close();
}

