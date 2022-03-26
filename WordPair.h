/*
 * WordPair.h
 * 
 * Description: Models an English word and its translation in another language.
 * 
 * Author: AL
 * Date of last modification: Feb. 2022
 */

#pragma once

#include <string>
#include <ostream>

using namespace std;

class WordPair {

private:
	string slang;
	string translation;
	
public:
	// Constructors
	WordPair() ;
	WordPair(string slang) ;
	WordPair(string slang, string translation) ;

	// Getters
	string getEnglish() const ;
	string getTranslation() const ;

	// Setters
	void setEnglish(string slang) ;
	void setTranslation(string translation) ;

	// Overloaded Operators
	bool operator==(const WordPair& rhs) const;
	bool operator<(const WordPair& rhs) const;
	bool operator>(const WordPair& rhs) const;

	// For testing purposes!
	// Description: Prints the content of "wP".
	friend ostream & operator<<(ostream & os, const WordPair & wP);

}; // end of WordPair.h