#ifndef MEMBUF_H
#define MEMBUF_H

namespace PGMA
{ // namespace

/*****************************************************************************/
class MemBuf
{
public:
    MemBuf();
    ~MemBuf();

private:
    const char*     pBuf_;
    int             iSize_;
    int             pos_;

}


} // namespace
