//---------------------------------------------------------------------------                                                                                                                                      //---------------------------------------------------------------------------
#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "Un_Calc.h"
#include "Un_Calc_Hist.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrMain *FrMain;
//---------------------------------------------------------------------------
__fastcall TFrMain::TFrMain(TComponent* Owner)
        : TForm(Owner)
{
  List=new TStringList;
  L_Num=new TStringList;
  L_Hist=new TStringList;
  if (FileExists("hist.calc"))
    L_Hist->LoadFromFile("hist.calc");
  L_Num->Add("0");
  flCom=0;
  fl=0;
  flRes=0;
}
//---------------------------------------------------------------------------

void __fastcall TFrMain::FormDestroy(TObject *Sender)
{
  delete List;
  delete L_Num;
  delete L_Hist;
}
//---------------------------------------------------------------------------

void __fastcall TFrMain::BtCClick(TObject *Sender)
{
  flCom=0;
  fl=0;
  flRes=0;
  Ed1->Text="";
  List->Clear();
  L_Num->Clear();
  L_Num->Add("0");
  Ed1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TFrMain::BtDelClick(TObject *Sender)
{
  if (List->Count==0)
    return;
  AnsiString s1=List->Strings[List->Count-1], s2;
  if (s1==",")
      flCom=0;
  else if ((s1=="+")||(s1=="-")||(s1=="*")||(s1=="/")||(s1=="^"))
  {
      fl=0;
      L_Num->Delete(1); 
  }
  List->Delete(List->Count-1);
  for (int i=0;i<(List->Count);i++)
  {
    s2+=List->Strings[i];
  }
  Ed1->Text=s2;
  if (Ed1->Text=="")
  {
    BtCClick(Owner);
  }
  Ed1->SetFocus();
  Ed1->SelStart=strL;
}
//---------------------------------------------------------------------------

void __fastcall TFrMain::BtResClick(TObject *Sender)
{
  flCom=0;
  fl=0;
  AnsiString s0,s;
  int n;
  try
  {
    s0=L_Num->Strings[0];
  }
  catch(...)
  {
    return;
  }
  n=s0.Length();
  s=Ed1->Text;
  s.Delete(1,n+1);
  List->Clear();
  try
  {
    if (L_Num->Strings[1]=="+")
      s_res=FloatToStr(StrToFloat(L_Num->Strings[0])+StrToFloat(s));
    else if (L_Num->Strings[1]=="-")
      s_res=FloatToStr(StrToFloat(L_Num->Strings[0])-StrToFloat(s));
    else if (L_Num->Strings[1]=="*")
      s_res=FloatToStr(StrToFloat(L_Num->Strings[0])*StrToFloat(s));
    else if (L_Num->Strings[1]=="/")
    {
      if (StrToFloat(s)==0)
      {
        MessageDlg("������� �� ���� ����������!",mtInformation,TMsgDlgButtons()<<mbOK,0);
        return;
      }
      else
        s_res=FloatToStr(StrToFloat(L_Num->Strings[0])/StrToFloat(s));
    }
    else if (L_Num->Strings[1]=="^")
      s_res=FloatToStr(pow(StrToFloat(L_Num->Strings[0]),StrToFloat(s)));
  }
  catch(...)
  {
    MessageDlg("����������, ��������� ������������ ����� ������.",mtError,TMsgDlgButtons()<<mbOK,0);
    return;
  }
  L_Num->Clear();
  L_Hist->Add(Ed1->Text);
  L_Hist->Strings[L_Hist->Count-1]=L_Hist->Strings[L_Hist->Count-1]+"="+s_res;
  Ed1->Text=s_res;
  L_Num->Add(s_res);
  List->Add(s_res);
  flRes=1;
  Ed1->SetFocus();
  Ed1->SelStart=s_res.Length()+1;
  FileSetAttr("hist.calc",32);
  L_Hist->SaveToFile("hist.calc");
  FileSetAttr("hist.calc",6);
}
//---------------------------------------------------------------------------

void __fastcall TFrMain::NumClick(TObject *Sender)
{
  if(((TButton*)Sender)->Caption==",")
  {
    if(flCom==1)
      return;
    else
      flCom=1;
  }
  str=Ed1->Text;
  strL=str.Length();
  if (strL==18)
    return;
  if (flRes==1)
  {
    Ed1->Text="";
    List->Clear();
  }
  flRes=0;
  List->Add(((TButton*)Sender)->Caption);
  Ed1->Text=Ed1->Text+((TButton*)Sender)->Caption;
  Ed1->SetFocus();
  Ed1->SelStart=strL+1;
}
//---------------------------------------------------------------------------

void __fastcall TFrMain::SignClick(TObject *Sender)
{
  str=Ed1->Text;
  strL=str.Length();
  if (strL==18)
    return;
  if (flRes==1)
  {
    List->Clear();
    List->Add(s_res);
  }
  flRes=0;
  if (fl==1)
    return;
  fl=1;
  if (Ed1->Text=="")
    Ed1->Text="0";
  List->Add(((TButton*)Sender)->Caption);
  L_Num->Strings[0]=Ed1->Text;
  L_Num->Add(((TButton*)Sender)->Caption);
  Ed1->Text=Ed1->Text+((TButton*)Sender)->Caption;
  flCom=0;
  Ed1->SetFocus();
  Ed1->SelStart=strL+1;
}
//---------------------------------------------------------------------------
void __fastcall TFrMain::BtHistClick(TObject *Sender)
{
  FrHist->ShowModal();
  Ed1->SetFocus();
  Ed1->SelStart=strL+1;
}
//---------------------------------------------------------------------------

