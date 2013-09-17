
/*! \file classecarre.hh
 *
 * \author Paul BERNARD <paul.bernard@eisti.fr>
 *                                                   
 * \version 0.1
 *            Creation du fichier classecarre.hh
 * \brief classe de carre
*/

#ifndef __CLASSECARRE_HH_
#define __CLASSECARRE_HH_


#include "include.hh"
#include "classerectangle.hh"


/*! \class Carre
 * \author Paul BERNARD
 * \version 0.1
 * \brief classe carre
 *
 */

class Carre : public Rectangle
{
  
  
public:
  
  /*! 
   * \fn Carre (void) 
   * \author Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   * \brief Constructeur de la class carre
   */ 
  Carre(void);
  
  /*! 
   * \fn ~Carre (void) 
   * \author Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   * \brief Destructeur de la class carreX
   */ 
  ~Carre(void);
  
  
  /*! \fn Carre(const Carre &care) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param &care : un carre
   * 
   * \brief constructeur par copie d'un carre
   * 
   * 
   */ 
  Carre(const Carre  &carre);


 /*! \fn Carre& operator=(const Carre &care) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param &care : un carre
   * 
   * \return la copie du carre
   * 
   * \brief permet d'effectuer une copie par affectation
   * 
   * 
   */ 
  Carre& operator=(const Carre &care);


  /*! \fn float  longueur(void) const
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * 
   * \return la longueur du carre
   * 
   * \brief permet de calculer la longueur du carre
   * 
   * 
   */ 
  float  longueur(void) const;
  

  /*! \fn Carre(bool &etat) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param &etat : etat du carre (true si carre sinon false)
   * 
   * \brief constructeur d'un carre
   * 
   * 
   */ 
  Carre(bool &etat);


};

  



#endif
