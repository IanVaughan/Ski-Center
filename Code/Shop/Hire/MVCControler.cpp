//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MVCControler.h"
#include "HireFormSrc.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

MVCControler::MVCControler()
{
}
// -----------------------------------------------------------------------------

MVCControler::~MVCControler()
{
}
// -----------------------------------------------------------------------------

bool MVCControler::ValidateUser(SystemUser tUser)
{
    bool bRet = false;

    if(tUser.kName.UpperCase() == "IAN" || tUser.kPassword.UpperCase() == "IAN")
    {
        bRet = true;
    }

    return bRet;
}
// -----------------------------------------------------------------------------

bool MVCControler::ValidateCustomerDetails(CustomerDetials)
{
    return false;
}
// -----------------------------------------------------------------------------


SkiMakes MVCControler::GetSkiMakeList()
{
    SkiMakes skis;
    skis.clear();

    SkiMake ski;
    ski.kMake = "Salomon";

    skis.push_back(ski);

    return skis;
}
//------------------------------------------------------------------------------

SkiSizes MVCControler::GetSkiSizes()
{
    SkiSizes sizes;
    sizes.clear();

    SkiSize size;
    size.kSize = "70";
    sizes.push_back(size);
    size.kSize = "80";
    sizes.push_back(size);
    size.kSize = "90";
    sizes.push_back(size);
    size.kSize = "100";
    sizes.push_back(size);
    size.kSize = "110";
    sizes.push_back(size);
    size.kSize = "120";
    sizes.push_back(size);
    size.kSize = "130";
    sizes.push_back(size);
    size.kSize = "140";
    sizes.push_back(size);
    size.kSize = "150";
    sizes.push_back(size);
    size.kSize = "160";
    sizes.push_back(size);
    size.kSize = "170";
    sizes.push_back(size);
    size.kSize = "180";
    sizes.push_back(size);
    size.kSize = "190";
    sizes.push_back(size);
    size.kSize = "200";
    sizes.push_back(size);

    return sizes;
}
//------------------------------------------------------------------------------

