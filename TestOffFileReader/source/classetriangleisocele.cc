
/*! \file classetriangleisocele.cc
 *
 * \author Paul BERNARD <paul.bernard@eisti.fr>
 *                                                   
 * \version 0.1
 *            Creation du fichier classetriangleisocele.cc
 * \brief classe de triangle isocele
*/

#include "classetriangleisocele.hh"




TriangleIsocele::TriangleIsocele(void){
  cout<<"constructeur par defaut de triangleIsocele\n";
}




TriangleIsocele::~TriangleIsocele(void){
  cout<<"TriangleIsocele detruit\n";
}






//constructeur par copie d'un triangleIsocele
TriangleIsocele::TriangleIsocele(const TriangleIsocele &tri_iso)  
  : Triangle(tri_iso)
{
  cout<<"constructeur par copie de triangleIsocele\n";
}



//permet d'effectuer une copie par affectation
TriangleIsocele& TriangleIsocele::operator=(const TriangleIsocele &tri_iso)
{
  if(this != &tri_iso){
    Triangle* tmp = this;
    *tmp = tri_iso;
  }
  
  return(*this);
}







//constructeur d'un triangleIsocele
TriangleIsocele::TriangleIsocele(bool &etat):  Triangle(etat)
{
  if(!((tabP[0].distance(tabP[1]) == tabP[0].distance(tabP[2])) ||
       (tabP[0].distance(tabP[1]) == tabP[1].distance(tabP[2])) ||
       (tabP[0].distance(tabP[2]) == tabP[1].distance(tabP[2])))){
    liberer();
    etat = false;
    //creation de l'errreur
    erreur err("construction TriangleIsocele, les points ne definnissent pas un triangle isocele");
    //evoi de l'erreur
    throw (err);
  }else{
    etat = true;
  }
}

