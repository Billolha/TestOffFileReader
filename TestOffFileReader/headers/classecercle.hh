
/*! \file classecercle.hh
 *
 * \author Paul BERNARD <paul.bernard@eisti.fr>
 *                                                   
 * \version 0.1
 *            Creation du fichier classecercle.hh
 * \brief classe de cercle
*/

#ifndef __CLASSECERCLE_HH_
#define __CLASSECERCLE_HH_


#include "include.hh"
#include "classeellipse.hh"


#include "ZoneAffichage.hh"



/*! \class Cercle
 * \author Paul BERNARD
 * \version 0.1
 * \brief classe cercle
 *
 */

class Cercle : public Ellipse{
public:
  
  /*! 
   * \fn Cercle (void) 
   * \author Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   * \brief Constructeur de la class Cercle
   */ 
  Cercle(void);
  
  /*! 
   * \fn ~Cercle (void) 
   * \author Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   * \brief Destructeur de la class Cercle
   */ 
  ~Cercle(void);
  
  
  /*! \fn Cercle(const Cercle &cerc) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param &cerc : un cercle
   * 
   * \brief constructeur par copie d'un cercle
   * 
   * 
   */ 
  Cercle(const Cercle &cerc);


 /*! \fn Cercle& operator=(const Cercle &cerc) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param &cerc : un cercle
   * 
   * \return la copie du cercle
   * 
   * \brief permet d'effectuer une copie par affectation
   * 
   * 
   */ 
  Cercle& operator=(const Cercle &cerc);


  /*! \fn float  rayon(void) const
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * 
   * \return la rayon du cercle
   * 
   * \brief permet de calculer la rayon du cercle
   * 
   * 
   */ 
  float  rayon(void) const;
  
  /*! \fn Cercle(const Point &c, float r) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param c : cenre du cercle
   * \param r : rayon du cercle
   * 
   * \brief constructeur d'un cercle
   * 
   * 
   */ 
  Cercle(const Point &c, float r) ;
  
  
};

  
#endif
