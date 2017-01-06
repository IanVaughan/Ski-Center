//---------------------------------------------------------------------------
#ifndef TCellComboBoxH
#define TCellComboBoxH
//---------------------------------------------------------------------------


class TCellComboBox : public TComboBox
{
private:
    // this method overrides the normal processing so that
    // navigation key events can be trapped and processed.
    void __fastcall WndProc(TMessage &message );

    // Handler for the OnExit event. This sets the selected direction
    // into the SegmentDataSG grid in the appropriate cell.
    void __fastcall ComboExit(TObject* Sender);

public:
    // this allows the caller to be identified so that it will
    // receive focus when the combo box is exited.
    TWinControl *m_pkCaller;

    __fastcall TCellComboBox( TComponent* AOwner);

    bool Focusing;//Signals that the WndProc method is refocusing to the
                  // SegmentDataSG string grid.
};
//---------------------------------------------------------------------------

#endif
