#include "PgMAQuery.h"

PgMAQuery::PgMAQuery()
{
}

PgMAQuery::PgMAQuery(EFormat eRetFmt)
{
    eRetFormat_=eRetFmt;
}

PgMAQuery::~PgMAQuery()
{
}

/**
 * @brief       : write data to file.
 * @filePath    : output file path with file name.
 */
FileInfo
PgMAQuery::writeToFile(string& filePath)
{
    return writeToFile(eRetFormat_, filePath);
}

/**
 * @brief       : write data to specified format file.
 * @eFileFormat : output file format.
 * @filePath    : output file path with file name.
 */
FileInfo
PgMAQuery::writeToFile(EFormat eFileFormat, string& filePath)
{
    switch(eFileFormat)
    {
        case eF_XML:
            return writeToXMLFile(filePath);
        case eF_KML:
            return writeToKMLFile(filePath);
        case eF_GML:
            return writeToGMLFile(filePath);
        case eF_Geojson:
            return writeToGeojsonFile(filePath);
        case eF_Geojson:
            return writeToShapefileFile(filePath);
        // add more supported format here.
        default:
            {
                //TODO: throw exception : format not supported.
            }
    }
}

/**
 * @brief       : write data to memory buffer.
 */
MemBuf
PgMAQuery::writeToBuf()
{
    return writeToBuf(eRetFormat_);
}

/**
 * @brief       : write data to memory buffer.
 * @eFormat     : output buf format
 */
MemBuf
PgMAQuery::writeToBuf(EFormat eFormat)
{
    switch(eFormat)
    {
        case eF_XML:
            return writeToXMLBuf();
        case eF_KML:
            return writeToKMLBuf();
        case eF_GML:
            return writeToGMLBuf();
        case eF_Geojson:
            return writeToGeojsonBuf();
        case eF_Geojson:
            return writeToShapefileBuf();
        // add more supported format here.
        default:
            {
                //TODO: throw exception : format not supported.
            }
    }

}




