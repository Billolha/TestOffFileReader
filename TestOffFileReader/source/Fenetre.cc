#include "Fenetre.hh"
#include <sys/types.h>
#include <dirent.h>

//#include "tmp.hh"





void Fenetre::zoomplus()
{
	//On lance la fonction zoom
  zoneAffichage->zoom(1.05);
  //On raffraichi la fenetre
  this->update();
}


void Fenetre::zoommoins()
{
	//On lance la fonction zoom
  zoneAffichage->zoom(0.95);
  //On raffrachi la fenetre
  this->update();
}



void Fenetre::droit()
{
	//On lance la fonction rotatezay 
  zoneAffichage->rotatezay(Pi/90.0);
  //On raffrachi la fenetre
  this->update();
}


void Fenetre::bas()
{
	//On lance la fonction rotatezax
  zoneAffichage->rotatezax(-Pi/90.0);
  //On raffrachi la fenetre
  this->update();
}


void Fenetre::haut()
{
	//On lance la fonction rotatezax
  zoneAffichage->rotatezax(Pi/90.0);
  //On raffrachi la fenetre
  this->update();
}


void Fenetre::gauche()
{
	//On lance la fonction rotatezay 
  zoneAffichage->rotatezay(-Pi/90.0);
  //On raffrachi la fenetre
  this->update();
}

/* Deplacement */


void Fenetre::mdroit()
{
	//On lance la fonction rotatezay 
  zoneAffichage->move(10,0);
  //On raffrachi la fenetre
  this->update();
}


void Fenetre::mbas()
{
	//On lance la fonction rotatezax
  zoneAffichage->move(0,10);
  //On raffrachi la fenetre
  this->update();
}


void Fenetre::mhaut()
{
	//On lance la fonction rotatezax
  zoneAffichage->move(0,-10);
  //On raffrachi la fenetre
  this->update();
}


void Fenetre::mgauche()
{
	//On lance la fonction rotatezay 
  zoneAffichage->move(-10,0);
  //On raffrachi la fenetre
  this->update();
}




void Fenetre::ouvrirDialogueaide()
{
  //Affichage message aide
  QMessageBox::question(this, "Aide du programme", "<ul><b>Pour charger un fichier : </b><li>ouvrir un dossier via le bouton ouvrir dossier</li><li>selectioner le fichier dans la liste déroulante</li></ul><br><ul><b>Raccourcis clavier :</b><li>Z = Rotation haut</li><li>S = Rotation bas</li><li>Q = Rotation gauche</li><li>D = Rotation droite</li><li>I = Mouvement haut</li><li>K = Mouvement bas</li><li>J = Mouvement gauche</li><li>L = Mouvement droit</li><li>T = Zoom -</li><li>G = Zoom +</li></ul>");
}


void Fenetre::ouvrirDialogue2(int id)
{
  //Si on est pas sur la premier case
  if(id != 0){
//On affiche une boite contenant ce qu'on a selectionné
    QMessageBox::information(this, "item select",(mybox->itemText(id)) + " sélectionné !");
	//transforme le qstring en string
    std::string st_dossier = dossier.toStdString();
    std::string st_fichier = (mybox->itemText(id)).toStdString();
    //On concatene de facon a avoir le chemin du fichier
    string st_chemin = st_dossier + st_fichier;
    //On transforme en char
    const char* c_chemin = st_chemin.c_str();
    int i;    
    //On cree le polyedre 
    Polyedre poly3D = chargeficoff(c_chemin);
    //On affecte celui-ci a la zoneaffichage
    zoneAffichage->set_poly(poly3D);
	//On creer un second polyedre
    Polyedre * poly3D_2 = new Polyedre;
    //On effectue le backfaceculling
    poly3D_2 = backfaceculling(poly3D);  
	//On trie les faces
    tripolyedre2(*poly3D_2)  ;
	//On creer un polygonne 2d
    Polygonne* poly = new Polygonne;
    //On transforme le polyedre en polygonne
    poly = to2d3d(poly3D_2); 
   //On stocke le nombre de face du polyedre backfaceculler
    int nbface = poly3D_2->nbface;
 //On creer un tableau d'objet2d
    Objet2d** tto2d = new Objet2d*[nbface];
    //On affecte le polygonne dans celui-ci
    for(i=0 ; i<nbface ; i++){  
      tto2d[i] = &poly[i];
    }
//On affecte la taille du polyedre backfaceculler a la zoneaffichage
    zoneAffichage->set_taille(poly3D_2->nbface);
    //on affecte le tableau d'objet 2d
    zoneAffichage->set_ttobj(tto2d);
    //On raffraichi la fenetre
    this->update();
    //zoneAffichage->setFocus();
    zoneAffichage->grabKeyboard();
    
    //On delete les allocations
    delete poly3D_2;
    delete [] tto2d;
        
    
  }
  
}




void Fenetre::ouvrirDialogue()
{
	//On recupere le dossier voulu
  dossier = QFileDialog::getExistingDirectory(this,"Selection d'un dossier");
  
  //On transforme le qstring en string puis en char
  std::string st_dossier = dossier.toStdString();
  const char* c_dossier = st_dossier.c_str();

  //On creer une liste de string (fichier)
  QStringList liste_files;
  
  //on met la selection de la liste deroulante a init
  mybox->setCurrentIndex(0);
  //on eneleve la liste des fichiers de la liste deroulante
  int nb_elem = mybox->count();
  while(nb_elem > 0){
    mybox->removeItem(nb_elem);
    nb_elem--;
  }


  struct dirent *lecture;
  DIR *rep;

  //on lit le repertoire ou se trouve les fichier .off
  rep = opendir(c_dossier);
  //si on a bien ouvert un repertoire
  if(rep != NULL){
    //tant qu'on a pas finis de tout lire
    while ((lecture = readdir(rep)))
      {
	//on fait un choix sur les ficiers a recup (que .off)
	if((strcmp(lecture->d_name,".")) && 
	   (strcmp(lecture->d_name,"..")) &&
	   (strstr(lecture->d_name,".off") != NULL)){
	  //on mets les noms de fichier a la suite de la liste
	  liste_files<<lecture->d_name;
	}
      }
    //on ferme le repertoire
    closedir(rep);
  }
  //on ceer la liste deroulante a partir de la liste de fichier
  mybox->addItems(liste_files);
}

Fenetre::Fenetre()
{
  //on creer un gridlayout (ou seront posé tt les objets)
  mainLayout = new QGridLayout;

  //on creer la zoneAffichage 
  zoneAffichage = new ZoneAffichage;
  //on la place sur la grille
  mainLayout->addWidget(zoneAffichage, 1, 1, 13, 10);  
  
  
  //on creer le bouton quitter
  QPushButton *quit = new QPushButton(tr("Quit"), this);
  // on lui definit un taille
  quit->setGeometry(62, 40, 75, 30);
  //on definit la police du texte
  quit->setFont(QFont("Times", 18, QFont::Bold));
  //on connecte le slot quitter l'application a l'event cliquer sur bouton
  connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
  //on la place sur la grille
  mainLayout->addWidget(quit, 13, 13, 1, 1);

  //on creer le bouton aide
  QPushButton *aide = new QPushButton(tr("Aide"), this);
  // on lui definit un taille
  aide->setGeometry(62, 40, 75, 30);
  //on definit la police du texte
  aide->setFont(QFont("Times", 18, QFont::Bold));
  //on connecte le signal ouvrir la boite de dialogue d'aide a l'evenement cliquer sur bouton
  connect(aide, SIGNAL(clicked()), this, SLOT(ouvrirDialogueaide()));
  //on la place sur la grille
  mainLayout->addWidget(aide,13, 11, 1, 1);

  //on creer le bouton apropos
  QPushButton *apropos = new QPushButton(tr("Apropos"), this);
  // on lui definit un taille
  apropos->setGeometry(62, 40, 75, 30);
  //on definit la police du texte
  apropos->setFont(QFont("Times", 18, QFont::Bold));
  //on connecte le signal ouvrir la boite de dialogue aboutQt a l'evenement cliquer sur bouton
  connect(apropos, SIGNAL(clicked()), qApp, SLOT(aboutQt()));
  //on la place sur la grille
  mainLayout->addWidget(apropos,13, 12, 1, 1);

  //on creer le bouton ouvrir dossier
  QPushButton *ouvrir = new QPushButton(tr("ouvrir dossier"), this);
  // on lui definit un taille
  ouvrir->setGeometry(62, 40, 75, 30);
  //on definit la police du texte
  ouvrir->setFont(QFont("Times", 18, QFont::Bold));
  //on connecte le signal ouvrir la boite de dialogue selection dossier a l'evenement cliquer sur bouton
  connect(ouvrir, SIGNAL(clicked()), this, SLOT(ouvrirDialogue()));
  //on la place sur la grille
  mainLayout->addWidget(ouvrir, 0, 11, 1, 3);

  //on creer la liste deroulante de fichier  
  mybox = new QComboBox(this);
  mybox->addItem("-- liste des fichiers --");
  //on connecte le signal pour creer la liste deroulante de fichier a l'evenement cliquer sur bouton
  connect(mybox, SIGNAL(currentIndexChanged(int)), this, SLOT(ouvrirDialogue2(int)));
  //on la place sur la grille
  mainLayout->addWidget(mybox, 1, 11, 1, 3);  

/* ROTATION */

	QLabel * txtrot = new QLabel("    Rotation",this);
	txtrot->setFont(QFont("Times", 18, QFont::Bold));
	mainLayout->addWidget(txtrot,2, 12, 1, 1);

  //on creer le bouton haut
  QPushButton *haut = new QPushButton(tr("up"), this);
  // on lui definit un taille
  haut->setGeometry(62, 40, 75, 30);
  //on definit la police du texte
  haut->setFont(QFont("Times", 18, QFont::Bold));
  //on connecte le signal haut a l'evenement cliquer sur bouton
  connect(haut, SIGNAL(clicked()), this, SLOT(haut()));
  //on la place sur la grille
  mainLayout->addWidget(haut,3, 12, 1, 1);

  //on creer le bouton bas
  QPushButton *bas = new QPushButton(tr("down"), this);
  // on lui definit un taille
  bas->setGeometry(62, 40, 75, 30);
  //on definit la police du texte
  bas->setFont(QFont("Times", 18, QFont::Bold));
  //on connecte le signal bas a l'evenement cliquer sur bouton
  connect(bas, SIGNAL(clicked()), this, SLOT(bas()));
  //on la place sur la grille
  mainLayout->addWidget(bas,5, 12, 1, 1);

  //on creer le bouton  gauche
  QPushButton *gauche = new QPushButton(tr("left"), this);
  // on lui definit un taille
  gauche->setGeometry(62, 40, 75, 30);
  //on definit la police du texte
  gauche->setFont(QFont("Times", 18, QFont::Bold));
  //on connecte le signal gauche a l'evenement cliquer sur bouton
  connect(gauche, SIGNAL(clicked()), this, SLOT(gauche()));
  //on la place sur la grille
  mainLayout->addWidget(gauche,4, 11, 1, 1);

    //on creer le bouton  droit
  QPushButton *droit = new QPushButton(tr("right"), this);
  // on lui definit un taille
  droit->setGeometry(62, 40, 75, 30);
  //on definit la police du texte
  droit->setFont(QFont("Times", 18, QFont::Bold));
  //on connecte le signal droit a l'evenement cliquer sur bouton
  connect(droit, SIGNAL(clicked()), this, SLOT(droit()));
  //on la place sur la grille
  mainLayout->addWidget(droit,4, 13, 1, 1);


/* ************************************** */
/*  Deplacement */
/* ************************************** */

QLabel * txtrot2 = new QLabel("Déplacement",this);
 txtrot2->setFont(QFont("Times", 18, QFont::Bold));
	mainLayout->addWidget(txtrot2,6, 12, 1, 1);

//on creer le bouton haut
  QPushButton *mhaut = new QPushButton(tr("up"), this);
  // on lui definit un taille
  mhaut->setGeometry(62, 40, 75, 30);
  //on definit la police du texte
  mhaut->setFont(QFont("Times", 18, QFont::Bold));
  //on connecte le signal haut a l'evenement cliquer sur bouton
  connect(mhaut, SIGNAL(clicked()), this, SLOT(mhaut()));
  //on la place sur la grille
  mainLayout->addWidget(mhaut,7, 12, 1, 1);

  //on creer le bouton bas
  QPushButton *mbas = new QPushButton(tr("down"), this);
  // on lui definit un taille
  mbas->setGeometry(62, 40, 75, 30);
  //on definit la police du texte
  mbas->setFont(QFont("Times", 18, QFont::Bold));
  //on connecte le signal bas a l'evenement cliquer sur bouton
  connect(mbas, SIGNAL(clicked()), this, SLOT(mbas()));
  //on la place sur la grille
  mainLayout->addWidget(mbas,9, 12, 1, 1);

  //on creer le bouton  gauche
  QPushButton *mgauche = new QPushButton(tr("left"), this);
  // on lui definit un taille
  mgauche->setGeometry(62, 40, 75, 30);
  //on definit la police du texte
  mgauche->setFont(QFont("Times", 18, QFont::Bold));
  //on connecte le signal gauche a l'evenement cliquer sur bouton
  connect(mgauche, SIGNAL(clicked()), this, SLOT(mgauche()));
  //on la place sur la grille
  mainLayout->addWidget(mgauche,8, 11, 1, 1);

    //on creer le bouton  droit
  QPushButton *mdroit = new QPushButton(tr("right"), this);
  // on lui definit un taille
  mdroit->setGeometry(62, 40, 75, 30);
  //on definit la police du texte
  mdroit->setFont(QFont("Times", 18, QFont::Bold));
  //on connecte le signal droit a l'evenement cliquer sur bouton
  connect(mdroit, SIGNAL(clicked()), this, SLOT(mdroit()));
  //on la place sur la grille
  mainLayout->addWidget(mdroit,8, 13, 1, 1);



QLabel * txtrot3 = new QLabel("      Zoom",this);
 txtrot3->setFont(QFont("Times", 18, QFont::Bold));
	mainLayout->addWidget(txtrot3,10, 12, 1, 1);



  //on creer le bouton  zoom plus
  QPushButton *zoomplus = new QPushButton(tr("Zoom +"), this);
  // on lui definit un taille
  zoomplus->setGeometry(62, 40, 75, 30);
  //on definit la police du texte
  zoomplus->setFont(QFont("Times", 18, QFont::Bold));
  //on connecte le signal zoomplus a l'evenement cliquer sur bouton
  connect(zoomplus, SIGNAL(clicked()), this, SLOT(zoomplus()));
  //on la place sur la grille
  mainLayout->addWidget(zoomplus,11, 13, 1, 1);

  //on creer le bouton zomm moins
  QPushButton *zoommoins = new QPushButton(tr("Zoom -"), this);
  // on lui definit un taille
  zoommoins->setGeometry(62, 40, 75, 30);
  //on definit la police du texte
    zoommoins->setFont(QFont("Times", 18, QFont::Bold));
    //on connecte le signal zoommoins a l'evenement cliquer sur bouton
  connect(zoommoins, SIGNAL(clicked()), this, SLOT(zoommoins()));
  //on la place sur la grille
  mainLayout->addWidget(zoommoins,11, 11, 1, 1);

  //on affiche le layout de la fenetre
  setLayout(mainLayout);  

  //on donne un titre a la fenetre
  setWindowTitle(tr("Projet affichage objet 3D"));
}


Fenetre::~Fenetre()
{
  //on detruit la zoneAffichage
  delete zoneAffichage ;
  //on detruit le mainLayout
  delete mainLayout;
  //on detruit la liste deroulante
  delete mybox;
}




 void Fenetre::keyPressEvent(QKeyEvent * event){
 	
   //en fonction de la touche appuié on effectue un action

   //touche D
   if (event->key() == 68) {
     //rotation vers la droite
     zoneAffichage->rotatezay(Pi/90.0);
   } 
   //touche Q
   if (event->key() == 81) {
     //rotation vers la gauche
     zoneAffichage->rotatezay(-Pi/90.0);
   } 
   //touche Z
   if (event->key() == 90) {
     //rotation vers le haut
     zoneAffichage->rotatezax(Pi/90.0);
   } 
   //touche S
   if (event->key() == 83) {
     //rotation vers le bas
     zoneAffichage->rotatezax(-Pi/90.0);
   }
   //touche G
   if (event->key() == 71) {
     //Zoom  sur la figure
     zoneAffichage->zoom(1.05);
   }
   //touche T
   if (event->key() == 84) {
     //Dezoom sur la figure
     zoneAffichage->zoom(0.95);
   }   
   //touche I
   if (event->key() == 73) {
     //Move haut
     zoneAffichage->move(0,-10);
   }   
   //touche J
   if (event->key() == 74) {
     //Move gauche
     zoneAffichage->move(-10,0);
   }   
   //touche K
   if (event->key() == 75) {
     //Move bas
     zoneAffichage->move(0,10);
   }   
   //touche L
   if (event->key() == 76) {
     //Move droit
     zoneAffichage->move(10,0);
   }   
   
   
   //on mets a jour la fenetre
   this->update();
 }


