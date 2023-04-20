#ifndef __DATABASE_H
#define __DATABASE_H

#include <map>
#include <string>

using namespace std;

class Database
{
    private:
        string db_name ="";
        map<string, table*> db_map;



};//end of Database obejct

#endif