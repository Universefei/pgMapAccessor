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
    EFormat getFormat();

    /**
     * setters
     */
    int     setName(string& name);
    int     setSize(int size)
    int     setPos(int pos);
    int     setFormat(EFormat format);

    /**
     * functions
     */
    int     convertFormatTo(EFormat eTarFormat);

private:
    string  name_;
    int     size_;
    int     pos_;
    EFormat format_;
}

} // namespace PGMA
