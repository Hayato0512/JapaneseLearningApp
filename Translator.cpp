/*
 * Translator.cpp
 * 
 * Description: Translator application 
 *               
 *
 * Author: Hayato Koyama
 * Last Modification Date: March 3rd. 2022
 */


/*
when you run, just type in the terminal the following 

g++ -o hack Translator.cpp WordPair.cpp

this means, telling compiler to include Translator.cpp and WordPair.cpp so that we can run them together.
and -o (NameOfExecutable) means, name the executable "hack", 
so, after typing 

g++ -o hack Translator.cpp WordPair.cpp
,
it will create an executable called "hack" in this hackathon folder, 
so, after that we can just type

./hack

and it will be run. 

everytime you make changes in  either Translator.cpp or WordPair, you need to do

g++ -o hack Translator.cpp WordPair.cpp

again, because executable "hack" is not gonna reflect the change otherwise.
*/




#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "WordPair.h"
//#include "ElementAlreadyExistsException.h"
//#include "ElementDoesNotExistException.h"
//#include "EmptyDataCollectionException.h"
//#include "Dictionary.h"

//description : desplay the content of anElement.
//              will be passed as an argument when needed.
void display(const WordPair& anElement) {
  cout << anElement << endl;
} // end of display



int main(int argc, char *argv[]) {
  WordPair array[50];
  //initiate the function pointer that points display() to pass it to a function.
  //void (*fun_ptr)(const WordPair&) = &display;
 
  //Dictionary<WordPair>* dict = new Dictionary<WordPair>();
  


  string aLine = "";
  string aWord = "";
  string slangW = "";
  string translationW = "";
  string filename = "myDataFile.txt";
  string delimiter = ":";
  size_t pos = 0;
  WordPair translated;
 
  //read texts from the file myDataFile.text
  ifstream myfile (filename);
  if (myfile.is_open()) {
    int i = 0;
    while ( getline (myfile,aLine) )
    { 
       pos = aLine.find(delimiter);
       //get the english word first
       slangW = aLine.substr(0, pos);
       aLine.erase(0, pos + delimiter.length());
       //get the translation next
       translationW = aLine;
       //make a WordPair object with obtained english and translation.
       WordPair aWordPair(slangW, translationW);
     
        array[i] = aWordPair;
        i++;
        
    }
    myfile.close();


    int userInput;
    cout<<"Hello, this is slang-translation app. What do you want to do?"<<endl;
    bool userDone = false;
    while(!userDone){
       cout<<"1, display \n2, test\n3, done"<<endl;
    cin>>userInput;
    if(userInput ==1){
      for(int i = 0;i<50;i++){
        cout<<array[i]<<endl;

      }
      
    }
    else if(userInput == 2){
      cout<<"Ok!!! let's test it."<<endl;
      
      //WordPair array[dict->getElementCount()];
      //WordPair pickedWord = dict->getRandomPair();
      int testScore = 0;
      for(int i = 0;i<10;i++){
          cout<<"\ntype your guess"<<endl;
          srand(time(0));
        WordPair toBeTested = array[rand()%50];
        cout<<toBeTested.getTranslation()<<endl;
        
        string userAnswer;
        cin >> userAnswer;
        if(userAnswer == toBeTested.getEnglish()){
            cout<<"\ncorrect !\n"<<endl;
            testScore++;
        }
      }
      cout<<"Your total score is "<<testScore<<endl;
      

      //cout<<pickedWord<<endl;
    }
    else if(userInput == 3){
      cout<<"OK!! thank you for using our translation app. see you around."<<endl;
      userDone = true;
    }
    }
    
   
    
    
    // If user entered "Display" at the command line ...
    // if ( ( argc > 1 ) && ( strcmp(argv[1], "display") == 0) ) {
    //     // ... then display the contents of the dictionary.
    //     dict->displayContent(*fun_ptr);
    // }
    // else if (argc == 1) {//if no argument, 
    //    // while user has not entered CTRL+D
    //    while ( getline(cin, aWord) ) {   

    //       //if user input "Display", display all the contents in ascending order.
    //       if(aWord=="display"){
    //         dict->displayContent(*fun_ptr);
    //       }
    //       else{
    //         //initiate WordPair object with the english that user entered.
    //         WordPair aWordPair(aWord);
    //         //search this word in the testing BST, if a word is found as a substring, then retrieve that element
    //         try{
    //             WordPair result = dict->get(aWordPair.getEnglish());
    //             cout<<endl<< result<<endl;
    //         } 
    //         //if not found, print "**NOT FOUND**".
    //         catch(ElementDoesNotExistException&anException){
    //           cout<<"**NOT FOUND**"<<endl;
    //         }
    //       }
         

    //    }
    // }
    //free the allocated dictionary object at the end.
    //delete dict;
  }
  else 
    cout << "Unable to open file"; 
  
  
  return 0;
}

/*
Savage: The cool way to say “cool.”
Woke: Highly aware of social issues.
Boots: This is a way to say “very” or “a lot.” It’s added after the verb or adjective.
Squad:Term for their friend group
FOMO:“Fear of missing out.”
Gucci:Something is good or cool
*/