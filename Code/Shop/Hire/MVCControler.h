//---------------------------------------------------------------------------
#ifndef MVCControlerH
#define MVCControlerH
//---------------------------------------------------------------------------
#include "vector.h"

typedef struct UserStrut
{
    String kName;
    String kPassword;
}SystemUser;
// -----------------------------------------------------------------------------

typedef struct CustSruct
{
    String kTitle;
    String kNameFirst;
    String kNameLast;

    String kAddressName;
    String kAddressNumber;
    String kAddressStreet;
    String kAddressTown;
    String kAddressCounty;
    String kAddressPostcode;

    String kTelephoneDay;
    String kTelephoneEve;
    String kTelephoneMob;

    String kDOB;
    String kWeight;
    String kHeight;
    String kAbility;

}CustomerDetials;

// -----------------------------------------------------------------------------

typedef struct
{
    String kMake;
}SkiMake;

typedef std::vector <SkiMake> SkiMakes;

typedef struct
{
    String kSize;
}SkiSize;
typedef std::vector <SkiSize> SkiSizes;

//------------------------------------------------------------------------------

class MVCControler
{
public:
    MVCControler();
    ~MVCControler();

    bool ValidateUser(SystemUser);

    bool ValidateCustomerDetails(CustomerDetials);

    SkiMakes GetSkiMakeList();
    SkiSizes GetSkiSizes();
};
// -----------------------------------------------------------------------------

#endif
