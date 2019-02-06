#include "FileUtil.h"
#include "Parameters.h"
#include <cstdlib>

int rmdb(int argc, const char **argv, const Command &command) {
    Parameters &par = Parameters::getInstance();
    par.parseParameters(argc, argv, command, 1);
    std::vector<std::string> files = FileUtil::findDatafiles(par.db1.c_str());
    for (size_t i = 0; i < files.size(); ++i) {
        FileUtil::remove(files[i].c_str());
    }
    if (FileUtil::fileExists(par.db1Index.c_str())) {
        FileUtil::remove(par.db1Index.c_str());
    }
    std::string dbTypeFile = par.db1 + ".dbtype";
    if (FileUtil::fileExists(dbTypeFile.c_str())) {
        FileUtil::remove(dbTypeFile.c_str());

    }
    std::string lookupFile = par.db1 + ".lookup";
    if (FileUtil::fileExists(lookupFile.c_str())) {
        FileUtil::remove(lookupFile.c_str());
    }
    return EXIT_SUCCESS;
}
