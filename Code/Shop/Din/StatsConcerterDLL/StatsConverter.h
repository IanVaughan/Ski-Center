//---------------------------------------------------------------------------
#ifndef StatsConverterH
#define StatsConverterH
//---------------------------------------------------------------------------

const double cdLBS_PER_KG = 2.20462;
const double cdLBS_PER_STONE = 14;

const double cdIN_PER_FT = 12;
const double cdIN_PER_CM = 0.3937008;

//------------------------------------------------------------------------------

#include "StatsConverterDLL.h"

class StatsConverter
{
private:

    double GetWeight_KG(String kValue, WeightType tFromUnit);
    double GetHeight_CM(String kValue, HeightType tFromUnit);

public:
    StatsConverter();

    double ConvertWeight(String kValue, WeightType wvFromUnit, WeightType wvToUnit);
    double ConvertHeight(String kValue, HeightType hvFromUnit, HeightType hvToUnit);
};
//------------------------------------------------------------------------------
#endif
