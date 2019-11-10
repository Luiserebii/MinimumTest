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
        void assert(bool b, const std::string& title, const std::string& fail);
        template <class T> void equal(const T val, const T exp, const std::string& title);
        void throws(void f(), const std::string& title, const std::string& fail);

        //Other
        int end();

    private:
        Status::Enum status;
        std::string tab;
        int testsPassing;
        int testsFailing;

        std::ostream& writeTestPass(const std::string& title);
        std::ostream& writeTestFail(const std::string& title, const std::string& fail);
};

Mint::Mint(): status(Status::SUCCESS), tab(std::string(4, ' ')), testsPassing(0), testsFailing(0) {

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


void Mint::assert(bool b, const std::string& title, const std::string& fail) {
    if(!b) { 
        std::cout << "✘ " << title << std::endl
            << tab << "FAIL: " << fail << std::endl;
        status = Status::FAIL;
        ++testsFailing;
    } else {
        std::cout << "✔ " << title << std::endl;
        ++testsPassing;
    }
}

template <class T>
void Mint::equal(const T val, const T exp, const std::string& title) {
    if(val != exp) {
        std::cout << "✘ " << title << std::endl
            << tab << "FAIL: Expected \"" << exp << "\", found: \"" << val << "\"" << std::endl;
        status = Status::FAIL;
        ++testsFailing;
    } else {
        std::cout << "✔ " << title << std::endl;
        ++testsPassing;
    }
}

void Mint::throws(void f(), const std::string& title, const std::string& fail) {
    try {
        f();
    } catch(...) {
        std::cout << "✔ " << title << std::endl;
        ++testsPassing;
        return;
    }
    std::cout << "✘ " << title << std::endl
        << tab << "FAIL: " << fail << " (function did not throw)" << std::endl;
    ++testsFailing;
}

int Mint::end() {
    if(status == Status::SUCCESS) {
        std::cout << std::endl << "SUCCESS! All tests (" << testsPassing << 
            ") passing with no tests failing. Returned with exit code \"" << status << "\"." << std::endl;
    } else if(status == Status::FAIL) {
        std::cout << std::endl << "FAIL! " << testsFailing << " tests failing with " << testsPassing 
            << " tests passing. Returned with exit code \"" << status << "\"." << std::endl;
    }
    //Return status as exit code
    return status;
}


std::ostream& writeTestPass(const std::string& title) {
    return std::cout << "✔ " << title << std::endl;
}
