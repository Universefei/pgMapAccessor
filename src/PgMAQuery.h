#ifndef PGMAQUERY_H
#define PGMAQUERY_H
#include <isotream>
#include "misc.h"
#include "FileInfo.h"
#include "MemBuf.h"

namespace PGMA
{

/*****************************************************************************/
/*                              class ConnInfo                               */
/*****************************************************************************/
class ConnInfo
{
    string hostname_;
    string port_;
    string username_;
    string password_;
    string dbname_;
public:
    /**
     * Constructor
     */
    ConnInfo();

    /**
     * Destructor
     */
    ~ConnInfo();

    /**
     * setters and getters
     */
    void setHostname(string hostname);
    void setPort(string port);
    void setUsername(string username);
    void setPassword(string password);
    void setDbname(string dbname);
}

/*****************************************************************************/
/*                              class PgMAQuery                              */
/*****************************************************************************/
class PgMAQuery
{
    // User demaind return format.
    enum EFormat eRetFormat_;
    ConnInfo*   pPgConn_;
    OGRDataSource* pPgDS_;
public:
    /**
     * constructor
     */
    PgMAQuery();
    PgMAQuery(EFormat eRetFmt=eF_XML, const ConnInfo& connInfo);


    /**
     * destructor
     */
    ~PgMAQuery();


    /**
     * @brief:      write query data to a file in disk.
     * @eFormat:    output file format supported in EFormat enum definition.
     * @filePath:   output file path on disk.
     */ 
    FileInfo*        writeToFile(EFormat eFileFormat, string& filePath);

    /**
     * @brief:      write query data to a file in disk with default format XML.
     * @filePath:   output file path on disk.
     */ 
    FileInfo*        writeToFile(string& filePath);

    /**
     * @brief:      write query data into a buffer in internal storage.
     * @eFormat:    output buffer data format.
     */
    MemBuf*      writeToBuf(EFormat eFormat);

    /**
     * @brief:      write query data into a buffer with default format XML.
     */
    MemBuf*      writeToBuf();
    
//private:
protected:

    PgMA_err    connectDB(ConnInfo& connInfo );

    virtual MemBuf*  writeToXMLBuf();
    virtual MemBuf*  writeToKMLBuf();
    virtual MemBuf*  writeToGMLBuf();
    virtual MemBuf*  writeToGeojsonBuf();
    virtual MemBuf*  writeToShapefileBuf();

    virtual FileInfo*    writeToXMLFile(string& filePath);
    virtual FileInfo*    writeToKMLFile(string& filePath);
    virtual FileInfo*    writeToGMLFile(string& filePath);
    virtual FileInfo*    writeToGeojsonFile(string& filePath);
    virtual FileInfo*    writeToShapefileFile(string& filePath);

};


} // namespace PGMA
#endif // PGMAQUERY_H
