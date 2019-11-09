/**
 * Mint is a minimal header-only C++ test runner.
 *
 * @author Luiserebii <luis@serebii.io>
 * @license MIT
 *
 */

#include <iostream>
#include <string>

class Mint { 

    public:
        enum Status { PASS, FAIL };

        //Constructors
        Mint();

        Status getStatus() const { return status; }
        
        template <class T> void assert(const T val, const T exp);


    private:
        Status status;



};

Mint::Mint(): status(PASS) {

}

template <class T>
void Mint::assert(const T val, const T exp) {
    if(val != exp) std::cout << "FAIL: Expected int \"" << exp << "\", found: \"" << val << "\"" << std::endl;
}
/*
inline void assert(bool b, const std::string& s) {
    if(!b) std::cout << "FAIL: " << s << std::endl;
}*/

