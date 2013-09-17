
/*! \file classerectangle.cc
 *
 * \author Paul BERNARD <paul.bernard@eisti.fr>
 *                                                   
 * \version 0.1
 *            Creation du fichier classerectangle.cc
 * \brief classe rectangle
 */

#include "classerectangle.hh"

 

Rectangle::Rectangle(void){
}




Rectangle::~Rectangle(void){
}






//constructeur par copie d'un rectangle
Rectangle::Rectangle(const Rectangle &rect)  : Polygonne(rect)
{
}



//permet d'effectuer une copie par affectation
Rectangle& Rectangle::operator=(const Rectangle &rect)
{
  if(this != &rect){
    Polygonne* tmp = this;
    *tmp = rect;
  }
  
  return(*this);
}




//permet de calculer la longueur du rectangle
float  Rectangle::longueur(void) const{
  if(tabP != NULL){
    return(tabP[0].distance(tabP[1]));
  }else{
    return(0);
  }
}


//permet de calculer la largeur du rectangle
float  Rectangle::largeur(void) const{
  if(tabP != NULL){
    return(tabP[1].distance(tabP[2]));
  }else{
    return(0);
  }
}




//constructeur d'un rectangle
Rectangle::Rectangle(bool &etat):  Polygonne(4)
{
  Point m1;
  Point m2;

//  Point pt(0,0);
//  tabP[0] = pt;
  
  m1 = ex7(tabP[0],tabP[2],0.5);
  m2 = ex7(tabP[1],tabP[3],0.5);
  
  if(!(m1 == m2)){
    liberer();
    etat = false;
    //creation de l'errreur
    erreur err("construction Rectangle, les points ne definnissent pas un rectangle");
    //evoi de l'erreur
    throw (err);
  }else{
    etat = true;
  }
}




//permet de calculer l'aire du rectangle
float Rectangle::aire(void) const{
  return(largeur() * longueur());
}


