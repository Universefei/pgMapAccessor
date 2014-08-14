#ifndef WFSGETCAPABILITIES_H
#define WFSGETCAPABILITIES_H

namespace PGMA
{

/**
 * WFSCapabilities store data that needed in getCapabilities request
 */
class WFSCapabilities
{
};

class WFSGetCapabilities : public WFSQuery
{
    WFSCapabilities*    getWFSCapabilities();
public:

};



} // namespace
