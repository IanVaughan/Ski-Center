//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MVC_Model.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

const String LESSON_FILE = "test.txt";

MVC_Model::MVC_Model()
{
    m_ptDaySheetAll = new DaySheetAll;
    m_ptBlankSheet = new DaySheet;

    m_ptBlankSheet->iNumOfRows = 5;
    m_ptBlankSheet->iNumOfBlocks = 10;

    LoadData();
}
//------------------------------------------------------------------------------

MVC_Model::~MVC_Model()
{
    SaveData();

    delete m_ptDaySheetAll;
    delete m_ptBlankSheet;
}
//------------------------------------------------------------------------------

bool MVC_Model::LoadData()
{
    TStringList *pkStringList = new TStringList;
    pkStringList->LoadFromFile(LESSON_FILE);


    for(int iDays=0; iDays<m_ptDaySheetAll->size(); iDays++)
    {
        DaySheet tDay = (*m_ptDaySheetAll)[iDays];

        tDay.kDate; //TDate
        tDay.iNumOfRows;//int
        tDay.iNumOfBlocks;//int
        
        LessonRowData tLessonRow = tDay.tLessonRowList;

        for (int iLessonRows=0; iLessonRows<tLessonRow.size(); iLessonRows++)
        {
            LessonRow tLessonRow = (*tLessonRow)[iLessonRows];

            LessonCellData tLessonRow = tLessonRow;

            for (int iLessonCell=0; iLessonCell< ; iLessonCell++)
            {

            }
        }
    }


    delete pkStringList;
    return false;
}
//------------------------------------------------------------------------------

bool MVC_Model::SaveData()
{
    TStringList *pkStringList = new TStringList;

    for(int iDays=0; m_ptDaySheetAll->size(); iDays++)
    {
        LessonRowData tRessonRow = (*m_ptDaySheetAll)[iDays].tLessonRowList;
//        pkStringList->Add(tRessonRow);
//        pkStringList->Add(tRessonRow);
//        pkStringList->Add(tRessonRow);

        for(int iLessonRow=0; tRessonRow.size(); iLessonRow++)
        {
            LessonCellData tLessonCell = tRessonRow[iLessonRow].tLessonCellList;

//            pkStringList->Add(tLessonCell.kInstructorName);
//            pkStringList->Add();
        }
    }

    pkStringList->SaveToFile(LESSON_FILE);
    delete pkStringList;

    return false;
}
//------------------------------------------------------------------------------

bool MVC_Model::GetSheet(TDateTime kDateIn, DaySheet *&tDaySheetOut)
{
    bool bFound = false;
    int i=0;
    for(i; m_ptDaySheetAll->size(); i++)
    {
        if((*m_ptDaySheetAll)[i].kDate == kDateIn)
        {
            bFound = true;
            break;
        }
    }

    if(bFound)
    {
        tDaySheetOut = &(*m_ptDaySheetAll)[i];
    }
    else
    {
        tDaySheetOut = m_ptBlankSheet;// NULL;
    }

    return true;
}
//------------------------------------------------------------------------------

