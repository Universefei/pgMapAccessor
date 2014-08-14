#include "PgMAQuery.h"
#include "PgMA_error.h"

using namespace PGMA;

/*****************************************************************************/
/*                               ConnInfo()                                  */
/*****************************************************************************/
ConnInfo::ConnInfo()
{
}

/*****************************************************************************/
/*                               ~ConnInfo()                                 */
/*****************************************************************************/
ConnInfo::~ConnInfo()
{
}

/*****************************************************************************/
/*                               setHostname()                               */
/*****************************************************************************/
ConnInfo::setHostname(string hostname)
{
    hostname_=hostname;
}

/*****************************************************************************/
/*                                setPort()                                  */
/*****************************************************************************/
ConnInfo::setPort(string port)
{
    port_=port;
}

/*****************************************************************************/
/*                               setUsername()                               */
/*****************************************************************************/
ConnInfo::setUsername(string username)
{
    username_=username;
}

/*****************************************************************************/
/*                               setUsername()                               */
/*****************************************************************************/
ConnInfo::setPassword(string password)
{
    password_=password;
}

/*****************************************************************************/
/*                               setUsername()                               */
/*****************************************************************************/
ConnInfo::setDbname(string dbname)
{
    dbname_dbname;
}


/*****************************************************************************/
/*                               PgMAQuery()                                 */
/*****************************************************************************/
PgMAQuery::PgMAQuery()
{
    eRetType=eF_XML;

    //TODO:parse /config/DBConn.conf
    //
    //string hostname = 
    //string port = 
    //string dbname =
    //string username =
    //string passowrd = 
    
    pPgConn_ = new ConnInfo();
    pPgConn_->setHostname(hostname);// setter's parameter can not be reference type.
    pPgConn_->setPort(port);
    pPgConn_->setDbname(dbname);
    pPgConn_->setUsername(username);
    pPgConn_->setPassword(password);

    connectDB(*pPgConn_);
}


PgMAQuery::PgMAQuery(EFormat eRetFmt, const ConnInfo& connInfo )
{
    eRetFormat_=eRetFmt;
    pPgConn_=new ConnInfo(connInfo);
    

}

/*****************************************************************************/
/*                               ~PgMAQuery()                                 */
/*****************************************************************************/
PgMAQuery::~PgMAQuery()
{
}


/*****************************************************************************/
/*                               connectDB()                                 */
/*****************************************************************************/
PgMA_err    
PgQuery::connectDB(ConnInfo& connInfo)
{
    OGRRegisterAll();
    const char* pszDriverName = "PostgreSQL";
    poDriver = OGRSFDriverRegistrar::GetRegistrar()->GetDriverByName(pszDriverName);
    const char* pgConnInfo = "";//TODO:make connection data form a string.
    pPgDS_ = poDriver->Open(pgConnInfo);
}

/*****************************************************************************/
/*                                 writeToFile()                             */
/*****************************************************************************/
/**
 * @brief       : write data to file.
 * @filePath    : output file path with file name.
 */
FileInfo*
PgMAQuery::writeToFile(string& filePath)
{
    return writeToFile(eRetFormat_, filePath);
}

/*****************************************************************************/
/*                               writeToFile()                               */
/*****************************************************************************/
/**
 * @brief       : write data to specified format file.
 * @eFileFormat : output file format.
 * @filePath    : output file path with file name.
 */
FileInfo*
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

/*****************************************************************************/
/*                                writeToBuf()                               */
/*****************************************************************************/
/**
 * @brief       : write data to memory buffer.
 */
MemBuf*
PgMAQuery::writeToBuf()
{
    return writeToBuf(eRetFormat_);
}

/*****************************************************************************/
/*                             writeToBuf(EFormat)                           */
/*****************************************************************************/
/**
 * @brief       : write data to memory buffer.
 * @eFormat     : output buf format
 */
MemBuf*
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


