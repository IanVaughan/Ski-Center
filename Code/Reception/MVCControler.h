//---------------------------------------------------------------------------
#ifndef MVCControlerH
#define MVCControlerH
//---------------------------------------------------------------------------
#include "MVC_Model.h"  //class MVC_Model;

class MVCControler
{
    TStringList *m_pkUsersList;

    MVC_Model *pkModel;

public:
    MVCControler(TComponent* Owner);
    ~MVCControler();

    bool LoadLoginFile();
    bool ValidLogin(String userName, String userPassword);

    bool ShowForm(TForm *pkForm);

    void SetShowDay(TDate kDate);

    bool GetSheet(TDateTime kDateIn, DaySheet *&tDaySheetOut);
};
//------------------------------------------------------------------------------
#endif
 