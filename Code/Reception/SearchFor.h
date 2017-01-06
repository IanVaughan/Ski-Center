//---------------------------------------------------------------------------
#ifndef searchForH
#define searchForH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TSearchForm : public TForm
{
__published:	// IDE-managed Components
    TComboBox *ComboBox1;
    TComboBox *ComboBox2;
    TComboBox *ComboBox3;
    TComboBox *ComboBox5;
    TComboBox *ComboBox6;
    TComboBox *ComboBox7;
    TButton *Button1;
    TListBox *ListBox1;
    TButton *Button2;
    TBevel *Bevel1;
    TLabel *Label1;
    void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TSearchForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSearchForm *SearchForm;
//---------------------------------------------------------------------------
#endif
