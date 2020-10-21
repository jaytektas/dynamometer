#ifndef FILEMAGIC_H
#define FILEMAGIC_H

namespace Dynamometer
{
enum MAGIC
{
    VERSION = 1,
    RUN = 0x38485625,
    CHANNEL = 0x87874561,
    CONFIGURATION = 0x69364751
};

}


#endif // FILEMAGIC_H
