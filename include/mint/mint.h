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
            enum Enum { SUCCESS, FAIL };
        };

        //Constructors
        Mint();

        //Getters/setters
        Status::Enum getStatus() const { return status; }
        std::string getTab() const { return tab; }
        std::string setTab(std::string t) { tab = t; }

        //Test titling functions
        void title(const std::string& title, int borderNum=2);

        //Assert functions       
        void assert(bool b, const std::string& title, const std::string& s);
        template <class T> void equal(const T val, const T exp, const std::string& title);

        //Other
        int end();

    private:
        Status::Enum status;
        std::string tab;
};

Mint::Mint(): status(Status::SUCCESS), tab(std::string(4, ' ')) {

}

void Mint::title(const std::string& title, int borderNum) {
    //Create border
    int size = title.length() + (borderNum * 2); 
    std::string border(size, '=');
    std::string pad(borderNum, ' ');
    //Print
    std::cout << border << std::endl << pad << title << std::endl 
        << border << std::endl;
}


void Mint::assert(bool b, const std::string& title, const std::string& s) {
    std::cout << title;
    if(!b) { 
        std::cout << " ✘" << std::endl
            << tab << "FAIL: " << s << std::endl;
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
            << tab << "FAIL: Expected \"" << exp << "\", found: \"" << val << "\"" << std::endl;
        status = Status::FAIL;
    } else {
        std::cout << " ✔" << std::endl;
    }
}

int Mint::end() {
    if(status == Status::SUCCESS) {
        std::cout << std::endl << "All tests passing! Returned with exit code \"" << status << "\"." << std::endl;
    } else if(status == Status::FAIL) {
        std::cout << std::endl << "Tests failing! Returned with exit code \"" << status << "\"." << std::endl;
    }
    //Return status as exit code
    return status;
}

