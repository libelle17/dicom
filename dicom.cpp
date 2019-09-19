// '//α' oder '//ω' als Kommentar sind nur fuer die Verwendung dieses Programms als Programmvorlage wichtig
const double& versnr= //α
#include "versdt"
;
#include "kons.h"
#include "DB.h" 
#include <tiffio.h>
#define VOMHAUPTCODE // um Funktionsdefinition manchmal mit "__attribute__((weak)) " versehen zu können //ω
#include "dicom.h"
// fuer verschiedene Sprachen //α
char const *DPROG_T[T_MAX+1][SprachZahl]=
{
 // T_pruefdictab
 {"pruefdictab()","checkdictab()"},
 // T_eindeutige_Identifikation
 {"eindeutige Identifikation","unique identification number"},
 // T_Patientenname
 {"Patientenname","Name of the patient"},
 // T_Geburtsdatum
 {"Geburtsdatum","Birth date"},
 // T_Patientennr
 {"Patientennr","Pat.-ID"},
 // T_Geschlecht
 {"Geschlecht","sex"},
 // T_Bildtyp
 {"Bildtyp","image type"},
 // T_TransducerData
 {"Schallkopf","transducer"},
 // T_ProcessingFunction
 {"Programm","program"},
 // T_Aufnahmedatum
 {"Aufnahmedatum","acquisition date"},
 // T_Importdatum
 {"Importdatum","import date"},
 // T_Arzt
 {"Arzt","Physician"},
	// T_MediaStorageSOPInstanceUID
	{"MediaStorageSOPInstanceUID","MediaStorageSOPInstanceUID"},
 // T_Tabelle_fuer_dicom_Bilder
 {"Tabelle fuer dicom-Bilder","table for dicom pictures"},
 // T_Fehler_beim_Pruefen_von_dictab
 {"Fehler eim Prüfen der Tabelle dictab","error checking table dictab"},
	// T_virtVorgbAllg
	{"virtVorgbAllg()","virtgeneralprefs()"},
	// T_pvirtVorgbSpeziell
	{"pvirtVorgbSpeziell()","pvirtspecialprefs()"},
	// T_virtMusterVorgb
	{"virtMusterVorgb()","virtsampleprefs"},
	// T_pvirtvorrueckfragen
	{"pvirtvorrueckfragen()","pvirtbeforecallbacks()"},
	// T_virtrueckfragen
	{"virtrueckfragen()","virtcallbacks()"},
	// T_virtpruefweiteres
	{"virtpruefweiteres()","virtcheckmore()"},
	// T_virtmacherkl_Tx_lgn
	{"pvirtmacherkl, Tx.lgn: ","pvirtmakeexpl, Tx.lgn: "},
	//	T_Fehler_beim_Pruefen_von
	{"Fehler beim Pruefen von: ","Error while examining: "},
	// T_st_k
	{"st","st"},
	// T_stop_l
	{"stop","stop"},
	// T_DPROG_anhalten
	{DPROG " anhalten","stop " DPROG},
	// T_anhalten
	{"anhalten()","stop()"},
	// T_Cron_Aufruf_von
	{"Cron-Aufruf von '","cron call of '"},
	// T_gestoppt
	{"' gestoppt.","' stopped."},
	// T_n_k
	{"n","n"},
	// T_dszahl_l
	{"dszahl","reccount"},
	// T_Zahl_der_aufzulistenden_Datensaetze_ist_zahl_statt
	{"Zahl der aufzulistenden Datensaetze = <zahl> statt","No. of listed entries = <no> instead of"},
	// T_Datenbank_nicht_initialisierbar_breche_ab
	{"Datenbank nicht initialisierbar, breche ab","database init failed, stopping"},
	// T_pvirtvorpruefggfmehrfach,
	{"pvirtvorpruefggfmehrfach()","pvirtbeforecheckmultiple()"},
	// T_pvirtfuehraus,
	{"pvirtfuehraus()","pvirtexecute()"},
	// T_in_pvirtfuehraus_pidw,
	{"in pvirtfuehraus(), pidw","in pvirtexecute(), pidw"},
	// T_virttesterg,
	{"virttesterg()","virtcheckresult()"},
	// T_virtzeigversion,
	{"virtzeigversion()","virtshowversion()"},
	// T_virtzeigueberschrift, 
	{"virtzeigueberschrift()","virtshowheadline()"},
	// T_Fuege_ein
	{"Fuege ein: ","Inserting: "}, //ω
	// T_rufpruefsamba
	{"rufpruefsamba()","callchecksamba()"},
	// T_DicomQuellVz
	{"DicomQuellVz","dicomSourceDir"},
	// T_DicomArchivVz
	{"DicomArchivVz","dicomArchiveDir"},
	// T_DicomZielVz
	{"DicomZielVz","dicomTargetDir"},
	// T_DicomZiel2Vz
	{"DicomZiel2Vz","dicomTarget2Dir"},
	// T_duser_k
	{"duser","duser"},
	// T_duser_l
	{"duser","duser"},
	// T_verwendet_fuer_Samba_den_Linux_Benutzer_string_anstatt
	{"verwendet fuer Samba den Linux-Benutzer <string> anstatt", "takes the linux user <string> for samba instead of"},
	// T_rueck_k
	{"rueck","back"},
	// T_rueck_l
	{"rueck","back"},
	// T_letzten_Import_rueckgaengig
	{"letzten Import rückgängig machen","revert last import"},
	// T_qvz_k
	{"qvz","sdr"},
	// T_qvz_l
	{"quellvz","sourcedir"},
	// T_avz_k
	{"avz","adr"},
	// T_avz_l
	{"archvz","archdir"},
	// T_zvz_k
	{"zvz","tdr"},
	// T_zvz_l
	{"zielvz","targetdir"},
	// T_z2vz_k
	{"z2vz","t2dr"},
	// T_z2vz_l
	{"ziel2vz","target2dir"},
	// T_Quellverzeichnis_anstatt
	{"Quellverzeichnis anstatt ","source directory instead of "},
	// T_Archivverzeichnis_anstatt
	{"Archiverzeichnis anstatt ","archive directory instead of "},
	// T_Zielverzeichnis_anstatt
	{"Zielverzeichnis anstatt ","target directory instead of "},
	// T_Zweites_Zielverzeichnis_anstatt
	{"Zweites Zielverzeichnis anstatt ","Second target directory instead of "},
	// T_Liest_Dicom_Dateien_aus
	{"Liest Dicom-Dateien aus ","Reads dicom-files from "},
	// T_speichert_sie_als_png_Bilder_in
	{", speichert sie als png-Bilder in ",", saves them as png pictures in "},
	// T_und
	{" und "," and "},
	// T_und_verschiebt_zuletzt_die_Orignale_nach
	{" und verschiebt zuletzt die Originale nach "," and at last moves the original files to "},
	// T_Optionen_die_nicht_gespeichert_werden
	// T_jahr
	{"<jahr>","<year>"},
	{"",""} //α
}; // char const *DPROG_T[T_MAX+1][SprachZahl]=

class TxB Tx((const char* const* const* const*)DPROG_T);
const char sep = 9; // geht auch: "[[:blank:]]"
const char *logdt="/var/log/" DPROG "vorgabe.log";//darauf wird in kons.h verwiesen;
pidvec pidw; // wird zweimal verwendet, um auf Kindprozesse zu warten: in wegfaxen (auf die Faxarten) und in pvirtfueraus (auf korrigierefbox, -capi und -hyla
const unsigned ktage=1; // kurzes Intervall fuer Faxtabellenkorrektur, 1 Tag
const unsigned mtage=30; // mittleres Intervall fuer Faxtabellenkorrektur, 1 Monat
const unsigned ltage=73000; // langes Intervall fuer Faxtabellenkorrektur, 200 Jahre
using namespace std; //ω

void hhcl::rufpruefsamba()
{
	hLog(violetts+Tx[T_rufpruefsamba]);
	vector<const string*> vzn;
	svec abschni,suchs;
	const int ISambaName[]{T_DicomQuellVz,T_DicomArchivVz,T_DicomZielVz,T_DicomZiel2Vz}; 
	////={&zufaxenvz,&wvz,&nvz,&empfvz};
	if (!qvz.empty()) vzn.push_back(&qvz);
	if (!avz.empty()) vzn.push_back(&avz);
	if (!zvz.empty()) vzn.push_back(&zvz);
	if (!z2vz.empty()) vzn.push_back(&z2vz);
	for(unsigned k=0;k<vzn.size();k++) {
		string schstr;
		abschni<<Tx[ISambaName[k]];
		Sprache altSpr{Tx.lgn};
		for(int aktsp=0;aktsp<SprachZahl;aktsp++) {
			Tx.lgn=(Sprache)aktsp;
			schstr=string("\\[")+Tx[ISambaName[k]]+"\\]\\|";
		} //         for(int aktsp=0;aktsp<SprachZahl;aktsp++)
		Tx.lgn=altSpr;
		suchs<<schstr;
	} // 	for(unsigned k=0;k<vzn.size();k++)
	pruefsamba(vzn,abschni,suchs,DPROG,duser);
	hLog(violetts+Txk[T_Ende]+Tx[T_rufpruefsamba]);
} // pruefsamba

void pruefdictab(DB *My,const string& tbn,int obverb,int oblog)
{
 fLog(violetts+Tx[T_pruefdictab]+schwarz,obverb,oblog);
	const size_t aktc{0};
 Feld felder[]= {
  Feld("ID","int","10","",Tx[T_eindeutige_Identifikation],1,1),
  Feld("PatientName","varchar","1","",Tx[T_Patientenname],/*obind=*/1,/*obauto=*/0,/*nnuull=*/1),
  Feld("Geburtsdatum","datetime","0","0",Tx[T_Geburtsdatum],/*obind=*/1,/*obauto=*/0,/*nnuull=*/1),
  Feld("PatientID","varchar","1","",Tx[T_Patientennr],/*obind=*/1,/*obauto=*/0,/*nnuull=*/1),
  Feld("Geschlecht","varchar","1","",Tx[T_Geschlecht],/*obind=*/1,/*obauto=*/0,/*nnuull=*/0),
  Feld("Bildtyp","varchar","1","",Tx[T_Bildtyp],/*obind=*/1,/*obauto=*/0,/*nnuull=*/0),
  Feld("ReferringPhysicianName","varchar","1","",Tx[T_Arzt],/*obind=*/1,/*obauto=*/0,/*nnuull=*/0),
  Feld("PerformingPhysicianName","varchar","1","",Tx[T_Arzt],/*obind=*/1,/*obauto=*/0,/*nnuull=*/0),
  Feld("TransducerData","varchar","1","",Tx[T_TransducerData],/*obind=*/1,/*obauto=*/0,/*nnuull=*/0),
  Feld("ProcessingFunction","varchar","1","",Tx[T_ProcessingFunction],/*obind=*/1,/*obauto=*/0,/*nnuull=*/0),
  Feld("MediaStorageSOPInstanceUID","varchar","1","",Tx[T_MediaStorageSOPInstanceUID],/*obind=*/1,/*obauto=*/0,/*nnuull=*/1),
  Feld("Aufnahmedatum","datetime","0","0",Tx[T_Aufnahmedatum],/*obind=*/1,/*obauto=*/0,/*nnuull=*/1),
  Feld("Importdatum","datetime","0","0",Tx[T_Importdatum],/*obind=*/1,/*obauto=*/0,/*nnuull=*/1),
 };
 Tabelle tad(My,tbn,felder,elemzahl(felder),/*indices=*/0,/*index size*/0,/*constraints*/0,/*constrzahl*/0,Tx[T_Tabelle_fuer_dicom_Bilder]);
 if (tad.prueftab(aktc,obverb)) {
	 exit(schluss(11,rots+Tx[T_Fehler_beim_Pruefen_von_dictab]+schwarz+tbn,1));
 }
} // void paramcl::pruefdictab()

int hhcl::dorueck(const size_t aktc)
{
	int erg=0;
		char ***cerg;
	RS ldat(My,"select date_format(max(aufnahmedatum),'%Y%m%d_%k%i%S') p0 from fotosinp.dictab",aktc,ZDB);
		if (cerg=ldat.HolZeile(),cerg?*cerg:0) {
			//// <<cjj(cerg,0)<<endl;
		} else {
			erg=10;
		}
 return erg;
} // hhcl::dorueck


hhcl::hhcl(const int argc, const char *const *const argv):dhcl(argc,argv,DPROG,/*mitcron*/1) //α
{
	hLog(violetts+"hhcl::hhcl()"+schwarz);
	// mitpids=1;
 // mitcron=0; //ω
} // hhcl::hhcl //α
// Hier neue Funktionen speichern: //ω
//α
// aufgerufen in lauf
void hhcl::virtVorgbAllg()
{
	hLog(violetts+Tx[T_virtVorgbAllg]+schwarz); //ω
	dhcl::virtVorgbAllg(); //α
} // void hhcl::virtVorgbAllg

// aufgerufen in lauf
void hhcl::pvirtVorgbSpeziell()
{
	hLog(violetts+Tx[T_pvirtVorgbSpeziell]+schwarz);
	virtMusterVorgb(); //ω
	dhcl::pvirtVorgbSpeziell(); //α
} // void hhcl::pvirtVorgbSpeziell

// aufgerufen in lauf
void hhcl::virtinitopt()
{
	hLog(violetts+"virtinitopt()"+schwarz); //ω
	opn<<new optcl(/*pptr*/&anhl,/*art*/puchar,T_st_k,T_stop_l,/*TxBp*/&Tx,/*Txi*/T_DPROG_anhalten,/*wi*/1,/*Txi2*/-1,/*rottxt*/nix,/*wert*/1,/*woher*/1); //α //ω
	opn<<new optcl(/*pptr*/&dszahl,/*art*/pdez,T_n_k,T_dszahl_l,/*TxBp*/&Tx,/*Txi*/T_Zahl_der_aufzulistenden_Datensaetze_ist_zahl_statt,/*wi*/1,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/1); //α //ω
	opn<<new optcl(/*pname*/"duser",/*pptr*/&duser,/*art*/pstri,T_duser_k,T_duser_l,/*TxBp*/&Tx, /*Txi*/T_verwendet_fuer_Samba_den_Linux_Benutzer_string_anstatt,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!duser.empty(),T_verwendet_fuer_Samba_den_Linux_Benutzer_string_anstatt);
	opn<<new optcl(/*pptr*/&obrueck,/*art*/puchar,T_rueck_k,T_rueck_l,/*TxBp*/&Tx, /*Txi*/T_letzten_Import_rueckgaengig, /*wi*/1, /*Txi2*/-1,/*rottxt*/string(),/*wert*/-1,/*woher*/1);
	opn<<new optcl(/*pname*/"qvz",/*pptr*/&qvz,/*art*/pverz,T_qvz_k,T_qvz_l,/*TxBp*/&Tx,/*Txi*/T_Quellverzeichnis_anstatt,/*wi*/1,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!qvz.empty(),T_Quellverzeichnis_anstatt);
	opn<<new optcl(/*pname*/"avz",/*pptr*/&avz,/*art*/pverz,T_avz_k,T_avz_l,/*TxBp*/&Tx,/*Txi*/T_Archivverzeichnis_anstatt,/*wi*/1,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!avz.empty(),T_Archivverzeichnis_anstatt);
	opn<<new optcl(/*pname*/"zvz",/*pptr*/&zvz,/*art*/pverz,T_zvz_k,T_zvz_l,/*TxBp*/&Tx,/*Txi*/T_Zielverzeichnis_anstatt,/*wi*/1,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!zvz.empty(),T_Zielverzeichnis_anstatt);
	opn<<new optcl(/*pname*/"z2vz",/*pptr*/&z2vz,/*art*/pverz,T_z2vz_k,T_z2vz_l,/*TxBp*/&Tx,/*Txi*/T_Zweites_Zielverzeichnis_anstatt,/*wi*/1,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!z2vz.empty(),T_Zweites_Zielverzeichnis_anstatt);
	dhcl::virtinitopt(); //α
} // void hhcl::virtinitopt

// aufgerufen in lauf
void hhcl::pvirtmacherkl()
{
	hLog(violetts+Tx[T_virtmacherkl_Tx_lgn]+schwarz+ltoan(Tx.lgn));
	erkl<<Tx[T_Liest_Dicom_Dateien_aus]<<blau<<qvz<<schwarz<<Tx[T_speichert_sie_als_png_Bilder_in]<<blau<<zvz<<schwarz<<
		Tx[T_und]<<blau<<z2vz<<vtz<<Tx[T_jahr]<<schwarz<<Tx[T_und_verschiebt_zuletzt_die_Orignale_nach]<<blau<<avz<<schwarz<<endl;
//	erkl<<violett<<DPROG<<blau<<Txk[T_tut_dieses_und_jenes]<<schwarz; //ω 
} // void hhcl::pvirtmacherkl //α
//ω
//α

// aufgerufen in lauf
void hhcl::virtMusterVorgb()
{
	hLog(violetts+Tx[T_virtMusterVorgb]+schwarz); //ω
	dhcl::virtMusterVorgb(); //α
} // void hhcl::MusterVorgb

// aufgerufen in lauf
void hhcl::pvirtvorzaehler()
{ //ω
} // void hhcl::virtvorzaehler //α
//ω
// aufgerufen in lauf //α
void hhcl::virtzeigversion(const string& ltiffv/*=string()*/)
{
	hLog(violetts+Tx[T_virtzeigversion]+schwarz);
	dhcl::virtzeigversion(ltiffv);  //ω
} // void hhcl::virtzeigversion //α
//ω
//α
// aufgerufen in lauf
void hhcl::pvirtvorrueckfragen()
{
	hLog(violetts+Tx[T_pvirtvorrueckfragen]+schwarz); //ω
} // void hhcl::pvirtvorrueckfragen //α

void hhcl::neurf()
{
	for(auto omit=opn.schl.end();omit!=opn.schl.begin();) {
		omit--;
		if ((*omit)->Txrf!=-1) {
		 const char* const text=(*(*omit)->TxBp)[(*omit)->Txrf];
		cout<<text<<endl;
		}
	}
} // void hhcl::neurf
 //ω
// aufgerufen in lauf //α
void hhcl::virtrueckfragen()
{
	hLog(violetts+Tx[T_virtrueckfragen]+", rzf: "+blau+ltoan(rzf)+schwarz);
	if (rzf) { //ω
	} // if (rzf) //α
	dhcl::virtrueckfragen();
	hcl::virtrueckfragen();
	//// opn.oausgeb(rot);
} // void hhcl::virtrueckfragen
//ω
//α
// aufgerufen in lauf
void hhcl::virtpruefweiteres()
{
	hLog(violetts+Tx[T_virtpruefweiteres]+schwarz); //ω
	// if (initDB()) exit(schluss(10,Tx[T_Datenbank_nicht_initialisierbar_breche_ab])); //α //ω
	hcl::virtpruefweiteres(); // z.Zt. leer //α
} // void hhcl::virtpruefweiteres

// aufgerufen in lauf
void hhcl::virtzeigueberschrift()
{ 
	hLog(violetts+Tx[T_virtzeigueberschrift]+schwarz); //ω
	// hier ggf. noch etwas an 'uebers' anhaengen //α
	hcl::virtzeigueberschrift();
} // void hhcl::virtzeigueberschrift
//ω
//α
// Parameter -st / --stop
// aufgerufen in: main
void hhcl::anhalten()
{
	hLog(violetts+Tx[T_anhalten]+schwarz);
	// crontab
	/*
	setztmpcron();
	for(int iru=0;iru<1;iru++) {
		const string befehl=
			"bash -c 'grep \""+saufr[iru]+"\" -q <(crontab -l)&&{ crontab -l|sed \"/"+zsaufr[iru]+"/d\">"+tmpcron+";crontab "+tmpcron+";};:'";
		systemrueck(befehl,obverb,oblog,*//*rueck=*//*0,*//*obsudc=*//*1);
	} // 	for(int iru=0;iru<2;iru++)
  */
	pruefcron("0"); // soll vor Log(Tx[T_Verwende ... stehen
	fLog(blaus+Tx[T_Cron_Aufruf_von]+schwarz+mpfad+blau+Tx[T_gestoppt]+schwarz,1,oblog); //ω
} // void hhcl::anhalten() //α
//ω
//α
void hhcl::pvirtnachvi()
{ //ω
} //α

// aufgerufen in lauf
void hhcl::pvirtvorpruefggfmehrfach()
{
	hLog(violetts+Tx[T_pvirtvorpruefggfmehrfach]+schwarz);
	// if (initDB()) exit(schluss(10,Tx[T_Datenbank_nicht_initialisierbar_breche_ab]));  //ω
} // void hhcl::pvirtvorpruefggfmehrfach //α
//ω
void hhcl::pvirtfuehraus() //α
{ 
	hLog(violetts+Tx[T_pvirtfuehraus]+schwarz); //ω
} // void hhcl::pvirtfuehraus  //α

// aufgerufen in lauf
void hhcl::virtschlussanzeige()
{  
	hLog(violetts+Txk[T_virtschlussanzeige]+schwarz); //ω
	dhcl::virtschlussanzeige(); //α
} // void hhcl::virtschlussanzeige
 
// aufgerufen in: main und pruefcapi
void hhcl::virtautokonfschreib()
{
//// const int altobverb=obverb; obverb=1;
	hLog(violetts+Txk[T_autokonfschreib]+schwarz+", "+Txk[T_zu_schreiben]+((rzf||hccd.obzuschreib)?Txk[T_ja]:Txk[T_nein])); //ω
	struct stat kstat{0}; //α
	if (lstat(akonfdt.c_str(),&kstat)) {
		caus<<"Setze obzuschreib, da "<<akonfdt<<" nicht da"<<endl;
		hccd.obzuschreib=1;
	}
	if (rzf||hccd.obzuschreib||kschreib) {
		hLog(gruens+Txk[T_schreibe_Konfiguration]+schwarz);
		// restliche Erklaerungen festlegen
		////    agcnfA.setzbem("language",sprachstr);
		hcl::virtautokonfschreib(); //ω
	} // if (rzf||hccd.obzuschreib) //α
//// obverb=altobverb;
} // void hhcl::virtautokonfschreib

hhcl::~hhcl() 
{ //ω
} // hhcl::~hhcl //α

// wird nur im Fall obhilfe==3 nicht aufgerufen
void hhcl::virtlieskonfein()
{
////	const int altobverb{obverb}; obverb=1;
	hLog(violetts+Txk[T_virtlieskonfein]+schwarz); //ω
	hcl::virtlieskonfein(); //α //ω
	hLog(violetts+Txk[T_Ende]+Txk[T_virtlieskonfein]+schwarz); //α
////	obverb=altobverb;
} // void hhcl::virtlieskonfein() //ω
int main(int argc,char** argv) //α
{
	if (argc>1) { //ω
	} //α
	hhcl hhi(argc,argv); // hiesige Hauptinstanz, mit lngzuw, setzlog und pruefplatte
	hhi.lauf(); // Einleitungsteil mit virtuellen Funktionen, 
	// mit virtVorgbAllg,pvirtVorgbSpeziell,initopt,parsecl,pvirtmacherkl,zeighilfe,virtlieskonfein,verarbeitkonf,lieszaehlerein,MusterVorgb,dovi,dovs,virtzeigversion
	// virtautokonfschreib,update,
	return hhi.retu;
} // int main 

void hhcl::virttesterg()
{
//	hLog(violetts+Txk[T_virttesterg]+schwarz);
	fLog(violetts+Tx[T_virttesterg]+schwarz,obverb,oblog,0,0);
} //ω
