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
 
        //Assert functions       
        void assert(bool b, const std::string& s);
        template <class T> void equal(const T val, const T exp);


    private:
        Status::Enum status;
};

Mint::Mint(): status(Status::PASS) {

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


