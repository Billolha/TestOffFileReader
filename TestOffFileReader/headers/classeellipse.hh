
/*! \file classeellipse.hh
 *
 * \author Paul BERNARD <paul.bernard@eisti.fr>
 *                                                   
 * \version 0.1
 *            Creation du fichier classeellipse.hh
 * \brief lasse ellipse
*/

#ifndef __CLASSEELLIPSE_HH_
#define __CLASSEELLIPSE_HH_


#include "include.hh"
#include "classepoint.hh"
#include "classeobjet2d.hh"
#include "ZoneAffichage.hh"



/*! \class Ellipse
 * \author Paul BERNARD
 * \version 0.1
 * \brief classe ellipse
 *
*/

class Ellipse : public Objet2d{
private:
Point my_centre;/*!< centre d'une ellipse*/
float my_gd_axe;/*!< le demi grand axe*/
float my_pt_axe;/*!< le demi petit axe*/

public:

  /*! 
   * \fn Ellipse (void) 
   * \author Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   * \brief Constructeur de la class Ellipse
   */ 
  Ellipse(void);
  
  
  /*! 
   * \fn Ellipse (const Point & centre_donnee, const float & gd_axe_donnee, const float & pt_axe_donnee) 
   *
   * \author Paul BERNARD <paul.bernard@eisti.fr> 
   *   
   * \version 0.1 
   *           Creation de la fonction
   * \version 0.2 
   *           Gestion des exceptions
   *
   * \param centre_donnee : La valeur que doit prendre my_centre
   * \param gd_axe_donnee : La valeur que doit prendre my_gd_axe
   * \param pt_axe_donnee : La valeur que doit prendre my_pt_axe
   *
   * \brief Constructeur de la class Ellipse avec valeur fournit
   *
   * \remarks peut lever une exception
   */ 
  Ellipse(const Point & centre_donnee, const float & gd_axe_donnee, const float & pt_axe_donnee);
  
  /*! 
   * \fn Ellipse(const Ellipse & Ellipse_autre);
   * \author Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   * 
   * \param Ellipse_autre : Ellipse au quel est associe le Ellipse sur lequel on travail
   * 
   * 
   * \brief Constructeur par copie d'une ellipse
   */ 
  Ellipse(const Ellipse & Ellipse_autre);


  /*! 
   * \fn ~Ellipse (void) 
   * \author Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   * \brief Destructeur de la class Ellipse
   */ 
  ~Ellipse(void);
  

  /*! 
   * \fn void set_centre(Point Point_donne);
   * \author Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   * 
   * \param Point_donne : la valeur que doit prendre my_centre
   * \return retourne le champ my_centre 
   * 
   * \brief Accesseur en ecriture a la variable my_centre
   */ 
  void set_centre(Point Point_donne);
  
  /*! 
   * \fn Point get_centre(void) const ;
   * \author Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   * 
   * \return retourne le champ my_centre 
   * 
   * \brief Accesseur en lecture a la variable my_centre
   */ 
  Point get_centre(void) const ;

  
  /*! 
   * \fn void set_gd_axe(float float_donne);
   * \author Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   * 
   * \param float_donne : la valeur que doit prendre my_gd_axe
   * \return retourne le champ my_gd_axe 
   * 
   * \brief Accesseur en ecriture a la variable my_gd_axe
   */ 
  void set_gd_axe(float float_donne);
  
  
  /*! 
   * \fn float get_gd_axe(void) const ;
   * \author Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   * 
   * \return retourne le champ my_gd_axe 
   * 
   * \brief Accesseur en lecture a la variable my_gd_axe
   */ 
  float get_gd_axe(void) const ;
  
  
  /*! 
   * \fn void set_pt_axe(float float_donne);
   * \author Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   * 
   * \param float_donne : la valeur que doit prendre my_pt_axe
   * \return retourne le champ my_pt_axe 
   * 
   * \brief Accesseur en ecriture a la variable my_pt_axe
   */ 
  void set_pt_axe(float float_donne);

  
  /*! 
   * \fn float get_pt_axe(void) const ;
   * \author Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   * 
   * \return retourne le champ my_pt_axe 
   * 
   * \brief Accesseur en lecture a la variable my_pt_axe
   */ 
  float get_pt_axe(void) const ;
  
  /*! 
   * \fn Ellipse & operator=(const Ellipse & Ellipse_autre);
   * \author Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   * 
   * \param Ellipse_autre : Ellipse au quel est associe le Ellipse sur lequel on travail
   * 
   * 
   * \brief Surcharge de l'operateur '=' 
   */ 
  Ellipse & operator=(const Ellipse & Ellipse_autre);

  
  /*! 
   * \fn bool operator==(const Ellipse & Ellipse_testee) const;
   * \author Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   * 
   * \param Ellipse_testee : Ellipse au quel est compare le Ellipse sur lequel on travail
   * \return vrai si les deux Ellipse sont egaux et faux sinon 
   * 
   * \brief Surcharge de l'operateur '==' 
   */ 
  bool operator==(const Ellipse & Ellipse_testee) const;


  /*! \fn void affichage(void) const
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * 
   * \brief permet d'afficher une ellipse
   * 
   * 
   */ 
  void affichage(void) const;

  /*! \fn void affichage(ZoneAffichage* zoneAffichage)
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param zoneAffichage : la zoneAffichage
   * 
   * \brief permet d'afficher les objets
   * 
   */ 
  void affichage(ZoneAffichage* zoneAffichage);
  

  /*! \fn float perimetre(void) const
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * 
   * \return le perimetre de l'ellipse
   * 
   * \brief permet de calculer le perimetre de l'ellipse
   * 
   * 
   */ 
  float perimetre(void) const;

  /*! \fn float aire(void) const
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * 
   * \return l' aire de l'ellipse
   * 
   * \brief permet de calculer l' aire de l'ellipse
   * 
   * 
   */ 
  float aire(void) const;

  /*! \fn void lire_ellipse_binaire(char* fichier) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * \version 0.2 
   *           Gestion des exceptions
   * \version 0.3 
   *           Gestion dans objet2d, changement de nom
   * 
   * 
   * \param fichier : le nom du fichier
   * 
   * 
   * \brief permet d'affecter le centre et les demi axes  
   *        d'une ellipse a partir d'un fichier
   * 
   * \remarks utilise la fonction lire_Point, peut lever une exception 
   */ 
  void lire_ellipse_binaire(char* fichier);

  /*! \fn void ecrire_ellipse_binaire(char* fichier) const 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * \version 0.2 
   *           Gestion des exceptions
   * 
   * \param fichier : le nom du fichier
   * 
   * 
   * \brief permet d'ecrire le centre et les demi axes  
   *        d'une ellipse dans un fichier
   * 
   * \remarks utilise la fonction ecrire_Point, peut lever une exception 
   */ 
  void ecrire_ellipse_binaire(char* fichier) const;



};


#endif
