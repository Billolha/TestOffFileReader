
/*! \file classepolygonne.cc
 *
 * \author Paul BERNARD <paul.bernard@eisti.fr>
 *                                                   
 * \version 0.1
 *            Creation du fichier classepolygonne.cc
 * \brief classe de polygonne
*/

#include "classepolygonne.hh"


//permet d'init un polygonne par defaut
Polygonne::Polygonne(void)
{
  //on init les champ a des valeurs par defaut
  nbSommet = 0;
  inciloin = 0.0;
  incipres = 0.0;
  ptloin = 0;
  ptpres = 0;
  tabP = NULL;
}



//permet d'init un polygonne
Polygonne::Polygonne(int nb)
{
  int i;//Indice de boucle
  float x;//flotant pour stocker l'abcisse d'un point 
  float y;//flotant pour stocker l'ordonnee d'un point 
  
  //si le nb est inferieur à 2 alors pas de polygonne
  if(nb <= 2){
    //on mets les valeurs par defaut
    nbSommet = 0;
    inciloin = 0.0;
  incipres = 0.0;
  ptloin = 0;
  ptpres = 0;
    tabP = NULL;
    //creation de l'errreur
    erreur err("nb de Sommet insuffisant pour creer un Polygone");
    //evoi de l'erreur
    throw (err);
  }else{//sinon
    //on creer le polygonne
    nbSommet = nb;
    inciloin = 0.0;
  incipres = 0.0;
  ptloin = 0;
  ptpres = 0;
    tabP = new Point[nbSommet];
  }

  //on va demander les abcisses et ordonnees pour chaque point
  for (i=0 ; i<nbSommet ; i++){
    //demande d'une abcisses
    cout<<"Une abcisse : ";
    cin>>x;
    //demande d'une ordonnee
    cout<<"Une ordonne : ";
    cin>>y;
    //on tente de rentrer le point 
    modifPoint(i,x,y);
  }
}



//constructeur par copie d'un polygonne
Polygonne::Polygonne(const Polygonne &pol) : Objet2d(pol)
{
  int i;//Indice de boucle

  //on definie le nb de sommet
  nbSommet = pol.nbSommet;

  //si le nb de sommet n'est pas suffisant
  if(nbSommet <= 2){
    //on mets les valeurs par defaut
    nbSommet = 0;
    inciloin = 0.0;
  incipres = 0.0;
  ptloin = 0;
  ptpres = 0;
    tabP = NULL;
   }else{//sinon
    //on creer le tab pour stocker les points
    tabP = new Point[nbSommet];
  inciloin = pol.inciloin;
  incipres = pol.incipres;
  ptloin = pol.ptloin;
  ptpres = pol.ptpres;

  	//on copie chaque point un par un
  	for (i=0 ; i<nbSommet ; i++){
  	  tabP[i] = pol.tabP[i];
  	}
  }
}





//permet d'effectuer une copy par affectation
Polygonne& Polygonne::operator=(const Polygonne &pol)
{
  int i;//Indice de boucle

  //si on a pas le meme objet
  if(this != &pol){
    //on definie le nb de sommet
    nbSommet = pol.nbSommet;
    //si le nb de sommet n'est pas suffisant
    if(nbSommet <= 2){
      //on mets les valeurs par defaut
      nbSommet = 0;
      tabP = NULL;
      inciloin = 0.0;
  incipres = 0.0;
  ptloin = 0;
  ptpres = 0;
    }else{//sinon
      //on creer le tab pour stocker les points
      tabP = new Point[nbSommet];
    
    //on copie chaque point un par un
    for (i=0 ; i<nbSommet ; i++){
      tabP[i] = pol.tabP[i];
    }
    //on copie les incidences ainsi que les point loin /près
     inciloin = pol.inciloin;
  incipres = pol.incipres;
   ptloin = pol.ptloin;
  ptpres = pol.ptpres;
    }
  }
  //on retourne 
  return(*this);
}






//permet de liberer le tab de Points de taille nbSommet
void Polygonne::liberer(void)
{
  //si on a un polygonne
  if((nbSommet > 2) && (tabP != NULL)){
    //on libere la memoire
    delete [] tabP;
    //on met le tab a NULL
    tabP = NULL;
  }
  //on definie le nb de sommet  a 0
  nbSommet = 0;
}


//permet d'afficher les coord des points du polygonne
void Polygonne::affichage(void) const
{
  int i;//Indice de boucle
  //si on a pas un polygonne
  if(tabP != NULL){
    cout<<"### Polygonne ###\n";
    cout<<"nb sommets : "<<nbSommet<<endl;
    //on affiche tous les points du polygonne un par un
    for (i=0 ; i<nbSommet ; i++){
      cout<<"Point "<<i<<" : ";
      tabP[i].affichage();
    }
  }else{
    cout<<"### Polygonne ###\n";
    cout<<"pas de polygonne a afficher. \n";
  }
}



void Polygonne::affichage(ZoneAffichage* zoneAffichage)
{
  int i;//Indice de boucle

  //si on a un polygonne
  if(tabP != NULL){
  	//On creer un Qpolygon
    QPolygon pol(nbSommet);
    //Pour chaque point
    for(i=0 ; i<nbSommet ; i++){
    	//on insere le point dans le polygon qt
      pol.putPoints(i,1,(int)tabP[i].abcisse(),(int)tabP[i].ordonnee());
    }
    //On creer un painter avec zoneaffichage
    QPainter painter(zoneAffichage);
    //On creer un degrade suivant la distance vis a vis du plan 0 0
    QLinearGradient linearGradient((int)tabP[ptpres].abcisse(), (int)tabP[ptpres].ordonnee(), (int)tabP[ptloin].abcisse(), (int)tabP[ptloin].ordonnee());
  	//On calcule les incidences des points loins et pres
  	int eclloin=(int)(45.44*sin(0.0237*inciloin-2.306)+54.7);
  	int eclpres=(int)(45.44*sin(0.0237*incipres-2.306)+54.7);
  	
  	//On creer les 2 couleurs correspondant a ces incidences
    QColor color1(0,143+eclpres,0,255);
    QColor color2(0,143+eclloin,0,255);
    //On affecte les couleurs au degrade
    linearGradient.setColorAt(0, color1);
    linearGradient.setColorAt(1, color2);
    //On choisi le type du degrade
    linearGradient.setSpread ( QGradient::PadSpread);
    //On affecte le degrade au paitner
  	painter.setBrush( linearGradient );
  	//on affiche le polygon creer
  	painter.drawPolygon(pol);
  	
  }
}





//permet de translater un polygonne suivant le vecteur en param
void Polygonne::translate(Vecteur vect)
{
  int i;//Indice de boucle
  
  //si on a un polygonne
  if(tabP != NULL){
    //on translate les points un par un
    for(i=0 ; i<nbSommet ; i++){
      tabP[i].translate(vect.abcisse(),vect.ordonnee());
    }
  }
}





//permet de realiser la symetrie centrale du polygone par rapport a pt
void Polygonne::symetrie_cent(const Point &pt)
{
  //une symetrie centrale est une homothetie de rapport -1
  homothetie(pt,-1.0);
}




//permet de faire une homothetie du polygonne par rapport a pt de rapport k
void Polygonne::homothetie(const Point &pt, float k)
{
  int i;//Indice de boucle
  Vecteur vect;//Declaration d'un vecteur pour l'homothetie
  
  //si on a un polygonne
  if(tabP != NULL){
    //on modif chaque point un par un
    for(i=0 ; i<nbSommet ; i++){
      vect.vecteur_modif(pt,tabP[i]);
      vect.multiplie(k); 
      modifPoint(i,
		 (vect.abcisse() + pt.abcisse()),
		 (vect.ordonnee() + pt.ordonnee()));
    }
  }
}



//destructeur de polygonne
Polygonne::~Polygonne(void)
{
  //on libere la memoire
  delete [] tabP;
  tabP = NULL;
}


//permet de calculer le perimetre du polygonne
float Polygonne::perimetre(void) const
{
  float perim;//flottant pour stocker le perimetre du polygonne
  int i;//Indice de boucle

  //on init le perimetre a 0
  perim = 0;
  
  //si on a un polygone
  if((nbSommet > 2) && (tabP != NULL)){
    //on calcule le perimetre
    for(i = 0 ; i < nbSommet-1 ; i++){
      perim = perim + tabP[i].distance(tabP[i+1]);
    }
    perim = perim + tabP[nbSommet-1].distance(tabP[0]);
  }else{//sinon on n'a pas un polygone
    //creation de l'errreur
    erreur err("pas de calcul du perimetre (polygonne vide)");
    //evoi de l'erreur
    throw (err);
  }
  //on retourne le perimetre
  return(perim);
}







//permet d'affecter les points d'un polygonne a partir d'un fichier
void Polygonne::lire_polygonne_binaire(char* fichier)
{
  ifstream * fic;//pointeur sur fichier de lecture
  int i;//Indice de boucle

  //si on a un polygonne on le remet sur une config init
  if(tabP != NULL){
    delete [] tabP;
    tabP = NULL;
    nbSommet = 0;
  }
  
  
  fic = new ifstream;
  
  //ouverture du fichier en mode binaire
  fic->open(fichier, ios::binary);
  //si erreur d'ouverture
  if (fic->fail()) {
    //on libere la memoire
    delete fic;
    //creation de l'errreur
    erreur err("Erreur d'ouverture du fichier");
    //evoi de l'erreur
    throw (err);
  }
  
  //lecture du nb de sommets
  fic->read((char*)  &nbSommet,sizeof(int)); 
  //si la derniere operation s'est mal deroule
  if (!fic->good()) {
    //on libere la memoire
    delete fic;
    //creation de l'errreur
    erreur err("Erreur de lecture du fichier (nbSommet)");
    //evoi de l'erreur
    throw (err);
  }
  
  //on creer le polygonne
  tabP = new Point[nbSommet];
  
  //on recupere tous les points du polygonne
  for(i=0;i<nbSommet;i++){
    tabP[i].lire_Point_binaire(fic);
  }
  
  //on ferme notre fichier
  fic->close();
  //on libere la memoire
  delete fic;
}



//permet d'ecrire les points d'un polygonne dans un fichier
void Polygonne::ecrire_polygonne_binaire(char* fichier) const
{
  int i;//Indice de boucle
  ofstream* ficsave;//pointeur sur fichier d'ecriture

  ficsave = new ofstream;
  
  //Ouverture du fichier binaire et ecrasement s'il existe
  ficsave->open(fichier,ios::out | ofstream::binary | ios::trunc);
  //Si l'ouverture ne se fait pas correctement
  if (ficsave->fail()) {
    //on libere la memoire
    delete ficsave;
    //creation de l'errreur
    erreur err("Erreur d'ouverture du fichier");
    //evoi de l'erreur
    throw (err);
  }
  
  //Sauvegarde du nombre de sommet
  ficsave->write((char*) &nbSommet,sizeof(int));
  //si la derniere operation ne s'est pas bien passe
  if (!ficsave->good()) {
    //on libere la memoire
    delete ficsave;
    //creation de l'errreur
    erreur err("Erreur d'ecriture du fichier (nbSommet)");
    //evoi de l'erreur
    throw (err);
  }
  
  //On sauvegarde chaque case du tableau			
  for (i=0; i<nbSommet;i++) {
    tabP[i].ecrire_Point_binaire(ficsave);
  }
  
  //on ferme notre fichier
  ficsave->close();
  //on libere la memoire
  delete ficsave;
}


//permet de calculer l'aire du polygonne
float Polygonne::aire(void) const
{  
  return(0);
}


//Accesseur en lecture a la variable nbSommet
int Polygonne::get_nb_sommet(void) const 
{
  //on retourne le champ nb de sommet
  return(nbSommet);
}
//Accesseur en lecture a la variable nbSommet
void Polygonne::set_nb_sommet(int nb)  
{
  //on retourne le champ nb de sommet
  nbSommet = nb;
}




//Accesseur en lecture au tab de points
Point* Polygonne::get_tab_pts(void) const
{
  //on remtourne le champ tableau de points
  return(tabP);
}

void Polygonne::modifPoint(Point *& p) {
	tabP = p;
}

//permet de modifier un point d'un polygonne
void Polygonne::modifPoint(int pos,float abs, float ord)
{
  int j;//Indice de boucle
  
  //init de l'indice
  j = 0;
  
  //si on a un polygone
  if(tabP != NULL){
    
    //si le point peut etre rentre dans le polygone
    if((pos >= 0) && (pos < nbSommet)){
      //on copie l'abcisse
      tabP[pos].my_dx = abs;
      //on copie l'ordonne
      tabP[pos].my_dy = ord;
      //verification si on a pas deja rentre ce point
      while(j < pos){
	//si le point est rentre en double
	if(tabP[j] == tabP[pos]){
	  //on libere le polygone
	  liberer();
	  //creation de l'errreur
	  erreur err("modif d'un point de polygonne (point en double dans le tab de points)");
	  //evoi de l'erreur
	  throw (err);
	}
	//incrementation de l'indice de boucle
	j++;
      }
    }else{//sinon
      //le point ne peut pas etre rentre dans le polygonne
      //creation de l'errreur
      erreur err("le point ne peut pas etre rentre dans le polygonne");
      //evoi de l'erreur
      throw (err);
    }
    
  }else{//sinon
    //on n'avait pas un polygonne il etait vide)
    //creation de l'errreur
    erreur err("pas de polygone a modifier (tabP vide)");
    //evoi de l'erreur
    throw (err);
  }
}


void Polygonne::set_inciloin(float nb){
	//On affecte l'incidence
	inciloin = nb;
}
void Polygonne::set_incipres(float nb) {
	//On affecte l'incidence
	incipres = nb;
}

void Polygonne::set_ptloin(int nb) {
	//On affecte l'indice du point
	ptloin = nb;
}
void Polygonne::set_ptpres(int nb) {
	//On affecte l'indice du point
	ptpres = nb ;
	}

float Polygonne::get_inciloin(void) const{
	//on renvoie l'incidence
	return(inciloin);
}
float Polygonne::get_incipres(void) const {
	//on renvoie l'incidence
	return(incipres);
}

int Polygonne::get_ptloin(void) const {
	//On renvoie l'indice du point
	return(ptloin);
}

int Polygonne::get_ptpres(void) const { 
	//On renvoie l'indice du point
	return(ptpres);
}


