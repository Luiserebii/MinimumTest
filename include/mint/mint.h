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
        //Substitute for scoped enums - meant to be compatible pre-C++11
        struct Status {
            enum Enum { PASS, FAIL };
        };

        //Constructors
        Mint();

        Status::Enum getStatus() const { return status; }
 
        //Test titling functions
        void title(const std::string& title, int borderNum=2);

        //Assert functions       
        void assert(bool b, const std::string& title, const std::string& s);
        template <class T> void equal(const T val, const T exp, const std::string& title);


    private:
        Status::Enum status;
};

Mint::Mint(): status(Status::PASS) {

}

void Mint::title(const std::string& title, int borderNum) {
    //Create border
    int size = title.length() + (borderNum * 2); 
    std::string border('=', size);
    //Print
    std::cout << border << std::endl << title << std::endl 
        << border << std::endl;
}


void Mint::assert(bool b, const std::string& title, const std::string& s) {
    std::cout << title;
    if(!b) { 
        std::cout << " ✘" << std::endl
            << "FAIL: " << s << std::endl;
        status = Status::FAIL;
    } else {
        std::cout << " ✔" << std::endl;
    }
}

template <class T>
void Mint::equal(const T val, const T exp, const std::string& title) {
    std::cout << title;
    if(val != exp) {
        std::cout << " ✘" << std::endl
            << "FAIL: Expected \"" << exp << "\", found: \"" << val << "\"" << std::endl;
        status = Status::FAIL;
    } else {
        std::cout << " ✔" << std::endl;
    }
}


