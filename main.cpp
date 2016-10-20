/*

main.cpp

FolderCompare - compares two directories file lists and reports any files which
are unique by name between these folders, if any.

Arguments - two folders - simply drag the two directories in or name them if
using command line.


-----------
MIT License

Copyright (c) 2016 Tony Alastair Brown

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#include<iostream>
#include<string>
#include<boost/filesystem.hpp>
#include"file_methods.hpp"

namespace bfile = ::boost::filesystem;

////////////////////////////////////////////////////////////////////////////////
//  main - run the FolderCompare program
////////////////////////////////////////////////////////////////////////////////


int main(int argc, char ** argv)
{
    try
    {
        if(argc != 3)
        {
            std::cout << "FolderCompare - compares two directories file lists  \
                          and reports any files which are unique by name       \
                          between these folders, if any. \n\n                  \
                          Arguments - two folders - simply drag the two        \
                          directories in or name them if using command line.";
            std::cin.get();
            return 0;
        }
        
        std::string A(argv[1]);
        std::string B(argv[2]);
        
        std::cout << "Comparing " << A << " with " << B <<":\n";
        compare_directories(A,B);  
        
        std::cin.get();
        return 0;      
    }
    catch(bfile::filesystem_error &e)
    {
        std::cout << "\nA boost filesystem error occurred:" << e.what(); 
        std::cin.get();  
        return 2;
    }
    catch(std::exception &e)
    {
        std::cout << "\nA std::exception has been thrown" << e.what();
        std::cin.get();
        return 1;
    }
    

}



