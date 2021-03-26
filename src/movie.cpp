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
    // set the member variable mFilm to the inputted filmName
    mFilmName = filmName;

    // ensure the tape is empty
    mFilm.clear();
    
    // call loadTape to fill the tape and rewind to the beginning of the film
    loadTape();
    // calling rewind will set the member variables currFrameNum and pos
    rewind();
}

MoviePlayer::~MoviePlayer()
{
    // clear the film
    mFilm.clear();
}

void MoviePlayer::goFwrd()
{
    // should not go past the end of the movie
    if (currFrameNum != mFilm.size()) {
        // move the tape forward by 1
        pos++;
        // increment currFrameNum
        currFrameNum++;
    }
}

void MoviePlayer::goBack()
{
    // should not go lower than frame 1
    if (currFrameNum != 1) {
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
    // return the dereferenced iterator pointer
	return *pos;
}

void MoviePlayer::delCurrFrame()
{
    // cannot delete frame if there are no frames
    if (pos != mFilm.end()) {
        // delete current frame
        pos = mFilm.erase(pos);
    }
    else {
        std::cout << "Cannot delete the frame or else there will not be any left." << std::endl;
    }
}

void MoviePlayer::copyCurrFrame()
{
	// copy the current frame
    pos = mFilm.insert(pos, *pos);
}

unsigned MoviePlayer::getCurrFrameNum() const
{
    //return the current frame num member variable
	return currFrameNum;
}

unsigned int MoviePlayer::getNumFrames() const
{
    // return the size of the member variable mFilm minus 1
    return mFilm.size() - 1;
}

unsigned int MoviePlayer::getFrameSize() const
{
    // return the framesize member variable
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
            // first line is the seperator (the number of times each image should be shown)
            std::string seperator;
            std::getline(fileInput, seperator);
            
            // converting the seperator to an int
            int sep;
            std::stringstream ss;
            ss << seperator;
            ss >> sep;
           
            // 13 lines afterwards is the image
            std::stringstream sss;
            // loop through the lines within framezine
            std::string line;
            for (int i = 0; i < FRAMESIZE; i++) {
                std::getline(fileInput, line);
                // add each line and a new line to the stringstream
                if (line[line.size() - 1] == '\\') {
                    sss << line << " \n";
                }
                else {
                    sss << line << "\n";
                }
            }
            // convert the stringstream to a string
            std::string image;
            image = sss.str();
            
            // add the image to the list as many times as the seperator says
            for (int j = 0; j < sep; j++) {
                mFilm.push_back(image);
            }
            
        }
    }
    else {
        throw std::invalid_argument("File not opening.");
    }
    
    // close the file
    fileInput.close();
}

