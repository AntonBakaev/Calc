//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Un_Calc.h"
#include "Un_Calc_Hist.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrHist *FrHist;
//---------------------------------------------------------------------------
__fastcall TFrHist::TFrHist(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrHist::BtClearHistClick(TObject *Sender)
{

  //L_Hist->SaveToFile("calc_hist.calc");
}
//---------------------------------------------------------------------------