/*

file_methods.cpp

Utility file methods using boost::filesystem

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

#include"file_methods.hpp"


////////////////////////////////////////////////////////////////////////////////
//  Compares directories A and B for files unique by name, and reports them
//  to standard output
////////////////////////////////////////////////////////////////////////////////

// See http://www.boost.org/doc/libs/1_41_0/libs/filesystem/example/simple_ls.cpp for is_regular_file amendments

void compare_directories(std::string A, std::string B)
{
    boost::filesystem::path a_path(A);
    boost::filesystem::path b_path(B);
    
    boost::filesystem::directory_iterator end;
    boost::filesystem::directory_iterator a_itr(a_path);
    boost::filesystem::directory_iterator b_itr(b_path);
    
    std::vector<std::string> a_unique;
    std::vector<std::string> b_unique;
    
    // Iterate through the directories in tandem, noting any unique files along
    //  the way until non-unique files have been matched.
    
    while(1)
    {
        if(a_itr == end)
        {
            for( ;b_itr!=end; ++b_itr)
            {
                b_unique.push_back(b_itr->path().leaf().string());
            }
            break;
        }
        else if (b_itr == end)
        {
            for( ;a_itr!=end; ++a_itr)
            {
                a_unique.push_back(a_itr->path().leaf().string());
            }
            break;
        }
        
        std::string a_filename = a_itr->path().leaf().string();
        std::string b_filename = b_itr->path().leaf().string();
        
        if(a_filename < b_filename)
        {
            a_unique.push_back(a_filename);
            ++a_itr;
        }
        else if (b_filename < a_filename)
        {
            b_unique.push_back(b_filename);
            ++b_itr;
        }
        else
        {
            ++a_itr;
            ++b_itr;
        }
    }
    
    // Output unique files
    
    std::cout << a_unique.size() << " file-names unique to " << A <<":\n";
    for(auto itr = a_unique.begin(); itr != a_unique.end(); ++itr)
    {
        std::cout << *itr << '\n';
    }
  
    std::cout << "\n\n" << b_unique.size() << " file-names unique to " << B <<":\n";
    for(auto itr = b_unique.begin(); itr != b_unique.end(); ++itr)
    {
        std::cout << *itr << '\n';
    }
}



////////////////////////////////////////////////////////////////////////////////
//  Seeks directory dir_path for a file with name file_name, and if found stores
//      this in path_found.
//  Returns true if the file was found, false if not
////////////////////////////////////////////////////////////////////////////////

bool find_file( const boost::filesystem::path & dir_path,        
                const std::string & file_name, 
                boost::filesystem::path & path_found )           
{
  using namespace boost::filesystem;
  
  if ( !exists( dir_path ) )
  {
      return false;
  }
  
  directory_iterator end_itr; // default construction yields past-the-end
  
  for ( directory_iterator itr( dir_path );
        itr != end_itr;
        ++itr )
  {
    if ( is_directory(itr->status()) )
    {
        if ( find_file( itr->path(), file_name, path_found ) )
        {
            return true;
        }
    }
    else if ( itr->path().leaf() == file_name ) // see below
    {
        path_found = itr->path();
        return true;
    }
  }
  
  return false;
}


////////////////////////////////////////////////////////////////////////////////
//  Compares folders A and B, outputting files that are unique to A by
//  searching B for them, and reporting to standard output if not found.
//  This is A Brute Force method used only in testing.
////////////////////////////////////////////////////////////////////////////////

void find_As_filenames_in_B(std::string A, std::string B)
{
    boost::filesystem::path files_to_find_directory(A);
    boost::filesystem::path search_directory(B);
    boost::filesystem::path found_path;
    
    boost::filesystem::directory_iterator end;
    for (boost::filesystem::directory_iterator itr(files_to_find_directory);
         itr != end;
         ++itr) {
        if(!find_file(search_directory, itr->path().leaf().string(), found_path))
        {
            std::cout << *itr << std::endl;
        }
    }
    
    std::cin.get();
}


