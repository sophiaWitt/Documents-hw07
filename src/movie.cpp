#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "movie.h"

// ITP 365 Spring 2021
// HW07 – Movie Player
// Name: Sophia Wittmeier
// Email: wittmeie@usc.edu
// Platform: Mac

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
        //rewind();
        std::cout << "End of film. Cannot go forward." << std::endl;
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
	return *pos;
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
	return (mFilm.size() - 1);
}

unsigned int MoviePlayer::getFrameSize() const
{
	return FRAMESIZE;
}

void MoviePlayer::loadTape()
{
    // open the file
    std::ifstream fileInput(mFilmName);
    
    // make sure the file exists
    if (fileInput.is_open()) {
        // only read in lines until the end of the file
        while (!fileInput.eof()) {
            // first line is the seperator
            std::string seperator;
            std::getline(fileInput, seperator);
            
            // converting the seperator to an int
            int sep;
            std::stringstream ss;
            ss << seperator;
            ss >> sep;
           
            // 13 lines afterwards is the image
            std::stringstream sss;
            
            std::string lin;
            for (int i = 0; i < FRAMESIZE; i++) {
                std::getline(fileInput, lin);
                sss << lin << "\n";
            }
            std::string image;
            image = sss.str();
            
            // add the image to the list as many times as the seperator says
            for (int j = 0; j < sep; j++) {
                mFilm.push_back(image);
            }
            
        }
    }
    else {
        std::cout << "Error: File not found :(" << std::endl;
    }
    
    // close the file
    fileInput.close();
}

