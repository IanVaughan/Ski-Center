//---------------------------------------------------------------------------
#ifndef HireListSrcH
#define HireListSrcH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class THireList : public TForm
{
__published:
    TStringGrid *HireListSG;
    TPanel *Panel1;
    TBitBtn *BitBtn1;
    TBitBtn *BitBtn2;
    TBitBtn *BitBtn3;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);

    
private:
    void PopulateTickBoxes();
    void RemoveTickBoxes();
    int GetColWidth(int iCount);

public:
    __fastcall THireList(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE THireList *HireList;
//---------------------------------------------------------------------------
#endif
