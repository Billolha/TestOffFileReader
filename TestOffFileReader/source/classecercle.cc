
/*! \file classecercle.cc
 *
 * \author Paul BERNARD <paul.bernard@eisti.fr>
 *                                                   
 * \version 0.1
 *            Creation du fichier classecercle.cc
 * \brief classe de cercle
*/

#include "classecercle.hh"


 

Cercle::Cercle(void){
  //  cout<<"constructeur par defaut de cercle\n";
}




Cercle::~Cercle(void){
  //  cout<<"Cercle detruit\n";
}






//constructeur par copie d'un cercle
Cercle::Cercle(const Cercle &cerc)  : Ellipse(cerc)
{
  //  cout<<"constructeur par copie de cercle\n";
}



//permet d'effectuer une copie par affectation
Cercle& Cercle::operator=(const Cercle &cerc)
{
  if(this != &cerc){
    Ellipse* tmp = this;
    *tmp = cerc;
  }
  
  return(*this);
}




//permet de calculer la rayon du cercle
float  Cercle::rayon(void) const{
  return(get_gd_axe());
}







//constructeur d'un cercle
Cercle::Cercle(const Point &c, float r):  Ellipse(c,r,r)
{
  //  cout<<"construteur d'un cercle par valeur\n";
}




