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
    

pravite:
    virtual MemBuf  writeToKMLBuf();
    virtual MemBuf  writeToGMLBuf();
    virtual MemBuf  writeToGeojsonBuf();

    virtual FileInfo    writeToKMLFile(string& filePath);
    virtual FileInfo    writeToGMLFile(string& filePath);
    virtual FileInfo    writeToGeojsonFile(string& filePath);

    // User demaind return format.
    enum EFormat eRetFormat_;
}


} // namespace PGMA

