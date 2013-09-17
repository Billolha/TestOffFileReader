
/*! \file classetriangleequilateral.cc
 *
 * \author Paul BERNARD <paul.bernard@eisti.fr>
 *                                                   
 * \version 0.1
 *            Creation du fichier classetriangleequilateral.cc
 * \brief classe de triangle equilateral
*/

#include "classetriangleequilateral.hh"




TriangleEquilateral::TriangleEquilateral(void){
  cout<<"constructeur par defaut de triangleEquilateral\n";
}




TriangleEquilateral::~TriangleEquilateral(void){
  cout<<"TriangleEquilateral detruit\n";
}






//constructeur par copie d'un triangleEquilateral
TriangleEquilateral::TriangleEquilateral(const TriangleEquilateral &tri_equi)  
  : Triangle(tri_equi)
{
  cout<<"constructeur par copie de triangleEquilateral\n";
}



//permet d'effectuer une copie par affectation
TriangleEquilateral& TriangleEquilateral::operator=(const TriangleEquilateral &tri_equi)
{
  if(this != &tri_equi){
    Triangle* tmp = this;
    *tmp = tri_equi;
  }
  
  return(*this);
}




//constructeur d'un triangleEquilateral
TriangleEquilateral::TriangleEquilateral(bool &etat):  Triangle(etat)
{
  if(!((tabP[0].distance(tabP[1]) == tabP[0].distance(tabP[2])) &&
       (tabP[0].distance(tabP[1]) == tabP[1].distance(tabP[2])))){
    liberer();
    etat = false;
    //creation de l'errreur
    erreur err("construction TriangleEquilateral, les points ne definnissent pas un triangle equilateral");
    //evoi de l'erreur
    throw (err);
  }else{
    etat = true;
  }
  
}



