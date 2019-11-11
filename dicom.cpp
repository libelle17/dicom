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
	// T_ra_k,
	{"ra","co"},
	// T_richtalte_l,
	{"richtalte","correctold"},
	// T_alte_nicht_bearbeitete_nachholen,
	{"alte, nicht bearbeitete nachholen","catch up old, not edited"},
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
	// T_pvirtnachrueckfragen,
	{"pvirtnachrueckfragen()","pvirtaftercallbacks()"},
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
	// T_in_Datenbank_schonda
	{"schon da: ","already here: "},
	// T_schon_da
	{" schon da!"," already here!"},
	// T_Erstellt
	{" Erstellt: ","Made: "},
	// T_Fehler_beim_Datumsetzen_von
	{"Fehler beim Datumsetzen von '","Error while setting the date for '"},
	// T_Nr
	{"Nr: ","No: "},
	// T_Dicom_Dateien
	{" Dicom-Dateien in '"," dicom files found in '"},
	// T_Datensaetze_in_Tabelle
	{" Datensaetze in Tabelle '"," records inserted in table '"},
	// T_in_Datenbank
	{"' in Datenbank '","' in database '"},
	// T_eingetragen
	{"' eingetragen,","',"},
	// T_Dateien_in_Verzeichnis
	{" Dateien in Verzeichnis '"," files created in directory '"},
	// T_erstellt
	{"' erstellt,","',"},
	// T_kopiert
	{"' kopiert,","',"},
	// T_Keine
	{"Keine","   No"},
	// T_Alle
	{" Alle","  All"},
	// T_Dateien_von
	{" Dateien von '"," files moved from '"},
	// T_nach_
	{"' nach '","' to '"},
	// T_verschoben
	{"' verschoben.","'."},
	// T_verzeichnisse
	{"verzeichnisse()","directories()"},
	// T_Keine_Dateien_in
	{"Keine Dateien in '","No files found in '"},
	// T_Gefunden
	{"' gefunden!","'!"},
	// T_Dateien_in
	{" Dateien in '"," files found in '"},
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
} // void paramcl::pruefdictab

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
	findv=3;
	qvz="/var/spool/dicomneu";
	avz="/var/spool/dicomalt";
	zvz="/var/spool/dicomziel";
	z2vz="/var/spool/dicomziel2";
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
	// Kopiervorlage:
	// opn<<new optcl(/*pname*/"pname",/*pptr*/pptr,/*art*/pstri,/*kurzi*/T_kurz_k,/*langi*/T_lang_l,/*TxBp*/&Tx,/*Txi*/T_Option_erklaert,/*wi*/1,/*Txi2*/T_Option_Nachtext,/*rottxt*/nix,/*wert*/1,/*woher*/!pname.empty(),/*Txtrf*/{},/*obno*/1,/*refstr*/0,/*obfragz*/0,/*fnobfragz*/0,/*fnnachhz*/&hcl::fu1,/*fnvorhz*/0,/*sonderrf*/0,/*fngueltigz*/0)
	opn<<new optcl(/*pptr*/&anhl,/*art*/puchar,T_st_k,T_stop_l,/*TxBp*/&Tx,/*Txi*/T_DPROG_anhalten,/*wi*/1,/*Txi2*/-1,/*rottxt*/nix,/*wert*/1,/*woher*/1); //α //ω
	opn<<new optcl(/*pptr*/&dszahl,/*art*/pdez,T_n_k,T_dszahl_l,/*TxBp*/&Tx,/*Txi*/T_Zahl_der_aufzulistenden_Datensaetze_ist_zahl_statt,/*wi*/1,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/1); //α //ω
	opn<<new optcl(/*pptr*/&richtalte,/*art*/puchar,T_ra_k,T_richtalte_l,/*TxBp*/&Tx,/*Txi*/T_alte_nicht_bearbeitete_nachholen,/*wi*/1,/*Txi2*/-1,/*rottxt*/nix,/*wert*/1,/*woher*/1); //α //ω
	opn<<new optcl(/*pname*/"duser",/*pptr*/&duser,/*art*/pstri,T_duser_k,T_duser_l,/*TxBp*/&Tx, /*Txi*/T_verwendet_fuer_Samba_den_Linux_Benutzer_string_anstatt,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!duser.empty());
	opn<<new optcl(/*pptr*/&obrueck,/*art*/puchar,T_rueck_k,T_rueck_l,/*TxBp*/&Tx, /*Txi*/T_letzten_Import_rueckgaengig, /*wi*/1, /*Txi2*/-1,/*rottxt*/string(),/*wert*/-1,/*woher*/1);
	opn<<new optcl(/*pname*/"qvz",/*pptr*/&qvz,/*art*/pverz,T_qvz_k,T_qvz_l,/*TxBp*/&Tx,/*Txi*/T_Quellverzeichnis_anstatt,/*wi*/1,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!qvz.empty());
	opn<<new optcl(/*pname*/"avz",/*pptr*/&avz,/*art*/pverz,T_avz_k,T_avz_l,/*TxBp*/&Tx,/*Txi*/T_Archivverzeichnis_anstatt,/*wi*/1,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!avz.empty());
	opn<<new optcl(/*pname*/"zvz",/*pptr*/&zvz,/*art*/pverz,T_zvz_k,T_zvz_l,/*TxBp*/&Tx,/*Txi*/T_Zielverzeichnis_anstatt,/*wi*/1,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!zvz.empty());
	opn<<new optcl(/*pname*/"z2vz",/*pptr*/&z2vz,/*art*/pverz,T_z2vz_k,T_z2vz_l,/*TxBp*/&Tx,/*Txi*/T_Zweites_Zielverzeichnis_anstatt,/*wi*/1,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!z2vz.empty());
	opn<<new optcl(/*pname*/"tbn",/*pptr*/&tbn,/*art*/pstri,/*kurzi*/T_tb_k,/*langi*/T_tabelle_l,/*TxBp*/&Txd,/*Txi*/T_verwendet_die_Tabelle_string_anstatt,/*wi*/1,/*Txi2*/-1,/*rottxt*/nix,/*wert*/1,/*woher*/!tbn.empty());
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
	tbn="dictab";
	duser="sturm";
	setzbenutzer(&duser);
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
		if (!(*omit)->Txtrf.empty()) {
		 const char* const text=(*omit)->Txtrf.c_str();
		cout<<text<<endl;
		}
	}
} // void hhcl::neurf
 //ω
//α
// aufgerufen in lauf
void hhcl::virtpruefweiteres()
{
	hLog(violetts+Tx[T_virtpruefweiteres]+schwarz); //ω
	// if (initDB()) exit(schluss(10,Tx[T_Datenbank_nicht_initialisierbar_breche_ab])); //α //ω
	verzeichnisse();
	if (!anhl && suchstr.empty())
		rufpruefsamba();
	if (logdateineu) tuloeschen(logdt,string(),obverb,oblog);
	hLog(Txk[T_Logpfad]+drots+loggespfad+schwarz+Txk[T_oblog]+drot+ltoan((int)oblog)+schwarz+")");
	// if (initDB()) exit(schluss(10,Tx[T_Datenbank_nicht_initialisierbar_breche_ab])); //α //ω
	if (initDB()) {
		exit(schluss(10,Tx[T_Datenbank_nicht_initialisierbar_breche_ab]));
	}
	pruefdictab(My,tbn, obverb,oblog);
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
void hhcl::pvirtnachrueckfragen() // pvirtvorpruefggfmehrfach()
{
	hLog(violetts+Tx[T_pvirtnachrueckfragen]+schwarz);
	// if (initDB()) exit(schluss(10,Tx[T_Datenbank_nicht_initialisierbar_breche_ab]));  //ω
	prueftif(TIFFGetVersion());
	pruefdcmtk();
} // void hhcl::pvirtnachrueckfragen //α
//ω
void hhcl::pvirtfuehraus() //α
{ 
	hLog(violetts+Tx[T_pvirtfuehraus]+schwarz); //ω
	const size_t aktc{0};
	if (obrueck) 
		exit(dorueck(aktc));
	machimpvz();
	svec rueck;
	const string* suchvz{richtalte?&avz:&qvz};
	// sonst Fehler zu viele offene Dateien
	cmd="find "+*suchvz+" -type f -not -path '*\\.*' -newermt '20190711' "/*-not -newermt '20191111'*/" -not -path '*DICOMDIR*'";
	systemrueck(cmd,obverb,oblog,&rueck);
	if (!rueck.size()) {
	 fLog(rots+Tx[T_Keine_Dateien_in]+blau+*suchvz+rot+Tx[T_Gefunden]+schwarz,1,0);
	 pfehler=1;
	} else {
		pruefimpvz();
		dcz=rueck.size();
		fLog(blaus+ltoan(rueck.size())+schwarz+Tx[T_Dateien_in]+blau+qvz+schwarz+Tx[T_Gefunden],1,0);
		for(size_t nr=0;nr<rueck.size();nr++) {
			datcl dat(rueck[nr]);
			if (dat.inDB(*this,aktc)) {
				dat.aufPlatte(*this,aktc,nr);
			}
		} // 	for(size_t nr=0;nr<rueck.size();nr++)
		if (!richtalte) verschieb();
	} // 	if (!rueck.size())
} // void hhcl::pvirtfuehraus  //α

// aufgerufen in lauf
void hhcl::virtschlussanzeige()
{  
	hLog(violetts+Txk[T_virtschlussanzeige]+schwarz); //ω
	fLog(blaus+ltoan(dcz,10,0,5)+schwarz+Tx[T_Dicom_Dateien]+blau+qvz+schwarz+Txk[T_gefunden],1,1);
	fLog(blaus+ltoan(dbz,10,0,5)+schwarz+Tx[T_Datensaetze_in_Tabelle]+blau+tbn+schwarz+Tx[T_in_Datenbank]+blau+dbq+schwarz+Tx[T_eingetragen],1,1);
	fLog(blaus+ltoan(umz,10,0,5)+schwarz+Tx[T_Dateien_in_Verzeichnis]+blau+zvz+schwarz+Tx[T_erstellt],1,1);
	fLog(blaus+ltoan(u2z,10,0,5)+schwarz+Tx[T_Dateien_in_Verzeichnis]+blau+z2vz+vtz+Tx[T_jahr]+schwarz+Tx[T_kopiert],1,1);
	if (!richtalte) {
		fLog(blaus+(pfehler?Tx[T_Keine]:Tx[T_Alle])+schwarz+Tx[T_Dateien_von]+blau+qvz+schwarz+Tx[T_nach_]+blau+avz+vtz+impvz+schwarz+Tx[T_verschoben],1,1);
	}
	dhcl::virtschlussanzeige(); //α
} // void hhcl::virtschlussanzeige

void hhcl::machimpvz()
{
	time_t jetzt;
	time(&jetzt);
	memcpy(&jt,localtime(&jetzt),sizeof jt);
	strftime(impvz,16,"%Y%m%d_%H%M%S",&jt);
	nvz=avz+vtz+impvz;
} // void paramcl::machimpvz()

void hhcl::pruefimpvz()
{
		pfehler= pruefverz(nvz,obverb,oblog,/*obmitfacl=*/1,/*obmitcon=*/1,/*besitzer=*/duser,/*benutzer=*/duser,/*obmachen=*/1);
} // void paramcl::pruefimpvz()

void hhcl::verschieb()
{
	if (!pfehler) {
		const string cmd{"mv -n '"+qvz+vtz+"'* '"+nvz+vtz+"'"};
		pfehler=systemrueck(cmd,obverb,oblog);
	} // 	if (!pfehler) 
} // void paramcl::verschieb()

void hhcl::verzeichnisse()
{
	hLog(violetts+Tx[T_verzeichnisse]+schwarz);
	pruefverz(qvz,obverb,oblog,/*obmitfacl=*/1,/*obmitcon=*/1,/*besitzer=*/duser,/*benutzer=*/duser,/*obmachen=*/1);
	pruefverz(avz,obverb,oblog,/*obmitfacl=*/1,/*obmitcon=*/1,/*besitzer=*/duser,/*benutzer=*/duser,/*obmachen=*/1);
	pruefverz(zvz,obverb,oblog,/*obmitfacl=*/1,/*obmitcon=*/1,/*besitzer=*/duser,/*benutzer=*/duser,/*obmachen=*/1);
	pruefverz(z2vz,obverb,oblog,/*obmitfacl=*/1,/*obmitcon=*/1,/*besitzer=*/duser,/*benutzer=*/duser,/*obmachen=*/1);
} // paramcl:: verzeichnisse

void hhcl::pruefdcmtk()
{
  const double dcmv=progvers("dcmj2pnm");
	if (dcmv<3.62) {
		int altobverb=obverb;
		obverb=1;
		linstp->doggfinst("cmake",obverb,oblog); 
		const string proj="dcmtk_copy";
		holvomnetz(proj);
		kompiliere(proj,s_gz);
		obverb=altobverb;
	} // 	if (dcmv<3.62)
} // void paramcl::pruefdcmtk()

 
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

constexpr const unsigned datcl::dim;
constexpr const char *datcl::knz[dim];
constexpr const unsigned datcl::pnnr, datcl::itnr, datcl::rpnr, datcl::tdnr, datcl::pfnr, datcl::adnr;

ulong datcl::inDB(hhcl& pm,const int& aktc)
{
	ulong zl{0};
	systemrueck("dcmdump +U8 '"+name+"' 2>/dev/null",pm.obverb,pm.oblog,&ir);
	string erg[dim];
	gibaus=0;
	int fehltzahl=dim;
	for(size_t zl=0;zl<ir.size();zl++) {
		for(unsigned j=0;j<dim;j++) {
			if (ord[j].empty()) {
				if (ir[zl].find(knz[j])!=string::npos) {
					size_t p1=ir[zl].find('[');
					if (p1!=string::npos) {
						size_t p2=ir[zl].find(']',p1);
						if (p2!=string::npos) {
							string roh=ir[zl].substr(p1+1,p2-p1-1);
							gtrim(&roh);
							if (j==tdnr) if ((p1=roh.find('\\'))!=string::npos) roh.erase(p1);
							if ((p1=roh.find('\''))!=string::npos) roh.erase(p1);
							if ((p1=roh.find('\"'))!=string::npos) roh.erase(p1);
							if (j==itnr) if ((p1=roh.rfind('\\'))!=string::npos) roh.erase(0,p1+1); // ImageType
							if (j==adnr) if ((p1=roh.rfind('.'))!=string::npos) roh.erase(p1); // AcquisitionDateTime
							if (j==pnnr) ersetzAlle(&roh,"^",","); // PatientName
							ord[j]=roh;
							fehltzahl--;
							gibaus=1;
						} // 								if (p2!=string::npos)
					} // 							if (p1!=string::npos)
				} // 						if (ir[zl].find(knz[j])!=string::npos)
			} // 					if (ord[j].empty())
		} // 				for(unsigned j=0;j<dim;j++)
		if (!fehltzahl) break;
	} // 	for(size_t zl=0;zl<ir.size();zl++)
	RS rins(pm.My,pm.tbn);
	vector<instyp> einf;
	for(unsigned j=0;j<dim;j++) {
		if (j==pnnr || j==pfnr) {
			char vor=0; //// (j==pnnr?0:1);
			for(unsigned jj=0;jj<ord[j].length();jj++) {
				if (vor&&vor!=','&&vor!='-') ord[j][jj]=tolower(ord[j][jj]);
				vor=ord[j][jj];
			} // 			for(unsigned jj=0;jj<ord[j].length();jj++)
		} // 		if (j==pnnr || j==pfnr)
	} // 	for(unsigned j=0;j<dim;j++)
	einf.push_back(instyp(pm.My->DBS,"PatientName",&ord[pnnr]));
	struct tm tmg{0};
	strptime(ord[1].c_str(),"%Y%m%d",&tmg);
	einf.push_back(instyp(pm.My->DBS,"Geburtsdatum",&tmg));
	einf.push_back(instyp(pm.My->DBS,"PatientID",&ord[2]));
	einf.push_back(instyp(pm.My->DBS,"Geschlecht",&ord[3]));
	einf.push_back(instyp(pm.My->DBS,"Bildtyp",&ord[itnr]));
	einf.push_back(instyp(pm.My->DBS,"ReferringPhysicianName",&ord[rpnr]));
	einf.push_back(instyp(pm.My->DBS,"PerformingPhysicianName",&ord[6]));
	einf.push_back(instyp(pm.My->DBS,"TransducerData",&ord[tdnr]));
	einf.push_back(instyp(pm.My->DBS,"ProcessingFunction",&ord[pfnr]));
	einf.push_back(instyp(pm.My->DBS,"MediaStorageSOPInstanceUID",&ord[uidnr]));
//	if (ord[adnr].empty()) ord[adnr]=ord[adnr+1];
	// Ersatz: Dateidatum
	if (ord[adnr].empty()) {
		struct stat st={0};
		if (!lstat(name.c_str(),&st)) {
			// ggf. AcquisitionDate mit noch hoeherer Präferenz, falls Datei editiert wurde
			memcpy(&tma,localtime(&st.st_mtime),sizeof tma);
			char buf[20];
			//// strftime(buf,sizeof buf,"%Y%m%d%H%M%S",&tma); caus<<violett<<buf<<schwarz<<endl;
			if (!ord[adnr+1].empty()) {
				tma.tm_year=atoi(ord[adnr+1].substr(0,4).c_str())-1900;
				tma.tm_mon=atoi(ord[adnr+1].substr(4,2).c_str())-1;
				tma.tm_mday=atoi(ord[adnr+1].substr(6,2).c_str());
				mktime(&tma);
			}
			strftime(buf,sizeof buf,"%Y%m%d%H%M%S",&tma);
			ord[adnr]=buf;
		} // 		if (!lstat(name.c_str(),&st))
	} else {
		strptime(ord[adnr].c_str(),"%Y%m%d%H%M%S",&tma);
	} // 	if (ord[adnr].empty()) else
	einf.push_back(instyp(pm.My->DBS,"Aufnahmedatum",&tma));
	einf.push_back(instyp(pm.My->DBS,"Importdatum",&pm.jt));
	if (ord[adnr].length()>8) ord[adnr].insert(8,"_"); // für bessere Lesbarkeit Datum und Zeit trennen
	svec eindfeld;
	eindfeld<<"PatientName";
	eindfeld<<"Geburtsdatum";
	eindfeld<<"PatientID";
	eindfeld<<"Aufnahmedatum";
	eindfeld<<"MediaStorageSOPInstanceUID";
	const int ZDB{(pm.obverb?pm.obverb-1:0)};
	zl=rins.tbins(&einf,aktc,/*sammeln=*/0,/*obverb=*/ZDB,&id,/*eindeutig=*/0,eindfeld);
	pm.dbz+=zl;
	if (!zl) { 
		fLog(Tx[T_in_Datenbank_schonda]+blaus+ord[pnnr]+", "+ord[uidnr]+schwarz,1,pm.oblog);
	}
	fLog("ID: '"+violetts+id+schwarz+"', affected rows: "+violett+ltoan(zl)+schwarz,pm.obverb,pm.oblog);
	return zl;
} // void datcl::inDB


datcl::datcl(string& name,int obverb/*=0*/): obverb(obverb),name(name)
{
}

// aufgerufen in main
void datcl::aufPlatte(hhcl& pm,const size_t& aktc,const size_t& nr)
{
	for(unsigned j=0;j<dim;j++) {
		if (j==adnr+1 && !ord[adnr].empty()) continue; // wenn AcquisitionDateTime fehlt, dann AcquisitionDate nehmen
		if (j==adnr && ord[adnr].empty()) j++;
		if (j!=itnr && j!=rpnr) {
			if (j==uidnr && ord[j].length()>10) { // die Nummer is a bisserl z lang, der hintere Teil is guad
				bname+=ord[j].substr(ord[j].length()-10);
			} else {
				bname+=ord[j];
			}
			if (j<dim-2) bname+='_'; // nicht am Schluss
		} // 			if (j!=itnr && j!=rpnr)
	} // 		for(int j=0;j<dim;j++)
	if (id.empty()) {
		fLog(rots+bname+schwarz+Tx[T_schon_da],pm.obverb,pm.oblog);
	} else {
		const string neuname=pm.zvz+"/"+bname+".png";
		for(int iru=0;iru<2;iru++) {
			svec srueck;
			systemrueck("dcmj2pnm +on2 '"+name+"' > '"+neuname+"'",pm.obverb,pm.oblog,&srueck);
			if (srueck.size()) {
				if (srueck[0].find("no version information")==string::npos)
							break;
			} else {
				break;
			}
			// hier dcmt installieren
		} // 		for(int iru=0;iru<2;iru++)
		struct stat nst{0};
		if (!lstat(neuname.c_str(),&nst)) {
			fLog(blaus+ltoan(nr+1)+schwarz+") "+Tx[T_Erstellt]+blaus+neuname+schwarz,1,pm.oblog);
			pm.umz++;
			const string jahr{ord[adnr].substr(0,4)};
			tma.tm_isdst=-1;
			const time_t modz{mktime(&tma)};
			struct utimbuf ub{0};
			ub.modtime=modz;
			ub.actime=modz;
			if (utime(neuname.c_str(),&ub)) {
				fLog(rots+Tx[T_Fehler_beim_Datumsetzen_von]+blau+neuname+"'"+schwarz,pm.obverb,pm.oblog);
			}
			uid_t duid;
			gid_t dgid;
			untersuser(pm.duser,&duid,&dgid);
			systemrueck("chown "+pm.duser+":"+ltoan(dgid)+" '"+neuname+"'",pm.obverb,pm.oblog);
			const string z2vzj{pm.z2vz+vtz+jahr};
			if (!pruefverz(z2vzj,pm.obverb,pm.oblog,/*obmitfacl=*/1,/*obmitcon=*/1,/*besitzer=*/pm.duser,/*benutzer=*/pm.duser,/*obmachen=*/1)) {
				const string cmd{"cp -a '"+neuname+"' '"+z2vzj+"'"};
				pm.u2z+=!systemrueck(cmd,pm.obverb,pm.oblog);
			} // 			if (!pruefverz(z2vzj,obverb,oblog,/*obmitfacl=*/1,/*obmitcon=*/1,/*besitzer=*/duser,/*benutzer=*/duser,/*obmachen=*/1))
		} else {
			RS weg(pm.My,"DELETE FROM `"+pm.tbn+"` WHERE ID="+id,aktc,pm.ZDB);
		} // 		if (!lstat(neuname.c_str(),&nst)) else
		//		systemrueck("touch -r '"+rueck[nr]+"' '"+neuname+"'",pm.obverb,pm.oblog); // = zu spaet
		if (gibaus)
			fLog(bname,pm.obverb,pm.oblog);
		fLog(Tx[T_Nr]+blaus+ltoan(nr)+schwarz+", "+blau+name+schwarz+" "+blau+(ir.size()?ir[0]:"")+schwarz,pm.obverb,pm.oblog);
	} // 			if (id.empty())
} // void datcl::aufPlatte
