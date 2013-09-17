
/*! \file classeellipse.cc
 *
 * \author Paul BERNARD <paul.bernard@eisti.fr>
 *                                                   
 * \version 0.1
 *            Creation du fichier classeellipse.cc
 * \brief classe ellipse
*/

#include "classeellipse.hh"



//constructeur par defaut de la classe ellipse
Ellipse::Ellipse(void){
  //  cout<<"constructeur par defaut ellipse \n";
  Point p(0,0);
  my_centre = p;
  //  my_centre.abcisse(0);
  //  my_centre.ordonnee(0);
  my_gd_axe = 0;
  my_pt_axe = 0;
}



//Constructeur de la class Ellipse avec valeur fournit
Ellipse::Ellipse(const Point & centre_donnee, const float & gd_axe_donnee, const float & pt_axe_donnee){
  //si un des axes est négatif
  if((gd_axe_donnee < 0) ||
     (pt_axe_donnee < 0)){
    Point p(0,0);
    my_centre = p;
    my_gd_axe = 0;
    my_pt_axe = 0;
    //creation de l'errreur
    erreur err("Erreur construction Ellipse par valeur, un des axes est negatif");
    //envoi de l'erreur
    throw (err);
  }else{
    my_pt_axe = pt_axe_donnee;
    my_gd_axe = gd_axe_donnee;
    my_centre = centre_donnee;
  }
}


//Constructeur par copie d'une ellipse
Ellipse::Ellipse(const Ellipse & Ellipse_autre) : Objet2d (Ellipse_autre)
{
  //  cout<<"constructeur par copie ellipse \n";
  my_pt_axe = Ellipse_autre.get_pt_axe();
  my_gd_axe = Ellipse_autre.get_gd_axe();
  my_centre = Ellipse_autre.get_centre();

  
}



//Destructeur de la class Ellipse
Ellipse::~Ellipse(void)
{
  //  cout<<"destructeur  ellipse \n";
}




//Accesseur en ecriture a la variable centre
void Ellipse::set_centre(Point Point_donne){
//On change centre par la valeur donnee en parametres
my_centre=Point_donne;
}

//Accesseur en lecture a la variable centre
Point Ellipse::get_centre(void) const {
//On retourne centre
return(my_centre);
}



//Accesseur en ecriture a la variable gd_axe
void Ellipse::set_gd_axe(float float_donne){
//On change gd_axe par la valeur donnee en parametres
my_gd_axe=float_donne;
}

//Accesseur en lecture a la variable gd_axe
float Ellipse::get_gd_axe() const {
//On retourne gd_axe
return(my_gd_axe);
}


//Accesseur en ecriture a la variable pt_axe
void Ellipse::set_pt_axe(float float_donne){
//On change pt_axe par la valeur donnee en parametres
my_pt_axe=float_donne;
}

//Accesseur en lecture a la variable pt_axe
float Ellipse::get_pt_axe() const {
//On retourne pt_axe
return(my_pt_axe);
}




Ellipse & Ellipse::operator=(const Ellipse & Ellipse_autre){
  //  cout<<"surcharge du = ellipse \n";
//on verifie qu'on a pas demande Ellipse_1 = Ellipse_1
if (this != &Ellipse_autre){
//on associe tous les champs 2 a 2
my_centre = Ellipse_autre.get_centre();
my_gd_axe = Ellipse_autre.get_gd_axe();
my_pt_axe = Ellipse_autre.get_pt_axe();
}
return(*this);
}




bool Ellipse::operator==(const Ellipse & Ellipse_testee) const {
  cout<<"surcharge du test == pour ellipse \n";
  //on verifie que tous les champs sont egaux 2 a 2
  return(my_centre == Ellipse_testee.get_centre()&&
	 my_gd_axe == Ellipse_testee.get_gd_axe()&&
	 my_pt_axe == Ellipse_testee.get_pt_axe());
}


//permet d'afficher une ellipse
void Ellipse::affichage(void) const{
  cout<<"### Ellipse ###\n";
  cout<<"centre : ";
  my_centre.affichage();
  cout<<"demi grand axe :"<<my_gd_axe<<endl;
  cout<<"demi petit axe :"<<my_pt_axe<<endl;
}

void Ellipse::affichage(ZoneAffichage* zoneAffichage)
{

  QRect rect((int)(get_centre().abcisse()-get_gd_axe()),
	     (int)(get_centre().ordonnee()-get_pt_axe()),
	     (int)(2*get_gd_axe()),
	     (int)(2*get_pt_axe()));
  
  QPainter painter(zoneAffichage);
  painter.drawEllipse(rect);
}


//permet de calculer le perimetre de l'ellipse
float Ellipse::perimetre(void) const{
  return(2 * Pi * sqrtf(0.5 * ( (my_pt_axe * my_pt_axe) + (my_gd_axe * my_gd_axe))));
}

//permet de calculer l'aire de l'ellipse
float Ellipse::aire(void) const {
  return(Pi * my_pt_axe * my_gd_axe);
}



//permet d'affecter le centre et les demi axes  
//d'une ellipse a partir d'un fichier
void Ellipse::lire_ellipse_binaire(char* fichier)
{
  ifstream * fic;

  fic = new ifstream;
  //ouverture du fichier en mode binaire
  fic->open(fichier, ios::binary);
  //si erreur d'ouverture
  if (fic->fail()) {
    delete fic;
    //creation de l'errreur
    erreur err("Erreur d'ouverture du fichier");
    //evoi de l'erreur
    throw (err);
  }
  
  //lecture du centre de l'ellipse
  my_centre.lire_Point_binaire(fic);  
  //si la derniere operation s'est mal deroule
  if (!fic->good()) {
    delete fic;
    //creation de l'errreur
    erreur err("Erreur de lecture du fichier");
    //evoi de l'erreur
    throw (err);
  }
  
  //lecture du demi grand axe
  fic->read((char*)  &my_gd_axe,sizeof(float)); 
  //si la derniere operation s'est mal deroule
  if (!fic->good()) {
    delete fic;
    //creation de l'errreur
    erreur err("Erreur de lecture du fichier");
    //evoi de l'erreur
    throw (err);
  }

  //lecture du demi petit axe
  fic->read((char*)  &my_pt_axe,sizeof(float)); 
  //si la derniere operation s'est mal deroule
  if (!fic->good()) {
    delete fic;
    //creation de l'errreur
    erreur err("Erreur de lecture du fichier");
    //evoi de l'erreur
    throw (err);
  }
  
  
  //on ferme notre fichier
  fic->close();
  //on libere la memoire
  delete fic;
}





//permet d'ecrire le centre et les demi axes  
//d'une ellipse dans un fichier
void Ellipse::ecrire_ellipse_binaire(char* fichier) const
{
  ofstream* ficsave;
  ficsave = new ofstream;
  
  //Ouverture du fichier binaire et ecrasement s'il existe
  ficsave->open(fichier,ios::out | ofstream::binary | ios::trunc);
  //Si l'ouverture ne se fait pas correctement
  if (ficsave->fail()) {
    delete ficsave;
    //creation de l'errreur
    erreur err("Erreur de lecture du fichier");
    //evoi de l'erreur
    throw (err);
  }
  
  //on sauve le centre
  my_centre.ecrire_Point_binaire(ficsave);
  //si la derniere operation ne s'est pas bien passe
  if (!ficsave->good()) {
    delete ficsave;
    //creation de l'errreur
    erreur err("Erreur d'ecriture du fichier");
    //evoi de l'erreur
    throw (err);
  }
  
  
  //Sauvegarde du demi grand axe
  ficsave->write((char*) &my_gd_axe,sizeof(float));
  //si la derniere operation ne s'est pas bien passe
  if (!ficsave->good()) {
    delete ficsave;
    //creation de l'errreur
    erreur err("Erreur d'ecriture du fichier");
    //evoi de l'erreur
    throw (err);
  }
  

  
  //Sauvegarde du demi petit axe
  ficsave->write((char*) &my_pt_axe,sizeof(float));
  //si la derniere operation ne s'est pas bien passe
  if (!ficsave->good()) {
    delete ficsave;
    //creation de l'errreur
    erreur err("Erreur d'ecriture du fichier");
    //evoi de l'erreur
    throw (err);
  }
  
  //on ferme notre fichier
  ficsave->close();
  //on libere la memoire
  delete ficsave;
}


