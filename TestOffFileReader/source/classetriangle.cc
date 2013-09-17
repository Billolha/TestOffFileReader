
/*! \file classetriangle.cc
 *
 * \author Paul BERNARD <paul.bernard@eisti.fr>
 *                                                   
 * \version 0.1
 *            Creation du fichier classetriangle.cc
 * \brief classe triangle
 */

#include "classetriangle.hh"

 

Triangle::Triangle(void){
  //  cout<<"constructeur par defaut de triangle\n";
}




Triangle::~Triangle(void){
  //  cout<<"Triangle detruit\n";
}






//constructeur par copie d'un triangle
Triangle::Triangle(const Triangle &tri)  : Polygonne(tri)
{
  //  cout<<"constructeur par copie de triangle\n";
}



//permet d'effectuer une copie par affectation
Triangle& Triangle::operator=(const Triangle &tri)
{
  if(this != &tri){
    Polygonne* tmp = this;
    *tmp = tri;
  }
  
  return(*this);
}





//constructeur d'un triangle
Triangle::Triangle(bool &etat):  Polygonne(3)
{
  if((tabP[0] == tabP[1]) ||
     (tabP[1] == tabP[2]) ||
     (tabP[2] == tabP[0])){
    liberer();
    etat = false;
    //creation de l'errreur
    erreur err("construction Triangle, les points ne definnissent pas un triangle");
    //evoi de l'erreur
    throw (err);
  }else{
    etat = true;
  }
}



//(1/4) * sqrt((a+b+c)*(-a+b+c)*(a-b+c)*(a+b-c))
//permet de calculer l'aire du triangle
float Triangle::aire(void) const
{
  if(tabP != NULL){
    float a = tabP[0].distance(tabP[1]); //21
    float b = tabP[1].distance(tabP[2]); //10
    float c = tabP[2].distance(tabP[0]); //17
    
    if(a != 0){
      float h2 = (c*c) - (( ( (a*a) + (c*c) - (b*b)) / (2*a) )*( ( (a*a) + (c*c) - (b*b)) / (2*a) ));
      float h = sqrtf(h2);
      float aire = 0.5 * a * h;
      //cout<<a<<endl<<b<<endl<<c<<endl<<h2<<endl<<h<<endl<<aire<<endl;
      return(aire);
    }else{
      //creation de l'errreur
      erreur err("pas de triangle donc on ne peut pas calculer son aire \n");
      //evoi de l'erreur
      throw (err);
      return(0);
    }
  }else{
   //creation de l'errreur
    erreur err("pas de triangle donc on ne peut pas calculer d'aire \n");
    //evoi de l'erreur
    throw (err);
    return(0);
  }
}


