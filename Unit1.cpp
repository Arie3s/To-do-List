//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.NmXhdpiPh.fmx", _PLAT_ANDROID)

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::addButtonClick(TObject *Sender)
{
	String taskText=task->Text;
	bool check=false;
	if(taskText!=""){
	taskBox->Items->Add(taskText);
	task->Text="";
	check=true;  }
	if(!check){
		Error->Text="Please Enter a Text";
	}
	if(check){
	Error->Text="";  }
	int count=taskBox->Items->Count;
	totalItems->Text="Items : "+IntToStr(count);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::taskBoxItemClick(TCustomListBox * const Sender, TListBoxItem * const Item)

{
	int index=Item->Index;
	taskBox->Items->Delete(index);
    int count=taskBox->Items->Count;
	totalItems->Text="Items : "+IntToStr(count);
}
//---------------------------------------------------------------------------
