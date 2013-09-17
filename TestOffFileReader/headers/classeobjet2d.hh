
/*! \file classeobjet2d.hh
 *
 * \author Paul BERNARD <paul.bernard@eisti.fr>
 *                                                   
 * \version 0.1
 *            Creation du fichier classeobjet2d.hh
 * \brief classe objet 2d
*/

#ifndef __CLASSEOBJET2D_HH_
#define __CLASSEOBJET2D_HH_


#include "include.hh"

//#include "ZoneAffichage.h"

class ZoneAffichage;


/*! \class Objet2d
 * \author Paul BERNARD
 * \version 0.1
 * \brief généralisation de tout les objet 2d affichable
 *
 */

class Objet2d{
public:

  Objet2d(void) ;
  //Objet2d(const Objet2d &obj) ;
  
  /*! 
   * \fn ~Objet2d (void) 
   * \author Paul BERNARD <paul.bernard@eisti.fr> 
   *
   * \version 0.1 
   *
   * \brief Destructeur de la class Objet2d
   *
   */ 
  virtual ~Objet2d(void);
  

  /*! \fn virtual void affichage(void) const = 0
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * 
   * \brief permet d'afficher un objet 2d
   * 
   * \remarks methode virtuelle pure
   * 
   */ 
  virtual void affichage(void) const = 0;

  /*! \fn virtual void affichage(ZoneAffichage* zoneAffichage) = 0
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param zoneAffichage : la zoneAffichage
   * 
   * \brief permet d'afficher les objets
   * 
   */ 
  virtual void affichage(ZoneAffichage* zoneAffichage) = 0;


   /*! \fn float virtual perimetre(void) const = 0
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * 
   * \return le perimettre du polygonne
   * 
   * \brief permet de calculer le perimetre de l'objet 2d
   * 
   *\remarks methode virtuelle pure
   * 
   */ 
  virtual float perimetre(void) const = 0;
  

  /*! \fn float virtual aire(void) const = 0
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * 
   * \return l'aire du polygonne
   * 
   * \brief permet de calculer l'aire de l'objet 2d
   * 
   *\remarks methode virtuelle pure
   * 
   */ 
  virtual float aire(void) const = 0;

  
   /*! \fn void Objet2d(const Objet2d &obj) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param &obj : un objet2d
   * 
   * \brief constructeur par copie d'un objet2d
   * 
   */ 
  Objet2d(const Objet2d &);

  


};



#endif
