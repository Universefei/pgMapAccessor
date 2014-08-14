#ifndef WFSQUERY_H
#define WFSQUERY_H


#include "PgMAQuery.h"

// using WFSQuery to implement some virtual functions inherit from PgMAQuery.
class WFSQuery : public PgMAQuery
{
public:
    WFSQuery();
    ~WFSQuery();

}



