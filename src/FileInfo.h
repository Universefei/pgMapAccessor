#ifndef FILEINFO_H
#define FILEINFO_H

#include <iostream>

namespace PGMA
{

class FileInfo
{
public:
    FileInfo();
    ~FileInfo();


    /**
     * geters
     */
    string  getName();
    int     getSize();
    int     getPos();

    /**
     * setters
     */
    int     setName(string& fileName);
    int     setPos(int iPos);

private:
    string  name_;
    int     size_;
    int     pos_;
}

} // namespace PGMA
