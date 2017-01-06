//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("ReceptionMain.res");
USEFORM("LoginScreenSrc.cpp", LoginScreen);
USEUNIT("MVCControler.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
        Application->Initialize();
        Application->CreateForm(__classid(TLoginScreen), &LoginScreen);
        Application->Run();
    }
    catch (Exception &exception)
    {
        Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
