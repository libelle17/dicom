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
		string duser{"sturm"}; // ="sturm";
		string qvz; // Quellverzeichnis // ="/DATA/Patientendokumente/HDneu";
		string avz; // Verzeichnis alter Übertragungen // ="/DATA/Patientendokumente/HDalt";
		string zvz; // Zielverzeichnis // ="/DATA/Patientendokumente/test";
		string z2vz; // 2. Zielverzeichnis // ="/DATA/Patientendokumente/eingelesen";
		uchar obrueck=0;   // ob der letzte Import rueckgaengig gemacht werden soll
	protected: //α
		string p1;
		int p2;
		string p3;
		uchar oblista{0};
		long listz{30}; //ω
	public: //α //ω
	private: //α //ω
		int dorueck(const size_t aktc);
		void virttesterg(); //α
		void virtlieskonfein();
		void virtautokonfschreib();
		void anhalten(); //ω
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
	public: //α
		hhcl(const int argc, const char *const *const argv);
    void rufpruefsamba();
		~hhcl();
		friend class fsfcl;
}; // class hhcl //ω
