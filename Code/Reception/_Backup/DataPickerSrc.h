//---------------------------------------------------------------------------
#ifndef DataPickerSrcH
#define DataPickerSrcH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "ccalendr.h"
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TDatePicker : public TForm
{
__published:	// IDE-managed Components
    TCCalendar *CCalendar1;
    TPanel *BottomPanel;
    TBitBtn *BitBtn1;
    TBitBtn *BitBtn2;
private:	// User declarations
public:		// User declarations
    __fastcall TDatePicker(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDatePicker *DatePicker;
//---------------------------------------------------------------------------
#endif
