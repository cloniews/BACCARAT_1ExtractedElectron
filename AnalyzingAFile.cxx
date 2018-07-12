//Christina Loniewski
//Edited 20171008
//This takes a root file and converts event information into a .csv file.

//In a terminal:
//screen -R root5
//In the screen session:
//cd /opt/root/bin
//source thisroot.sh
//root
//In root:
//.L /opt/LZSim/BACCARAT-updated20170825/tools/libBaccRootConverterEvent.so 
//.x /home/christina/LZSim/AnalyzingAFile.cxx("name of root file")


#include <iostream>
#include <string>
using namespace std;

void AnalyzingAFile() //This is an error message.
{
  cout << "You did not enter a rootfile.  Please enter a rootfile." << endl;
}

void AnalyzingAFile(TString rootfile)
{
//"rootfile" must be the name of the file that we want opened.  Write this in quotes.

TString csvfile = rootfile;
csvfile.ReplaceAll("root","csv");
cout << csvfile << endl << endl;

TFile *f = new TFile(rootfile);
TTree *data = (TTree*)f->FindObjectAny( "DataTree" );
TBranch *eventBranch = data->GetBranch( "Event" );
BaccRootConverterEvent *anEvent = new BaccRootConverterEvent();
eventBranch->SetAddress( &anEvent );
Int_t numEvents = data->GetEntries();
cout << numEvents << endl;

ofstream myfile;
myfile.open(csvfile);

//This runs through all events.
for(Int_t event=1;event < numEvents;event++){    

eventBranch->GetEntry(event);
Int_t NumVolumes = anEvent->volumes.size();


//This runs through all volumes.
vector <Int_t> pmts(541);
for( Int_t j=0; j<NumVolumes; j++ ) {
string pmtName = anEvent->volumes[j].sName;
string pmtNameEnd = pmtName.substr( pmtName.length() - 3  );  //This gets the pmt ID
stringstream geek(pmtNameEnd);
int pmtValueEnd = 0;
geek >> pmtValueEnd;
pmts[pmtValueEnd] = anEvent->volumes[j].iTotalOptPhotNumber;
}
for(Int_t m =0; m<541;m++){myfile << pmts[m] << ",";}
myfile << "\n"  ;


}
myfile.close();
}

