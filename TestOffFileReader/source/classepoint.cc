
/*! \file classepoint.cc
 *
 * \author Paul BERNARD <paul.bernard@eisti.fr>
 *                                                   
 * \version 0.1
 *            Creation du fichier classepoint.cc
 * \brief classe de point
*/

#include "classepoint.hh"


//permet d'init un point aux valeurs par defaut
Point::Point(void)
{
  //on init le point
  my_dx = 0.0;
  my_dy = 0.0; 
}


//permet d'init un point au valeur x y
Point::Point(float x, float y)
{
  //on init le point
  my_dx = x;
  my_dy = y;
}




//constructeur par copie d'un point
Point::Point(const Point &p)
{
  //on copie les champs un par un
  my_dx = p.my_dx;
  my_dy = p.my_dy;
}


//permet d'effectuer une copy par affectation
Point& Point::operator=(const Point &p)
{
  //si l'objet n'est pas le meme 
  if(this!= &p){
    //on copie les champs un par un
    my_dx = p.my_dx;
    my_dy = p.my_dy;
  }
  //on retourne l'objet
  return(*this);
}






////permet d'init l'abcisse d'un point
//void Point::abcisse(float x)
//{
//  my_dx = x;
//}
//
////permet d'init l'ordonnee d'un point
//void Point::ordonnee(float y)
//{
//  my_dy = y;
//}



//permet d'afficher les coord d'un point
void Point::affichage(void) const
{
  cout<<"coord du point : X = "<<my_dx<<" et Y = "<<my_dy<<endl;
}






//permet de translater un point de +x +y  
void Point::translate(float x, float y)
{
  //translation des coords
  my_dx = my_dx + x;
  my_dy = my_dy + y;
}


//permet de calculer la distance avec le point placé en param
float Point::distance(const Point &pt) const
{
  //on retourne la distance entre les deux points
  return(sqrt((my_dx - pt.my_dx)*(my_dx - pt.my_dx) + (my_dy - pt.my_dy)*(my_dy - pt.my_dy)));
}


//permet de retourner l'abcisse du point
float Point::abcisse(void) const
{
  //on retourne le champ abcisse
  return(my_dx);
}



//permet de retourner l'ordonne du point
float Point::ordonnee(void) const
{
  //on retourne le champ ordonnee
  return(my_dy);
}


//destructeur de point
Point::~Point(void)
{
}






//permet de lire un point dans un fichier
void Point::lire_Point_binaire(ifstream* fic)
{
  //on lit l'abcisse
  fic->read((char*)  &my_dx,sizeof(float)); 
  //si la derniere operation ne s'est pas bien passe
  if (!fic->good()) {
    //on libere la memoire
    delete fic;
    //creation de l'errreur
    erreur err("Erreur de lecture du fichier (point.my_dx)");
    //evoi de l'erreur
    throw (err);
  }

  //on lit l'ordonnee
  fic->read((char*)  &my_dy,sizeof(float)); 
  //si la derniere operation ne s'est pas bien passe
  if (!fic->good()) {
    //on libere la memoire
    delete fic;
    //creation de l'errreur
    erreur err("Erreur de lecture du fichier (point.my_dy)");
    //evoi de l'erreur
    throw (err);
  }
}





//permet d'ecrire un point dans un fichier
void Point::ecrire_Point_binaire(ofstream* fic) const
{
  //on sauve l'abcisse
  fic->write((char*) &my_dx,sizeof(float));
  //si la derniere operation ne s'est pas bien passe
  if (!fic->good()) {
    //on libere la memoire
    delete fic;
    //creation de l'errreur
    erreur err("Erreur d'ecriture du fichier (point.my_dx)");
    //evoi de l'erreur
    throw (err);
  }
  
  //on sauve l'ordonnee
  fic->write((char*) &my_dy,sizeof(float));
  //si la derniere operation ne s'est pas bien passe
  if (!fic->good()) {
    //on libere la memoire
    delete fic;
    //creation de l'errreur
    erreur err("Erreur d'ecriture du fichier (point.my_dy)");
    //evoi de l'erreur
    throw (err);
  }
}


//permet de faire un test d'égalité entre deux point
bool Point::operator==(const Point &pt) const
{
  return((my_dx == pt.my_dx) &&
	 (my_dy == pt.my_dy));
}
