#ifdef PGMAQUERY_H
#define PGMAQUERY_H
#include <isotram>
#include "misc.h"

namespace PGMA
{

class MemBuf;

class PgMAQuery
{
public:
    /**
     * constructor
     */
    PgMAQuery();
    PgMAQuery(EFormat eRetFmt);


    /**
     * destructor
     */
    ~PgMAQuery();


    /**
     * @brief:      write query data to a file in disk.
     * @eFormat:    output file format supported in EFormat enum definition.
     * @filePath:   output file path on disk.
     */ 
    FileInfo        writeToFile(EFormat eFileFormat, string& filePath);

    FileInfo        writeToFile(string& filePath);
    /**
     * @brief:      write query data into a buffer in internal storage.
     * @eFormat:    output buffer data format.
     */
    MemBuf      writeToBuf(EFormat eFormat);

    MemBuf      writeToBuf();
    

//pravite:
protected:
    virtual MemBuf  writeToXMLBuf();
    virtual MemBuf  writeToKMLBuf();
    virtual MemBuf  writeToGMLBuf();
    virtual MemBuf  writeToGeojsonBuf();
    virtual MemBuf  writeToShapefileBuf();

    virtual FileInfo    writeToXMLFile(string& filePath);
    virtual FileInfo    writeToKMLFile(string& filePath);
    virtual FileInfo    writeToGMLFile(string& filePath);
    virtual FileInfo    writeToGeojsonFile(string& filePath);
    virtual FileInfo    writeToShapefileFile(string& filePath);

private:
    // User demaind return format.
    enum EFormat eRetFormat_;
}


} // namespace PGMA

