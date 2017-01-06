//---------------------------------------------------------------------------
#ifndef DinStatsCoverterH
#define DinStatsCoverterH
//---------------------------------------------------------------------------

typedef enum
{
    wtKILOS,
    wtSTONES,
    wtPOUNDS
}WeightType;

typedef enum
{
    htCMS,
    htINCHES,
    htFEET
}HeightType;

//------------------------------------------------------------------------------

typedef struct
{
    int iValue;
    WeightType tType;
}WeightValue;

typedef struct
{
    int iValue;
    HeightType tType;
}HeightValue;

//------------------------------------------------------------------------------

class DinStatsCoverter
{
private:

public:
    DinStatsCoverter();

    int GetKG(WeightValue wv);
    int GetCM(HeightValue hv);
};
//------------------------------------------------------------------------------
#endif
