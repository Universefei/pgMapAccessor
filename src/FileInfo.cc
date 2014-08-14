#include "FileInfo.h"

FileInfo::FileInfo()
{
}

FileInfo::~FileInfo()
{
}

/**
 * geters
 */

string
FileInfo::getName()
{
    return name_;
}

int
FileInfo::getSize()
{
    return size_;
}

int 
FileInfo::getPos();
{
    return  pos_;
}

EFormat
FileInfo::getFormat()
{
    return eFormat_;
}


/**
 * Setters
 */
int
FileInfo::setName(string& name)
{
    name_=name;
    return 1;
}

int
FileInfo::setSize(int size)
{
    size_=size;
    return 1;
}

int
FileInfo::setPos(int pos)
{
    pos_=pos;
    return 1;
}

int
FileInfo::setFormat(EFormat format)
{
    format_=format;
    return 1;
}


/**
 * functions
 */
int
FileInfo::convertFormatTo(EFormat eTarFormat)
{
    //TODO:do converte
    //size_=
    format_=eTarFormat;
    return 1;
}
