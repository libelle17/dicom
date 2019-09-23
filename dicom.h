#define DPROG "dicom"
// fuer verschiedene Sprachen //α
enum T_      
{
	T_pruefdictab,
	T_eindeutige_Identifikation,
	T_Patientenname,
	T_Geburtsdatum,
	T_Patientennr,
	T_Geschlecht,
	T_Bildtyp,
	T_TransducerData,
	T_ProcessingFunction,
	T_Aufnahmedatum,
	T_Importdatum,
	T_Arzt,
	T_MediaStorageSOPInstanceUID,
	T_Tabelle_fuer_dicom_Bilder,
	T_Fehler_beim_Pruefen_von_dictab,
	T_virtVorgbAllg,
	T_pvirtVorgbSpeziell,
	T_virtMusterVorgb,
	T_pvirtvorrueckfragen,
	T_virtpruefweiteres,
	T_virtmacherkl_Tx_lgn,
	T_Fehler_beim_Pruefen_von,
	T_st_k,
	T_stop_l,
	T_DPROG_anhalten,
	T_anhalten,
	T_Cron_Aufruf_von,
	T_gestoppt,
	T_n_k,
	T_dszahl_l,
	T_Zahl_der_aufzulistenden_Datensaetze_ist_zahl_statt,
	T_Datenbank_nicht_initialisierbar_breche_ab,
	T_pvirtnachrueckfragen,
	T_pvirtfuehraus,
	T_in_pvirtfuehraus_pidw,
	T_virttesterg,
	T_virtzeigversion,
	T_virtzeigueberschrift, 
	T_Fuege_ein, //ω
	T_rufpruefsamba,
	T_DicomQuellVz,
	T_DicomArchivVz,
	T_DicomZielVz,
	T_DicomZiel2Vz,
	T_duser_k,
	T_duser_l,
	T_verwendet_fuer_Samba_den_Linux_Benutzer_string_anstatt,
	T_rueck_k,
	T_rueck_l,
	T_letzten_Import_rueckgaengig,
	T_qvz_k,
	T_qvz_l,
	T_avz_k,
	T_avz_l,
	T_zvz_k,
	T_zvz_l,
	T_z2vz_k,
	T_z2vz_l,
	T_Quellverzeichnis_anstatt,
	T_Archivverzeichnis_anstatt,
	T_Zielverzeichnis_anstatt,
	T_Zweites_Zielverzeichnis_anstatt,
	T_Liest_Dicom_Dateien_aus,
	T_speichert_sie_als_png_Bilder_in,
	T_und,
	T_und_verschiebt_zuletzt_die_Orignale_nach,
	T_jahr,
	T_in_Datenbank_schonda,
	T_schon_da,
	T_Erstellt,
	T_Fehler_beim_Datumsetzen_von,
	T_Nr,
	T_Dicom_Dateien,
	T_Datensaetze_in_Tabelle,
	T_in_Datenbank,
	T_eingetragen,
	T_Dateien_in_Verzeichnis,
	T_erstellt,
	T_kopiert,
	T_Keine,
	T_Alle,
	T_Dateien_von,
	T_nach_,
	T_verschoben,
	T_verzeichnisse,
	T_Keine_Dateien_in,
	T_Gefunden,
	T_Dateien_in,
	T_MAX //α
}; // enum T_ //ω

//α
class hhcl:public dhcl
{
	private: 
		svec fbip; // Fritzbox-IP
		uchar anhl{0};    // <DPROG> anhalten
		string dszahl{"30"}; // Datensatzzahl fuer Tabellenausgaben
		//ω
		string qvz; // Quellverzeichnis // ="/DATA/Patientendokumente/HDneu";
		string avz; // Verzeichnis alter Übertragungen // ="/DATA/Patientendokumente/HDalt";
		uchar obrueck{0};   // ob der letzte Import rueckgaengig gemacht werden soll
		int pfehler{0}; // Rueckgabewert
		char impvz[16]; // Importverzeichnis, z.B. 20171011_082351
    string suchstr;  // Wortteil, nach dem in alten Uebertragungen gesucht werden soll
	protected: //α
		string p1;
		int p2;
		string p3;
		uchar oblista{0};
		long listz{30}; //ω
	public: //α //ω
    string tbn; // Tabellenname
		struct tm jt; // Datum des Importverzeichnises
		string zvz; // Zielverzeichnis // ="/DATA/Patientendokumente/test";
		string z2vz; // 2. Zielverzeichnis // ="/DATA/Patientendokumente/eingelesen";
		ulong dcz{0}; // Dicomzahl
		ulong dbz{0}; // Datenbankzahl
		ulong umz{0}; // Zahl der Umgewandelten
		ulong u2z{0}; // Zahl der nach Ziel 2 Verschobenen
		string duser; // ="sturm";
		string nvz; // Gesamtpfad Importverzeichnis, z.B. /DATA/Patientendokumente/HDalt/20171011_082351
	private: //α //ω
		int dorueck(const size_t aktc);
		void virttesterg(); //α
		void virtlieskonfein();
		void virtautokonfschreib();
		void anhalten(); //ω
		void pruefimpvz();
		void verschieb();
		void verzeichnisse();
	protected: //α
		void virtVorgbAllg();
		void pvirtVorgbSpeziell()
#ifdef VOMHAUPTCODE
			__attribute__((weak)) // implementationsspezifische Vorgaben, Modul vgb.cpp)
#endif
			;
		void virtinitopt(); // (programm-)spezifische Optionen
		void pvirtmacherkl();
		void virtMusterVorgb();
		void pvirtvorzaehler();
		void virtzeigversion(const string& ltiffv=string());
		void pvirtvorrueckfragen();
		void neurf();
		void pvirtnachvi();
		void pvirtnachrueckfragen(); // pvirtvorpruefggfmehrfach();
		void virtpruefweiteres();
		void virtzeigueberschrift();
		void loeschenix();
		void pvirtfuehraus();
		void virtschlussanzeige();
		void zeigdienste(); //ω
		void pruefdcmtk();
	public: //α
		hhcl(const int argc, const char *const *const argv);
    void rufpruefsamba();
		void machimpvz();
		~hhcl();
		friend class fsfcl;
}; // class hhcl //ω

class datcl
{
	private:
		static constexpr const char *knz[]{"PatientName","PatientBirthDate","PatientID","PatientSex","ImageType","ReferringPhysicianName","PerformingPhysicianName","TransducerData","ProcessingFunction","MediaStorageSOPInstanceUID","AcquisitionDateTime","AcquisitionDate"};
		static constexpr const unsigned dim{sizeof knz/sizeof *knz}; // =12;
		static constexpr const unsigned pnnr{0}, itnr{4}, rpnr{5}, tdnr{7}, pfnr{8}, uidnr{9}, adnr{10};
		string id; // Rueckgabe: ID
		svec ir;
	public:
		string name;
		uchar gibaus;
		string bname;
		string ord[dim];
		struct tm tma={0}; // Aufnahmedatum
	public:
		ulong inDB(hhcl& pm, const int& aktc);
		void aufPlatte(hhcl& pm,const size_t& aktc,const size_t& nr);
		datcl(string& name);
};

