//---------------------------------------------------------------------------
#ifndef DatePickerSrcH
#define DatePickerSrcH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "ccalendr.h"
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TDatePicker : public TForm
{
__published:	// IDE-managed Components
    TCCalendar *CalendarPicker;
    TPanel *BottomPanel;
    TBitBtn *BitBtn1;
    TBitBtn *BitBtn2;
    TPanel *TopPanel;
    TPopupMenu *PopupMenu;
    TMenuItem *Hold;
    TMenuItem *N1;
    TMenuItem *NextMonth1;
    TMenuItem *LastMonth1;
    TComboBox *MonthCombo;
    TLabel *Label1;
    TComboBox *YearCombo;
    TLabel *Label2;
    void __fastcall MonthComboChange(TObject *Sender);
    void __fastcall YearComboChange(TObject *Sender);
    void __fastcall BitBtn2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TDatePicker(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDatePicker *DatePicker;
//---------------------------------------------------------------------------
#endif
