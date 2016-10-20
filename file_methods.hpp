/*

file_methosd.hpp

Methods used to compare the two directories

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

#ifndef FILE_METHODS_HPP
#define FILE_METHODS_HPP
#include<iostream>
#include<string>
#include<boost/filesystem.hpp>

namespace bfile = ::boost::filesystem;

////////////////////////////////////////////////////////////////////////////////
//  Compares directories A and B for files unique by name, and reports them
//  to standard output
////////////////////////////////////////////////////////////////////////////////

void compare_directories(std::string A, std::string B);


////////////////////////////////////////////////////////////////////////////////
//  Seeks directory dir_path for a file with name file_name, and if found stores
//      this in path_found.
//  Returns true if the file was found, false if not
////////////////////////////////////////////////////////////////////////////////

bool find_file( const boost::filesystem::path & dir_path,  
                const std::string & file_name, 
                boost::filesystem::path & path_found );  


////////////////////////////////////////////////////////////////////////////////
//  Compares folders A and B, outputting files that are unique to A by
//  searching B for them, and reporting to standard output if not found.
//  This is A Brute Force method used only in testing.
////////////////////////////////////////////////////////////////////////////////

void find_As_filenames_in_B(std::string A, std::string B);


#endif
