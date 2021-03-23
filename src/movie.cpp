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
        //TODO: QUESTIONS FOR TA
        // what should I do instead of this.
        // what can I signal to end the film 
        // i think the issue is that when it does go forward and it hits the end of the film it prints "End of film.Cannot go forward" over and over again until i stop the film.
        // what should i do instead?
        // maybe this is the case for all the github things? am i just handling errors wrong?
        // should I throw an exception instead?
        
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
        // same thing as goforward. how do i get it to stop.
        
        
        
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
    // cannot delete frame if there are no frames
    if (getNumFrames() != 1) {
        // delete current frame
        mFilm.erase(pos);
        // move the tape forward by one
        // this function already updates the currPositionNum, keeping track of how many frames have been viewed
        // if the current frame is the end, it will rewind the film
        if (currFrameNum == mFilm.size()) {
            goBack();
        }
        else if (currFrameNum < mFilm.size()){
            goFwrd();
        }
        
    }
    else {
        std::cout << "Cannot delete the frame or else there will not be any left." << std::endl;
    }
}

void MoviePlayer::copyCurrFrame()
{
	// copy the current frame
    std:: string copy = *pos;

    // add the copy to mFilm just before the original frame
    pos--;
    mFilm.insert(pos, copy);
}

//TODO: QUESTION: is this wrong?
unsigned MoviePlayer::getCurrFrameNum() const
{
	return currFrameNum;
}

unsigned int MoviePlayer::getNumFrames() const
{
	return mFilm.size();
    //return mFilm.size();
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
            
            std::string line;
            for (int i = 0; i < FRAMESIZE; i++) {
                std::getline(fileInput, line);
                sss << line << "\n";
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
        // same question as the go forward and back - is this not supposed to be here?
        
        
        
    }
    
    // close the file
    fileInput.close();
}

