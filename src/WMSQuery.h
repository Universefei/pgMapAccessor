#ifndef WMSQUERY_H
#define WMSQUERY_H


#include "PgMAQuery.h"

// using WFSQuery to implement some virtual functions inherit from PgMAQuery.
class WMSQuery : public PgMAQuery
{
public:
    WMSQuery();
    ~WMSQuery();



}



