
/*! \file classetrianglerectangle.cc
 *
 * \author Paul BERNARD <paul.bernard@eisti.fr>
 *                                                   
 * \version 0.1
 *            Creation du fichier classetrianglerectangle.cc
 * \brief classe de triangle rectangle
*/

#include "classetrianglerectangle.hh"




TriangleRectangle::TriangleRectangle(void){
  cout<<"constructeur par defaut de triangleRectangle\n";
}




TriangleRectangle::~TriangleRectangle(void){
  cout<<"TriangleRectangle detruit\n";
}






//constructeur par copie d'un triangleRectangle
TriangleRectangle::TriangleRectangle(const TriangleRectangle &tri_rect)  
  : Triangle(tri_rect)
{
  cout<<"constructeur par copie de triangleRectangle\n";
}



//permet d'effectuer une copie par affectation
TriangleRectangle& TriangleRectangle::operator=(const TriangleRectangle &tri_rect)
{
  if(this != &tri_rect){
    Triangle* tmp = this;
    *tmp = tri_rect;
  }
  
  return(*this);
}





//constructeur d'un triangleRectangle
TriangleRectangle::TriangleRectangle(bool &etat):  Triangle(etat)
{
  Vecteur v1(tabP[0],tabP[1]);
  Vecteur v2(tabP[1],tabP[2]);
  Vecteur v3(tabP[2],tabP[0]);
  
  if(!((v1.pdt_scalaire(v2) == 0) ||
       (v2.pdt_scalaire(v3) == 0) ||
       (v3.pdt_scalaire(v1) == 0))){
    liberer();
    etat = false;
    //creation de l'errreur
    erreur err("construction TriangleRectangle, les points ne definnissent pas un triangle rectangle");
    //evoi de l'erreur
    throw (err);
  }else{
    etat = true;
  }
}
