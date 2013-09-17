
/*! \file classecarre.cc
 *
 * \author Paul BERNARD <paul.bernard@eisti.fr>
 *                                                   
 * \version 0.1
 *            Creation du fichier classecarre.cc
 * \brief classe de carre
*/

#include "classecarre.hh"


Carre::Carre(void){
}




Carre::~Carre(void){
}






//constructeur par copie d'un carre
Carre::Carre(const Carre &care)  : Rectangle(care)
{
}



//permet d'effectuer une copie par affectation
Carre& Carre::operator=(const Carre &care)
{
  if(this != &care){
    Rectangle* tmp = this;
    *tmp = care;
  }
  
  return(*this);
}




//permet de calculer la longueur du carre
float  Carre::longueur(void) const{
  return(longueur());
    
}


//constructeur d'un carre
Carre::Carre(bool &etat):  Rectangle(etat)
{
  
  //on regarde si c'est un acrre
  Vecteur v1(tabP[0],tabP[2]);
  Vecteur v2(tabP[1],tabP[3]);
  float pdsc = v1.pdt_scalaire(v2);
  
  //si on a pas un carre
  if(pdsc != 0){
    liberer();
    etat = false;
    //creation de l'errreur
    erreur err("Construction Carre : les points ne definnissent pas un carre \n");
    //evoi de l'erreur
    throw (err);
  }else{
    etat = true;
  }
}


