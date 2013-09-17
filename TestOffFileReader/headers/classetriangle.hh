
/*! \file classetriangle.hh
 *
 * \author Paul BERNARD <paul.bernard@eisti.fr>
 *                                                   
 * \version 0.1
 *            Creation du fichier classetriangle.hh
 * \brief classe triangle
 */

#ifndef __CLASSETRIANGLE_HH_
#define __CLASSETRIANGLE_HH_


#include "include.hh"
#include "classepolygonne.hh"





/*! \class Triangle
 * \author Paul BERNARD
 * \version 0.1
 * \brief classe triangle
 *
 */

class Triangle : public Polygonne{
public:
  
  /*! 
   * \fn Triangle (void) 
   * \author Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   * \brief Constructeur de la class Triangle
   */ 
  Triangle(void);
  
  /*! 
   * \fn ~Triangle (void) 
   * \author Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   * \brief Destructeur de la class Triangle
   */ 
  ~Triangle(void);
  
  
  /*! \fn Triangle(const Triangle &tri) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param &tri : un triangle
   * 
   * \brief constructeur par copie d'un triangle
   * 
   * 
   */ 
  Triangle(const Triangle &tri);


 /*! \fn Triangle& operator=(const Triangle &tri) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param &tri : un triangle
   * 
   * \return la copie du triangle
   * 
   * \brief permet d'effectuer une copie par affectation
   * 
   * 
   */ 
  Triangle& operator=(const Triangle &tri);


  /*! \fn Triangle(bool &etat) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param &etat : etat du triangle (true si triangle sinon false)
   * 
   * \brief constructeur d'un triangle
   * 
   * 
   */ 
  Triangle(bool &etat);

 
  /*! \fn float aire(void) const
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * 
   * \return l'aire du triangle
   * 
   * \brief permet de calculer l'aire du triangle
   * 
   * 
   */ 
  float aire(void) const;
 

};

  




#endif
