//---------------------------------------------------------------------------
#ifndef MVCControlerH
#define MVCControlerH
//---------------------------------------------------------------------------
class MVCControler
{
    TStringList *m_pkUsersList;

public:
    MVCControler();
    ~MVCControler();

    bool ValidLogin(String userName, String userPassword);

};
//------------------------------------------------------------------------------
#endif
 