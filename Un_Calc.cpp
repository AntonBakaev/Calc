//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Un_Calc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrMain *FrMain;
//---------------------------------------------------------------------------
__fastcall TFrMain::TFrMain(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFrMain::FormCreate(TObject *Sender)
{
  List=new TStringList;
  L_Num=new TStringList;
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
}
//---------------------------------------------------------------------------

void __fastcall TFrMain::Bt0Click(TObject *Sender)
{
  str=Ed1->Text;
  strL=str.Length();
  if (strL==18)
    return;
  Ed1->SetFocus();
  if (flRes==1)
  {
    Ed1->Text="";
    List->Clear();
  }
  List->Add("0");
  Ed1->Text=Ed1->Text+"0";

}
//---------------------------------------------------------------------------

void __fastcall TFrMain::Bt1Click(TObject *Sender)
{
  str=Ed1->Text;
  strL=str.Length();
  if (strL==18)
    return;
  Ed1->SetFocus();
  if (flRes==1)
  {
    Ed1->Text="";
    List->Clear();
  }
  flRes=0;
  List->Add("1");
  Ed1->Text=Ed1->Text+"1";
}
//---------------------------------------------------------------------------

void __fastcall TFrMain::Bt2Click(TObject *Sender)
{
  str=Ed1->Text;
  strL=str.Length();
  if (strL==18)
    return;
  Ed1->SetFocus();
  if (flRes==1)
  {
    Ed1->Text="";
    List->Clear();
  }
  flRes=0;
  List->Add("2");
  Ed1->Text=Ed1->Text+"2";
}
//---------------------------------------------------------------------------

void __fastcall TFrMain::Bt3Click(TObject *Sender)
{
  str=Ed1->Text;
  strL=str.Length();
  if (strL==18)
    return;
  Ed1->SetFocus();
  if (flRes==1)
  {
    Ed1->Text="";
    List->Clear();
  }
  flRes=0;
  List->Add("3");
  Ed1->Text=Ed1->Text+"3";
}
//---------------------------------------------------------------------------

void __fastcall TFrMain::Bt4Click(TObject *Sender)
{
  str=Ed1->Text;
  strL=str.Length();
  if (strL==18)
    return;
  Ed1->SetFocus();
  if (flRes==1)
  {
    Ed1->Text="";
    List->Clear();
  }
  flRes=0;
  List->Add("4");
  Ed1->Text=Ed1->Text+"4";
}
//---------------------------------------------------------------------------

void __fastcall TFrMain::Bt5Click(TObject *Sender)
{
  str=Ed1->Text;
  strL=str.Length();
  if (strL==18)
    return;
  Ed1->SetFocus();
  if (flRes==1)
  {
    Ed1->Text="";
    List->Clear();
  }
  flRes=0;
  List->Add("5");
  Ed1->Text=Ed1->Text+"5";
}
//---------------------------------------------------------------------------

void __fastcall TFrMain::Bt6Click(TObject *Sender)
{
  str=Ed1->Text;
  strL=str.Length();
  if (strL==18)
    return;
  Ed1->SetFocus();
  if (flRes==1)
  {
    Ed1->Text="";
    List->Clear();
  }
  flRes=0;
  List->Add("6");
  Ed1->Text=Ed1->Text+"6";
}
//---------------------------------------------------------------------------

void __fastcall TFrMain::Bt7Click(TObject *Sender)
{
  str=Ed1->Text;
  strL=str.Length();
  if (strL==18)
    return;
  Ed1->SetFocus();
  if (flRes==1)
  {
    Ed1->Text="";
    List->Clear();
  }
  flRes=0;
  List->Add("7");
  Ed1->Text=Ed1->Text+"7";
}
//---------------------------------------------------------------------------

void __fastcall TFrMain::Bt8Click(TObject *Sender)
{
  str=Ed1->Text;
  strL=str.Length();
  if (strL==18)
    return;
  Ed1->SetFocus();
  if (flRes==1)
  {
    Ed1->Text="";
    List->Clear();
  }
  flRes=0;
  List->Add("8");
  Ed1->Text=Ed1->Text+"8";
}
//---------------------------------------------------------------------------

void __fastcall TFrMain::Bt9Click(TObject *Sender)
{
  str=Ed1->Text;
  strL=str.Length();
  if (strL==18)
    return;
  Ed1->SetFocus();
  if (flRes==1)
  {
    Ed1->Text="";
    List->Clear();
  }
  flRes=0;
  List->Add("9");
  Ed1->Text=Ed1->Text+"9";
}
//---------------------------------------------------------------------------

void __fastcall TFrMain::BtComClick(TObject *Sender)
{
  str=Ed1->Text;
  strL=str.Length();
  if (strL==18)
    return;
  Ed1->SetFocus();
  if (flRes==1)
  {
    Ed1->Text="";
    List->Clear();
  }
  flRes=0;
  if (flCom==1)
    return;
  flCom=1;
  List->Add(",");
  Ed1->Text=Ed1->Text+",";
}
//---------------------------------------------------------------------------

void __fastcall TFrMain::BtCClick(TObject *Sender)
{
  Ed1->SetFocus();
  flCom=0;
  fl=0;
  flRes=0;
  Ed1->Text="";
  List->Clear();
  L_Num->Clear();
  L_Num->Add("0");
}
//---------------------------------------------------------------------------

void __fastcall TFrMain::BtDelClick(TObject *Sender)
{
  Ed1->SetFocus();
  if (List->Count==0)
    return;
  AnsiString s1=List->Strings[List->Count-1], s2;
  if (s1==",")
      flCom=0;
  else if ((s1=="+")||(s1=="-")||(s1=="*")||(s1=="/"))
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
    List->Clear();
    L_Num->Clear();
    L_Num->Add("0");
    flCom=0;
    fl=0;
    flRes=0;
  }
}
//---------------------------------------------------------------------------

void __fastcall TFrMain::BtPlusClick(TObject *Sender)
{
  str=Ed1->Text;
  strL=str.Length();
  if (strL==18)
    return;
  Ed1->SetFocus();
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
  List->Add("+");
  L_Num->Strings[0]=Ed1->Text;
  L_Num->Add("+");
  Ed1->Text=Ed1->Text+"+";
  flCom=0;
}
//---------------------------------------------------------------------------

void __fastcall TFrMain::BtMinusClick(TObject *Sender)
{
  str=Ed1->Text;
  strL=str.Length();
  if (strL==18)
    return;
  Ed1->SetFocus();
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
  List->Add("-");
  L_Num->Strings[0]=Ed1->Text;
  L_Num->Add("-");
  Ed1->Text=Ed1->Text+"-";
  flCom=0;
}
//---------------------------------------------------------------------------

void __fastcall TFrMain::BtMultipClick(TObject *Sender)
{
  str=Ed1->Text;
  strL=str.Length();
  if (strL==18)
    return;
  Ed1->SetFocus();
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
  List->Add("*");
  L_Num->Strings[0]=Ed1->Text;
  L_Num->Add("*");
  Ed1->Text=Ed1->Text+"*";
  flCom=0;
}
//---------------------------------------------------------------------------

void __fastcall TFrMain::BtDivClick(TObject *Sender)
{
  str=Ed1->Text;
  strL=str.Length();
  if (strL==18)
    return;
  Ed1->SetFocus();
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
  List->Add("/");
  L_Num->Strings[0]=Ed1->Text;
  L_Num->Add("/");
  Ed1->Text=Ed1->Text+"/";
  flCom=0;
}
//---------------------------------------------------------------------------

void __fastcall TFrMain::BtResClick(TObject *Sender)
{
  Ed1->SetFocus();
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
        MessageDlg("������� �� ���� ����������!",mtInformation,
                   TMsgDlgButtons()<<mbOK,0);

        return;
      }
      else
        s_res=FloatToStr(StrToFloat(L_Num->Strings[0])/StrToFloat(s));
    }
  }
  catch(...)
  {
    MessageDlg("����������, ��������� ������������ ����� ������.",mtError,
                   TMsgDlgButtons()<<mbOK,0);
    return;
  }
  L_Num->Clear();
  Ed1->Text=s_res;
  L_Num->Add(s_res);
  List->Add(s_res);
  flRes=1;
}
//---------------------------------------------------------------------------

void __fastcall TFrMain::Ed1KeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  switch (Key)
  {
  case VK_NUMPAD0:
  case '0':
    Bt0Click(Owner);
    break;
  case VK_NUMPAD1:
  case '1':
    Bt1Click(Owner);
    break;
  case VK_NUMPAD2:
  case '2':
    Bt2Click(Owner);
    break;
  case VK_NUMPAD3:
  case '3':
    Bt3Click(Owner);
    break;
  case VK_NUMPAD4:
  case '4':
    Bt4Click(Owner);
    break;
  case VK_NUMPAD5:
  case '5':
    Bt5Click(Owner);
    break;
  case VK_NUMPAD6:
  case '6':
    Bt6Click(Owner);
    break;
  case VK_NUMPAD7:
  case '7':
    Bt7Click(Owner);
    break;
  case VK_NUMPAD8:
  case '8':
    Bt8Click(Owner);
    break;
  case VK_NUMPAD9:
  case '9':
    Bt9Click(Owner);
    break;
  case ',':
    BtComClick(Owner);
    break;
  case 0xBB:
    BtResClick(Owner);
    break;
  case VK_ADD:
    BtPlusClick(Owner);
    break;
  case VK_SUBTRACT:
    BtMinusClick(Owner);
    break;
  case VK_MULTIPLY:
    BtMultipClick(Owner);
    break;
  case VK_DIVIDE:
    BtDivClick(Owner);
    break;
  case VK_BACK:
    BtDelClick(Owner);
    break;
  }
}
//---------------------------------------------------------------------------
