
/*! \file classerectangle.hh
 *
 * \author Paul BERNARD <paul.bernard@eisti.fr>
 *                                                   
 * \version 0.1
 *            Creation du fichier classerectangle.hh
 * \brief classe rectangle
 */

#ifndef __CLASSERECTANGLE_HH_
#define __CLASSERECTANGLE_HH_


#include "include.hh"
#include "classepolygonne.hh"
#include "fonctions.hh"






/*! \class Rectangle
 * \author Paul BERNARD
 * \version 0.1
 * \brief classe rectangle
 *
 */

class Rectangle : public Polygonne{
public:
  
  /*! 
   * \fn Rectangle (void) 
   * \author Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   * \brief Constructeur de la class Rectangle
   */ 
  Rectangle(void);
  
  /*! 
   * \fn ~Rectangle (void) 
   * \author Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   * \brief Destructeur de la class Rectangle
   */ 
  ~Rectangle(void);
  
  
  /*! \fn Rectangle(const Rectangle &rect) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param &rect : un rectangle
   * 
   * \brief constructeur par copie d'un rectangle
   * 
   * 
   */ 
  Rectangle(const Rectangle &rect);


 /*! \fn Rectangle& operator=(const Rectangle &rect) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param &rect : un rectangle
   * 
   * \return la copie du rectangle
   * 
   * \brief permet d'effectuer une copie par affectation
   * 
   * 
   */ 
  Rectangle& operator=(const Rectangle &rect);


  /*! \fn float  longueur(void) const
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * 
   * \return la longueur du rectangle
   * 
   * \brief permet de calculer la longueur du rectangle
   * 
   * 
   */ 
  float  longueur(void) const;
  

  /*! \fn float  largeur(void) const
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * 
   * \return la largeur du rectangle
   * 
   * \brief permet de calculer la largeur du rectangle
   * 
   * 
   */ 
  float  largeur(void) const;

  /*! \fn Rectangle(bool &etat) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param &etat : etat du rectangle (true si un rectangle sinon false)
   * 
   * \brief constructeur d'un rectangle
   * 
   * 
   */ 
  Rectangle(bool & etat);




  /*! \fn float aire(void) const
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * 
   * \return l'aire du rectangle
   * 
   * \brief permet de calculer l'aire du rectangle
   * 
   * 
   */ 
  float aire(void) const;
 

};

  




#endif
