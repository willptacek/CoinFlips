#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
//Coin Flips by Will Ptacek
//The goal of the program is to get input from a user on how many times the coin will flip.
//Then, the program will show the different combinations possible from the all of the flips.
//Made in about an hour on 11/9/2018
int main() {
    std::vector<std::string> outcomes; //Primary vector for outcomes (H dominated)
    std::vector<std::string> outcomes2; //Secondary (T dominated)
    std::string final, prog;

    int flips = 0, dummy = 0, charCount = 0, topBinaryNumber;

    std::cout << "How many flips of the coin?\n";
    std::cin >> flips;

    topBinaryNumber = pow(2, flips); //This determines how far the program should go in terms of binary calcs

    for(int i = 0; i < topBinaryNumber; i++) {
        final.clear();
        dummy = i;
        charCount = 0;
        while (dummy != 0) { //When dummy = 0, that means that no more division can be done and the binary number is complete
            prog.clear();
            prog = std::to_string(dummy % 2); //the string prog is always a 1 or a 0, appending to final
                                                //builds the binary number
            final.append(prog);
            dummy = dummy / 2;//does the necessary division for binary conversion
            charCount++;//tracks char count, as only the outcomes with x 'flips' are necessary
        } if(charCount == flips){
            std::replace(final.begin(), final.end(), '1', 'H'); //this is for the first string vector, changes all of
                                                                //1's to H's and 0's to T's, to represent coin flips
            std::replace(final.begin(), final.end(), '0', 'T');

            outcomes.push_back(final);

            std::replace(final.begin(), final.end(), 'H', '0');//Does the same thing but for the second vector
            std::replace(final.begin(), final.end(), 'T', 'H');
            std::replace(final.begin(), final.end(), '0', 'T');

            outcomes2.push_back(final);
        }
    }

    for(int i = 0; i < outcomes.size(); i++){
        std::cout << outcomes[i] << " " << outcomes2[i] << std::endl; //Prints
    }
    return 0;
}