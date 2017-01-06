//---------------------------------------------------------------------------
#ifndef HelpAboutSrcH
#define HelpAboutSrcH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class THelpAbout : public TForm
{
__published:	// IDE-managed Components
    TBevel *Bevel1;
    TSpeedButton *SpeedButton1;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TImage *Image1;
    TLabel *Label4;
    TImage *Image2;
    void __fastcall SpeedButton1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall THelpAbout(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE THelpAbout *HelpAbout;
//---------------------------------------------------------------------------
#endif
