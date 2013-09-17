
/*! \file classevecteur.cc
 *
 * \author Paul BERNARD <paul.bernard@eisti.fr>
 *                                                   
 * \version 0.1
 *            Creation du fichier classevecteur.cc
 * \brief classe de vecteur
*/

#include "classevecteur.hh"

//permet d'init un Vecteur aux valeurs par defaut
Vecteur::Vecteur(void)
{
  //on init le point
  my_dx = 0.0;
  my_dy = 0.0;  
}



 //permet d'init un vecteur de composantes x et y
Vecteur::Vecteur(float x, float y)
{
  //on init le le vecteur
  my_dx = x;
  my_dy = y;
}


//permet d'init un vecteur avec deux point
Vecteur::Vecteur(const Point &A, const Point &B)
{
  my_dx = B.abcisse() - A.abcisse();
  my_dy = B.ordonnee() - A.ordonnee();
}



//constructeur par copie d'un vecteur
Vecteur::Vecteur(const Vecteur &v){
  my_dx = v.my_dx;
  my_dy = v.my_dy;
}


//permet d'effectuer une copy par affectation
Vecteur& Vecteur::operator=(const Vecteur &v){
  if(this!= &v){
    my_dx = v.my_dx;
    my_dy = v.my_dy;
  }
  return(*this);
}











//permet de recalculer un vecteur avec deux point
void Vecteur::vecteur_modif(const Point &A, const Point &B)
{
  my_dx = A.abcisse() - B.abcisse();
  my_dy = B.ordonnee() - B.ordonnee();
  
}






//permet d'afficher les composantes d'un vecteur
void Vecteur::affichage(void) const
{
  cout<<"composantes du vecteur : X = "<<my_dx<<" et Y = "<<my_dy<<endl;
}



//permet l'addition du vecteur avec celui placé en param
void Vecteur::addition(const Vecteur &vect)
{
  my_dx = my_dx + vect.my_dx;
  my_dy = my_dy + vect.my_dy;
}



//permet de calculer la norme du vecteur
float Vecteur::norme(void) const
{
  return( sqrt( (my_dx*my_dx) + (my_dy*my_dy)));
}


//permet de normaliser un vecteur
void Vecteur::normalise(void){
  if(norme() != 0.0){
    my_dx = my_dx / norme();
    my_dy = my_dy / norme();
  }
  else{
    my_dx = 0.0;
    my_dy = 0.0;
  }
}


//permet de multiplier le vecteur par le scalaire alph
void Vecteur::multiplie(float alpha)
{
  my_dx = my_dx * alpha;
  my_dy = my_dy * alpha;
}


//permet de calculer le pdt scalaire par le vecteur placé en param
float Vecteur::pdt_scalaire(const Vecteur &vect) const
{
  return((my_dx*vect.my_dx)+(my_dy*vect.my_dy));
}



//permet de retourner l'abcisse du vect
float Vecteur::abcisse(void) const {
  return(my_dx);
}

//permet de retourner l'ordonne du vect
float Vecteur::ordonnee(void) const{
  return(my_dy);
}



//destructeur de vecteur
Vecteur::~Vecteur(void){
}



//permet de calculer le produit scalaire de deux vecteurs
float Vecteur::produitScalaire1(Vecteur v) const
{
  return (my_dx * v.my_dx + my_dy * v.my_dy);
}


//permet de calculer le produit scalaire de deux vecteurs
float Vecteur::produitScalaire2(Vecteur &v) const
{
  return (my_dx * v.my_dx + my_dy * v.my_dy);
}


// Renvoie le produit scalaire avec passage par reference constante.
float Vecteur::produitScalaire3(const Vecteur &v) const
{
  
  return (my_dx * v.my_dx + my_dy * v.my_dy);
}





//permet de faire un test d'égalité entre deux vecteur
bool Vecteur::operator==(const Vecteur &v) const{

  return((my_dx == v.my_dx) &&
	 (my_dy == v.my_dy));
  
}


//permet de faire la somme de deux vecteurs
Vecteur Vecteur::operator+(const Vecteur &v) const
{
  Vecteur ret;
  
  ret.my_dx = my_dx + v.my_dx;
  ret.my_dy = my_dy + v.my_dy;
  
  return(ret);
  
}





//permet de faire le produit externe d'un vecteur
Vecteur Vecteur::operator*(float lamdda)const{

  Vecteur v;
  
  v.my_dx = lamdda * my_dx;
  v.my_dy = lamdda * my_dy;
  
  return(v);
}




//permet de faire la translation d'un point
Point Vecteur::operator+(const Point &p) const
{
  Point ret((my_dx + p.abcisse()),(my_dy + p.ordonnee()));
  return(ret);
  
  
}
