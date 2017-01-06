//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MVC_ModelLayoutLessons.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)


/*
bool TLessonBookingSheet::SaveAll()
{
    //save instructors time/days etc
    //save the changes
    TStringList *list = new TStringList;
    String name;

    for (int i=0; i < LessonSG->RowCount; i++)
    {
        if(!m_pkBookingSheetUtils->RowEven(i))
        for (int j=0; j < LessonSG->ColCount; j++)
        {
            name = LessonSG->Cells[j][i];

            //add time on
            //name = (String)j +" - " + name;
            list->Add(name);
        }
    }

    name = m_pkBookingSheetUtils->GetStringDOW(weekSelector->TabIndex) + ".ins";

    list->SaveToFile("Instructors\\"+name);

    delete list;

    return true;
}
// -----------------------------------------------------------------------------

/*bool TbookingSheet::LoadDow(BookingSheetUtils::DayOfWeek dow)
{
/*    char days[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
    TDateTime dtDate = StrToDate(Edit1->Text);
    ShowMessage(Edit1->Text + AnsiString(" is a ") + days[dtDate.DayOfWeek()]);*/
/*
    String filename = GetStringDOW(dow);

    filename = "Instructors\\"+ filename + ".ins";

    bool yes = FileExists(filename);
    if(!yes)
    {
        int ans = Application->MessageBox("That day of the week file was not found, perhaps it wasnt saved!\nDo you want to create one now, if you dont one will get created as soon as a change is made anyway.", "File not found", MB_YESNO|MB_ICONQUESTION);
        if(ans == ID_YES)
        {
            TStringList *list = new TStringList;
            list->SaveToFile(filename);
            delete list;
        }
        else
            return false;
    }

    TStringList *list = new TStringList;
    list->LoadFromFile(filename);

    //load in times and intructors booked in
    String name;

    int col = 0;
    int row = 0;

    for(int i=0; i< list->Count; i++)
    {
        name = list->Strings[i];

        LessonSG->Cells[col][row] = name;

        if(col < 9)
            col++;
        else
        {
            col = 0;

            if(row <= 0)
                row ++;
            else
                row+=2;
        }
    }

    return true;
}
// -----------------------------------------------------------------------------
*/
