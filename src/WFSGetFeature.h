#ifndef WFSGETFEATURE_H
#define WFSGETFEATURE_H

namespace PGMA
{


class WFSGetFeature : public WFSQuery
{
    typeName_;
    outputFormat_;
    bBox_;
    filter_;
    sortBy_;
    maxFeatures_;
    protertyName_;
    srsName_;
    featureID_;
    expiry_;
    resultType_;
    featureVersion_;

    // functions
    OGRLayer*   getOGRLayer();

public:
    WFSGetFeature();
    ~WFSGetFeature();

    /// Setters
    void setTypeName();

    /// Getters
    
};







}// namespace


#endif // WFSGETFEATURE
