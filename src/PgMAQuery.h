#ifdef PGMAQUERY_H
#define PGMAQUERY_H
#include <isotram>


//class MemBuf;

class pgMAQuery
{
public:
    pgMAQuery();
    ~pgMAQuery();

    MemBuf serilization();

pravite:
    enum ERetType retType_;


}

